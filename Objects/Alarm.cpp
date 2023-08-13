//
// Created by User on 06.08.2023.
//

#include <iostream>
#include "Alarm.h"

Alarm::Alarm(Point leftDown, Point rightUp) {
    base = RectangleType(leftDown, rightUp);
}

double Alarm::GetDistance(const Point &p) const {
    if (base.IsInside(p)) { return 0; }
    return base.GetDistance(p);
}

bool Alarm::IsValid() const {
    return base.IsValid();
}

RectangleType Alarm::GetBase() const {
    return base;
}




