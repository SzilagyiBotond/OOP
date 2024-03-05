//
// Created by admin on 2023. 04. 20..
//

#include "EventList.h"

void EventList::display() {
    for (auto event:this->events) {
        event.toString();
//        ShellExecute(NULL,"open",event.getLink().c_str(),NULL,NULL,SW_SHOWNORMAL);
    }
}
bool EventList::isEmpty() {
    return this->events.size()==0;
}

Event &EventList::returnEvent(int index) {
    return this->events[index];
}

void EventList::add(const Event &event) {
    this->events.push_back(event);
}

void EventList::remove(string &title) {

}
