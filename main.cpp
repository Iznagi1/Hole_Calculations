#include <iostream>
#include <exception>
#include "Algorithm.h"
#include "Display.h"
#include "io_tools/XMLParser.h"


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    try {
        XMLParser parser("input.xml");
        std::vector<Hole> holes(parser.GetHoleList());
        for (const auto& it : holes) {
            it.Print();
        }
        std::vector<Alarm> alarms(parser.GetAlarmList());
        for (const auto& it : alarms) {
            it.Print();
        }
        Field field = parser.GetField();
        field.Print();

        if (!Algorithm::CalculateHoles(alarms, holes, field)) {
            std::cout << "Unfortunately, with the given data, it is impossible to locate all the holes" << std::endl;
            return 0;
        }
        for (const auto& it : holes) {
            it.Print();
        }
        run(argc, argv);






    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
        return 1;
    }
}
