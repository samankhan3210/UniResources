//LAB TASKS#03 QUESTION#05
#include<iostream>
using namespace std;
class bank
{
    float B, interest , WD, D; //balance, withdraw, deposit
    static int trans; //static so that transactions keep updating
    int RateofInt, y; //rate of interest, year
    public:
    void setBal() //setter 1 to store balance
    {
        int b;
        cout<<"Whtat's the balance in your account? ";
        cin>>b;
        if(b<0)
        {
            cout<<"Error";
        }
        else
        {
            B=b;
        }
    }
    void getBal() //getter 1 to get balance
    {
        cout<<"Balance in Account: "<<B<<endl;
    }
    void Trans() //function 1 for transactions
    {
        cout<<"Total Transactions: "<<trans<<endl;
        trans=trans+1;
    }
    void setinterest() //setter 2 to the store interest
    {
    	cout<<"Enter total number of years for calculating interest: ";
    	cin>>y;
    	cout<<"Enter rate of interest: ";
    	cin>>RateofInt;
    	interest=(B*y*RateofInt)/100; //formula for calculating interest
	}
	void getinterest() //getter 2 to get interest
	{
		cout<<"Interest: "<<interest<<endl;
	}
	void addinterest() //funtion 2 to update the balance by adding interest into cureent balance
	{
		
		B=B+interest;
		getBal();
	} 
    void Deposit() //function 3 for depositing
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
    }
    void Withdraw() //function 4 for withdrawing
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
    }
};
int bank::trans=0;

int main()
{
   bank b1; //object of class bank
   b1.setBal(); //calling setter 1
   b1.setinterest(); //calling setter 2
   int n; //variable for choice 
   while(1) 
  {	
   cout<<"     STANDARD CHARTED BANK"<<endl;
   cout<<"1. Display the account balance"<<endl;
   cout<<"2. Display the number of transactions"<<endl; 
   cout<<"3. Display interest earned for this period"<<endl; 
   cout<<"4. Make a deposit"<<endl; 
   cout<<"5. Make a withdrawal"<<endl; 
   cout<<"6. Add interest for this period"<<endl; 
   cout<<"7. Exit the program"<<endl;
   cout<<"Enter your choice: ";
   cin>>n;
   if(n==1)
   		{
   			b1.getBal(); //calling getter 1
		}
	else if(n==2)
   		{
   			b1.Trans(); //calling function 1 for transactions
		}
	else if(n==3)
   		{
   			b1.getinterest(); //calling getter 2
		}
	else if(n==4)
   		{
   			b1.Deposit(); //calling function 3
   			b1.getBal(); //calling getter 1 to update the balance
   			b1.Trans(); //calling function 1 to update the transaction
		}		
	else if(n==5)
   		{
   			b1.Withdraw(); //calling function 4
   			b1.getBal(); //calling getter 1 to update the balance
   			b1.Trans(); //calling function 1 to update the transaction
		}	
	else if(n==6)
   		{
   			b1.addinterest(); //calling function 2 to display the new balance after adding interest
		}	
	else if(n==7)
   		{
   			break;
		}	
   		
   }
}
