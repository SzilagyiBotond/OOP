//
// Created by admin on 2023. 03. 23..
//

#include "Ui.h"
#include "CSVEventList.h"
#include "RepositoryExceptions.h"
#include "EventValidator.h"
#include "HTMLEventList.h"
Ui::Ui(Service &service): service{service} {

}

void Ui::printAdministratorOptions() {
    cout<<"1. Add an event"<<endl;
    cout<<"2. Delete an event" << endl;
    cout<<"3. Update an event" << endl;
    cout <<"4. Display all events" << endl;
    cout<<"5. Exit" <<endl;
}

void Ui::printAdministratorUpdateOptions() {
    cout <<"1. Update an events description" << endl;
    cout<<"2. Update an events time" << endl ;
    cout<<"3. Update an events participants" << endl;
    cout<<"4. Update an events link" << endl;
}

void Ui::printAdministratorUpdateTimeOptions() {
    cout << "1. Update the events year"<< endl;
    cout << "2. Update the events month" << endl;
    cout<<"3. Update the events day" << endl;
    cout<<"4. Update the events hour" << endl;
    cout<<"5. Update the events minute" << endl;
}

void Ui::addEvent() {
    string title,description,link;
    int nrOfPeople = 0;
    Event event;
    int year,month,day,hour,minute;
    cout << "The title is: ";
    cin >> title;
    cout << "The description is: " ;
    cin >> description;
    cout << "The link: ";
    cin>> link;
    cout<<"The participants: ";
    cin>>nrOfPeople;
    cout<<"The year is: " ;
    cin>> year;
    cout<<"The month is: ";
    cin>> month;
    cout << "The day is: ";
    cin >> day;
    cout<<"The hour is: ";
    cin>> hour;
    cout<< "The minute is: ";
    cin>>minute;
//    if (minute>59|| day<1 || day>31 || hour>24 || hour < 0 || minute<0 || 2023>year || 0>month || month>12)
//        throw exception();
//    if (month==4 || month==6 || month==9 || month==11)
//        if (day>30)
//            throw exception();
//    if(month==2)
//    {
//        if (year%4==2)
//        {
//            if (day>29)
//                throw exception();
//        }
//        else {
//                if (day > 28)
//                    throw exception();
//            }
//    }
    event.setTitle(title);
    event.setDescription(description);
    event.setLink(link);
    event.setNrOfPeople(nrOfPeople);
    event.setTime(year,month,day,hour,minute);
    this->service.addEvent(event);
}

void Ui::deleteEvent() {
    string title;
    cout << "The event's name is: ";
    cin >> title;
    this->service.deleteEvent(title);
}

void Ui::updateEvent() {
    int option;
    string title;
    cout << "The event's name is: ";
    cin >> title;
    this->printAdministratorUpdateOptions();
    cout << "What to do: ";
    cin>>option;
    switch (option) {
        case 1:
        {
            string newDescription;
            cout << "What is the new description: ";
            cin >> newDescription;
            this->service.updateDescription(title,newDescription);
            break;
        }
        case 2:
        {
            int option2;
            this->printAdministratorUpdateTimeOptions();
            cout << "What to do: ";
            cin >> option2;
            switch (option2) {
                case 1:
                {
                    int newYear;
                    cout << "What is the new year: ";
                    cin >> newYear;
                    if (newYear<2023)
                        throw exception();
                    this->service.updateTimeYear(title,newYear);
                    break;
                }
                case 2:
                {
                    int newMonth;
                    cout << "What is the new month: ";
                    cin >> newMonth;
                    if (newMonth<1 || newMonth>12)
                        throw exception();
                    this->service.updateTimeMonth(title,newMonth);
                    break;
                }
                case 3:
                {
                    int newDay;
                    cout << "What is the new day: ";
                    cin >> newDay;
                    if (newDay>31 || newDay<0)
                        throw exception();
                    this->service.updateTimeDay(title,newDay);
                    break;
                }
                case 4:
                {
                    int newHour;
                    cout << "What is the new hour: ";
                    cin >> newHour;
                    if (newHour<0 || newHour>23)
                        throw exception();
                    this->service.updateTimeHour(title,newHour);
                    break;
                }
                case 5:
                {
                    int newMinute;
                    cout << "What is the new minute: ";
                    cin >> newMinute;
                    if (newMinute>59 or newMinute<0)
                        throw exception();
                    this->service.updateTimeMinute(title,newMinute);
                    break;
                }
                default:
                    break;
            }
        }
        case 3:
        {
            int newNrOfPeople;
            cout << "What is the new nr of people going: ";
            cin>>newNrOfPeople;
            this->service.updateNrOfPeople(title,newNrOfPeople);
            break;
        }
        case 4:
        {
            string newLink;
            cout << "What is the new link: ";
            cin>> newLink;
            this->service.updateLink(title,newLink);
            break;
        }
        default:
            break;
    }
}

void Ui::displayAllEvent() {
    vector<Event> vector= this->service.getAll();
    for (int i = 0; i < this->service.getSize(); i++) {
        cout << vector[i].toString()<< endl;
    }
}

