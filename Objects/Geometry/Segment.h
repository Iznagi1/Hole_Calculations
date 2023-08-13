//
// Created by User on 11.08.2023.
//

#ifndef SEGMENT_H
#define SEGMENT_H

#include "Point.h"
#include "Shape.h"

struct Segment : Shape {
    Point leftDown;
    Point rightUp;
    Segment(Point leftDown, Point rightUp) : leftDown(leftDown), rightUp(rightUp) {}

    double GetDistance (const Point& p) const override;
    bool IsInside(const Point& p1) const override;
    bool IsValid() const override;
};


#endif //SEGMENT_H
