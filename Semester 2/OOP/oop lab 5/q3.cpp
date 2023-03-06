//LAB TASK QUESTION#03
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class bank
{
    string name, AT; //name, account type
    float B, interest , WD, D; //balance, withdraw, deposit
    static int trans; //static so that transactions keep updating
    int AN, RateofInt, y; //account number, rate of interest, year
    public:
    bank() //default constructor
    {      }
    bank(string name, string AT, int AN, float B)  //parametrized constructor
    {
        this->name=name;
        this->AT=AT;
        this->AN=AN;
        this->B=B;
    }
    void getBal() //getter to get balance
    {
        cout<<"Balance: "<<B<<endl;
    }
    void Trans() //function for transactions
    {
        cout<<"Number of Transactions at the moment: "<<trans<<endl;
        trans=trans+1;
    }
    void setinterest() //setter to the store interest
    {
    	cout<<"Enter total number of years for calculating interest: ";
    	cin>>y;
    	cout<<"Enter rate of interest: ";
    	cin>>RateofInt;
    	interest=(B*y*RateofInt)/100; //formula for calculating interest
	}
	void getinterest() //getter to get interest
	{
		cout<<"Interest: "<<interest<<endl;
	}
	void addinterest() //funtion 2 to update the balance by adding interest into current balance
	{
		
		B=B+interest;
        cout<<"Balance after adding interest becomes:"<<endl;
		getBal();
	} 
    void Deposit() //function for making deposit
    {
        int d;
        cout<<"How much amount do you wanna deposit?";
        cin>>d;
        if(d<0)
        {
            cout<<"Error";
        }
        else
        {
            B=B+d;
        }
    cout<<"Balance after deposit becomes:"<<endl;
	getBal();   
    }
    void Withdraw() //function for withdrawal
    {
        int wd;
        cout<<"How much amount do you wanna with draw withdraw: ";
        cin>>wd;
        if(wd<0)
        {
            cout<<"Error";
        }
        else
        {
            B=B-wd;
        }
    cout<<"Balance after withdraw becomes:"<<endl;
	getBal(); 
    }
    void display()
    {
        cout<<"NAME:  "<<name<<endl;
        cout<<"ACCOUNT NUMBER:  "<<AN<<endl;
        cout<<"ACCOUNT TYPE:  "<<AT<<endl;
        cout<<"BALANCE: "<<B<<endl;
    }
};
int bank::trans=0;

int main()
{
   string Name, AccType;
   float bal;
   int  AccNo;
   cout<<"Enter your account name: ";
   cin>>Name;
   cout<<"What's your account type? ";
   cin>>AccType;
   cout<<"What's your account number? ";
   cin>>AccNo;
   cout<<"Enter the balance in your account: ";
   cin>>bal;
   bank b1(Name,AccType, AccNo, bal);   //calling object of class bank and passing values 
   b1.Trans(); //calling transaction funtion
   int n; //variable for choice 
   while(1) 
  {	
   cout<<"                  BANK"<<endl; 
   cout<<"1. Make a deposit"<<endl; 
   cout<<"2. Make a withdrawal"<<endl; 
   cout<<"3. Display the interest"<<endl; 
   cout<<"4. Display all the details"<<endl;
   cout<<"5. Exit the program"<<endl;
   cout<<"Enter your choice: ";
   cin>>n;
    if(n==1)
   		{
   			b1.Deposit(); //calling deposit function 
   			b1.Trans(); //calling transaction function to update the transactions
		}	
	else if(n==2)
   		{
   			b1.Withdraw(); //calling deposit function 
   			b1.Trans(); //calling transaction function to update the transactions
		}		
	else if(n==3)
   		{
            b1.setinterest();    
   			b1.getinterest(); 
            b1.addinterest();   
		}
    else if(n==4)
        {
            b1.display();
        }    
	else if(n==5)
   		{
   			break;
		}	
   		
   }
}
