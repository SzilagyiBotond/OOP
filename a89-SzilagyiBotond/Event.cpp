//
// Created by admin on 2023. 03. 23..
//

#include "Event.h"
#include "Utils.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

Event::Event() : title{" "}, description{" "},time{dateTime{0,0,0,0,0}}, nrOfPeople{0},link{" "}
{
}

Event::Event(const string& title, const string& description, dateTime time, int nrOfPeople, string& link) : title{title},description{description},time{time},nrOfPeople{nrOfPeople},link{link}
{
}

string Event::getTitle() const {
    return this->title;
}

string Event::getDescription() const {
    return this->description;
}
int Event::getNrOfPeople() const {
    return this->nrOfPeople;
}
string Event::getLink() const {
    return this->link;
}

void Event::setTitle(string& title) {
    this->title=title;
}
void Event::setDescription(string &description) {
    this->description=description;
}
void Event::setTime(int year,int month,int day,int hour,int minute) {
    this->time.year=year;
    this->time.month=month;
    this->time.day=day;
    this->time.hour=hour;
    this->time.minute=minute;
}
void Event::setNrOfPeople(int nrOfPeople) {
    this->nrOfPeople=nrOfPeople;
}
void Event::setLink(string &link) {
    this->link=link;
}

Event::~Event() {

}

Event::Event(const Event &e) {
    this->title=e.title;
    this->description=e.description;
    this->time=e.time;
    this->nrOfPeople=e.nrOfPeople;
    this->link=e.link;
}


Event& Event::operator=(const Event &e) = default;

string Event::toString() {
    stringstream txt;
    txt << "The events title is: " << this->title << endl << "The description: " << this->description << endl << "The date and time: " << this->time.year << "/"<<this->time.month << "/" << this->time.day << " " << this->time.hour << ":" << this->time.hour << endl << "Attendance: " << this->nrOfPeople << endl << "Link to the event: " << this->link <<endl;
    return txt.str();
}

void Event::setTimeYear(int year) {
    this->time.year=year;
}

void Event::setTimeMonth(int month) {
    this->time.month=month;
}

void Event::setTimeDay(int day) {
    this->time.day=day;
}

void Event::setTimeHour(int hour) {
    this->time.hour=hour;
}

void Event::setTimeMinute(int minute) {
    this->time.minute=minute;
}

std::istream &operator>>(istream &is, Event &e) {
    string line;
    getline(is,line);
    vector<string > tokens=tokenize(line,',');
    if (tokens.size()!=5)
        return is;
    e.title=tokens[0];
    e.description=tokens[1];
    vector<string > getTimeTokens = tokenize(tokens[2],'|');
    if (getTimeTokens.size()!=5)
        return is;
    e.time=dateTime{stoi(getTimeTokens[0]),stoi(getTimeTokens[1]),stoi(getTimeTokens[2]),stoi(getTimeTokens[3]),stoi(getTimeTokens[4])};
    e.nrOfPeople= stoi(tokens[3]);
    e.link= tokens[4];
    return is;
}

std::ostream &operator<<(ostream &os, const Event &e) {
    os << e.title << "," << e.description << "," << e.time.year << "|" << e.time.month << "|" << e.time.day << "|" << e.time.hour << "|" << e.time.minute << "," << e.nrOfPeople << "," << e.link << "\n" ;
    return os;
}



