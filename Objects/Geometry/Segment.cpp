//
// Created by User on 11.08.2023.
//

#include <cmath>
#include <stdexcept>
#include <iostream>
#include "Segment.h"


double Segment::GetDistance(const Point &p) const {
    double segmentLength = std::pow(rightUp.x - leftDown.x, 2) + std::pow(rightUp.y - leftDown.y, 2);
    double t = ((p.x - leftDown.x) * (rightUp.x - leftDown.x) + (p.y - leftDown.y) * (rightUp.y - leftDown.y)) /
               std::pow(segmentLength, 2);

    if (t < 0.0) {
        return std::sqrt(std::pow(p.x - leftDown.x, 2) + std::pow(p.y - leftDown.y, 2));
    }
    if (t > 1.0) {
        return std::sqrt(std::pow(p.x - rightUp.x, 2) + std::pow(p.y - rightUp.y, 2));
    }

    double closestPointX = leftDown.x + t * (rightUp.x - leftDown.x);
    double closestPointY = leftDown.y + t * (rightUp.y - leftDown.y);
//    std::cout << p.x << ' ' << p.y << ' ' << std::pow(p.x - closestPointX, 2) + std::pow(p.y - closestPointY, 2) << std::endl;
    return std::sqrt(std::pow(p.x - closestPointX, 2) + std::pow(p.y - closestPointY, 2));
}

bool Segment::IsInside(const Point &p1) const {
    throw std::runtime_error(std::string("Logic error: no need use IsInside for Segment"));
}

bool Segment::IsValid() const {
    return !((leftDown.x == rightUp.x && leftDown.y == rightUp.y) ||
             (leftDown.x > rightUp.x) && (leftDown.y > rightUp.y));
}
