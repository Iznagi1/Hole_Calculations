//
// Created by User on 11.08.2023.
//

#ifndef OBJECT_H
#define OBJECT_H


class Object {
public:
    virtual double GetDistance(const Point &obj) const = 0;

    virtual bool IsValid() const = 0;
};


#endif //OBJECT_H
