#pragma once
#include "EventList.h"

class FileEventList: public EventList
{
protected:
    std::string fileName;
public:
    FileEventList(vector<Event> &events1, const std::string &filename)
            : EventList(events1) {
        this->fileName=filename;
    }
    ~FileEventList(){}
    virtual void writeToFile()=0;
    virtual void displayEventList()=0;
};