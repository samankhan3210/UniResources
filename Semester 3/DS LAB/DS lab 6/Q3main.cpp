#include"Q3class.cpp"
#include<iostream>

using namespace std;

int main()
{
    CircularLL ob1;
    ob1.insertBeg(3);
    ob1.insertBeg(8);
    ob1.insertBeg(6);
    cout<<"After insertion at begining : "<<endl;
    ob1.Print();
    ob1.insertEnd(2);
    ob1.insertEnd(6);
    ob1.insertEnd(4);
    cout<<endl<<"After insertion at end : "<<endl;
    ob1.Print();
    ob1.DelBeg();
    ob1.DelEnd();
    cout<<endl<<"After deletion at end and begining : "<<endl;
    ob1.Print();
}