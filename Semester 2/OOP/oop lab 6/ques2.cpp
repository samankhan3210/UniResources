#include<iostream>
using namespace std;
class fruit
{
	protected:
	static int T;
	public:
	static void getTotal()
	{
		cout<<"Total Fruits in the Basket are: "<<T<<endl;
	}
};
int fruit::T=0;
class apple:public fruit
{
	int A;
	public:
	apple()
	{
		cout<<"How many apples are there? ";
		cin>>A;
		cout<<"The no.of Apples in the Basket are: "<<A<<endl;
		T=T+A;
	}
	
};
class mango:public fruit
{
	int M;
	public:
	mango()
	{
		cout<<"How many mangoes are there? ";
		cin>>M;
		cout<<"The no.of Mangoes in the Basket are: "<<M<<endl;
		T=T+M;
	}
};
int main()
{
	apple a;
	mango m;
	fruit::getTotal();
}
