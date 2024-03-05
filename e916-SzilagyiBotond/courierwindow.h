//
// Created by admin on 2023. 06. 28..
//

#ifndef E916_SZILAGYIBOTOND_COURIERWINDOW_H
#define E916_SZILAGYIBOTOND_COURIERWINDOW_H

#include <QWidget>
#include "Service.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CourierWindow; }
QT_END_NAMESPACE

class CourierWindow : public QWidget, public Observer{
Q_OBJECT
private:
    Service& service;
    Courier courier;
public:
    explicit CourierWindow(Service& service,Courier c1,QWidget *parent = nullptr);
    void populateList();
    void populateComboBox();
    void populateSorted();
    void updatePackage();
    int getSelectedIndex();
    void update() override;
    ~CourierWindow() override;
    void connectSignalsAndSlots();

private:
    Ui::CourierWindow *ui;
};


#endif //E916_SZILAGYIBOTOND_COURIERWINDOW_H
