//
// Created by User on 06.08.2023.
//

#include <algorithm>
#include <vector>
#include <numeric>
#include "Rectangle.h"
#include "Segment.h"


RectangleType::RectangleType(Point leftDown, Point rightUp) {
    this->width = rightUp.x - leftDown.x;
    this->height = rightUp.y - leftDown.y;
    this->center.x = leftDown.x + (rightUp.x - leftDown.x) / 2;
    this->center.y = leftDown.y + (rightUp.y - leftDown.y) / 2;
}

double RectangleType::GetCenterX() const {
    return center.x;
}

double RectangleType::GetCenterY() const {
    return center.y;
}

Point RectangleType::GetCenter() const {
    return center;
}

double RectangleType::GetWidth() const {
    return width;
}

double RectangleType::GetHeight() const {
    return height;
}

void RectangleType::SetCenterX(double x) {
    center.x = x;
}

void RectangleType::SetCenterY(double x) {
    center.y = x;
}

void RectangleType::SetWidth(double x) {
    width = x;
}

void RectangleType::SetHeight(double x) {
    height = x;
}

void RectangleType::SetCenter(Point p) {
    center = p;
}

double RectangleType::GetDistance(const Point &p) const {
    Segment left(Point(center.x - width / 2, center.y - height / 2),
                 Point(center.x - width / 2, center.y + height / 2));

    Segment right(Point(center.x + width / 2, center.y - height / 2),
                  Point(center.x + width / 2, center.y + height / 2));

    Segment up(Point(center.x - width / 2, center.y + height / 2),
               Point(center.x + width / 2, center.y + height / 2));

    Segment down(Point(center.x - width / 2, center.y - height / 2),
                 Point(center.x + width / 2, center.y - height / 2));

    std::vector<Segment> sides = {std::move(left), std::move(right), std::move(up), std::move(down)};
//    for (const auto& a : sides) {
//        std::cout << a.GetDistance(p) << ' ';
//    }
//    std::cout << std::endl;

    auto ptr = std::min_element(sides.begin(), sides.end(),
                                [&p](Segment &seg1, Segment &seg2) {
                                    return seg1.GetDistance(p) < seg2.GetDistance(p);
                                });
//    std::cout << ptr->GetDistance(p) << std::endl;
    return ptr->GetDistance(p);
}

bool RectangleType::IsInside(const Point &p1) const {
    return (center.x - width / 2 >= p1.x) && (p1.x <= center.x + width / 2) &&
           (center.y - height / 2 >= p1.y) && (p1.y <= center.y + height / 2);

}

bool RectangleType::IsValid() const {
    return Segment(Point(center.x - width / 2, center.y - height / 2),
                   Point(center.x + width / 2, center.y + height / 2)).IsValid();
}


