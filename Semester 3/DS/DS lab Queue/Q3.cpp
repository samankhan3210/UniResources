#include <iostream>
#include "stack.cpp"
#define size 50
using namespace std;
 
class Queue 
{
	int arr[size], front, rear;
	public:
	Queue()
	{
		front=-1;
		rear=-1;
	}
	bool isEmpty()
	{
		if(front==-1)
		{
			return true;
		}
		else
		{
			return false;
		}	
	}
	bool isFull()
	{
		if(front==0 && rear==size - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void enQueue(int d)
	{
		if(isFull()==true)
		{
			cout<<"Queue is full"<<endl;
		}
		else
		{
			if(front==-1)
			{
				front++;
			}
			arr[++rear]=d;
		}
	}
	int deQueue()
	{
		if(isEmpty()==true)
		{
			cout<<"Queue is empty"<<endl;
			return 0;
		}
		else
		{
			int val=arr[front];
			if(front==rear)
			{
				front=-1;
				rear=-1;
			}
			else
			{
				front++;
			}
			return val;
		}
	}
	void Display()
	{ 
		int i;
		if(isEmpty()) 
		{
			cout << endl << "Queue is Empty!!" << endl;
		}
		else 
		{
			for(i=front; i<=rear; i++)
			{
				cout << arr[i] << "\t";
			}
		}
	}
};

Queue Reverse(Queue ob)
{
	Queue ob1;
	Stack ob2;
	while(ob.isEmpty()!=true)
	{
		int a=ob.deQueue();
		ob2.Push(a);
	}
	while(ob2.SEmpty()!=true)
	{
		int b=ob2.Pop();
		ob1.enQueue(b);
	}
	return ob1;
}

int main()
{
	Queue ob;
	Queue q2; 
	int n, a[50];            
	cout<<"Enter how many numbers you want to enter in the queue : ";
	cin>>n;
	cout<<"Enter "<<n<<" elements : ";
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	for(int i=0; i<n; i++)
	{
		ob.enQueue(a[i]);
	}
	cout<<"Original Queue : ";
	ob.Display(); 
	q2=Reverse(ob);
	cout<<endl<<"Reversed Queue : ";
	q2.Display(); 	
}