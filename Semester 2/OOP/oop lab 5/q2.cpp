//LAB TASK QUESTION#02
#include <iostream> 
#include <string> 
#include<iomanip>
using namespace std; 
class Hotel
{
	const float RPD; //rent per day
    const string name; 
    int days; 
    float TR; //total rent
    public: 
    Hotel(string name, int days):name(name), RPD(1000.85) //constructor
    {
        this->days=days;
        
    }
    void CalculateTotalRent()  //function to calculate the rent
    {
        if(days<=7)
        TR=days*RPD;
        else
        {
            TR=(days-1)*RPD;
        }
    }
    void display()  //function to display the customer's data
    {
    	cout<<"\t\tCUSTOMER'S INFORMATION"<<endl;
        cout<<"Name of the Customer: "<<name<<endl; 
        cout<<"No.of Days Spent at the Hotel: "<<days<<endl;
        cout<<"Total Rent: "<<fixed<<setprecision(2)<<TR<<endl;
    }
}; 

int main()
{
    string n; 
    int d; 
    cout<<"Enter the customer's name: "; 
    cin>>n; 
    cout<<"Enter the number of total days spent at the hotel: "; 
    cin>>d; 
    Hotel h1(n,d); //object 1
    h1.CalculateTotalRent();  //calling function 1 to calculate the total tent
    h1.display(); //calling display function to display the data
}