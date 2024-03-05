//
// Created by admin on 2023. 05. 14..
//

#ifndef A89_SZILAGYIBOTOND_GUI_H
#define A89_SZILAGYIBOTOND_GUI_H
#include "Service.h"
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <qwidget.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <qlabel.h>
#include <QMessageBox>
#include "HTMLEventList.h"
class GUIAdmin : public QWidget {
    Q_OBJECT
private:
    Service& service;
public:
    GUIAdmin(Service& service,QWidget* parent=0);
    void initGui();
private:
    QListWidget* eventlist;
    QPushButton* add;
    QPushButton* edit;
    QPushButton* remove;
    QPushButton* exit;
    void populateList();
    void connectSignalsAndSlots();
    void listItemChanged();
    int getSelectedItem();
    QLineEdit* titleLineEdit;
    QLineEdit* descriptionLineEdit;
    QLineEdit* linkLineEdit;
    QLineEdit* peopleLineEdit;
    QLineEdit* yearLineEdit;
    QLineEdit* monthLineEdit;
    QLineEdit* dayLineEdit;
    QLineEdit* hourLineEdit;
    QLineEdit* minuteLineEdit;
    void addEvent();
    void removeEvent();
    void updateEvent();
};
class GUIUser:public QWidget{
    Q_OBJECT
private:
    Service& service;
    vector<Event> userRepository;
    vector<Event> eventsInMonth;
    int count;
public:
    GUIUser(Service& service, QWidget* parent=0):service{service},QWidget(parent),count{0}{initGui();connectSignalsAndSlots();}
    void initGui();
    void connectSignalsAndSlots();
private:
    QLineEdit* titleLineEdit;
    QLineEdit* descriptionLineEdit;
    QLineEdit* linkLineEdit;
    QLineEdit* peopleLineEdit;
    QLineEdit* yearLineEdit;
    QLineEdit* monthLineEdit;
    QLineEdit* dayLineEdit;
    QLineEdit* hourLineEdit;
    QLineEdit* minuteLineEdit;
    QLineEdit* month;
    QListWidget* userEvents;
    QPushButton* exit;
    QPushButton* nextEvent;
    QPushButton* addEvent;
    QPushButton* previousEvent;
    QPushButton* removeEvent;
    QPushButton* openLink;
    QPushButton* startSearch;
    QPushButton* csv;
    QPushButton* html;
public:
    void openCSV();
    void openHTML();
    void populateList();
    void displayEvent();
    int getSelectedItem();
    void addEventToUserList();
    void goNext();
    void goPrevious();
    void openEventLink();
    void removeEventFromUserList();
    void startSearchForEventsInMonth();
};
class GUIMain : public QWidget{
Q_OBJECT
private:
    GUIAdmin& admin;
    GUIUser& user;
public:
    GUIMain(GUIAdmin& ga,GUIUser& gu,QWidget* parent=0);
    void initGui();
    void connectSignalsAndSlots();
    void launchAdmin();
    void launchUser();
private:
    QPushButton* adminButton;
    QPushButton* userButton;
};

#endif //A89_SZILAGYIBOTOND_GUI_H
