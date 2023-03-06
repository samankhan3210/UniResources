//LAB TASKS#03 QUESTION#02
#include<iostream>
#include <iomanip>
#include <string>
using namespace std;
class Employee
{
    string FN, LN; //variables for storing first name and last name
    float sal; //variable for storing salary
    public:
    void setInfo(string fn, string ln, float s) //constructor 
    {
        FN=fn;
        LN=ln;
        if(sal>0) //condition for checking salary
        {
        	sal=s;
		}
		else
		{
		    sal=0;
		}
    }
    void getFName() //getter 1 to get first name
    {
        cout<<"First Name:"<<FN<<endl;
    }
    void getLName() //getter 2 to get last name
    {
        cout<<"Last Name:"<<LN<<endl;
    }
    void getYSalary() //getter 3 to get yearlt salary
    {
        cout<<"Annual Salary:"<<(sal*12)<<endl;
    }
    void raisesalary() //function 1 for calculating raised salary
    {
        sal=sal+(sal*0.1);
        getYSalary(); //calling getter 3 
    }
};
int main()
{
    Employee e1; //object 1 of class employee
    Employee e2; //object 2 of class employee
    string fn1,fn2,ln1,ln2; 
    float s1,s2;
    cout<<"Enter first name: ";
    cin>>fn1;
    cout<<"Enter last name: ";
    cin>>ln1;
    cout<<"Enter salary: ";
    cin>>s1;
    cout<<"Enter first name: ";
    cin>>fn2;
    cout<<"Enter last name: ";
    cin>>ln2;
    cout<<"Enter salary: ";
    cin>>s2;
	e1.setInfo(fn1,ln1,s1); //constructor call for employee 1 
	e2.setInfo(fn2,ln2,s2); // constructor call for employee 2
	cout<<"Employee's One Info"<<endl; //employee's 1 info
	e1.getFName(); //calling getter 1
	e1.getLName(); //calling getter 2
	e1.getYSalary(); //calling getter 3 
	cout<<"Employee One salary after raise: ";
	e1.raisesalary(); //calling function 1
	cout<<"Employee's Two Info"<<endl; //employee's 2 info
	e2.getFName(); //calling getter 1 
	e2.getLName(); //calling getter 2 
	e2.getYSalary(); //calling getter 3 
	cout<<"Employee Two salary after raise: ";
	e2.raisesalary(); //calling function 1
}

