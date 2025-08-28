#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;

class Person {
    char Name[50], Gender[10];
    int Age, Date, Month, Year;
    long int PhoneNum;
    int ZipCode, PersonID;
    char City[50], Country[50], State[50], blood_g[5];
public:
    void PersonInfo();
    void Display_info();
};

#endif