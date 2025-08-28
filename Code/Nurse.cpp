#include "Nurse.h"

void Nurse::GetNurseInfo()
{
    cout << "--------------------------------" << endl;
    staff_info();
    cout << "Enter Nurse ID:";
    cin >> NurseID;
    cout << "Enter Nurse Duty Room :";
    cin >> ChargeRoom;
}

void Nurse::Display_NurseInfo()
{
    cout << "--------------------------------" << endl;
    cout << "Nurse ID :" << NurseID;
    show_staff();
    cout << "\n"
         << "Nurse in charge Room :" << ChargeRoom;
    cout << endl;
}

void Nurse::Write_NurseInfo()
{
    Nurse n;
    ofstream outFile;
    outFile.open("NurseInfo.dat", ios::binary | ios::app);
    n.GetNurseInfo();
    outFile.write(reinterpret_cast<char *>(&n), sizeof(Nurse));
    outFile.close();
    cout << "\n\nrecord Has Been Created ";
    cin.ignore();
    cin.get();
}

void Nurse::display_n(int m)
{
    Nurse n;
    ifstream inFile;
    inFile.open("NurseInfo.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag = false;
    while (inFile.read(reinterpret_cast<char *>(&n), sizeof(Nurse)))
    {
        if (n.NurseID == m)
        {
            n.Display_NurseInfo();
            flag = true;
        }
    }
    inFile.close();
    if (!flag)
        cout << "\n\nrecord does not exist";
    cin.ignore();
    cin.get();
}

void Nurse::modify_Nurse(int m)
{
    bool found = false;
    Nurse n;
    fstream File;
    File.open("NurseInfo.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    while (!File.eof() && !found)
    {
        File.read(reinterpret_cast<char *>(&n), sizeof(Nurse));
        if (n.NurseID == m)
        {
            n.Display_NurseInfo();
            cout << "\n\nPlease Enter The New Details of nurse" << endl;
            n.GetNurseInfo();
            int pos = (-1) * static_cast<int>(sizeof(n));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&n), sizeof(Nurse));
            cout << "\n\n\t Record Updated";
            found = true;
        }
    }
    File.close();
    if (!found)
        cout << "\n\n Record does Not Found ";
    cin.ignore();
    cin.get();
}

void Nurse::display_all_Nurse()
{
    Nurse n;
    ifstream inFile;
    inFile.open("NurseInfo.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    while (inFile.read(reinterpret_cast<char *>(&n), sizeof(Nurse)))
    {
        n.Display_NurseInfo();
        cout << "\n\n=======================================================================================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void Nurse::Nurse_menu()
{
    char ch;
    do
    {
        int n;
        system("cls");

        cout << "\n\n\t01. INSERT NURSE DATA";
        cout << "\n\n\t02. Search NURSE ";
        cout << "\n\n\t03. ALL NURSE ";
        cout << "\n\n\t04. MODIFY NURSE DATA";
        cout << "\n\n\t05. To EXIT..........";
        cout << "\n\n\tPlease Select Your Option (1-5) ";
        cin >> ch;

        switch (ch)
        {
        case '1':
            Write_NurseInfo();
            break;
        case '2':
            cout << "Enter NURSE ID :";
            cin >> n;
            display_n(n);
            break;
        case '3':
            display_all_Nurse();
            break;
        case '4':
            cout << "Enter Nurse ID :";
            cin >> n;
            modify_Nurse(n);
            break;
        }
    } while (ch != '5');
}
