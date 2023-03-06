#include "Q3class.cpp"
#include<iostream>
#include<string>

using namespace std;

int main()
{
    int y, y1, p, p1;
    string mn, colr, mn1, colr1;
    cout<<"Enter model, color, year, and price of the car :";
    cin>>mn>>colr>>y>>p;
    Car c1(mn,colr,y,p);
    cout<<"CAR 1 DETAILS"<<endl;
    c1.Display();
    Car c2(c1);
    cout<<"CAR 2 DETAILS"<<endl;
    c2.Display();
    Car c3;
    c3=c1;
    cout<<"CAR 3 DETAILS"<<endl;
    c3.Display();
}
