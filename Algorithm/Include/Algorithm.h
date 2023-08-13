//
// Created by User on 12.08.2023.
//

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <memory>
#include <functional>
#include "Hole.h"

class Algorithm {
    static constexpr double EPS = 1e-4;

    static bool IsHole(std::unique_ptr<Object> &);

    static double GetSumOfDistance(const Point &p, std::vector<std::unique_ptr<Object>> &objects);

    static double GetMinDistanceToHole(const Point &p, std::vector<std::unique_ptr<Object>> &objects);

    static double GetMinDistanceToBorders(const Point &p, std::vector<std::unique_ptr<Object>> &objects);

    static void ValidateData(std::vector<Alarm> &alarms, std::vector<Hole> &holes, const Field &field);

    static bool
    CalculateHolesImpl(std::vector<std::unique_ptr<Object>> &objects, std::vector<Hole> &holes, const Field &field);

    static bool CalculateHole(Hole &hole, std::vector<std::unique_ptr<Object>> &objects, const Field &field);

    static std::pair<double, double>
    TernarySearchOnY(const std::pair<double, double> &range, double x, const Hole &hole,
                     std::vector<std::unique_ptr<Object>> &objects);

public:
    static bool CalculateHoles(std::vector<Alarm> &alarms, std::vector<Hole> &holes, const Field &field);
};


#endif //ALGORITHM_H
