//
// Created by User on 06.08.2023.
//

#ifndef ALARM_H
#define ALARM_H

#include "Rectangle.h"
#include "Object.h"

class Alarm : public Object {
    RectangleType base;
public:
    Alarm(Point leftDown, Point rightUp);

    RectangleType GetBase() const;

    double GetDistance(const Point &p) const override;

    bool IsValid() const override;
};


#endif //ALARM_H
