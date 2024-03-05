
#pragma once
#include "Service.h"
#include <iostream>

class Ui
{
private:
    Service& service;
    string password="root";
public:
    Ui(Service& service);
    static void printUserOptions();
    static void printAdministratorOptions();
    static void printAdministratorUpdateOptions();
    static void printAdministratorUpdateTimeOptions();
    void addEvent();
    void deleteEvent();
    void updateEvent();
    void displayAllEvent();
    void runAdminConsole();
    void runUserConsole();
    void runGeneralConsole();
};
