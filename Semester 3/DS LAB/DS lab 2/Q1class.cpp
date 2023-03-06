#include "Q1class.h"
#include <iostream>
#include <cmath>

using namespace std;

QuadraticEquation::QuadraticEquation()
{
    cout<<"Enter the value of coefficients a, b, and c: ";
    cin>>a>>b>>c;
    cout<<"a : "<<a<<"\t b : "<<b<<"\t c : "<<c<<endl;
}

void QuadraticEquation::Calculate()
{
    d=(b*b)-(4*a*c);
    if(d==0)
    {
        x1=(-b+sqrt(d))/(2*a);
        cout<<"x1 = "<<x1<<"\t x2 = "<<x1<<endl;
        cout<<"Roots are real and equal"<<endl;
    }
    else if(d>0)
    {
        x1=(-b+sqrt(d))/(2*a);
        x2=(-b-sqrt(d))/(2*a);
        cout<<"x1 = "<<x1<<"\t x2 = "<<x2<<endl;
        cout<<"Roots are real and distinct"<<endl;
    }
    else if(d<0)
    {
        p=-b/(2*a);
        q=sqrt(-d)/(2*a);
        cout<<"x1 = " <<p<< "+" <<q<<"i"<<"\t x2 = "<<p<<"-"<<q<<"i"<< endl;
        cout<<"Roots are complex and distinct"<<endl;
    }
}