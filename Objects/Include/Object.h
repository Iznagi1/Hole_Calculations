//
// Created by User on 11.08.2023.
//

#ifndef HOLE_CALCULATIONS_OBJECT_H
#define HOLE_CALCULATIONS_OBJECT_H


class Object {
public:
    virtual double GetDistance(const Point& obj) const = 0;
    virtual bool IsValid() const = 0;
    virtual void Print() const = 0;
};


#endif //HOLE_CALCULATIONS_OBJECT_H
