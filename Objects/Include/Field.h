//
// Created by User on 06.08.2023.
//

#ifndef FIELD_H
#define FIELD_H

#include "Rectangle.h"
#include "Object.h"

class Field : public Object {
    RectangleType base;
public:
    Field(Point leftDown = Point(0, 0), Point rightUp = Point(0, 0));

    RectangleType GetBase() const;

    double GetDistance(const Point &p) const override;

    bool IsValid() const override;

    std::pair<std::pair<double, double>, std::pair<double, double>> GetRanges() const;
};


#endif //FIELD_H
