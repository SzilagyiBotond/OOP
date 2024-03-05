//
// Created by admin on 2023. 06. 28..
//

#include "Utils.h"
vector<string> tokenize(string& line,char delimiter){
    string token;
    stringstream ss(line);
    vector<string> result;
    while (getline(ss,token,delimiter)){
        result.push_back(token);
    }
    return result;
}