//
// Created by admin on 2023. 06. 28..
//

// You may need to build the project (run Qt uic code generator) to get "ui_CourierWindow.h" resolved

#include "courierwindow.h"
#include "ui_CourierWindow.h"
#include <QMessageBox>

CourierWindow::CourierWindow(Service& service,Courier c1,QWidget *parent) :service(service),courier(c1),
        QWidget(parent), ui(new Ui::CourierWindow) {
    service.addObserver(this);
    ui->setupUi(this);
    setWindowTitle(QString::fromStdString(courier.getName()));
    ui->radiusLabel->setText(QString::number(courier.getZone().radius));
    ui->xLabel->setText(QString::number(courier.getZone().x));
    ui->yLabel->setText(QString::number(courier.getZone().y));
    connectSignalsAndSlots();
    populateList();
    populateComboBox();
}

CourierWindow::~CourierWindow() {
    delete ui;
}

void CourierWindow::populateList() {
    ui->undeliveredList->clear();
    for (auto package:service.getZone(courier.getZone(),courier.getStreets())) {
        if (!package.getStatus())
            ui->undeliveredList->addItem(QString::fromStdString(package.toString()));
    }
}

void CourierWindow::populateComboBox() {
//    for (auto street:courier.getStreets()) {
//        ui->filterComboBox->addItem(QString::fromStdString(street));
//    }
//
    for(auto street:service.getAllStreets()){
        ui->filterComboBox->addItem(QString::fromStdString(street));
    }
}

void CourierWindow::populateSorted() {
    string street=ui->filterComboBox->currentText().toStdString();
    ui->undeliveredList->clear();
    for (auto package:service.getZoneStreet(courier.getZone(),street)) {
        if (!package.getStatus())
            ui->undeliveredList->addItem(QString::fromStdString(package.toString()));
    }
}

int CourierWindow::getSelectedIndex() {
    QModelIndexList index=ui->undeliveredList->selectionModel()->selectedIndexes();
    if (index.size()==0)
        return -1;
    return index.at(0).row();
}

void CourierWindow::updatePackage() {
    int index=getSelectedIndex();
    if (index==-1)
        QMessageBox::critical(this,"Error","No index selected");
    else {
        Package &p = service.getByRecipient(service.getZoneStreet(courier.getZone(),
                                                                  ui->filterComboBox->currentText().toStdString())[index].getRecipient());
        service.setDelivered(service.getZoneStreet(courier.getZone(),
                                                   ui->filterComboBox->currentText().toStdString())[index].getRecipient());
        service.notify();
    }
}

void CourierWindow::update() {
    populateList();
}

void CourierWindow::connectSignalsAndSlots() {
//    QObject::connect(ui->filterComboBox,&QComboBox::activated)
    QObject::connect(ui->filterButton,&QPushButton::clicked,this,&CourierWindow::populateSorted);
    QObject::connect(ui->deliverButton,&QPushButton::clicked,this,&CourierWindow::updatePackage);
}



