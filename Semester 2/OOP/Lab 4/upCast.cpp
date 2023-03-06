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
//class C: public A
//{
	//public:
	//	void func()
      // {
	//		cout<<"IN C()"<<endl;
		//}
	
//};
//class D:public B,public C
//{
//	public:
	//	void func()
	//	{
	//		cout<<"IN D()"<<endl;
	//	}
	
//};
int main()
{
    // A* ob;  //early binding
	A* ob= new B; //upcasting early binding
    //B* ob;
    //B* ob= (B*) new A //downcastimg or explicit casting 
	//to perform late binding add virtual before the parent class 
	ob->func();
	//virtual keyword kay baghiar output A ka aiga jo hamay nahi chahiye or vitual kay sarh B ka output show hoga
}