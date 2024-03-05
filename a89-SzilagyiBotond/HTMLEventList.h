#pragma once
#include "FileEventList.h"

class HTMLEventList:public FileEventList{
public:
    HTMLEventList(std::vector<Event> events,const std::string& filename): FileEventList(events,filename){};
    ~HTMLEventList(){};
    void writeToFile() override;
    void displayEventList() override;
};