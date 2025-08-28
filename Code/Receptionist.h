#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include "Staff.h"
#include "Patient.h"

class Receptionist : public Staff
{
    Patient p;
    int RecID;

public:
    void RecInfo();
    void show_receptionist();
    void entry_Patient();
    void write_receptionist();
    void display_all_Receptionist();
    void display_r(int n);
    void modify_receptionist(int n);
    void Receptionist_menu();
};

#endif
