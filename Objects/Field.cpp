//
// Created by User on 06.08.2023.
//

#include <iostream>
#include "Field.h"

Field::Field(Point leftDown, Point rightUp) {
    base = RectangleType(leftDown, rightUp);
}

double Field::GetDistance(const Point &p) const {
//    p.Print();
//    std::cout << base.GetDistance(p) << std::endl;
    return base.GetDistance(p);
}

void Field::Print() const {
    std::cout << "x= " << base.GetCenterX() - base.GetWidth() / 2 << " y= " << base.GetCenterY() - base.GetHeight() / 2
              << " x= " << base.GetCenterX() + base.GetWidth() / 2 << " y= " << base.GetCenterY() + base.GetHeight() / 2
              << std::endl;
}

bool Field::IsValid() const {
    return base.IsValid();
}

std::pair<std::pair<double, double>, std::pair<double, double>> Field::GetMarkup() const {
    double minX = base.GetCenterX() - base.GetWidth() / 2;
    double maxX = base.GetCenterX() + base.GetWidth() / 2;
    double minY = base.GetCenterY() - base.GetHeight() / 2;
    double maxY = base.GetCenterY() + base.GetHeight() / 2;


    return {{minX, maxX}, {minY, maxY}};
}
