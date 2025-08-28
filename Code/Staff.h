#ifndef STAFF_H
#define STAFF_H

#include "Person.h"   // because Staff inherits Person
#include <iostream>
using namespace std;

class Staff : public Person {
    int salary;
    char time_from[30], time_to[30];

public:
    void staff_info();
    void show_staff();
};

#endif