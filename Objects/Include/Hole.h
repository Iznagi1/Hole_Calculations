//
// Created by User on 06.08.2023.
//

#ifndef OBJECTS_HOLE_H
#define OBJECTS_HOLE_H

#include "Circle.h"
#include "Alarm.h"
#include "Field.h"
#include "Object.h"

class Hole : public Object {
    int id;
    Point center = Point(0, 0);
    CircleType innerCircle;
    CircleType externalCircle;

public:
    explicit Hole(int id, double innerRadius, double externalRadius);
    int GetId() const;
    Point GetCenter() const;
    CircleType GetInnerCircle() const;
    CircleType GetExternalCircle() const;

    void SetInnerCircle(const CircleType& circle);
    void SetExternalCircle(const CircleType& circle);
    void SetCenter(const Point& p);
    void Print() const;

    double GetDistance(const Point& p) const override;
    bool IsValid() const override;
    bool operator<(const Hole& other) const;


};


#endif //OBJECTS_HOLE_H
