//
// Created by User on 05.08.2023.
//

#include "XMLParser.h"
#include <iostream>

XMLParser::XMLParser(std::string&& fileName) {
    pugi::xml_parse_result parseResult = doc.load_file(&fileName[0]);
    if (!parseResult) {
        throw std::runtime_error(std::string("Invalid xml"));
    }
}

pugi::xml_node XMLParser::CheckXml(const std::vector<std::string> &namesOfNode) const {
    pugi::xml_node root = doc.document_element();
    if (!root) {
        throw std::runtime_error(std::string("Have no root node"));
    }
    pugi::xml_node result;
    for (auto nameOfNode: namesOfNode) {
        result = root.child(static_cast<const pugi::char_t *>(&nameOfNode[0]));
        if (!result) {
            throw std::runtime_error(std::string("Have no necessary node"));
        }
        root = result;
    }
    return result;
}

std::vector<Hole> XMLParser::GetHoleList() const {
    pugi::xml_node circles = CheckXml({"circles"});
    std::vector<Hole> res;
    for (const auto &circle: circles) {
        for (pugi::xml_attribute_iterator ait = circle.attributes_begin(); ait != circle.attributes_end(); ++ait) {
            int id = std::stoi(ait->value());
            double innerRad = std::stof((++ait)->value());
            double externalRad = std::stof((++ait)->value());
            res.emplace_back(id, innerRad, externalRad);
        }
    }
    return std::move(res);
}

std::vector<Alarm> XMLParser::GetAlarmList() const {
    pugi::xml_node alarms = CheckXml({"placement_zone", "alarms"});
    std::vector<Alarm> res;
    for (const auto &alarm: alarms) {
        Point leftDown;
        Point rightUp;
        for (auto it = alarm.begin(); it != alarm.end(); it++) {
            double x, y;
            pugi::xml_attribute_iterator ait = it->attributes_begin();
            x = std::stof(ait->value());
            y = std::stof((++ait)->value());
            leftDown = Point(x, y);

            it++;

            ait = it->attributes_begin();
            x = std::stof(ait->value());
            y = std::stof((++ait)->value());
            rightUp = Point(x, y);
        }
        res.emplace_back(leftDown, rightUp);
    }
    return std::move(res);
}

Field XMLParser::GetField() const {
    pugi::xml_node field = CheckXml({"placement_zone", "rect"});
    auto it = field.begin();
    double x, y;
    Point leftDown;
    Point rightUp;
    pugi::xml_attribute_iterator ait = it->attributes_begin();
    x = std::stof(ait->value());
    y = std::stof((++ait)->value());
    leftDown = Point(x, y);

    it++;
    ait = it->attributes_begin();
    x = std::stof(ait->value());
    y = std::stof((++ait)->value());
    rightUp = Point(x, y);
    return {leftDown, rightUp};
}

void XMLParser::CreateOutputXML(const std::vector<Hole> &holes) {
    pugi::xml_document outputDoc;

    pugi::xml_node root = outputDoc.append_child("data");

    pugi::xml_node circles = root.append_child("circles");

    for (const auto &hole: holes) {
        pugi::xml_node circle = circles.append_child("circle");
        std::string toXML =
                "id = " + std::to_string(hole.GetId()) + " x = " + std::to_string(hole.GetInnerCircle().GetCenterX()) +
                " y = " + std::to_string(hole.GetInnerCircle().GetCenterY());
        circle.append_attribute("circle").set_value(&toXML[0]);
    }

    outputDoc.save_file("result.xml");
}


