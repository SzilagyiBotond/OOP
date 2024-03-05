//
// Created by admin on 2023. 06. 28..
//

#ifndef E916_SZILAGYIBOTOND_SERVICE_H
#define E916_SZILAGYIBOTOND_SERVICE_H
#include "Observer.h"
#include "Repository.h"
class Service :public Subject{
private:
    Repository& repository;
public:
    Service(Repository& repository1):repository(repository1){}
    void addPackage(Package p){repository.addPackage(p);notify();}
    void setDelivered(string name){
        Package& p=repository.getByRecipient(name);
        p.setStatus();
        notify();
    }
    vector<string> getAllStreets();
    Package& getByRecipient(string name){return repository.getByRecipient(name);}
    vector<Package>& getPackages(){return repository.getPackages();}
    vector<Package> getZone(zoneCourier zone,vector<string> streets){return repository.getByCourier(zone,streets);}
    vector<Package> getZoneStreet(zoneCourier zone,string street){return repository.getByCourierStreet(zone,street);}
};


#endif //E916_SZILAGYIBOTOND_SERVICE_H
