#include "Doctor.h"

bool Doctor::CheckRegNo(int n)
{
    bool found = false;
    Doctor d;
    fstream File;
    File.open("Doctor.dat", ios::binary | ios::in);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&d), sizeof(Doctor));
        if (d.DocID == n)
        {
            found = true;
        }
    }
    File.close();
    return found;
    cin.ignore();
    cin.get();
}

void Doctor::DoctorInfo()
{
    staff_info();
id:
    cout << "Enter Doctor ID(1200-1299):";
    int m;
    cin >> m;
    if (CheckRegNo(m) == false)
    {
        DocID = m;
    }
    else
    {
        cout << "ID already taken\n";
        goto id;
    }

    cout << "Enter Doctor Specialize :";
    cin >> Spz;
    system("pause");
}

void Doctor::show_doctor()
{
    cout << "Doctor ID: " << DocID;
    show_staff();

    cout << "\nDoctor Specialize: " << Spz;
}

int Doctor::retDid()
{
    return DocID;
}

void Doctor::Prescribe_Medicine()
{
    int n;
    cout << "\n\n\tEnter Reg Number Of patient : ";
    cin >> n;
    p.modify_medicine(n);
}

void Doctor::write_doctor()
{
    Doctor d;
    ofstream outFile;
    outFile.open("Doctor.dat", ios::binary | ios::app);
    d.DoctorInfo();
    outFile.write(reinterpret_cast<char *>(&d), sizeof(Doctor));

    cout << "\n\nDoctor record Has Been Created ";
    outFile.close();
    cin.ignore();
}

void Doctor::display_all_Doctor()
{
    Doctor d;
    ifstream inFile;
    inFile.open("Doctor.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    while (inFile.read(reinterpret_cast<char *>(&d), sizeof(Doctor)))
    {
        d.show_doctor();
        cout << "\n\n=======================================================================================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void Doctor::display_d(int n)
{
    Doctor d;
    ifstream inFile;
    inFile.open("Doctor.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag = false;
    while (inFile.read(reinterpret_cast<char *>(&d), sizeof(Doctor)))
    {
        if (d.DocID == n)
        {
            d.show_doctor();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\nrecord not exist";
    cin.ignore();
    cin.get();
}

void Doctor::modify_doctor(int n)
{
    bool found = false;
    Doctor d;
    fstream File;
    File.open("Doctor.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&d), sizeof(Doctor));
        if (d.DocID == n)
        {
            d.show_doctor();
            cout << "\n\nPlease Enter The New Details:" << endl;
            d.DoctorInfo();
            int pos = (-1) * static_cast<int>(sizeof(d));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&d), sizeof(Doctor));
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

void Doctor::Doctor_choice()
{
    char ch;

    do
    {
        int n;
        system("cls");

        cout << "\n\n\t01. Prescribe Medicine for patient ";
        cout << "\n\n\t02. Search DOCTOR ";
        cout << "\n\n\t03. To exit.....";
        cout << "\n\n\tPlease Select Your Option (1-3) ";
        cin >> ch;

        switch (ch)
        {
        case '1':
            Prescribe_Medicine();
            break;
        case '2':
            cout << "Enter Doctor ID :";
            cin >> n;
            display_d(n);
            break;
        case '3':
            break;
        default:
            cout << "\b";
        }
    } while (ch != '3');
}

void Doctor::Doctor_menu()
{
    char ch;

    do
    {
        int n;
        system("cls");

        cout << "\n\n\t01. INSERT DOCTOR DATA";
        cout << "\n\n\t02. Search DOCTOR ";
        cout << "\n\n\t03. ALL DOCTOR ";
        cout << "\n\n\t04. MODIFY DOCTOR DATA";
        cout << "\n\n\t05. TO EXIT............";
        cout << "\n\n\tPlease Select Your Option (1-5) ";
        cin >> ch;
        system("cls");
        switch (ch)
        {
        case '1':
            write_doctor();
            break;
        case '2':
            cout << "Enter Doctor ID :";
            cin >> n;
            display_d(n);
            break;

        case '3':
            display_all_Doctor();
            break;
        case '4':
            cout << "Enter Doctor ID :";
            cin >> n;
            modify_doctor(n);
            break;
        }
    } while (ch != '5');
}
