//
// Created by admin on 2023. 03. 23..
//
#pragma once
#include "Event.h"
#include <vector>
class Repository
{
private:
//    DynamicVector<Event> events;
    std::vector<Event> events;
    std::string fileName;


public:
    Repository(const std::string& filename);
    void addEvent(const Event& e);
    vector<Event> getAll() const;
    int getSize() const;
    void deleteEvent(string& title);
    void updateEvent(Event& e1,Event& e2);
    Event& getEvent(string &title);
    int searchEvent(string& title);
    void readFromFile();
    void writeToFile();
};

void testRepository();