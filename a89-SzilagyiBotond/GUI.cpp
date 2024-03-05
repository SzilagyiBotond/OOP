//
// Created by admin on 2023. 05. 14..
//

#include "GUI.h"
#include "RepositoryExceptions.h"
#include "CSVEventList.h"
GUIAdmin::GUIAdmin(Service &service, QWidget *parent) : QWidget{parent}, service{service} {
    this->initGui();
    this->populateList();
    this->connectSignalsAndSlots();
}

void GUIAdmin::initGui() {
    setWindowTitle("Administrator mode");
    QVBoxLayout *layout = new QVBoxLayout{this};
    eventlist = new QListWidget{};
    exit = new QPushButton{"Return to main menu"};
    QLabel *title = new QLabel{"Events"};
    layout->addWidget(exit);
    layout->addWidget(title);
    layout->addWidget(eventlist);
    eventlist->setWindowTitle("Administrator mode");
    eventlist->setFixedHeight(eventlist->sizeHint().height());
    titleLineEdit = new QLineEdit{};
    descriptionLineEdit = new QLineEdit{};
    linkLineEdit = new QLineEdit{};
    peopleLineEdit=new QLineEdit{};
    yearLineEdit=new QLineEdit{};
    monthLineEdit=new QLineEdit{};
    dayLineEdit=new QLineEdit{};
    hourLineEdit=new QLineEdit{};
    minuteLineEdit=new QLineEdit{};
    QFormLayout *formLayout = new QFormLayout{};
    formLayout->addRow("Title", titleLineEdit);
    formLayout->addRow("Description", descriptionLineEdit);
    formLayout->addRow("Link", linkLineEdit);
    formLayout->addRow("People",peopleLineEdit);
    formLayout->addRow("Year",yearLineEdit);
    formLayout->addRow("Month",monthLineEdit);
    formLayout->addRow("Day",dayLineEdit);
    formLayout->addRow("Hour",hourLineEdit);
    formLayout->addRow("Minute",minuteLineEdit);
    layout->addLayout(formLayout);
    QHBoxLayout *buttons = new QHBoxLayout{};
    add = new QPushButton{"Add"};
    remove = new QPushButton{"Remove"};
    edit = new QPushButton{"Update"};
    buttons->addWidget(add);
    buttons->addWidget(remove);
    buttons->addWidget(edit);
    layout->addLayout(buttons);
    
}

void GUIAdmin::populateList() {
    eventlist->clear();
    for (auto e: service.getAll()) {
        eventlist->addItem(QString::fromStdString(e.toString()));
    }
    eventlist->setCurrentRow(0);
}


void GUIAdmin::connectSignalsAndSlots() {
//QObject::connect(eventlist,&QListWidget::itemSelectionChanged,this,&GUI::listItemChanged());
    QObject::connect(eventlist, &QListWidget::clicked, [this]() {
        int selectedIndex = getSelectedItem();
        Event e = this->service.getAll()[selectedIndex];
        titleLineEdit->setText(QString::fromStdString(e.getTitle()));
        descriptionLineEdit->setText(QString::fromStdString(e.getDescription()));
        linkLineEdit->setText(QString::fromStdString(e.getLink()));
        yearLineEdit->setText(QString::number(e.getTime().year));
        monthLineEdit->setText(QString::number(e.getTime().month));
        dayLineEdit->setText(QString::number(e.getTime().day));
        hourLineEdit->setText(QString::number(e.getTime().hour));
        minuteLineEdit->setText(QString::number(e.getTime().minute));
        peopleLineEdit->setText(QString::number(e.getNrOfPeople()));
    });
    QObject::connect(exit,&QPushButton::clicked,[this](){
        hide();
    });
    QObject::connect(add, &QPushButton::clicked, this,&GUIAdmin::addEvent);
    QObject::connect(remove,&QPushButton::clicked,this,&GUIAdmin::removeEvent);
    QObject::connect(edit,&QPushButton::clicked,this,&GUIAdmin::updateEvent);
}

int GUIAdmin::getSelectedItem() {
    QModelIndexList indexList = this->eventlist->selectionModel()->selectedIndexes();
    if (indexList.size() == 0)
        return -1;
    return indexList.at(0).row();
}

void GUIAdmin::addEvent() {
    string title = titleLineEdit->text().toStdString();
    string description = descriptionLineEdit->text().toStdString();
    string link = linkLineEdit->text().toStdString();

    try {
        service.addEvent(Event(title, description, dateTime{yearLineEdit->text().toInt(), monthLineEdit->text().toInt(), dayLineEdit->text().toInt(), hourLineEdit->text().toInt(), minuteLineEdit->text().toInt()}, 1, link));
        populateList();
    }
    catch (DuplicateEventException &e) {
        QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
    }
}

