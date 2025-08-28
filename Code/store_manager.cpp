#include "store_manager.h"

void store_manager::SInfo()
{
    staff_info();
    cout << "Enter Receptionist ID :";
    cin >> SID;
}

void store_manager::show_StoreManager()
{
    show_staff();
    cout << "Store Manager ID: " << SID;
}

void store_manager::orderproducts()
{
    cout << "\n\n|----------- ORDER Products & SUPPLIES ----------|" << endl << endl;

    cout << "Enter Product Name: ";
    cin >> productName;
    cout << "\nEnter Supplier's Name: ";
    cin >> supplierName;
    cout << "\nEnter Number of Unit: ";
    cin >> unit;
    cout << "\nEnter Total bill: ";
    cin >> bill;

    ofstream fout("Products&Supplies.txt", ios::app);
    fout << "Product Name: " << productName << endl;
    fout << "Supplier's Name: " << supplierName << endl;
    fout << "Number of Unit: " << unit << endl;
    fout << "Total Bill: " << bill << endl << endl;
    fout.close();

    cout << "\n\nPRODUCT ORDERED SUCCESSFULLY!!" << endl << endl;

    int choice;
    cout << "Do you want to order more?" << endl;
    cout << "(1) Yes" << endl;
    cout << "(2) No" << endl << endl;
    cin >> choice;

    if (choice == 1)
    {
        system("cls");
        orderproducts();
    }
}

void store_manager::readFromFile()
{
    ifstream fin("Products&Supplies.txt");
    string str;
    if (!fin)
    {
        cout << "\nERROR LOADING FILE!!" << endl;
        return;
    }
    while (getline(fin, str))
    {
        cout << str << endl;
    }
    cout << endl << endl;
    fin.close();
    cin.get();
    system("pause");
}

void store_manager::write_store_manager()
{
    store_manager s;
    ofstream outFile("StoreManager.dat", ios::binary | ios::app);
    s.SInfo();
    outFile.write(reinterpret_cast<char *>(&s), sizeof(store_manager));
    outFile.close();
    cout << "\n\nrecord Has Been Created ";
    cin.ignore();
    cin.get();
}

void store_manager::display_all_storeManager()
{
    store_manager s;
    ifstream inFile("StoreManager.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    while (inFile.read(reinterpret_cast<char *>(&s), sizeof(store_manager)))
    {
        s.show_StoreManager();
        cout << "\n\n=======================================================================================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void store_manager::display_s(int n)
{
    store_manager s;
    ifstream inFile("StoreManager.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag = false;
    while (inFile.read(reinterpret_cast<char *>(&s), sizeof(store_manager)))
    {
        if (s.SID == n)
        {
            s.show_StoreManager();
            flag = true;
        }
    }
    inFile.close();
    if (!flag)
        cout << "\n\nrecord not exist";
    cin.ignore();
    cin.get();
}

void store_manager::store_manager_choice()
{
    char ch;
    do
    {
        int n;
        system("cls");

        cout << "\n\n\t01. Order Products ";
        cout << "\n\n\t02. Show Order Products & Bills ";
        cout << "\n\n\t03. To exit.....";
        cout << "\n\n\tPlease Select Your Option (1-3) ";
        cin >> ch;

        switch (ch)
        {
        case '1': orderproducts(); break;
        case '2': readFromFile(); break;
        case '3': break;
        default: cout << "\b";
        }
    } while (ch != '3');
}

void store_manager::store_manager_menu()
{
    char ch;
    do
    {
        int n;
        system("cls");

        cout << "\n\n\t01. INSERT STORE MANAGER DATA";
        cout << "\n\n\t02. Search STORE MANAGER ";
        cout << "\n\n\t03. ALL STORE MANAGER ";
        cout << "\n\n\t04. To exit this menu";
        cout << "\n\n\tPlease Select Your Option (1-4) ";
        cin >> ch;

        switch (ch)
        {
        case '1': write_store_manager(); break;
        case '2':
            cout << "Enter STORE MANAGER ID :";
            cin >> n;
            display_s(n);
            break;
        case '3': display_all_storeManager(); break;
        case '4': break;
        default: cout << "\b";
        }
    } while (ch != '4');
}
