#include<iostream>
using namespace std;

class Employee
{
	string name;
	int age, exp, workH;
    float sal;
	public:
	Employee()
    {}
	void setData()
	{
        cout<<"Enter employee name : ";
        cin>>name;
        cout<<"Enter employee age : ";
        cin>>age;
        cout<<"Enter employee experience : ";
        cin>>exp;
        cout<<"Enter employee working hours : ";
        cin>>workH;
        if(age>50 && exp>10 && workH>240)
		{
			sal=500*workH;
		}
		else if(age<=50 && age>40 && exp <=10 && exp>6 && workH>200 && workH<=240)
		{
			sal=425*workH;
		}
		else if(age<=40 && age>30 && exp>3 && exp <=6 && workH>160 && workH<=200)
		{
			sal=375*workH;
		}
		else if(age<=30 && age>22 && exp<=3 && exp>1 && workH>120 && workH<=160)
		{
			sal=300*workH;
		}
		else
		{
			cout<<"Error, invalid parameters."<<endl;
		}
	}
	
	void printOut()
	{
		cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Salary: "<<sal<<endl;
        cout<<"Experience: "<<exp<<endl;
        cout<<"Working Hours: "<<workH<<endl;
	}
};

int main()
{
    int n;
    cout<<"How many employees data do you want to enter? ";
    cin>>n;
	Employee* E=new Employee[n];
	for(int i=0;i<n;i++)
	{
		(E+i)->setData();
	}
	for(int i=0;i<n;i++)
	{
		(E+i)->printOut();
	}
	delete []E;
}
