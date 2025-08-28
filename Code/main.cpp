#include <iostream>
#include "Patient.h"
#include "Doctor.h"
#include "Receptionist.h"
#include "store_manager.h"
#include "Staff.h"
#include "Person.h"
#include "Nurse.h"
#include "Ambulance.h"
#include "Admin.h"
using namespace std;

int main()
{
    admin a;
    Receptionist r;
    Doctor d;
    store_manager s;
    int ch;
    char pass[15];
    do
    {
        cout << "\t\t\n\n\n";
        cout << "\t\t1.Admin\n";
        cout << "\t\t2.Receptionist\n";
        cout << "\t\t3.Doctor\n";
        cout << "\t\t4.Store Manager\n";
        cout << "\t\t5.Exit From The SYSTEM\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
        login1:
            cout << "Enter ADMIN password: ";

            cin >> pass;

            if (strcmp(pass, "admin") == 0)
            {
                a.staff_menu();
            }
            else
            {
                cout << "WRONG PASSWORD!!!\n";
                goto login1;
            }
            break;
        case 2:
        login2:
            cout << "Enter Receptionist password: ";

            cin >> pass;

            if (strcmp(pass, "receptionist") == 0)
            {
                r.entry_Patient();
            }
            else
            {
                cout << "WRONG PASSWORD!!!\n";
                goto login2;
            }
            break;
        case 3:

        login3:
            cout << "Enter Doctor password: ";

            cin >> pass;

            if (strcmp(pass, "doctor") == 0)
            {
                d.Doctor_choice();
            }
            else
            {
                cout << "WRONG PASSWORD!!!\n";
                goto login3;
            }
            break;
        case 4:
        login4:
            cout << "Enter STORE MANAGER password: ";

            cin >> pass;
            if (strcmp(pass, "store") == 0)
            {
                s.store_manager_choice();
            }
            else
            {
                cout << "WRONG PASSWORD!!!\n";
                goto login4;
            }
            break;
        }
    } while (ch != 5);
}
