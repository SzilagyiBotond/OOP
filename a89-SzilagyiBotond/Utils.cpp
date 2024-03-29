//
// Created by admin on 2023. 04. 20..
//
#include <sstream>
#include <vector>
#include "Utils.h"
using namespace std;

std::string trim(const std::string& s)
{
    std::string result(s);
    size_t pos = result.find_first_not_of(" ");
    if(pos !=-1)
        result.erase(0,pos);
    pos =result.find_last_not_of(" ");
    if (pos!=std::string::npos)
        result.erase(pos+1);
    return result;
}

vector<string> tokenize(const string& str, char delimiter)
{
    vector<string> result;
    stringstream ss(str);
    string token;
    while(getline(ss,token,delimiter))
        result.push_back(token);
    return result;
}
