//
// Created by User on 06.08.2023.
//

#include <iostream>
#include "Alarm.h"

Alarm::Alarm(Point leftDown, Point rightUp) {
    base = RectangleType(leftDown, rightUp);
}

double Alarm::GetDistance(const Point &p) const {
    return base.GetDistance(p);
}

void Alarm::Print() const {
    std::cout << "x= " << base.GetCenterX() - base.GetWidth() / 2 << " y= " << base.GetCenterY() - base.GetHeight() / 2
              << " x= " << base.GetCenterX() + base.GetWidth() / 2 << " y= " << base.GetCenterY() + base.GetHeight() / 2
              << std::endl;
}

bool Alarm::IsValid() const {
    return base.IsValid();
}




