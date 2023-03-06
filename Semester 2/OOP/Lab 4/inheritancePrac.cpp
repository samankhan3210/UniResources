#include<iostream>
using namespace std;
class A
{
	public:
		void func()
		{
			cout<<"IN A()"<<endl;
		}
	
};
class B:virtual public A
{
	public:
		void func()
		{
			cout<<"IN B()"<<endl;
		}
	
};
class C:virtual public A
{
	public:
		void func()
		{
			cout<<"IN C()"<<endl;
		}
	
};
class D:public B,public C
{
	public:
		void func()
		{
			cout<<"IN D()"<<endl;
		}
	
};
int main()
{
	D ob;
	ob.func();
}