void Ui::runAdminConsole() {
    int adminOption;
    while (true)
    {
        this->printAdministratorOptions();
        cout<< "What to do: ";
        cin>> adminOption;
        if (adminOption==5)
            break;
        try {
            switch (adminOption) {
                case 1:
                {
                    this->addEvent();
                    break;
                }
                case 2:
                {
                    this->deleteEvent();
                    break;
                }
                case 3:
                {
                    this->updateEvent();
                    break;
                }
                case 4:
                {
                    this->displayAllEvent();
                    break;
                }
                default:
                    break;
            }
        }
        catch (EventException& e) {
            cout << "Invalid time" << endl;
        }
        catch (DuplicateEventException& e ) {
            cout << e.what() << endl;
        }
        catch (NoEventException& e ) {
            cout << e.what()<<endl;
        }
        catch (...) {
            cout << "Invalid input" << endl;
        }
    }
}

void Ui::printUserOptions() {
    cout << "1. Add events to your list" << endl;
    cout<< "2. Remove event from your list" << endl;
    cout << "3. Display all the events you are interested in: " << endl;
    cout <<"4. Exit"<< endl;
}

void Ui::runUserConsole() {
    int userOption;
    std::vector<Event> userEvents;
    while (1) {
        try {

            this->printUserOptions();
            cout << "What to do: ";
            cin >> userOption;
            if (userOption == 4)
                break;
            switch (userOption) {
                case 1: {
                    int month;
                    cout << "What month: ";
                    cin >> month;
                    if (month > 12 || month < 0)
                        throw exception();
                    vector<Event> eventsPerMonth = this->service.getPerMonth(month);
                    int i = 0;
                    while (true) {
                        cout << eventsPerMonth[i].toString() << endl;
                        ShellExecuteA(NULL,"open",eventsPerMonth[i].getLink().c_str(),NULL,NULL,SW_SHOWNORMAL);
                        cout << "1. Add to your events" << endl << "2. Next" <<endl<< "3. Exit"<<endl;
                        int optionUser2;
                        cout << "What to do: ";
                        cin >> optionUser2;
                        if (optionUser2 == 3)
                            break;
                        switch (optionUser2) {
                            case 1: {
                                bool found=false;
                                string toTo=eventsPerMonth[i].getTitle();
                                for (int j = 0; j < userEvents.size(); j++) {
                                    if (userEvents[i].getTitle()==toTo)
                                    {
                                        cout<<"Event already added"<<endl;
                                        found=true;
                                        break;
                                    }
                                }
                                if (found)
                                    break;
                                userEvents.push_back(eventsPerMonth[i]);
                                userEvents.back().setNrOfPeople(eventsPerMonth[i].getNrOfPeople() + 1);
                                eventsPerMonth[i].setNrOfPeople(eventsPerMonth[i].getNrOfPeople()+1);
//                                userEvents.updateEvent(userEvents.getEvent(eventsPerMonth[i].getTitle()));

                                this->service.updateNrOfPeople(toTo,eventsPerMonth[i].getNrOfPeople());
                                cout << "Successfully added" << endl;
                                break;
                            }
                            case 2: {
                                break;
                            }
                            default:
                                break;
                        }
                        i++;
                        if (i == eventsPerMonth.size())
                            i = 0;
                    }
                    break;
                }
                case 2: {
                    string title;
                    cout << "What is the title of the event to delete: ";
                    cin >> title;
                    for (int i=0; i < userEvents.size() ; i++) {
                        if (userEvents[i].getTitle()==title)
                            userEvents.erase(userEvents.cbegin()+i);
                    }
                    for (int i = 0; i < this->service.getSize(); i++) {
                        if(this->service.getAll()[i].getTitle()==title)
                            this->service.updateNrOfPeople(title, this->service.getAll()[i].getNrOfPeople()-1);
                    }
                    break;
                }
                case 3: {
                    int what;
                    cout << "In what should it be stored(1.csv 2.html)";
                    cin >> what;
                    if(what==1)
                    {
                        CSVEventList list(userEvents,"ex.csv");
                        list.writeToFile();
                        list.displayEventList();
                    }
                    if(what==2)
                    {
                        HTMLEventList list2(userEvents,"test.html");
                        list2.writeToFile();
                        list2.displayEventList();
                    }
                    else
                    {
                        cout << "Invalid input";
                    }
//                    for (int i = 0; i < userEvents.size(); i++) {
//                        cout << userEvents[i].toString() << endl;
//                    }
                    break;
                }
                default:
                    break;
            }


        }
        catch (FileException& e) {
            cout << e.what()<<endl;
        }
        catch (...) {
            cout<< "Invalid input" <<endl;
        }
    }

}
void printGeneralConsoleOptions()
{
    cout<<"1. Enter administrator mode"<< endl;
    cout<<"2. Enter user mode" << endl;
    cout << "3. Exit" << endl;
}
void Ui::runGeneralConsole() {
    int generalOption;
    while (1)
    {
        printGeneralConsoleOptions();
        cout << "What to do: ";
        cin >> generalOption;
        if(generalOption==3)
            break;
        switch (generalOption) {
            case 1:
            {
                this->runAdminConsole();
                break;
            }
            case 2:
            {
                this->runUserConsole();
                break;
            }
            default:
                break;

        }
    }
}



