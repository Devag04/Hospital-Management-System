#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <map>
#include <queue>
#include <climits>
#include <set>
#include <map>
#include <functional>
#include<algorithm>
using namespace std;

class Patient : public Person {
    int reg_no;
    char occupation[30];
    char date_admit[30];
    char date_discharge[30];
    int bill, total;

public:
    char medicine[100];

    void patient_bill();
    void getdata();          // function to accept data from user
    void showdata();         // function to show data on screen
    int retidno();
    void modify_medicine(int n);
    void write_patient();       // write the record in file
    void display_all();         // read all records from file
    void display_p(int n);      // accept reg_no and read record from file
    void modify_patient(int n); // accept reg_no and update record of file
    void delete_patient(int n); // accept reg_no and delete selected records from file
};

#endif
