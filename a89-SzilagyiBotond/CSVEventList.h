#pragma once
#include "FileEventList.h"

class CSVEventList:public FileEventList{
public:
    CSVEventList(std::vector<Event>& events,const std::string& filename): FileEventList(events,filename){};
    ~CSVEventList(){};
    void writeToFile() override;
    void displayEventList() override;
};