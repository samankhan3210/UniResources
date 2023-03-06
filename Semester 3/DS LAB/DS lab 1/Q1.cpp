#include <iostream> 
#include <string.h> 
using namespace std; 

class Student
{
    string name;
    string id;
    int marks;
    public:
    Student()
    {}
    void setData()
    {
        cout<<"Enter student name : ";
        cin>>name;
        cout<<"Enter student id : ";
        cin>>id;
        cout<<"Enter student marks : ";
        cin>>marks;
    }
    void Display()
    {
        cout<<"Student name : "<<name<<endl;
        cout<<"Student id : "<<id<<endl;
        cout<<"student marks : "<<marks<<endl;
    }
    bool operator < (const Student* s)
    {
        return name < s->name;
    }
};

void Swapping(Student *a, Student *b)  
{  
    Student temp;
    temp=*a;  
    *a=*b;  
    *b=temp;  
}

int main()
{
    Student* S=new Student[5];
    int i=0, j=0;
    for(i=0 ; i<5 ; i++)
    {
        (S+i)->setData();
    }
    cout<<"Before Sorting"<<endl;
    for(i=0 ; i<5 ; i++)
    {
        (S+i)->Display();
    }
    for(i=0 ; i<5 ; i++)
    {
        for(j=0 ; j<5-i ; j++)
        {
            if ((S+i)->operator<((S+i+j)))
            {
                Swapping((S+i),(S+i+j));
            }
        }
    }
    cout<<"After Sorting"<<endl;
    for(i=0 ; i<5 ; i++)
    {
        (S+i)->Display();
    }
    delete []S;   
}