#include<iostream>
using namespace std;
class A
{
	public:
		virtual void func()
		{
			cout<<"IN A()"<<endl;
        }
	
};
class B:public A
{
	public:
    //over ridding function
	    void func()
		{
			cout<<"IN B()"<<endl;
		}
	
};
int main()
{
    A*ob= new B;
    ob->func(); //early binding or compile time binding or lazy binding
    // add virtual keyword to avoid it
}
