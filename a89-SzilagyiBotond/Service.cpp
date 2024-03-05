//
// Created by admin on 2023. 03. 23..
//

#include "Service.h"
Service::Service(Repository &repository,EventValidator v):repository{repository},validator{v} {

}
void Service::addEvent(const Event &event) {
    this->validator.validate(event);
    this->repository.addEvent(event);
}
void Service::deleteEvent(string &title) {
    this->repository.deleteEvent(title);
}
int Service::getSize() const {
    return this->repository.getSize();
}
vector<Event> Service::getAll() {
    return this->repository.getAll();
}

void Service::updateDescription(string &title, string &description) {
    Event event(this->repository.getEvent(title));
    event.setDescription(description);
    this->repository.updateEvent(this->repository.getEvent(title),event);
}

void Service::updateTimeYear(string &title, int newYear) {
    Event event(this->repository.getEvent(title));
    event.setTimeYear(newYear);
    this->repository.updateEvent(this->repository.getEvent(title),event);
}

void Service::updateTimeMonth(string &title, int newMonth) {
    Event event(this->repository.getEvent(title));
    event.setTimeMonth(newMonth);
    this->repository.updateEvent(this->repository.getEvent(title),event);
}

void Service::updateTimeDay(string &title, int newDay) {
    Event event(this->repository.getEvent(title));
    event.setTimeDay(newDay);
    this->repository.updateEvent(this->repository.getEvent(title),event);
}

void Service::updateTimeHour(string &title, int newHour) {
    Event event(this->repository.getEvent(title));
    event.setTimeHour(newHour);
    this->repository.updateEvent(this->repository.getEvent(title),event);
}

void Service::updateTimeMinute(string &title, int newMinute) {
    Event event(this->repository.getEvent(title));
    event.setTimeMinute(newMinute);
    this->repository.updateEvent(this->repository.getEvent(title),event);
}

void Service::updateNrOfPeople(string &title, int newNrOfPeople) {
    Event event(this->repository.getEvent(title));
    event.setNrOfPeople(newNrOfPeople);
    this->repository.updateEvent(this->repository.getEvent(title),event);
}

void Service::updateLink(string &title, string &newLink) {
    Event event(this->repository.getEvent(title));
    event.setLink(newLink);
    this->repository.updateEvent(this->repository.getEvent(title),event);
}

vector<Event> Service::getPerMonth(int month) {
    vector<Event> storage= this->getAll();
    vector<Event> toReturn;
    for (const auto & i : storage) {
        if (i.getTime().month==month)
            toReturn.push_back(i);
    }
    this->sortEvents(toReturn);
    return toReturn;
}
bool sortCriteria(const Event& a, const Event& b)
{
    if(a.getTime().year!=b.getTime().year)
        return a.getTime().year<b.getTime().year;
    if(a.getTime().month!=b.getTime().month)
        return a.getTime().month<b.getTime().month;
    if (a.getTime().day!=b.getTime().day)
        return a.getTime().day<b.getTime().day;
    return true;
}

void Service::sortEvents(vector<Event> &vector) {
    for (int i = 0; i < vector.size(); i++) {
        for (int j = i+1; j < vector.size(); j++) {
            if(sortCriteria(vector[i],vector[j])== false)
            {
                Event e1=vector[i];
                vector[i]=vector[j];
                vector[j]=e1;
            }
        }
    }
}

void Service::generateTenEntries(){
    string title1="Vibe";
    string title2="Electric castle";
    string title3="Untold";
    string title4="Tusvanyos";
    string title5="Mera";
    string title6="Neversea";
    string title7="Awake";
    string title8="Tabako";
    string title9="Forgatag";
    string title10="Sziget";
    string desc1="Festival";
    string desc2="Festival";
    string desc3="Festival";
    string desc4="Festival";
    string desc5="Festival";
    string desc6="Festival";
    string desc7="Festival";
    string desc8="Festival";
    string desc9="Festival";
    string desc10="Festival";
    string link1="https://vibefestival.ro";
    string link2="https://vibefestival.ro";
    string link3="https://vibefestival.ro";
    string link4="https://vibefestival.ro";
    string link5="https://vibefestival.ro";
    string link6="https://vibefestival.ro";
    string link7="https://vibefestival.ro";
    string link8="https://vibefestival.ro";
    string link9="https://vibefestival.ro";
    string link10="https://vibefestival.ro";
    Event event1(title1,desc1, dateTime{2023,5,5,5,5},10,link1);
    Event event2(title2,desc2, dateTime{2023,5,6,5,5},10,link1);
    Event event3(title3,desc1, dateTime{2023,5,7,5,5},10,link1);
    Event event4(title4,desc1, dateTime{2023,5,8,5,5},10,link1);
    Event event5(title5,desc1, dateTime{2023,5,9,5,5},10,link1);
    Event event6(title6,desc1, dateTime{2023,5,10,5,5},10,link1);
    Event event7(title7,desc1, dateTime{2023,5,11,5,5},10,link1);
    Event event8(title8,desc1, dateTime{2023,5,12,5,5},10,link1);
    Event event9(title9,desc1, dateTime{2023,5,13,5,5},10,link1);
    Event event10(title10,desc1, dateTime{2023,5,14,5,5},10,link1);
    addEvent(event1);
    addEvent(event2);
    addEvent(event3);
    addEvent(event4);
    addEvent(event5);
    addEvent(event6);
    addEvent(event7);
    addEvent(event8);
    addEvent(event9);
    addEvent(event10);


}

void testService()
{
    Repository repo("e.txt");
    EventValidator v;
    Service service{repo,v};
    Event event2;
    event2.setTime(2222,6,6,12,40);
    string title2="Vibbe";
    string link2="ww.ev.hu";
    string description2="Bulaj";
    Event event;
    event.setTime(2023,6,1,0,0);
    string title="Vibe";
    string link="ww.hu.hu";
    string description="Festival";
    event.setTitle((string &) title);
    event.setLink((string &) link);
    event.setNrOfPeople(10000);
    event.setDescription((string &) description);
    event2.setTitle((string &) title2);
    event2.setLink((string &) link2);
    event2.setNrOfPeople(100000);
    event2.setDescription((string &) description2);
    service.addEvent(event);
    service.addEvent(event2);
    service.deleteEvent(title);
    assert(service.getAll()[0].getNrOfPeople()==event2.getNrOfPeople());
    assert(service.getSize()==1);
    service.updateNrOfPeople(title2,100);
    service.updateDescription(title2,description);
    service.updateLink(title2,link);
    service.updateTimeMinute(title2,1);
    service.updateTimeHour(title2,1);
    service.updateTimeDay(title2,2);
    service.updateTimeMonth(title2,1);
    service.updateTimeYear(title2,2023);
    service.addEvent(event);
    service.updateTimeMonth(title,1);
    service.updateTimeYear(title,2023);
    vector<Event> vec=service.getPerMonth(1);
}
