//
// Created by User on 06.08.2023.
//

#ifndef OBJECTS_ALARM_H
#define OBJECTS_ALARM_H

#include "Rectangle.h"
#include "Object.h"

class Alarm : public Object {
    RectangleType base;
public:
    Alarm(Point leftDown, Point rightUp);

    double GetDistance(const Point& p) const override;
    void Print() const;
    bool IsValid() const override;
};


#endif //OBJECTS_ALARM_H
