#include <iostream>
#define size 100
using namespace std;

struct node
{
    int data, prio;
};

class Queue 
{
	int front, rear;
    node *arr[size]={0};
	public:
	Queue()
	{
		front=-1;
		rear=-1;
	}
	int peek()
	{
		return arr[front]->data;
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
			arr[rear]->data=d;
            arr[rear]->prio=p;
            cout<<arr[rear]->data;
            cout<<arr[rear]->prio;
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
			cout<<arr[front]->prio<<"  ";
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
				cout<<arr[i]->prio<<"\t";
			}
			cout<<endl;
			for(i=front; i<=rear; i++)
			{
				cout<<arr[i]->data<<"\t";
			}
			cout<<endl;
		}
	}
	void SortFunction(int *a, int n)
	{
		for(int i=0; i<n; i++)
		{
			arr[i]->data=a[i]/arr[i]->data;
            cout<<arr[i]->data;
		}
		for(int i=0; i<n-1; i++)
		{
			for(int j=0; j<n-1; j++)
			{
				if(arr[j]->data > arr[j+1]->data)
				{
					int temp=arr[j]->data;
					arr[j]->data=arr[j+1]->data;
					arr[j+1]->data=temp;
					int temp2=arr[j]->prio;
					arr[j]->prio=arr[j+1]->prio;
					arr[j+1]->prio=temp2;
                    // node *temp=arr[j];
					// arr[j]->data=arr[j+1]->data;
                    // arr[j]->prio=arr[j+1]->prio;
					// arr[j+1]=temp;

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
    ob.Display();
	ob.SortFunction(a3,n);
	cout<<"Final Priority : ";
	for(int i=0; i<n; i++)
	{
		ob.deQueue();
	}  
}

