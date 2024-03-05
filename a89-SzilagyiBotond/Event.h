#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include <windows.h>
#include <iostream>
using namespace std;
struct dateTime{
    int year;
    int month;
    int day;
    int hour;
    int minute;
};
class Event
{
private:
    string title;
    string description;


    dateTime time{};
    int nrOfPeople;
    string link;
public:
    Event();
    Event(const string& title, const string& description, dateTime time, int nrOfPeople, string& link);
    string getTitle() const;
    string getDescription() const;
    dateTime getTime() const {return this->time;}
    int getNrOfPeople() const;
    string getLink() const;
    void setTitle(string& title);
    void setDescription(string& description);
    void setTime(int year,int month,int day,int hour,int minute);
    void setTimeYear(int year);
    void setTimeMonth(int month);
    void setTimeDay(int day);
    void setTimeHour(int hour);
    void setTimeMinute(int minute);
    void setNrOfPeople(int nrOfPeople);
    void setLink(string& link);
    ~Event();
    Event(const Event& e);
    Event& operator=(const Event& e);
    string toString();
    friend std::istream& operator>>(std::istream& is, Event& e);
    friend std::ostream& operator<<(std::ostream& os, const Event& e);
};
