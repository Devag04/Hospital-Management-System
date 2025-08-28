#include <iostream>
#include <cstdlib>
#include "Admin.h"
using namespace std;

void admin::staff_menu()
{
    char ch;
    do
    {
        system("cls");
        cout << "\n\n\tStaff Menu";
        cout << "\n\n\t1.Doctor";
        cout << "\n\n\t2.Nurse";
        cout << "\n\n\t3.Receptionist";
        cout << "\n\n\t4.Store Manager";
        cout << "\n\n\t5.TO EXIT";
        cout << "\n\n\tPlease Enter Your Choice (1-4): ";
        cin >> ch;
        system("cls");

        switch (ch)
        {
        case '1':
            d.Doctor_menu();
            break;
        case '2':
            n.Nurse_menu();
            break;
        case '3':
            r.Receptionist_menu();
            break;
        case '4':
            s.store_manager_menu();
            break;
        }
    } while (ch != '5');
}

