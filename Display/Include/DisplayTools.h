//
// Created by User on 13.08.2023.
//

#ifndef DISPLAY_H
#define DISPLAY_H

#include <windows.h>
#include <gl/glut.h>
#include <gl/glu.h>
#include <vector>
#include "Hole.h"
#include "Alarm.h"

class DisplayTools {
public:
    static void Run(int argc, char **argv);

    static void FillInfo(Field &&field, std::vector<Alarm> &&alarms, std::vector<Hole> &&holes);

    static void DrawRectangle(const RectangleType &rect);

    static void DrawCircle(const CircleType &circle);

    static void DrawField();

    static void DrawAlarms();

    static void DrawHoles();


};


#endif //DISPLAY_H
