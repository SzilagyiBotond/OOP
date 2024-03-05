#pragma once
#include "Repository.h"
#include <vector>
#include "EventValidator.h"
class Service
{
private:
    Repository& repository;
    EventValidator validator;
public:
    Service(Repository& repository,EventValidator v);
    void addEvent(const Event& event);
    void deleteEvent(string &title);
    int getSize() const;
    vector<Event> getAll();
    vector<Event> getPerMonth(int month);
    void updateDescription(string& title,string& description);
    void updateTimeYear(string& title, int newYear);
    void updateTimeMonth(string& title, int newMonth);
    void updateTimeDay(string& title, int newDay);
    void updateTimeHour(string& title, int newHour);
    void updateTimeMinute(string& title, int newMinute);
    void updateNrOfPeople(string& title, int newNrOfPeople);
    void updateLink(string& title, string& newLink);
    void sortEvents(vector<Event>& vector);
    void generateTenEntries();
};
void testService();