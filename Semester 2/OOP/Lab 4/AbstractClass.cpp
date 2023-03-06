#include<iostream>
using namespace std;
class Employee  //abstract class: we cannot make an object of abstract class
{
    int empID, salary;
    string empName;
	public:
    Employee()
    {
        cout<<"This employee works for capsule corp"<<endl;
    }
	virtual void work()=0;  //pure virtual function or abstract function
    void leave()  //concrete function
    {
        cout<<"30-days leave for all employees"<<endl;
    }
};
class Accounts:public Employee
{
	public:
		void work()
		{
			cout<<"Manages accounts"<<endl;
		}
};
class HR:public Employee
{
	public:
		void work()
		{
			cout<<"Manages HR related work"<<endl;
		}	
};
int main()
{
	// Employee ob; //this will give error b/c we can't make an object of incomplete class
    // Accounts ae;
    // ae.work();
    // ae.leave();  //accesimg leave function through child class
    // HR hre;
    // hre.leave();
    Employee* e=new HR;
    e->work();
    e=new Accounts;
    e->work();
}
