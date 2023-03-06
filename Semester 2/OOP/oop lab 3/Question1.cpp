//LAB TASK#03 QUESTION#01 
#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class Account
{
    string name; //variable for storing customer's name
    int AN; //variable for storing account number
    float B; //variable for toring balance
    public:
    void setName() //setter 1 to store name
    {
        cout<<"Enter the name: ";
        cin>>name;
    }
    void getName() // getter 1 to get name
    {
        cout<<name<<endl;
    }
    void setAmount() //setter 2 to store balance
    {
        cout<<"Enter present amount: ";
        cin>>B;
    }
    void Balance() //getter 2 to get balance
    {
        cout<<"Balance in the account: "<<B<<endl;
    }
    void Withdraw() //function 1 for withdrawal
    {
        float wd;
        cout<<"How much do you wanna withdraw?";
        cin>>wd;
        if(B<wd) //condition to check that there's enough money for withdrawal
        {
            cout<<"You don't have enough money to withdraw"<<endl;
        }
        else
        {
            B=B-wd;
        }
    }
    void Deposit() //function 1 for depositing money
    {
        float d;
        cout<<"How much do you wanna deposit?";
        cin>>d;
        if(d<0)
        {
            cout<<"Invalid ammount";
        }
        else
        {
            B=B+d;
        }
    }
};

int main()
{
    Account a1;
    a1.setName(); //calling setter 1
    a1.setAmount(); //calling setter 2
    int x;
    cout<<"\n Enter your choice: \n\(1)Name \n(2)Account Balance \n(3)Withdraw Money \n(4)Deposit Money \n";
    cin>>x;
    switch(x)
    {
    	case 1:
    		{
    			a1.getName(); //calling getter 1
    			break;
			}
		case 2:
		    {
		    	a1.Balance(); //calling getter 2
		    	break;
			}	
		case 3:
			{
				a1.Withdraw(); //calling funtion 1
				a1.Balance(); //calling getter 2
				break;
			}
		case 4:
			{
				a1.Deposit(); //calling funtion 2
				a1.Balance(); //calling getter 2
				break;		
	        }
	    default:
		{
			cout<<"Invalid choice" <<endl;
			break; 
	   }
    }
    

}
