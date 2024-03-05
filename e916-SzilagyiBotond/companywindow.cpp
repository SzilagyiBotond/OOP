//
// Created by admin on 2023. 06. 28..
//

// You may need to build the project (run Qt uic code generator) to get "ui_CompanyWindow.h" resolved

#include "companywindow.h"
#include "ui_CompanyWindow.h"
#include <QMessageBox>

CompanyWindow::CompanyWindow(Service& service,QWidget *parent) :service(service),
        QWidget(parent), ui(new Ui::CompanyWindow) {
    service.addObserver(this);
    ui->setupUi(this);
    connectSignalsAndSlots();
    populateList();
    setWindowTitle(QString::fromStdString("Main window"));
}

CompanyWindow::~CompanyWindow() {
    delete ui;
}

void CompanyWindow::populateList() {
    ui->packagesList->clear();
    for (auto package:service.getPackages()) {
        ui->packagesList->addItem(QString::fromStdString(package.toString()));
    }
    for (int i = 0; i < service.getPackages().size(); ++i) {
        if (service.getPackages()[i].getStatus())
            ui->packagesList->item(i)->setBackground(Qt::green);
    }
}

void CompanyWindow::addPackage() {
    if (ui->recipientLineEdit->text().toStdString()=="")
        QMessageBox::critical(this,"Error","Cannot leave empty spaces");
    else
        service.addPackage(Package{ui->recipientLineEdit->text().toStdString(),addr{ui->streetLineEdit->text().toStdString(),ui->numberLineEdit->text().toInt()},loc{ui->locationxLineEdit->text().toInt(),ui->locationyLineEdit->text().toInt()},false});
}

void CompanyWindow::connectSignalsAndSlots() {
    QObject::connect(ui->addButton,&QPushButton::clicked,this,&CompanyWindow::addPackage);
}
