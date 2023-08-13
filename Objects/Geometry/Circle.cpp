//
// Created by User on 06.08.2023.
//

#include <stdexcept>
#include <string>
#include <valarray>
#include "Circle.h"


double CircleType::GetCenterX() const {
    return center.x;
}

double CircleType::GetCenterY() const {
    return center.y;
}

double CircleType::GetRadius() const {
    return radius;
}

Point CircleType::GetCenter() const {
    return center;
}

void CircleType::SetCenterX(double x) {
    center.x = x;
}

void CircleType::SetCenterY(double x) {
    center.y = x;
}

void CircleType::SetCenter(Point p) {
    center = p;
}

void CircleType::SetRadius(double x) {
    radius = x;
}

double CircleType::GetDistance(const Point& p1) const {
    double distance = ::GetDistance(p1, center);
    return distance;
}

bool CircleType::IsInside(const Point &p1) const {
    throw std::runtime_error(std::string("Logic error: no need use IsInside for Circle"));
}

bool CircleType::IsValid() const {
    return radius > 0;
}
