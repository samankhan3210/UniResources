#include<iostream>
#define size 50
using namespace std;
class Stack
{
	int  top;
	public:
	int array[size];
	Stack()
	{
		top=-1;
	}
	bool SEmpty()
	{
		if(top==-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool SFull()
	{
		if(top==size-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Push(int d)
	{
		if(SFull()==true)
		{
			cout<<"Full Stack";
		}
		else
		{
			array[++top]=d;
		}
	}
	int Pop()
	{
		if(SEmpty())
		{
			cout<<"Empty Stack";
			return 0;
		}
		else
		{
			int val=array[top--];
			return val;
		}
	}
    int peek()
    {
        return array[top];
    }
};