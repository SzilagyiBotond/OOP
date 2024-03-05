//
// Created by admin on 2023. 03. 23..
//

#include "Repository.h"
#include <cassert>
#include <string>
#include <fstream>
#include "Utils.h"
#include "RepositoryExceptions.h"
void Repository::addEvent(const Event &e) {
    string title=e.getTitle();
    if (this->searchEvent(title)==-1) {
        this->events.push_back(e);
        this->writeToFile();
    }
    else
        throw DuplicateEventException();
}
vector<Event> Repository::getAll() const {
    vector<Event> vec= this->events;
    return this->events;
}

int Repository::getSize() const {
    return this->events.size();
}
void Repository::deleteEvent(string &title) {
    if(this->searchEvent(title)==-1)
        throw NoEventException();
    else {
        this->events.erase(this->events.begin() + this->searchEvent(title));
        this->writeToFile();
    }
    }
void Repository::updateEvent(Event &e1, Event &e2) {
    string title=e1.getTitle();
    if (this->searchEvent(title)==-1)
        throw NoEventException();
    else {
        e1 = e2;
        this->writeToFile();
    }
}
Event& Repository::getEvent(string &title) {
    if (this->searchEvent(title)==-1)
        throw NoEventException();
    return this->events[this->searchEvent(title)];
}

int Repository::searchEvent(string &title) {
    for (int i=0; i < events.size() ; i++) {
        if (events[i].getTitle()==title)
            return i;
    }
    return -1;
}

Repository::Repository(const string &filename) : fileName{filename}{
    this->readFromFile();
}

void Repository::readFromFile() {
    ifstream file(this->fileName);
    if (!file.is_open())
//        return;
        throw FileException("Cannot open file");
    Event e;
    while(file >> e)
        this->events.push_back(e);
    file.close();
}

void Repository::writeToFile() {
    ofstream file(this->fileName);
    if(!file.is_open())
        throw FileException("Cannot open file");
    for(auto e: this->events)
        file<< e;
    file.close();
}

void testRepository()
{
    Event event;
    event.setTime(2022,6,6,12,40);
    string title="Vibe";
    string title_test="vibe";
    string link="ww.hu.hu";
    string description="Festival";
    event.setTitle((string &) title);
    event.setLink((string &) link);
    event.setNrOfPeople(10000);
    event.setDescription((string &) description);
    Event event2;
    event2.setTime(2222,6,6,12,40);
    string title2="Vibe";
    string link2="ww.ev.hu";
    string description2="Bulaj";
    event.setTitle((string &) title2);
    event.setLink((string &) link2);
    event.setNrOfPeople(100000);
    event.setDescription((string &) description2);
   string file="e.txt";
    Repository repo("test");
    repo.addEvent(event);
    assert(repo.getSize()==1);
    repo.deleteEvent(title);
    assert(repo.getSize()==0);
    repo.addEvent(event);
    repo.updateEvent(repo.getAll()[0],event2);
    assert(repo.getEvent(title2).getNrOfPeople()==repo.getAll()[0].getNrOfPeople());
    assert(repo.getAll()[0].getDescription()==description2);
    event2.setTitle(title_test);
    try {
        repo.addEvent(event);
    }
    catch (...) {

    }
    try {
        repo.deleteEvent(title_test);
    }
    catch (...) {

    }
    try {
        Event ev=repo.getEvent(title_test);
    }
    catch (...) {

    }
    try{
        repo.updateEvent(event2,event);
    }
    catch (...) {

    }
    repo.writeToFile();
    repo.deleteEvent(title);
    assert(repo.getSize()==0);
}
