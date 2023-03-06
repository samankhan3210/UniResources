//LAB TASKS#01 QUESTION#01
#include<iostream>
#include<iomanip>
using namespace std;
class person
{
	float kg; //var 1 for storing weight in kg
	float pounds; //var 2 for storing weight in pounds
	public:
	person() //default constructor
	{		}	
	void setWeight(float w) //setter function for weight in kg
	{
		kg=w;
	}
	float getWeight() //getter function to get weight in kg
	{
		cout<<"Weight in kg= "<<fixed<<setprecision(2)<<kg<<endl; //method to display the weight in kg with two decimal places
	}
	float Pounds() //function to display weight in pounds
	{
		pounds=kg*2.2;
		cout<<"Weight in pounds= "<<fixed<<setprecision(2)<<pounds<<endl; //method to display the weight in pounds with two decimal places
	}
};
int main()
{
	float w; //variable for storing user inputted weight
	person ob;
	cout<<"\nEnter the weight of the person in kg: ";
	cin>>w;
	ob.setWeight(w); //calling setter function
	ob.getWeight(); //calling getter function
	ob.Pounds(); //calling Pounds function to display weight in pounds
	return 0;
}
