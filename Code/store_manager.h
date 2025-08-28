#ifndef STORE_MANAGER_H
#define STORE_MANAGER_H

#include "Staff.h"   // because store_manager inherits Staff
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class store_manager : public Staff
{
private:
    string productName;
    string supplierName;
    int unit;
    int bill;
    int SID;

public:
    void SInfo();
    void show_StoreManager();
    void orderproducts();
    void readFromFile();

    void write_store_manager();
    void display_all_storeManager();
    void display_s(int n);

    void store_manager_choice();
    void store_manager_menu();
};

#endif
