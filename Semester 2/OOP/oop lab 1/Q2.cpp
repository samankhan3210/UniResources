//LAB TASKS#01 QUESTION#02
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class Cinema
{
	int AT, CT, TT, T; //variables for adult ticket, child ticket, total tickets, tickets
	string MN; //Movie name
	float AD, AP, CP , NS, GA; //amount donated, adult ticket price, child ticket price, net sale, gross amount
	public:
	Cinema()
	{
		AT=0;
	    CT=0;
	    TT=5000; //hard coded values
		T=5000; 
		AP=0;
		CP=0;
	    GA=0;
	    AD=0;
	    NS=0;
	}
	void setMovieName() //setter 1 for movie name
	{
		cout<<"\n Enter the movie name: ";
		cin>>MN;
	}
	void setTicketPrice() //setter 2 for setting tickets prices
	{
		cout<<"Enter the price for an adult ticket: ";
		cin>>AP;
		cout<<"Enter the price for a child ticket: ";
		cin>>CP;
	}
	void getTicketPrice() //getter function to get tickets prices
	{
		cout<<"Adults ticket price: "<<AP<<endl;
		cout<<"Kids ticket price: "<<CP<<endl;
	}
	void setTicketInfo() //function 1 for tickets calculation 
	{
		int t,at,ct,x,y; 
		cout<<"Enter the number of adult tickets you wanna buy: ";
		cin>>at;
		cout<<endl<<"Enter the number of child tickets you wanna buy: ";
		cin>>ct;
		t=at+ct; //total tickets bought
		AT=AT+at;
		CT=CT+ct;
		TT=TT-t; //tickets left
		x=AT*AP; 
		y=CT*CP;
		GA=x+y;
		AD=GA*0.10; //formula for finding the amount donated 
		NS=GA-AD; //formula for calculating net sale
		if(TT<0)
			{
				cout<<"Not enough tickets left"<<endl;
				setTicketInfo();
			}
	}
	void ShowOutput() //funtion 2 for displaying the output
	{
		cout<<"\n Movie Name: ....................     "<<MN<<endl;
		cout<<"Number of Tickets Sold:............     "<<(T-TT)<<endl;
		cout<<"Gross Amount:...................... $ "<<fixed<<setprecision(2)<<GA<<endl;
		cout<<"Percentage of Gross Amount Donated:   10%"<<endl;
        cout<<"Amount Donated:.................... $ "<<fixed<<setprecision(2)<<AD<<endl;
		cout<<"Net Sale:.......................... $ "<<fixed<<setprecision(2)<<NS<<endl;	
	}
};
int main()
{
	Cinema ob; //object of class cinema
	ob.setMovieName(); //callling setter function for movie name
	ob.setTicketPrice(); //callling setter 2 
	ob.getTicketPrice(); //callling getter function 
	ob.setTicketInfo(); //calling function 1
	ob.ShowOutput();//calling function 2
	return 0;
}
