#pragma once

#include "Event.h"
#include <vector>
#include <Windows.h>
class EventList
{
protected:
    std::vector<Event> events;
public:
    EventList(std::vector<Event>& _events ): events(_events){};
    void display();
    Event& returnEvent(int index);
    bool isEmpty();
    void add(const Event& event);
    void remove(std::string& title);
    virtual ~EventList(){};
};
