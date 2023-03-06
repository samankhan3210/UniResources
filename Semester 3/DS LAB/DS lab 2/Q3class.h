#ifndef Q3CLASS_H
#define Q3CLASS_H

#include<string>

using namespace std;

class Car
{
    int year,price;
    string MN, color;
    public:
    Car();
    Car(string MN, string color, int year, int price);
    ~Car();
    Car(const Car& ob);
    void operator=(const Car& ob);
    void Display();
};

#endif