#include "Q2class.cpp"

using namespace std;

int main()
{
    int a, i, x;
    cout<<"Enter the number of students : ";
    cin>>a;
    Student* s=new Student[a];
    for(i=0; i<a; i++)
    {
        cout<<"Student "<<i+1<<" Data : "<<endl;
        (s+i)->Data();
        cout<<endl;
    }
    cout<<"Enter the student number whose data you want to display : ";
    cin>>x;
    x=x-1;
    if(x>=a || x<0)
    {
        cout<<"Index out of bound : "<<endl;
    }
    else
    {
        cout<<"Student "<<x+1<<" : "<<endl;
        (s+x)->Display();
    }
}