void GUIAdmin::removeEvent() {
    int index=getSelectedItem();
    if(index==-1){
        QMessageBox::critical(this,"Error",QString::fromStdString("Stupid"));
    }
    try{
        string del=service.getAll()[index].getTitle();
        service.deleteEvent(del);
        populateList();
    }
    catch (NoEventException& e) {
        QMessageBox::critical(this,"Error",QString::fromStdString(e.what()));
    }
}

void GUIAdmin::updateEvent() {
    try {
        string title = titleLineEdit->text().toStdString();
        string description = descriptionLineEdit->text().toStdString();
        string link = linkLineEdit->text().toStdString();
        service.updateDescription(title, description);
        service.updateNrOfPeople(title, peopleLineEdit->text().toInt());
        service.updateLink(title, link);
        service.updateTimeYear(title, yearLineEdit->text().toInt());
        service.updateTimeMonth(title, monthLineEdit->text().toInt());
        service.updateTimeDay(title, dayLineEdit->text().toInt());
        service.updateTimeHour(title, hourLineEdit->text().toInt());
        service.updateTimeMinute(title, minuteLineEdit->text().toInt());
        populateList();

    }
    catch (NoEventException& e) {
        QMessageBox::critical(this,"Error",QString::fromStdString(e.what()));
    }
}

GUIMain::GUIMain(GUIAdmin &admin,GUIUser &user, QWidget *parent) : admin{admin},user{user}, QWidget(parent){
    initGui();
    connectSignalsAndSlots();
}

void GUIMain::initGui() {
    setWindowTitle("Main menu");
    QHBoxLayout* mainLayout=new QHBoxLayout{this};
    adminButton=new QPushButton{"Admin"};
    userButton=new QPushButton{"User"};
    mainLayout->addWidget(adminButton);
    mainLayout->addWidget(userButton);
}

void GUIMain::launchAdmin() {
    QMessageBox::critical(this,"Welcome",QString::fromStdString("You entered the admin mode, any data you modify cannot be reverted."));
    admin.show();
}

void GUIMain::launchUser() {
    QMessageBox::critical(this,"Welcome",QString::fromStdString("You entered the user mode mode."));
    user.show();
}

void GUIMain::connectSignalsAndSlots() {
    QObject::connect(adminButton,&QPushButton::clicked,this,&GUIMain::launchAdmin);
    QObject::connect(userButton,&QPushButton::clicked,this,&GUIMain::launchUser);
}

void GUIUser::initGui() {
    QVBoxLayout* mainLayout=new QVBoxLayout{this};
    exit=new QPushButton{"Return to the main menu"};
    mainLayout->addWidget(exit);
    QFormLayout* eventForUser=new QFormLayout{};
    QLabel* monthLabel=new QLabel{"In what month should we search: "};
    month=new QLineEdit{};
    titleLineEdit = new QLineEdit{};
    descriptionLineEdit = new QLineEdit{};
    linkLineEdit = new QLineEdit{};
    peopleLineEdit=new QLineEdit{};
    yearLineEdit=new QLineEdit{};
    monthLineEdit=new QLineEdit{};
    dayLineEdit=new QLineEdit{};
    hourLineEdit=new QLineEdit{};
    minuteLineEdit=new QLineEdit{};
    startSearch=new QPushButton{"Start search"};
    eventForUser->addRow(monthLabel,month);
    eventForUser->addRow(startSearch);
    eventForUser->addRow("Title", titleLineEdit);
    eventForUser->addRow("Description", descriptionLineEdit);
    eventForUser->addRow("Link", linkLineEdit);
    eventForUser->addRow("People",peopleLineEdit);
    eventForUser->addRow("Year",yearLineEdit);
    eventForUser->addRow("Month",monthLineEdit);
    eventForUser->addRow("Day",dayLineEdit);
    eventForUser->addRow("Hour",hourLineEdit);
    eventForUser->addRow("Minute",minuteLineEdit);
    mainLayout->addLayout(eventForUser);
    addEvent=new QPushButton{"Add event"};
    nextEvent=new QPushButton{"Next"};
    previousEvent=new QPushButton{"Previous"};
    removeEvent=new QPushButton{"Remove event"};
    openLink=new QPushButton{"Open link"};
    QHBoxLayout* buttons=new QHBoxLayout{};
    buttons->addWidget(previousEvent);
    buttons->addWidget(nextEvent);
    buttons->addWidget(addEvent);
    buttons->addWidget(openLink);
    mainLayout->addLayout(buttons);
    userEvents=new QListWidget{};
    removeEvent=new QPushButton{"Remove event"};
    mainLayout->addWidget(userEvents);
    mainLayout->addWidget(removeEvent);
    csv=new QPushButton{"CSV"};
    html=new QPushButton{"HTML"};
    QVBoxLayout *lay2=new QVBoxLayout{};
    lay2->addWidget(csv);
    lay2->addWidget(html);
    mainLayout->addLayout(lay2);
}

