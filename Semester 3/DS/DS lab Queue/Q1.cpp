#include<iostream>
using namespace std;

struct node
{
    int data;
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

    void enQueue(int n)
    {
        node *temp = new node;
        temp->data = n;
        temp->next = NULL;
        if(isEmpty()==true)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
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

    int deQueue()
    {
        node *temp=front;
        if(temp==NULL)
        {
            cout<<"Empty Queue!"<<endl;
            return 0;
        }
        else
        {
            front=front->next;
            free(temp);
            return temp->data;
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
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
    }
};

int main()
{
    Queue ob; 
	int n, a[50];            
	// cout<<"Enter how many numbers you want to enter in the array : ";
	// cin>>n;
	// cout<<"Enter "<<n<<" elements : ";
	// for(int i=0; i<n; i++)
	// {
	// 	cin>>a[i];
    //     ob.enQueue(a[i]);
	// }
    ob.enQueue(1);
    ob.enQueue(2);
    ob.enQueue(3);
    ob.enQueue(4);
	cout<<"Queue : ";
	ob.Display(); 
    ob.deQueue();
    ob.deQueue();
    cout<<endl<<"New Queue : ";
	ob.Display(); 
}