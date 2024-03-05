//
// Created by admin on 2023. 06. 28..
//

#include "Service.h"

vector<string> Service::getAllStreets() {
    vector<string > result;
    for (auto pac:repository.getPackages()) {
        bool found=false;
        for (auto street:result) {
            if(street==pac.getAddress().street){
                found=true;
                break;
            }
        }
        if (!found)
            result.push_back(pac.getAddress().street);
    }
    return result;
}
