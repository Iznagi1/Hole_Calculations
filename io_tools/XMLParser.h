//
// Created by User on 05.08.2023.
//
#include "string"
#include <fstream>
#include <utility>
#include <vector>
#include "pugixml.hpp"
#include "Hole.h"


#ifndef XMLPARSER_H
#define XMLPARSER_H

class XMLParser {
    pugi::xml_document doc;
    const std::string fileName;

    pugi::xml_node CheckXml(const std::vector<std::string> &namesOfNode) const;

public:
    explicit XMLParser(std::string&& fileName);

    std::vector<Hole> GetHoleList() const;

    std::vector<Alarm> GetAlarmList() const;

    Field GetField() const;

    static void CreateOutputXML(const std::vector<Hole> &holes);


};


#endif //XMLPARSER_H
