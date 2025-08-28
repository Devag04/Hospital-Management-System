#include "Person.h"

void Person::PersonInfo()
    {
        cout << "Enter Name :";
        cin.clear();
        cin.ignore();
        cin.getline(Name, 50);
        cout << "Enter Gender :";
        cin >> Gender;
        cout << "Enter Age :";
        cin >> Age;
        cout << "Enter Address :";
        cin >> Country;
        cout << "Enter Blood group:";
        cin >> blood_g;
    }

    void Person::Display_info()
    {
        cout << "Name: " << Name << endl;
        cout << "Gender: " << Gender << endl;
        cout << "Age: " << Age << endl;
        cout << "Address: " << this->Country << endl;
        cout << "Blood Group:" << blood_g << endl;
    }