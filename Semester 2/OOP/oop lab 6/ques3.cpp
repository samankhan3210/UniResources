#include<iostream>
using namespace std;
class birthday
{
	protected:
	int d,m,y;
	public:
	birthday()
	{
		cout<<"Enter birthdate day: ";
		cin>>d;
		cout<<"Enter birthdate month: ";
		cin>>m;
		cout<<"Enter birthdate year: ";
		cin>>y;
	}
};
class teacher
{
	protected:
	string name, n;
	char g;
	int age;
	public:
	teacher()
	{
		cout<<"Enter name: ";
		cin>>name;
		cout<<"Enter age: ";
		cin>>age;
		cout<<"Enter gender(M/F): ";
		cin>>g;
		cout<<"Enter number: ";
		cin>>n;
	}
};
class Teaching:public teacher,public birthday
{
	public:
	Teaching()
	{
	}
	void display()
	{
		cout<<endl<<"NUMBER : "<<n<<endl;
		cout<<"NAME : "<<name<<endl;
		cout<<"AGE : "<<age<<endl;
		cout<<"GENDER : "<<g<<endl;
		cout<<"BIRTHDAY : "<<d<<"/"<<m<<"/"<<y<<endl;
	}
};
int main()
{
	Teaching p;
	p.display();
}
