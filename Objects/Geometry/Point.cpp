//
// Created by User on 06.08.2023.
//

#include "Point.h"
#include <cmath>

double GetDistance(const Point& p1, const Point& p2) {
    return std::sqrt(pow((p1.x - p2.x), 2) + pow(p1.y - p2.y, 2));
}

void Point::Print() const {
    std::cout << "x = " << x << " y = " << y << std::endl;
}
