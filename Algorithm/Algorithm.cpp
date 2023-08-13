//
// Created by User on 12.08.2023.
//

#include <algorithm>
#include <stdexcept>
#include <memory>
#include <numeric>
#include <iostream>
#include <valarray>
#include <cfloat>
#include "Algorithm.h"

void Algorithm::ValidateData(std::vector<Alarm> &alarms, std::vector<Hole> &holes, const Field &field) {
    bool isValid = std::all_of(alarms.begin(), alarms.end(), [](const Alarm &alarm) { return alarm.IsValid(); }) &&
                   std::all_of(holes.begin(), holes.end(), [](const Hole &hole) { return hole.IsValid(); }) &&
                   field.IsValid();
    if (!isValid) {
        throw std::runtime_error(std::string("Invalid data"));
    }
}

double Algorithm::GetSumOfDistance(const Point &p, const Hole &hole, std::vector<std::unique_ptr<Object>> &objects) {
    return std::accumulate(objects.begin(), objects.end(), 0., [&p, &hole](double acc, std::unique_ptr<Object> &obj) {
        return acc + obj->GetDistance(p) -
               (IsHole(obj) ? hole.GetExternalCircle().GetRadius() : hole.GetInnerCircle().GetRadius());
    });
}

bool Algorithm::IsHole(std::unique_ptr<Object> &object) {
    return dynamic_cast<Hole *>(object.get()) != nullptr;
}

double Algorithm::GetMinDistanceToBorders(const Point &p, std::vector<std::unique_ptr<Object>> &objects) {
    auto ptr = std::min_element(objects.begin(), objects.end(),
                                [&p](std::unique_ptr<Object> &obj1, std::unique_ptr<Object> &obj2) {
                                    return std::pair<bool, double>(IsHole(obj1), obj1->GetDistance(p)) <
                                           std::pair<bool, double>(IsHole(obj2), obj2->GetDistance(p));
                                });
    if (ptr == objects.end() || IsHole(*ptr)) {
        return DBL_MAX;
    }
    return (*ptr)->GetDistance(p);
}

double Algorithm::GetMinDistanceToHole(const Point &p, std::vector<std::unique_ptr<Object>> &objects) {
    auto ptr = std::min_element(objects.begin(), objects.end(),
                                [&p](std::unique_ptr<Object> &obj1, std::unique_ptr<Object> &obj2) {
                                    return std::pair<bool, double>(!IsHole(obj1), obj1->GetDistance(p)) <
                                           std::pair<bool, double>(!IsHole(obj2), obj2->GetDistance(p));
                                });
    if (ptr == objects.end() || !IsHole(*ptr)) {
        return DBL_MAX;
    }
    return (*ptr)->GetDistance(p);
}

std::pair<double, double>
Algorithm::TernarySearchOnY(const std::pair<double, double> &range, double x, const Hole &hole,
                            std::vector<std::unique_ptr<Object>> &objects) {
    auto [left, right] = range;
    left += hole.GetInnerCircle().GetRadius() + EPS;
    right -= hole.GetInnerCircle().GetRadius() + EPS;
    while (right - left > EPS) {
        double mid1 = left + (right - left) / 3, mid2 = right - (right - left) / 3;
//        std::cout << GetSumOfDistance(Point(x, mid1), hole, objects) << ' ' << GetSumOfDistance(Point(x, mid2), hole, objects) << std::endl;
        if (GetSumOfDistance(Point(x, mid1), hole, objects) < GetSumOfDistance(Point(x, mid2), hole, objects)) {
            left = mid1;
        } else {
            right = mid2;
        }
    }
    return {left, GetSumOfDistance(Point(x, left), hole, objects)};
}

bool Algorithm::CalculateHole(Hole &hole, std::vector<std::unique_ptr<Object>> &objects, const Field &field) {
    auto [xRange, yRange] = field.GetMarkup();
    auto [left, right] = xRange;
    double radius = hole.GetInnerCircle().GetRadius();
    left += radius + EPS;
    right -= radius + EPS;
    std::cout << left << ' ' << right << std::endl;

    while (right - left > EPS) {
        double mid1 = left + (right - left) / 3, mid2 = right - (right - left) / 3;
        if (TernarySearchOnY(yRange, mid1, hole, objects).second <
            TernarySearchOnY(yRange, mid2, hole, objects).second) {
            left = mid1;
        } else {
            right = mid2;
        }
    }
    Point res = Point(left, TernarySearchOnY(yRange, left, hole, objects).first);
    std::cout << "OUTPUT:\n";
    res.Print();

//    hole.SetCenter(Point(left, TernarySearchOnY(yRange, left, radius, objects).first));
//    objects.push_back(std::make_unique<Hole>(Hole(hole)));
//    return true;
    std::cout << "Zabor " << GetMinDistanceToBorders(res, objects) << " " << radius << std::endl;
    std::cout << "Dirka " << GetMinDistanceToHole(res, objects) << " " << hole.GetExternalCircle().GetRadius()
              << std::endl;
    if (GetMinDistanceToBorders(res, objects) > radius &&
        GetMinDistanceToHole(res, objects) > hole.GetExternalCircle().GetRadius()) {
        hole.SetCenter(Point(left, TernarySearchOnY(yRange, left, hole, objects).first));
        objects.push_back(std::make_unique<Hole>(Hole(hole)));
        return true;
    }
    return false;
}

bool Algorithm::CalculateHoles(std::vector<Alarm> &alarms, std::vector<Hole> &holes, const Field &field) {
    ValidateData(alarms, holes, field);
    std::vector<std::unique_ptr<Object>> objects;
    objects.reserve(alarms.size() + 1);
    for (const auto &alarm: alarms) {
        objects.push_back(std::make_unique<Alarm>(Alarm(alarm)));
    }
    std::sort(holes.begin(), holes.end());
    std::reverse(holes.begin(), holes.end());

    return CalculateHolesImpl(objects, holes, field);
}

bool Algorithm::CalculateHolesImpl(std::vector<std::unique_ptr<Object>> &objects, std::vector<Hole> &holes,
                                   const Field &field) {
    for (auto &hole: holes) {
        if (!CalculateHole(hole, objects, field)) {
            return false;
        }
    }
    return true;
}










