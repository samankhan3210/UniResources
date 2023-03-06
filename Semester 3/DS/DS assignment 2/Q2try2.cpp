#include <iostream>
#define size 100
using namespace std;

class Queue 
{
	int data[size], prio[size], front, rear;
	public:
	Queue()
	{
		front=-1;
		rear=-1;
	}
	int peek()
	{
		return data[front];
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
	void enQueue(int d,int p)
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
            ++rear;
			data[rear]=d;
            prio[rear]=p;
		}
	}
	void deQueue()
	{
		if(isEmpty()==true)
		{
			cout<<"Queue is empty"<<endl;
		}
		else
		{
			cout<<prio[front]<<"  ";
			if(front==rear)
			{
				front=-1;
				rear=-1;
			}
			else
			{
				front++;
			}
		}
	}
	void Display()
	{ 
		int i;
		if(isEmpty()) 
		{
			cout<<endl<<"Queue is Empty!!"<<endl;
		}
		else 
		{
            for(i=front; i<=rear; i++)
			{
				cout<<prio[i]<<"\t";
			}
			cout<<endl;
			for(i=front; i<=rear; i++)
			{
				cout<<data[i]<<"\t";
			}
			cout<<endl;
		}
	}
	void SortFunction(int *a, int n)
	{
		int temp1[100];
		for(int i=0; i<n; i++)
		{
			data[i]=a[i]/data[i];
		}
		for(int i=0; i<n-1; i++)
		{
			for(int j=0; j<n-1; j++)
			{
				if(data[j]>data[j+1])
				{
					int temp=data[j];
					data[j]=data[j+1];
					data[j+1]=temp;
					int temp2=prio[j];
					prio[j]=prio[j+1];
					prio[j+1]=temp2;
				}
			}
		}
	}
};

int main()
{
    Queue ob;
	int n, a1[100], a2[100], a3[100];
	cout<<"Enter the number of processes : ";
	cin>>n;
	cout<<"Enter "<<n<<" processes : ";
	for(int i=0; i<n; i++)
	{
		cin>>a1[i];
	}
	cout<<"Enter quota of "<<n<<" processes : ";
	for(int i=0; i<n; i++)
	{
		cin>>a2[i];
	}
	cout<<"Enter requirements of CPU of "<<n<<" processes : ";
	for(int i=0; i<n; i++)
	{
		cin>>a3[i];
	}  
	for(int i=0; i<n; i++)
	{
    	ob.enQueue(a2[i],a1[i]);
	}
	ob.SortFunction(a3,n);
	cout<<"Final Priority : ";
	for(int i=0; i<n; i++)
	{
		ob.deQueue();
	}  
}

