//
// Created by admin on 2023. 06. 28..
//

#include "Repository.h"

vector<Package> Repository::getByCourierStreet(zoneCourier zone,string street) {
    vector<Package> result;
    for (auto package:packages) {
        if (((abs(package.getLocation().x-zone.x)*abs(package.getLocation().x-zone.x)+abs(package.getLocation().y-zone.y)*abs(package.getLocation().y-zone.y))<(zone.radius*zone.radius))&&package.getAddress().street==street){
            result.push_back(package);
        }
    }
    return result;
}

Package &Repository::getByRecipient(string rec) {
    for (auto &package:packages) {
        if (package.getRecipient()==rec)
            return package;
    }
}

void Repository::readFromFile() {
    ifstream file(fileName);
    Package p;
    while(file>>p)
        packages.push_back(p);
    file.close();
}

void Repository::writeToFile() {
    ofstream file(fileName);
    for (auto p:packages) {
        file << p ;
    }
    file.close();
}

vector<Package> Repository::getByCourier(zoneCourier zone,vector<string> streets) {
    vector<Package> result;
    for (auto package:packages) {
        if ((abs(package.getLocation().x-zone.x)*abs(package.getLocation().x-zone.x)+abs(package.getLocation().y-zone.y)*abs(package.getLocation().y-zone.y))<(zone.radius*zone.radius)){
            result.push_back(package);
        }
        else{
            for(auto street:streets){
                if(street==package.getAddress().street)
                    result.push_back(package);
            }
        }
    }
    return result;
}

