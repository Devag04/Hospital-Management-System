#include "Receptionist.h"
#include "Ambulance.h"
#include <iostream>
#include <fstream>
using namespace std;

void Receptionist::RecInfo()
{
    staff_info();
    cout << "Enter Receptionist ID :";
    cin >> RecID;
}

void Receptionist::show_receptionist()
{
    show_staff();
    cout << "Receptionist ID: " << RecID;
}

void Receptionist::entry_Patient()
{
    char ch;
    int num;
    do
    {
        system("cls");
        cout << "\n\n\n\tENTRY MENU";
        cout << "\n\n\t1.CREATE PATIENT RECORD";
        cout << "\n\n\t2.DISPLAY ALL PATIENTS RECORDS";
        cout << "\n\n\t3.SEARCH PATIENT RECORD ";
        cout << "\n\n\t4.MODIFY PATIENT RECORD";
        cout << "\n\n\t5.DELETE PATIENT RECORD";
        cout << "\n\n\t6.FIND SHORTEST PATH BETWEEN CITIES";
        cout << "\n\n\t7.TO EXIT";
        cout << "\n\n\tPlease Enter Your Choice (1-6) ";
        cin >> ch;
        system("cls");

        switch (ch)
        {
        case '1':
            p.write_patient();
            break;
        case '2':
            p.display_all();
            break;
        case '3':
            cout << "\n\n\tPlease Enter The reg  number ";
            cin >> num;
            p.display_p(num);
            break;
        case '4':
            cout << "\n\n\tPlease Enter The reg number ";
            cin >> num;
            p.modify_patient(num);
            break;
        case '5':
            cout << "\n\n\tPlease Enter The reg number ";
            cin >> num;
            p.delete_patient(num);
            break;
        case '6':
            ambulanceRoutingMenu();
            break;
        }
    } while (ch != '7');
}

void Receptionist::write_receptionist()
{
    Receptionist r;
    ofstream outFile;
    outFile.open("Receptionist.dat", ios::binary | ios::app);
    r.RecInfo();
    outFile.write(reinterpret_cast<char *>(&r), sizeof(Receptionist));
    outFile.close();
    cout << "\n\nReceptionist record Has Been Created ";
    cin.ignore();
    cin.get();
}

void Receptionist::display_all_Receptionist()
{
    Receptionist r;
    ifstream inFile;
    inFile.open("Receptionist.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    while (inFile.read(reinterpret_cast<char *>(&r), sizeof(Receptionist)))
    {
        r.show_receptionist();
        cout << "\n\n=======================================================================================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void Receptionist::display_r(int n)
{
    Receptionist r;
    ifstream inFile;
    inFile.open("Receptionist.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag = false;
    while (inFile.read(reinterpret_cast<char *>(&r), sizeof(Receptionist)))
    {
        if (r.RecID == n)
        {
            r.show_receptionist();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\nrecord not exist";
    cin.ignore();
    cin.get();
}

void Receptionist::modify_receptionist(int n)
{
    bool found = false;
    Receptionist r;
    fstream File;
    File.open("Receptionist.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&r), sizeof(Receptionist));
        if (r.RecID == n)
        {
            r.show_receptionist();
            cout << "\n\nPlease Enter The New Details " << endl;
            r.RecInfo();
            int pos = (-1) * static_cast<int>(sizeof(r));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&r), sizeof(Receptionist));
            cout << "\n\n\t Record Updated";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n Record Not Found ";
    cin.ignore();
    cin.get();
}

void Receptionist::Receptionist_menu()
{
    char ch;
    do
    {
        int n;
        system("cls");

        cout << "\n\n\t01. INSERT Receptionist DATA";
        cout << "\n\n\t02. Search Receptionist ";
        cout << "\n\n\t03. ALL Receptionist ";
        cout << "\n\n\t04. MODIFY Receptionist DATA";
        cout << "\n\n\t05. To EXIT..........";
        cout << "\n\n\tPlease Select Your Option (1-5) ";
        cin >> ch;

        switch (ch)
        {
        case '1':
            write_receptionist();
            break;
        case '2':
            cout << "Enter Receptionist ID :";
            cin >> n;
            display_r(n);
            break;
        case '3':
            display_all_Receptionist();
            break;
        case '4':
            cout << "Enter Receptionist ID :";
            cin >> n;
            modify_receptionist(n);
            break;
        }
    } while (ch != '5');
}
