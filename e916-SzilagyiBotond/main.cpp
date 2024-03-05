#include <QApplication>
#include <QPushButton>
#include "companywindow.h"
#include "courierwindow.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Repository repo{"Packages.txt"};
    Service service{repo};
    ifstream file("Courier.txt");
    Courier c1;
    vector<CourierWindow*> windows;
    while(file>>c1){
        CourierWindow* wind=new CourierWindow{service,c1};
        windows.push_back(wind);
    }
//    vector<string> streets{"sesame","susame"};
////    Courier c1{"Sam",streets,zoneCourier {0,0,2}};
    CompanyWindow window{service};
    for (auto win:windows) {
        win->show();
    }
//    CourierWindow window1{service,c1};
//    window1.show();
    window.show();
//    QPushButton button("Hello world!", nullptr);
//    button.resize(200, 100);
//    button.show();
    return QApplication::exec();
}
