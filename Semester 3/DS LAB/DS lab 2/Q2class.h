#ifndef Q2CLASS_H
#define Q2CLASS_H

#include<string>

using namespace std;

class Student
{
    int n, batch, YoG;
    string id, discipline, currCourses[7];
    public:
    Student();
    void Data();
    void Display();
};

#endif