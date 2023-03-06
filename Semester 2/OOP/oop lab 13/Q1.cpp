#include<iostream>
using namespace std;

template<class T1, class T2>
void display(T1 a, T2 b) 
{
    cout<<endl;
    cout<<"a = "<<a<<"\t b = "<<b<<endl;
    cout<<"Addition a+b : "<<(a+b)<<endl;
    cout<<"Subtraction a-b : "<<(a-b)<<endl;
    cout<<"Multiplication axb : "<<(a*b)<<endl;
    cout<<"Division a/b : "<<(a/b)<<endl;
}

int main()
{
    int x1, y1, ch;
    float x2, y2;
    cout<<endl;
    cout<<"1. For int and float"<<endl;
    cout<<"2. For float and int"<<endl;
    cout<<"3. For int and int"<<endl;
    cout<<"4. For float and float"<<endl;
    cout<<"Enter your choice : ";
    cin>>ch;
    if(ch==1)
    {
        cout<<"Enter first value (int) : ";
        cin>>x1;
        cout<<"Enter second value (float): ";
        cin>>y2;
        display(x1,y2);
    }
    else if(ch==2)
    {
        cout<<"Enter first value (float) : ";
        cin>>x2;
        cout<<"Enter second value (int): ";
        cin>>y1;
        display(x2,y1);
    }
    else if(ch==3)
    {
        cout<<"Enter first value (int) : ";
        cin>>x1;
        cout<<"Enter second value (int): ";
        cin>>y1;
        display(x1,y1);
    }
    else if(ch==4)
    {
        cout<<"Enter first value (float) : ";
        cin>>x2;
        cout<<"Enter second value (float): ";
        cin>>y2;
        display(x2,y2);
    }
    else if(ch>=5)
    {
        cout<<"Invalid Choice";
    }
}