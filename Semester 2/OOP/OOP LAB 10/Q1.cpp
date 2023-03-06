//LAB 10 QUESTION#01
#include<iostream>
using namespace std;

class Marks
{
    public:
    Marks()
    {}
    virtual float getPercentage()=0;
};

class A: public Marks
{
    float biology, physics, chemistry, percentage;
    public:
    A(int biology, int physics, int chemistry)
    {
        this->biology=biology;
        this->physics=physics;
        this->chemistry=chemistry;
    }
    float getPercentage()
    {
        percentage=((biology+physics+chemistry)/300)*100;
        return percentage;
    }
    void display1()
    {
        cout<<"\t\t\t\tRESULT OF STUDENT A"<<endl;
        cout<<"BIOLOGY : "<<biology<<endl;
        cout<<"PHYSICS : "<<physics<<endl;
        cout<<"CHEMISTRY : "<<chemistry<<endl;
        cout<<"PERCENTAGE : "<<getPercentage()<<endl;
    }
};

class B: public Marks
{
    float english, maths, physics, chemistry, percentage;
    public:
    B(int english, int maths, int physics, int chemistry)
    {
        this->english=english;
        this->maths=maths;
        this->physics=physics;
        this->chemistry=chemistry;
    }
    float getPercentage()
    {
        percentage=((english+maths+physics+chemistry)/400)*100;
        return percentage;
    }
    void display2()
    {
        cout<<"\t\t\t\tRESULT OF STUDENT B"<<endl;
        cout<<"ENGLISH : "<<english<<endl;
        cout<<"MATHS : "<<maths<<endl;
        cout<<"PHYSICS : "<<physics<<endl;
        cout<<"CHEMISTRY : "<<chemistry<<endl;
        cout<<"PERCENTAGE : "<<getPercentage()<<endl;
    }
};

int main()
{
    int b, p1, c1, e, m, p2, c2;
    cout<<"Enter biology marks of student A : ";
    cin>>b;
    cout<<"Enter physics marks of student A : ";
    cin>>p1;
    cout<<"Enter chemistry marks of student A : ";
    cin>>c1;
    cout<<"Enter english marks of student B : ";
    cin>>e;
    cout<<"Enter maths marks of student B : ";
    cin>>m;
    cout<<"Enter physics marks of student B : ";
    cin>>p2;
    cout<<"Enter chemistry marks of student B : ";
    cin>>c2;
    A a1(b,p1,c1);
    a1.getPercentage();
    a1.display1();
    B b1(e,m,p2,c2);
    b1.getPercentage();
    b1.display2();
}