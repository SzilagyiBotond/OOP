//
// Created by admin on 2023. 06. 28..
//

#ifndef E916_SZILAGYIBOTOND_COMPANYWINDOW_H
#define E916_SZILAGYIBOTOND_COMPANYWINDOW_H

#include <QWidget>

#include "Service.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CompanyWindow; }
QT_END_NAMESPACE

class CompanyWindow : public QWidget, public Observer {
Q_OBJECT
private:
    Service& service;
public:
    explicit CompanyWindow(Service& service,QWidget *parent = nullptr);
    void populateList();
    ~CompanyWindow() override;
    void update() override{populateList();}
    void addPackage();
    void connectSignalsAndSlots();

private:
    Ui::CompanyWindow *ui;
};


#endif //E916_SZILAGYIBOTOND_COMPANYWINDOW_H
