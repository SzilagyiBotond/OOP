//
// Created by admin on 2023. 06. 28..
//

#ifndef E916_SZILAGYIBOTOND_PACKAGE_H
#define E916_SZILAGYIBOTOND_PACKAGE_H
#include "Utils.h"
typedef struct{
    string street;
    int number;
}addr;
typedef struct{
    int x;
    int y;
}loc;
class Package {
private:
    string recipient;
    addr address;
    loc location;
    bool status;
public:
    Package(){}
    Package(string recipient,addr address,loc location,bool status):recipient(recipient), address(address), location(location),status(status){}
    ~Package(){}
    friend istream& operator>>(istream& is,Package& p);
    friend ostream& operator<<(ostream& os,Package& p);
    loc getLocation(){return location; }
    addr getAddress(){return address;}
    string getRecipient(){return recipient;}
    void setStatus(){status=true;}
    string toString();
    bool getStatus(){return status;}
};


#endif //E916_SZILAGYIBOTOND_PACKAGE_H
