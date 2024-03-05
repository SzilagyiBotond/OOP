/********************************************************************************
** Form generated from reading UI file 'courierwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURIERWINDOW_H
#define UI_COURIERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CourierWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *xLabel;
    QLabel *yLabel;
    QLabel *radiusLabel;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *undeliveredList;
    QVBoxLayout *verticalLayout;
    QComboBox *filterComboBox;
    QPushButton *deliverButton;
    QPushButton *filterButton;

    void setupUi(QWidget *CourierWindow)
    {
        if (CourierWindow->objectName().isEmpty())
            CourierWindow->setObjectName("CourierWindow");
        CourierWindow->resize(551, 623);
        verticalLayout_2 = new QVBoxLayout(CourierWindow);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        xLabel = new QLabel(CourierWindow);
        xLabel->setObjectName("xLabel");

        horizontalLayout->addWidget(xLabel);

        yLabel = new QLabel(CourierWindow);
        yLabel->setObjectName("yLabel");

        horizontalLayout->addWidget(yLabel);

        radiusLabel = new QLabel(CourierWindow);
        radiusLabel->setObjectName("radiusLabel");

        horizontalLayout->addWidget(radiusLabel);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        undeliveredList = new QListWidget(CourierWindow);
        undeliveredList->setObjectName("undeliveredList");

        horizontalLayout_2->addWidget(undeliveredList);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        filterComboBox = new QComboBox(CourierWindow);
        filterComboBox->setObjectName("filterComboBox");

        verticalLayout->addWidget(filterComboBox);

        deliverButton = new QPushButton(CourierWindow);
        deliverButton->setObjectName("deliverButton");

        verticalLayout->addWidget(deliverButton);

        filterButton = new QPushButton(CourierWindow);
        filterButton->setObjectName("filterButton");

        verticalLayout->addWidget(filterButton);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(CourierWindow);

        QMetaObject::connectSlotsByName(CourierWindow);
    } // setupUi

    void retranslateUi(QWidget *CourierWindow)
    {
        CourierWindow->setWindowTitle(QCoreApplication::translate("CourierWindow", "CourierWindow", nullptr));
        xLabel->setText(QCoreApplication::translate("CourierWindow", "TextLabel", nullptr));
        yLabel->setText(QCoreApplication::translate("CourierWindow", "TextLabel", nullptr));
        radiusLabel->setText(QCoreApplication::translate("CourierWindow", "TextLabel", nullptr));
        deliverButton->setText(QCoreApplication::translate("CourierWindow", "Deliver", nullptr));
        filterButton->setText(QCoreApplication::translate("CourierWindow", "Filter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CourierWindow: public Ui_CourierWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURIERWINDOW_H
