//
// Created by admin on 2023. 06. 28..
//

#ifndef E916_SZILAGYIBOTOND_COURIER_H
#define E916_SZILAGYIBOTOND_COURIER_H
#include "Utils.h"
typedef struct{
    int x;
    int y;
    int radius;
}zoneCourier;
class Courier {
private:
    string name;
    vector<string> streets;
    zoneCourier zone;
public:
    Courier(){}
    Courier(string _name,vector<string> _streets,zoneCourier _zone):name(_name),streets(_streets), zone(_zone){}
    ~Courier(){}
    string getName(){return name;}
    zoneCourier getZone(){return zone;}
    friend istream& operator>>(istream& is,Courier& courier);
    vector<string > getStreets(){return streets;}
};


#endif //E916_SZILAGYIBOTOND_COURIER_H
