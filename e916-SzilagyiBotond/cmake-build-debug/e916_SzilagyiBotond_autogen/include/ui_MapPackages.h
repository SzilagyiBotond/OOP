/********************************************************************************
** Form generated from reading UI file 'mappackages.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPPACKAGES_H
#define UI_MAPPACKAGES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapPackages
{
public:

    void setupUi(QWidget *MapPackages)
    {
        if (MapPackages->objectName().isEmpty())
            MapPackages->setObjectName("MapPackages");
        MapPackages->resize(400, 300);

        retranslateUi(MapPackages);

        QMetaObject::connectSlotsByName(MapPackages);
    } // setupUi

    void retranslateUi(QWidget *MapPackages)
    {
        MapPackages->setWindowTitle(QCoreApplication::translate("MapPackages", "MapPackages", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MapPackages: public Ui_MapPackages {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPPACKAGES_H
