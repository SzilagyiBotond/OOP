//
// Created by admin on 2023. 06. 28..
//

#ifndef E916_SZILAGYIBOTOND_REPOSITORY_H
#define E916_SZILAGYIBOTOND_REPOSITORY_H
#include "Package.h"
#include "Courier.h"
#include <fstream>
class Repository {
private:
    vector<Package> packages;
    string fileName;
public:
    Repository(string filename):fileName(filename){readFromFile();}
    void readFromFile();
    void writeToFile();
    void addPackage(Package p){
        packages.push_back(p);
    }
    vector<Package>& getPackages(){return packages;}
    vector<Package> getByCourierStreet(zoneCourier zone,string street);
    vector<Package> getByCourier(zoneCourier zone,vector<string> streets);
    Package& getByRecipient(string rec);
    ~Repository(){writeToFile();}
};


#endif //E916_SZILAGYIBOTOND_REPOSITORY_H
