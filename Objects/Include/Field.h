//
// Created by User on 06.08.2023.
//

#ifndef OBJECTS_FIELD_H
#define OBJECTS_FIELD_H

#include "Rectangle.h"
#include "Object.h"

class Field : public Object {
    RectangleType base;
public:
    Field(Point leftDown, Point rightUp);
    void Print() const;

    double GetDistance(const Point& p) const override;
    bool IsValid() const override;
    std::pair<std::pair<double, double>, std::pair<double, double>> GetMarkup() const;
};


#endif //OBJECTS_FIELD_H
