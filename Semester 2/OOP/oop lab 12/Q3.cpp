#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Person
{
    string name;
    int age;
    public:
    Person()
    {}
    Person(string n, int a)
    {
        name=n;
        age=a;
    }
    void display()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
    }
};

int main()
{
    string N;
    int A;
    cout<<"Enter Name : ";
    cin>>N;
    cout<<"Enter Age : ";
    cin>>A;
    Person person1(N,A);
    Person person2;
    ofstream per("person.bin", ios::app);
    per.write((char*) &person1, sizeof(person1));
    per.close();
    ifstream perf("person.bin");
    perf.read((char*) &person2, sizeof(person2));
    person2.display();
    perf.close();
}