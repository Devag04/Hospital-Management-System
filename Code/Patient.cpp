#include "Patient.h"

void Patient::patient_bill() // using scope resolution operator to define function outside class
{
    system("CLS");
    cout << "********************************************************************************";
    cout << "\n\n\t\t\t\tPatient Fee Charge\n\n ";
    cout << "*******************************************************************************";
    // cout << "\nHospital Room Charges                      :\t  1000";
    cout << "\nHospital Care Charges                      :\t  50";
    cout << "\nHospital Maintaince Charges                :\t  50";
    cout << "\nPatient Individual  Charges                :\t " << bill;
    total = 50 + 50 + bill;
    cout << "\nTotal Fee Charge                           :\t" << total << "\n";
    cout << "********************************************************************************";
}

void Patient::getdata()
{
    PersonInfo();
    cout << "\nEnter The registration number of the patient: ";
    cin >> reg_no;
    cout << "\nEnter The occupation of the patient: ";
    cin >> occupation;
    cout << "\nEnter The bill of the patient:";
    cin >> bill;
    cout << "\nEnter The date admitted(dd/mm/yyyy):";
    cin >> date_admit;
    cout << "\nEnter The date discharged(dd/mm/yyyy):";
    cin >> date_discharge;
    patient_bill();
    strncpy(medicine, "null", sizeof(medicine) - 1);
    medicine[sizeof(medicine) - 1] = 0;
}

void Patient::showdata()
{
    cout << "\nRegistration number of patient: " << reg_no << "\n";
    Display_info();
    cout << "\nOccupation : " << occupation;
    cout << "\nAdmit date : " << date_admit;
    cout << "\nDischarhge date :" << date_discharge;
    cout << "\nBill :" << total;
    cout << "\nPrescribed Medicine: " << medicine;
}

int Patient::retidno()
{
    return reg_no;
}

void Patient::modify_medicine(int n)
{
    bool found = false;
    Patient p;
    fstream File;
    File.open("patient.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    while (!File.eof() && found == false)
    {

        File.read(reinterpret_cast<char *>(&p), sizeof(Patient));
        if (p.retidno() == n)
        {
            p.showdata();
            cout << "\n\nPlease Enter The Medicine of patient" << endl;
            cin >> p.medicine;
            int pos = (-1) * static_cast<int>(sizeof(p));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&p), sizeof(Patient));
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

void Patient::write_patient() // writing into file
{
    Patient p;
    ofstream outFile;
    outFile.open("patient.dat", ios::binary | ios::app);
    p.getdata();
    outFile.write(reinterpret_cast<char *>(&p), sizeof(Patient));
    outFile.close();
    cout << "\n\nPatient record Has Been Created ";
    cin.ignore();
    cin.get();
}

void Patient::display_all() // reading from file
{
    Patient p;
    ifstream inFile;
    inFile.open("patient.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    while (inFile.read(reinterpret_cast<char *>(&p), sizeof(Patient)))
    {
        p.showdata();
        cout << "\n\n=======================================================================================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void Patient::display_p(int n) // reading specific file
{
    Patient p;
    ifstream inFile;
    inFile.open("patient.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag = false;
    while (inFile.read(reinterpret_cast<char *>(&p), sizeof(Patient)))
    {
        if (p.retidno() == n)
        {
            p.showdata();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\nrecord not exist";
    cin.ignore();
    cin.get();
}

void Patient::modify_patient(int n) // modifying patient details
{
    bool found = false;
    Patient p;
    fstream File;
    File.open("patient.dat", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    while (!File.eof() && found == false)
    {

        File.read(reinterpret_cast<char *>(&p), sizeof(Patient));
        if (p.retidno() == n)
        {
            p.showdata();
            cout << "\n\nPlease Enter The New Details of patient" << endl;
            p.getdata();
            int pos = (-1) * static_cast<int>(sizeof(p));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&p), sizeof(Patient));
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

void Patient::delete_patient(int n) // deleting a particular file
{
    Patient p;
    ifstream inFile;
    inFile.open("patient.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream outFile;
    outFile.open("Temp.dat", ios::out);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char *>(&p), sizeof(Patient)))
    {
        if (p.retidno() != n)
        {
            outFile.write(reinterpret_cast<char *>(&p), sizeof(Patient));
        }
    }
    outFile.close();
    inFile.close();
    remove("patient.dat");
    rename("Temp.dat", "patient.dat");
    cout << "\n\n\tRecord Deleted ..";
    cin.ignore();
    cin.get();
}