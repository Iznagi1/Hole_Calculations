//
// Created by User on 06.08.2023.
//

#ifndef GEOMETRY_CIRCLE_H
#define GEOMETRY_CIRCLE_H

#include <utility>
#include "../Geometry/Point.h"
#include "../Geometry/Shape.h"

class CircleType : Shape {
    Point center;
    double radius;

public:
    explicit CircleType(double centerX = 0, double centerY = 0, double radius = 0) :
    center(centerX, centerY), radius(radius) {}
    explicit CircleType(Point center, double radius) :
    center(center), radius(radius) {}
    ~CircleType() = default;
    double GetCenterX() const;
    double GetCenterY() const;
    Point GetCenter() const;
    double GetRadius() const;

    void SetCenterX(double x);
    void SetCenterY(double x);
    void SetCenter(Point p);
    void SetRadius(double x);

    double GetDistance(const Point& p1) const override;
    bool IsInside(const Point& p1) const override;
    bool IsValid() const override;
};


#endif //GEOMETRY_CIRCLE_H
