//
// Created by admin on 2023. 06. 28..
//

#include "Package.h"

istream &operator>>(istream &is, Package &p) {
    string line;
    getline(is,line);
    vector<string> tokens= tokenize(line,';');
    if (tokens.size()!=4)
        return is;
    p.recipient=tokens[0];
    vector<string> adTokens=tokenize(tokens[1],'|');
    p.address.street=adTokens[0];
    p.address.number=stoi(adTokens[1]);
    vector<string> locTokens=tokenize(tokens[2],'|');
    p.location.x=stoi(locTokens[0]);
    p.location.y= stoi(locTokens[1]);
    if (stoi(tokens[3])==1)
        p.status=true;
    else
        p.status=false;
    return is;
}

ostream &operator<<(ostream &os, Package &p) {
    os << p.recipient << ";" << p.address.street << "|" << p.address.number << ";" << p.location.x << "|" << p.location.y<< ";" ;
    if (p.status== true)
        os << 1 << endl;
    else
        os << 0 << endl;
    return os;
}

string Package::toString() {
    stringstream txt;
    txt << recipient << " " << address.street << " " << address.number << " " << location.x << " " << location.y << " " ;
    if (status)
        txt << "delivered";
    else
        txt << "pending";
    return txt.str();
}

