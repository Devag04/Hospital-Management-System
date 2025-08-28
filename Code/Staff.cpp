#include "Staff.h"

void Staff::staff_info() {
    PersonInfo();  // calling base class function
    cout << "Enter salary:";
    cin >> salary;
    cout << "Enter Duty time:" << endl;
    cout << "From: ";
    cin >> time_from;
    cout << "To: ";
    cin >> time_to;
}

void Staff::show_staff() {
    cout << "\nSalary: " << salary;
    cout << "\nDuty Time: " << time_from << "--" << time_to << endl;
    Display_info();  // show info from Person
}
