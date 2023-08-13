//
// Created by User on 11.08.2023.
//

#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"

class Shape {
    virtual double GetDistance(const Point &p1) const = 0;

    virtual bool IsInside(const Point &p1) const = 0;

    virtual bool IsValid() const = 0;
};


#endif //SHAPE_H
