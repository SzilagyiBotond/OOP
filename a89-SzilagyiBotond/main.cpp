#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QFormLayout>
#include "Ui.h"
#include <QLineEdit>
#include <iostream>
#include "GUI.h"
int main(int argc, char *argv[]) {
    Repository repository{"test"};
//    repository.readFromFile();
    Service service{repository,EventValidator()};
////    service.generateTenEntries();
//    Ui ui{service};
//////    ui.runAdminConsole();
//    ui.runGeneralConsole();
    QApplication a(argc, argv);
    GUIAdmin guiAdmin{service};
    GUIUser guiUser{service};
    GUIMain guiMain{guiAdmin,guiUser};
    guiMain.show();


    return a.exec();
}
