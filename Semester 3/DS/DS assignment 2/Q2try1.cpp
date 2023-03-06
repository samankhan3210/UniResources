#include<iostream>
using namespace std;

struct node
{
    int data;
    int priority;
    node *next;
};

class Queue
{
    node *front, *rear;
    public:
    Queue()
    {
        front==NULL;
        rear==NULL;
    }
    bool isEmpty()
    {
        if(front==NULL && rear==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void enQueue(int d, int p)
    {
        node *temp=new node;
        temp->data=d;
        temp->priority=p;
        temp->next=NULL;
        if(isEmpty()==true)
        {
            front=temp;
            rear=temp;
            cout<<front->data<<endl;
        }
        else
        {
            rear->next=temp;
            rear=temp;
            cout<<rear->data<<endl;
        }
    }
    void deQueue()
    {
        if(isEmpty()==true)
        {
            cout<<"Empty Queue!"<<endl;
        }
        else
        {
            node *temp=front;
            front=front->next;
            cout<<temp->priority<<" ";
            free(temp);
        }
    }
    void Display()
    {
        if(isEmpty()==true)
        {
            cout<<"Queue is Empty ";
        }
        else
        {
            node *temp=front;
            // while(temp!=NULL)
            // {
            //     cout<<temp->priority<<" ";
            //     temp=temp->next;
            // }
            cout<<endl;
            temp=front;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
    }
	void SortFunction(int *a, int n)
	{
        int i=0;
        node *temp=front;
		while(temp!=NULL && i<n)
		{
			temp->data=a[i]/temp->data;
            cout<<temp->data;
            temp=temp->next;
            i++;
		}
        node *k, *j;
        k=front;
        j=front->next;
		for(k=0 ; k->next!=NULL ; k=k->next)
		{
			for(j=k->next ; k!=NULL ; j=j->next)
			{
				if(k->data > j->data)
				{
					int temp=k->data;
					k->data=j->data;
					j->data=temp;
					int temp2=k->priority;
					k->priority=j->priority;
					j->priority=temp2;
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
    ob.deQueue();
	// ob.SortFunction(a3,n);
	// cout<<"Final Priority : ";
	// for(int i=0; i<n; i++)
	// {
	// 	ob.deQueue();
	// }  
}
