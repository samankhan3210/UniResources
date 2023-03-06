#include<iostream>
using namespace std;

template<class T>
T swap(T *a, T *b) 
{
    T *c=a;
    a=b;
    b=c;
}

int main()
{
    int x1, y1, ch;
    float x2, y2;
    char x3, y3;
    cout<<endl;
    cout<<"1. For int and int"<<endl;
    cout<<"2. For float and float"<<endl;
    cout<<"3. For char and char"<<endl;
    cout<<"Enter your choice : ";
    cin>>ch;
    if(ch==1)
    {
        cout<<"Enter first value (int) : ";
        cin>>x1;
        cout<<"Enter second value (int): ";
        cin>>y1;
        cout<<"Before swapping : a = "<<x1<<"\t b = "<<y1<<endl;
        swap(x1,y1);
        cout<<"After swapping : a = "<<x1<<"\t b = "<<y1<<endl;
    } 
    else if(ch==2)
    {
        cout<<"Enter first value (float) : ";
        cin>>x2;
        cout<<"Enter second value (float): ";
        cin>>y2;
        cout<<"Before swapping : a = "<<x2<<"\t b = "<<y2<<endl;
        swap(x2,y2);
        cout<<"After swapping : a = "<<x2<<"\t b = "<<y2<<endl;
    } 
    else if(ch==3)
    {
        cout<<"Enter first value (char) : ";
        cin>>x3;
        cout<<"Enter second value (char): ";
        cin>>y3;
        cout<<"Before swapping : a = "<<x3<<"\t b = "<<y3<<endl;
        swap(x3,y3);
        cout<<"After swapping : a = "<<x3<<"\t b = "<<y3<<endl;
    }
    else if(ch>=4)
    {
        cout<<"Invalid Choice ";
    }
}