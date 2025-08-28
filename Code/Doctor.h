#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include <fstream>
#include "Staff.h"
#include "Patient.h"
using namespace std;

class Doctor : public Staff
{
    int DocID;
    Patient p;
    char Spz[500];

public:
    bool CheckRegNo(int n);
    void DoctorInfo();
    void show_doctor();
    int retDid();
    void Prescribe_Medicine();
    void write_doctor();
    void display_all_Doctor();
    void display_d(int n);
    void modify_doctor(int n);
    void Doctor_choice();
    void Doctor_menu();
};

#endif
