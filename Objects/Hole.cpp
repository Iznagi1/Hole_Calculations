//
// Created by User on 06.08.2023.
//

#include <iostream>
#include "Hole.h"

Hole::Hole(int id, double innerRadius, double externalRadius) {
    this->id = id;
    innerCircle = CircleType(center, innerRadius);
    externalCircle = CircleType(center, externalRadius);
}

int Hole::GetId() const {
    return id;
}

CircleType Hole::GetInnerCircle() const {
    return innerCircle;
}

CircleType Hole::GetExternalCircle() const {
    return externalCircle;
}

void Hole::SetInnerCircle(const CircleType &circle) {
    innerCircle = circle;
}

void Hole::SetExternalCircle(const CircleType &circle) {
    externalCircle = circle;
}

double Hole::GetDistance(const Point &p) const {
    return externalCircle.GetDistance(p);
}


bool Hole::IsValid() const {
    return innerCircle.IsValid() && externalCircle.IsValid();
}

bool Hole::operator<(const Hole &other) const {
    return innerCircle.GetRadius() < other.GetInnerCircle().GetRadius();
}

void Hole::SetCenter(const Point &p) {
    center = p;
    innerCircle.SetCenter(center);
    externalCircle.SetCenter(center);
}





