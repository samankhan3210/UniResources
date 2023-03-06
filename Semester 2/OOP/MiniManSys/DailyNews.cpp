//mini management system
#include<iostream>
#include"Reporter.h"
#include"Editor.h"
#include"Employee.h"
using namespace std;
int main()
{
    Reporter r1("rep123","Alam");
    Editor e1("ed123","Talat");
    string n= r1.submitNews();
    e1.receiveNews(n);
}