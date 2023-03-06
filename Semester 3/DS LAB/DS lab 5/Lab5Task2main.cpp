#include"Lab5Task2.cpp"
#include<iostream>

using namespace std;

int main()
{
    LinkedList ob1;
    LinkedList ob2;
    int i;
    float a[12];
    cout<<"Enter 12 numbers in the list : "<<endl;
    for(i=0; i<12; i++)
    {
        cout<<i+1<<". ";
        cin>>a[i];
        ob1.add_node(a[i]);
    }
    Four(ob1,ob2);
    cout<<"List Before Calculating the Average  : "<<endl;
    ob1.Print();
    cout<<"List After Calculating the Average  : "<<endl;
    ob2.Print();
}