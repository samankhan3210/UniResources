#include<iostream>
#include<string.h>
using namespace std;

template<class T, class U>
class Addition
{
    public:
    T x;
    U y;
    Addition(T x, U y)
    {
        this->x=x;
        this->y=y;
    }
    void add()
    {
        cout<<x+y<<endl;
    }
};

template<>
class Addition<char*, char*>
{
    public:
    char* a; 
    char* b;
    Addition(char* a, char* b)
    {
        this->a=a;
        this->b=b;
    }
    void concatenate()
    {
        cout<<a;
        cout<<b;
        // char *c;
        // strcpy(c,a);
        // strcat(c,b);
        // return c;
    }
};

int main()
{
    Addition<int, float> a1(10,0.23);
    a1.add();
    Addition<char*, char*> a2("Now","Then");
    a2.concatenate();
    //cout<<a2.concatenate()<<endl;
}