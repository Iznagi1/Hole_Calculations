//
// Created by User on 06.08.2023.
//

#ifndef GEOMETRY_POINT_H
#define GEOMETRY_POINT_H


#include <iostream>

struct Point {
    double x;
    double y;

    explicit Point(double x = 0, double y = 0) : x(x), y(y) {}

    void Print() const;
};

double GetDistance(const Point &p1, const Point &p2);

#endif //GEOMETRY_POINT_H
