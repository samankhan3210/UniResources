#include<iostream>
using namespace std;
class marks{
	protected:
	int marks;
	string RN,name;
};
class phy:public marks
{
	static int TM;
	public:
	phy()
	{
		cout<<"Enter name: ";
		cin>>name;
		cout<<"Enter physics marks: ";
		cin>>marks;
		cout<<"Enter roll no: ";
		cin>>RN;
		TM=TM+marks;
	}
	void avg(int a)
	{
		cout<<"Physics Average Marks: "<<(TM/a)<<endl;
	}
};
int phy::TM=0;
class chem:public marks
{
	static int TM;
	public:
	chem()
	{
		cout<<"Enter name: ";
		cin>>name;
		cout<<"Enter chemistry marks: ";
		cin>>marks;
		cout<<"Enter roll no : ";
		cin>>RN;
		TM=TM+marks;
	}
	void avg(int a)
	{
		cout<<"Chemistry Average Marks: "<<(TM/a)<<endl;
	}
};
int chem::TM=0;
class maths:public marks
{
	static int TM;
	public:
	maths()
	{
		cout<<"Enter name: ";
		cin>>name;
		cout<<"Enter maths marks: ";
		cin>>marks;
		cout<<"Enter roll no: ";
		cin>>RN;
		TM=TM+marks;
	}
	void avg(int c)
	{
		cout<<"Maths Average Marks: "<<(TM/c)<<endl;
	}
};
int maths::TM=0;
int main()
{
	int x;
	cout<<"Enter total number of students: ";
	cin>>x;
	phy p[x];
	chem c[x];
	maths m[x];
	p[x-1].avg(x);
	c[x-1].avg(x);
	m[x-1].avg(x);
}
