//LAB TASK QUESTION#01
#include <iostream> 
#include <string> 
using namespace std; 
class Employee
{
    string EmployeeName; 
    const int EmployeeID; 
    public:
    Employee(string EmployeeName, int EmployeeID):EmployeeID(EmployeeID) //construtor
    {
        this->EmployeeName=EmployeeName; 
    }
    void display() //function to display data
    {
        cout<<"Employee's Name: "<<EmployeeName<<endl;
        cout<<"Employee's ID: "<<EmployeeID<<endl;
    }
    void updatename() //function to change  name
    {
    	string n;
        cout<<"Enter the new name: "; 
        cin>>n;
        EmployeeName=n;
    }
};

int main ()
{
    string n1, n2, n3, N1, N2, N3; 
    int x, y, id1, id2, id3; 
    cout<<"Enter the name of employee number one: "; 
    cin>>n1; 
    cout<<"Enter the ID of employee number one: "; 
    cin>>id1;
    Employee e1(n1, id1);   //object 1
    cout<<"Enter the name of employee number two: "; 
    cin>>n2; 
    cout<< "Enter the ID of employee number two: "; 
    cin>>id2;
    Employee e2(n2, id2);   //object 2
    cout<<"Enter the name of employee number three: "; 
    cin>>n3; 
    cout<< "Enter the ID of employee number three: "; 
    cin>> id3;  
    Employee e3(n3, id3);    //object 3
    while(1)
    {
    cout<<"Press 1 to display data or press 2 to update the name of employees or press 3 to end the program"<<endl;
    cin>>x;
    if(x==1)
	{
	cout<<"\t\tEMPLOYEE 1 DATA:-"<<endl;
    e1.display();  //calling display function to display employee's 1 data
	cout<<"\t\tEMPLOYEE 2 DATA:-"<<endl;    
    e2.display();  //calling display function to display employee's 2 data
	cout<<"\t\tEMPLOYEE 3 DATA:-"<<endl;
    e3.display();	//calling display function to display employee's 3 data
	}
    else if(x==2)
    {
    cout<<"Press 1 to update employee's one name or 2 to update employee's two name or 3 to update employee's two name or 4 if you don't want to update any ";	
    cin>>y;
	if(y==1)
	{     e1.updatename();  //calling update function to change employee's 1 name 
    }
    else if(y==2)
    {     e2.updatename();   //calling update function to change  employee's 2 name
    }
    else if(y==3)
    {     e3.updatename();    //calling update function to change  employee's 3 name  
     }
    else if(y==4)
    {    break;	}
	}
    if(x==3)
    {
    	break;
	}
}
}