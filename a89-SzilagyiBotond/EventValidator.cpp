//
// Created by admin on 2023. 04. 20..
//
#include "EventValidator.h"

void EventValidator::validate(const Event &e) {
    vector<string > errors;
    if (e.getTime().minute>59|| e.getTime().day<1 || e.getTime().day>31 || e.getTime().hour>24 || e.getTime().hour < 0 || e.getTime().minute<0 || 2023>e.getTime().year || 0>e.getTime().month || e.getTime().month>12)
        errors.emplace_back("Invalid time\n");
    if (e.getTime().month==4 || e.getTime().month==6 || e.getTime().month==9 || e.getTime().month==11)
        if (e.getTime().day>30)
            errors.emplace_back("Invalid time\n");
    if(e.getTime().month==2)
    {
        if (e.getTime().year%4==2)
        {
            if (e.getTime().day>29)
                errors.emplace_back("Invalid time\n");
        }
        else {
            if (e.getTime().day > 28)
                errors.emplace_back("Invalid time\n");
        }
    }
    if (!errors.empty())
        throw EventException(errors);
}
