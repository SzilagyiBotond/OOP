//
// Created by admin on 2023. 06. 28..
//

#ifndef E916_SZILAGYIBOTOND_OBSERVER_H
#define E916_SZILAGYIBOTOND_OBSERVER_H
#include <vector>
using namespace std;

class Observer {
public:
    virtual ~Observer(){}
    virtual void update()=0;
};
class Subject{
private:
    vector<Observer*> observers;
public:
    void addObserver(Observer* obs){
        observers.push_back(obs);
    }
    void notify(){
        for (auto obs:observers) {
            obs->update();
        }
    }
};

#endif //E916_SZILAGYIBOTOND_OBSERVER_H
