#include<iostream>
#include<string.h>
using namespace std;
class Member
{
    string s1;
    public:
    Member(string s1)
    {
        this->s1=s1;
    }
    void print() 
    {
        cout<<"Your string is: "<<s1<<endl;
    }
    void print(string a)
    {
        cout<<"Old string: "<<s1<<endl<<"New string: "<<a<<endl;
    }
};
int main()
{
    string s,NS;
    cout<<"Enter a string: ";
    cin>>s;
    Member m1(s);
    m1.print();
    cout<<"Enter a new string: ";
    cin>>NS;
    m1.print(NS);
}