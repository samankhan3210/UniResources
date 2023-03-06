#include<iostream>
#include<string.h>
using namespace std;
class Bank
{
    protected:
    int x;
    public:
    int getBalance() 
    {
        return 0;
    }
};
class BankA: public Bank
{
    public:
    BankA(int x)
    {
        this->x=x;
    }
    int getBalance() 
    {
        return x;
    }
};
class BankB: public Bank
{
    public:
    BankB(int x)
    {
        this->x=x;
    }
    int getBalance() 
    {
        return x;
    }
};
class BankC: public Bank
{
    public:
    BankC(int x)
    {
        this->x=x;
    }
    int getBalance() 
    {
        return x;
    }
};
int main()
{
    int a, b, c;
    cout<<"Enter balance 1: ";
    cin>>a;
    cout<<"Enter balance 2: ";
    cin>>b;
    cout<<"Enter balance 3: ";
    cin>>c;
    BankA A(a);
    cout<<"Amount deposited in bank A: "<<"$"<<A.getBalance()<<endl;
    BankB B(b);
    cout<<"Amount deposited in bank B: "<<"$"<<B.getBalance()<<endl;
    BankC C(c);
    cout<<"Amount deposited in bank C: "<<"$"<<C.getBalance()<<endl;
}

