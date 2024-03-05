#pragma once
#include <string>
#include "Event.h"
#include <vector>
using namespace std;

class EventException{
private:
    std::vector<string> errors;
public:
    EventException(vector<string> _errors): errors{_errors}{}
    vector<string> getErrors() const {return this->errors;}
};

class EventValidator{
public:
    EventValidator()= default;
    static void validate(const Event& e);
};