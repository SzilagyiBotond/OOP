//
// Created by admin on 2023. 06. 28..
//

#include "Courier.h"

istream &operator>>(istream &is, Courier &courier) {
    string line;
    getline(is,line);
    vector<string > tokens= tokenize(line,';');
    if (tokens.size()!=3)
        return is;
    courier.name=tokens[0];
    vector<string> streetTokens=tokenize(tokens[1],'|');
    for (auto street:streetTokens) {
        courier.streets.push_back(street);
    }
    vector<string > zoneTokens= tokenize(tokens[2],'|');
    courier.zone.x=stoi(zoneTokens[0]);
    courier.zone.y= stoi(zoneTokens[1]);
    courier.zone.radius= stoi(zoneTokens[2]);
    return is;
}
