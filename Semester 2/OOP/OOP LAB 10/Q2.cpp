//LAB 10 QUESTION#02
#include<iostream>
using namespace std;

class Bank
{
    public:
    Bank()
    {}
    virtual void getBalance()=0;
};

class BankA: public Bank
{ 
    static int balanceA;
    int withdraw;
    public:
    BankA()
    {}
    void getBalance()
    {
        cout<<"Enter the amount you want to withdraw from your account : ";
        cin>>withdraw;
        if (withdraw <= balanceA)
        {
            cout<<"Balance Before Withdrawal : $"<<balanceA<<endl;
            balanceA=balanceA-withdraw;
            cout<<"Amount Withdrawn : "<<withdraw<<endl;
            cout<<"Balance After Withdrawal : $"<<balanceA<<endl;
        }
        else
        {
            cout<<"Insufficient Balance"<<endl;
        }
    }
};
int BankA::balanceA=100;

class BankB: public Bank
{
   static int balanceB;
   int withdraw;
   public:
   BankB()
   {}
   void getBalance()
    {
        cout<<"Enter the amount you want to withdraw from your account : ";
        cin>>withdraw;
        if (withdraw <= balanceB)
        {
            cout<<"Balance Before Withdrawal : $"<<balanceB<<endl;
            balanceB=balanceB-withdraw;
            cout<<"Amount Withdrawn : "<<withdraw<<endl;
            cout<<"Remaining Balance : "<<balanceB<<endl;
        }
        else
        {
            cout<<"Insufficient Balance"<<endl;
        }
    }
};
int BankB::balanceB=150;

class BankC: public Bank
{
    static int balanceC;
    int withdraw;
    public:
    BankC()
    {}
    void getBalance()
    {
        cout<<"Enter the amount you want to withdraw from your account : ";
        cin>>withdraw;
        if (withdraw <= balanceC)
        {
            cout<<"Balance Before Withdrawal : $"<<balanceC<<endl;
            balanceC=balanceC-withdraw;
            cout<<"Amount Withdrawn : "<<withdraw<<endl;
            cout<<"Remaining Balance : "<<balanceC<<endl;
        }
        else
        {
            cout<<"Insufficient Balance"<<endl;
        }
    }
};
int BankC::balanceC=200;

int main()
{
    int x;
    do
    {
    cout<<"\t\t\t\t\tBANK A"<<endl;
    BankA BA;
    BA.getBalance();
    cout<<"\t\t\t\t\tBANK B"<<endl;
    BankB BB;
    BB.getBalance();
    cout<<"\t\t\t\t\tBANK C"<<endl;
    BankC BC;
    BC.getBalance();
    cout<<"Enter 1 to end the program else enter anyother number to continue : ";
    cin>>x;
    }
    while(x!=1);
}