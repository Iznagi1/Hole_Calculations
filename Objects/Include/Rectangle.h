//
// Created by User on 06.08.2023.
//

#ifndef GEOMETRY_RECTANGLE_H
#define GEOMETRY_RECTANGLE_H

#include <utility>
#include "../Geometry/Point.h"
#include "../Geometry/Shape.h"

class RectangleType : public Shape {
    Point center;
    double width;
    double height;


public:
    explicit RectangleType(double centerX = 0, double centerY = 0, double width = 0, double height = 0) :
    center(centerX, centerY), width(width), height(height) {}
    explicit RectangleType(Point left_down, Point right_up);
    double GetCenterX() const;
    double GetCenterY() const;
    Point GetCenter() const;
    double GetWidth() const;
    double GetHeight() const;

    void SetCenterX(double x);
    void SetCenterY(double x);
    void SetCenter(Point p);
    void SetWidth(double x);
    void SetHeight(double x);

    double GetDistance(const Point& p) const override;
    bool IsInside(const Point& p1) const override;
    bool IsValid() const override;

};


#endif //GEOMETRY_RECTANGLE_H
