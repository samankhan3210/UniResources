#include<iostream>
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
    string id, name;
     public:
     Employee(void);
     Employee(string, string);
     string getID();
     string getName();
};
#endif