void GUIUser::connectSignalsAndSlots() {
    QObject::connect(startSearch,&QPushButton::clicked,this,&GUIUser::startSearchForEventsInMonth);
    QObject::connect(nextEvent,&QPushButton::clicked,this,&GUIUser::goNext);
    QObject::connect(previousEvent,&QPushButton::clicked,this,&GUIUser::goPrevious);
    QObject::connect(addEvent,&QPushButton::clicked,this,&GUIUser::addEventToUserList);
    QObject::connect(openLink,&QPushButton::clicked,this,&GUIUser::openEventLink);
    QObject::connect(removeEvent,&QPushButton::clicked,this,&GUIUser::removeEventFromUserList);
    QObject::connect(exit,&QPushButton::clicked,[this](){
        hide();
    });
    QObject::connect(html,&QPushButton::clicked,this,&GUIUser::openHTML);
    QObject::connect(csv,&QPushButton::clicked,this,&GUIUser::openCSV);
}

void GUIUser::populateList() {
    userEvents->clear();
    for (auto s:userRepository) {
        userEvents->addItem(QString::fromStdString(s.toString()));
    }
//    userEvents->setCurrentRow(0);
}

void GUIUser::displayEvent() {
    Event e = eventsInMonth[count];
    titleLineEdit->setText(QString::fromStdString(e.getTitle()));
    descriptionLineEdit->setText(QString::fromStdString(e.getDescription()));
    linkLineEdit->setText(QString::fromStdString(e.getLink()));
    yearLineEdit->setText(QString::number(e.getTime().year));
    monthLineEdit->setText(QString::number(e.getTime().month));
    dayLineEdit->setText(QString::number(e.getTime().day));
    hourLineEdit->setText(QString::number(e.getTime().hour));
    minuteLineEdit->setText(QString::number(e.getTime().minute));
    peopleLineEdit->setText(QString::number(e.getNrOfPeople()));
}

void GUIUser::startSearchForEventsInMonth() {
    int monthToSearch=month->text().toInt();
    eventsInMonth=service.getPerMonth(monthToSearch);
    count=0;
    if (eventsInMonth.empty())
        QMessageBox::critical(this,"Error","There are no events in that month");
    else{
        displayEvent();
    }
}

void GUIUser::goNext() {
    count++;
    if (eventsInMonth.empty())
        QMessageBox::critical(this,"Error","There are no events in that month");
    else{
        if (count==eventsInMonth.size())
            count=0;
        displayEvent();
    }
}

void GUIUser::goPrevious() {
    count--;
    if (eventsInMonth.empty())
        QMessageBox::critical(this,"Error","There are no events in that month");
    else{
        if (count==-1)
            count=eventsInMonth.size()-1;
        displayEvent();
    }
}

void GUIUser::addEventToUserList() {
    string title = titleLineEdit->text().toStdString();
    string description = descriptionLineEdit->text().toStdString();
    string link = linkLineEdit->text().toStdString();
    int found=0;
    for (auto e:userRepository) {
        if (e.getTitle()==title)
        {
            QMessageBox::critical(this,"Error","Event already added");
            found=1;
            break;
        }
    }
    if (found==0) {
        service.updateNrOfPeople(title, peopleLineEdit->text().toInt() + 1);
        userRepository.emplace_back(title, description,
                                    dateTime{yearLineEdit->text().toInt(), monthLineEdit->text().toInt(),
                                             dayLineEdit->text().toInt(), hourLineEdit->text().toInt(),
                                             minuteLineEdit->text().toInt()}, peopleLineEdit->text().toInt()+1, link);
//        userRepository[userRepository.size()-1].setNrOfPeople(userRepository[userRepository.size()-1].getNrOfPeople()+1);

        populateList();
    }
}

int GUIUser::getSelectedItem() {
    QModelIndexList indexList = userEvents->selectionModel()->selectedIndexes();
    if (indexList.empty())
        return -1;
    return indexList.at(0).row();
}

void GUIUser::openEventLink() {
    string link=linkLineEdit->text().toStdString();
    ShellExecuteA(NULL,"open",link.c_str(),NULL,NULL,SW_SHOWNORMAL);
}

void GUIUser::removeEventFromUserList() {
    int index=getSelectedItem();
    if (index==-1)
        QMessageBox::critical(this,"Error","No event selected");
    else{
        string title=userRepository.at(index).getTitle();
        service.updateNrOfPeople(title,userRepository.at(index).getNrOfPeople()-1);
        eventsInMonth=service.getPerMonth(month->text().toInt());
        userRepository.erase(userRepository.cbegin()+index);
        populateList();
    }
}

void GUIUser::openCSV() {
    CSVEventList list(userRepository,"ex.csv");
    list.writeToFile();
    list.displayEventList();
}

void GUIUser::openHTML() {
    HTMLEventList list2(userRepository,"test.html");
    list2.writeToFile();
    list2.displayEventList();
}




