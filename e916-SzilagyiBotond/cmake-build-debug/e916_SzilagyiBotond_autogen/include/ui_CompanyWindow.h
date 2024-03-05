/********************************************************************************
** Form generated from reading UI file 'companywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPANYWINDOW_H
#define UI_COMPANYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CompanyWindow
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *packagesList;
    QLineEdit *recipientLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *streetLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *numberLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *locationxLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *locationyLineEdit;
    QPushButton *addButton;

    void setupUi(QWidget *CompanyWindow)
    {
        if (CompanyWindow->objectName().isEmpty())
            CompanyWindow->setObjectName("CompanyWindow");
        CompanyWindow->resize(540, 577);
        verticalLayout = new QVBoxLayout(CompanyWindow);
        verticalLayout->setObjectName("verticalLayout");
        packagesList = new QListWidget(CompanyWindow);
        packagesList->setObjectName("packagesList");

        verticalLayout->addWidget(packagesList);

        recipientLineEdit = new QLineEdit(CompanyWindow);
        recipientLineEdit->setObjectName("recipientLineEdit");

        verticalLayout->addWidget(recipientLineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        streetLineEdit = new QLineEdit(CompanyWindow);
        streetLineEdit->setObjectName("streetLineEdit");

        horizontalLayout_2->addWidget(streetLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        numberLineEdit = new QLineEdit(CompanyWindow);
        numberLineEdit->setObjectName("numberLineEdit");

        horizontalLayout_3->addWidget(numberLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        locationxLineEdit = new QLineEdit(CompanyWindow);
        locationxLineEdit->setObjectName("locationxLineEdit");

        horizontalLayout_4->addWidget(locationxLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        locationyLineEdit = new QLineEdit(CompanyWindow);
        locationyLineEdit->setObjectName("locationyLineEdit");

        horizontalLayout_5->addWidget(locationyLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        addButton = new QPushButton(CompanyWindow);
        addButton->setObjectName("addButton");

        verticalLayout->addWidget(addButton);


        retranslateUi(CompanyWindow);

        QMetaObject::connectSlotsByName(CompanyWindow);
    } // setupUi

    void retranslateUi(QWidget *CompanyWindow)
    {
        CompanyWindow->setWindowTitle(QCoreApplication::translate("CompanyWindow", "CompanyWindow", nullptr));
        addButton->setText(QCoreApplication::translate("CompanyWindow", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CompanyWindow: public Ui_CompanyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPANYWINDOW_H
