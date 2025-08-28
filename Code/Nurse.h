#ifndef NURSE_H
#define NURSE_H

#include "Staff.h"
#include "Patient.h"
#include <fstream>
#include <iostream>
using namespace std;

class Nurse : public Staff
{
    int NurseID;
    char ChargeRoom[50];
    Patient p;

public:
    void GetNurseInfo();
    void Display_NurseInfo();
    void Write_NurseInfo();
    void display_n(int m);
    void modify_Nurse(int m);
    void display_all_Nurse();
    void Nurse_menu();
};

#endif
