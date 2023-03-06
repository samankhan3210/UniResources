#include "Q2class.h"
#include <iostream>
#include <string>

using namespace std;

Student::Student()
{}

void Student::Data()
{
    cout<<"Enter student id : ";
    cin>>id;
    cout<<"Enter student batch : ";
    cin>>batch;
    cout<<"Enter student discipline : ";
    cin>>discipline;
    cout<<"Enter student expected year of graduation : ";
    cin>>YoG;
    cout<<"Enter how many courses the student is currently enrolled in : ";
    cin>>n;
    cout<<"Enter the name of the courses he/she is enrolled in : "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter the name of course "<<i+1<<" : ";
        cin>>currCourses[i];
    }
}

void Student::Display()
{
    cout<<"ID : "<<id<<endl;
    cout<<"Batch : "<<batch<<endl;
    cout<<"Discipline : "<<discipline<<endl;
    cout<<"Expected Year of Graduation : "<<YoG<<endl;
    cout<<"Current Courses: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<i+1<<". "<<currCourses[i]<<endl;
    }
}