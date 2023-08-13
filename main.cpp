#include <iostream>
#include <exception>
#include "Algorithm.h"
#include "DisplayTools.h"
#include "io_tools/XMLParser.h"


int main(int argc, char **argv) {
    try {
        std::string fileName;
        std::cout << "enter a file name, please" << std::endl;
        std::cin >> fileName;
        XMLParser parser(std::move(fileName));
        std::vector<Hole> holes(parser.GetHoleList());
        std::vector<Alarm> alarms(parser.GetAlarmList());
        Field field = parser.GetField();

        if (!Algorithm::CalculateHoles(alarms, holes, field)) {
            std::cout << "Unfortunately, with the given data, it is impossible to locate all the holes" << std::endl;
            return 0;
        }
        std::sort(holes.begin(), holes.end(), [](const Hole& a, const Hole& b) {
            return a.GetId() < b.GetId();
        });
        XMLParser::CreateOutputXML(holes);

        DisplayTools::FillInfo(std::move(field), std::move(alarms), std::move(holes));
        DisplayTools::Run(argc, argv);

    } catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
        return 1;
    }
}
