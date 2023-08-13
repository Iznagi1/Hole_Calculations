//
// Created by User on 06.08.2023.
//

#include <algorithm>
#include <valarray>
#include "Rectangle.h"


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
    double dx = std::max(std::max((center.x - width / 2) - p.x, 0.0), p.x - (p.x <= center.x + width / 2));
    double dy = std::max(std::max((center.y - height / 2) - p.y, 0.0), p.y - (center.y + height / 2));

    return std::sqrt(dx * dx + dy * dy);
}

bool RectangleType::IsInside(const Point &p1) const {
    return p1.x >= center.x - width / 2 && p1.x <= center.x + width / 2 &&
           p1.y >= center.y - height / 2 && p1.y <= center.y + height / 2;

}

bool RectangleType::IsValid() const {
    return width > 0 && height > 0;
}


