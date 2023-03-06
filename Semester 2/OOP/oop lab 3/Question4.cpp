//LAB TASKS#03 QUESTION#04
#include<iostream>
#include<string>
using namespace std;
class CounterType
{
	int count; //variable for storing count number
	public:
	void setCount() //setter to store the count
	{
		cout<<"Enter the counter number: ";
		cin>>count;
		this->count=count;
		if(count>0)
		{
			this->count=count;
		}
		else
		{
			cout<<"ERROR"<<endl;
		}
	}
	void IncreaseC() //function 1  to increment counter by 1
	{
		count++;
	}
	void DecreaseC() //function 1  to decrement counter by 1
	{
		count--;
	}
	int getCount() //getter to get the count 
	{
		return count;
	}
	void ShowC() //function 3 to display the count 
	{
		cout<<"Count= "<<count<<endl;
	}
};
int main()
{
    int x;
	CounterType c1; //object of class CounterType
	c1.setCount(); //callin setter function
    while(1)
    {
	cout<<"1. Increment The Counter"<<endl;
    cout<<"2. Decrement The Counter"<<endl;
    cout<<"3. Display The Count Number"<<endl;
    cout<<"4. Stop"<<endl;
    cout<<"What do you wanna do? "<<endl;
	cin>>x;
    if(x==1)
    {
        c1.IncreaseC(); //calling function 1 to increment the count number
    }
    else if(x==2)
     {
        c1.DecreaseC(); //calling function 2 to decrement the count number 
     }
    else if(x==3)
     {
         c1.ShowC(); //calling function 3 to display the current count number
     }
    else if(x==4)
     {
         break;
     }
    }
}
	

