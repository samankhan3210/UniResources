#include "Q3class.h"
#include <iostream>
#include <string>

using namespace std;

Car::Car()
{
}

Car::Car(string MN, string color, int year, int price)
{
    this->MN=MN;
    this->color=color;
    this->year=year;
    this->price=price;
}

void Car::operator=(const Car& ob)
{
    MN=ob.MN;
    color=ob.color;
    year=ob.year;
    price=ob.price;
    cout<<"Copy Assignment Operator Called."<<endl;
}

Car::Car(const Car& ob)
{
    MN=ob.MN;
    color=ob.color;
    year=ob.year;
    price=ob.price;
    cout<<"Copy Constructor Called."<<endl;
}

Car::~Car()
{
    cout<<"Object Destroyed!!"<<endl;
}

void Car::Display()
{
    cout<<"Model : "<<MN<<endl;
    cout<<"Color : "<<color<<endl;
    cout<<"Year : "<<year<<endl;
    cout<<"Price : "<<price<<endl;
}