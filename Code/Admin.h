#ifndef ADMIN_H
#define ADMIN_H

#include "Doctor.h"
#include "Patient.h"
#include "Receptionist.h"
#include "store_manager.h"
#include "Nurse.h"

class admin
{
private:
    Doctor d;
    Patient p;
    Receptionist r;
    store_manager s;
    Nurse n;

public:
    void staff_menu();
};

#endif