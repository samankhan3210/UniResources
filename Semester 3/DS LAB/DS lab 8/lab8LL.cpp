#include<iostream>
using namespace std;

struct node
{
	float data;
	node *next;
};

class LinkedList
{
	node *top;
	public:
    LinkedList()
    {
	    top=NULL;
    }
    bool isEmpty()
    {
        if(top==NULL)
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
        node* temp=new node;
        temp->data=d;
        temp->next=top;
        top=temp;
    }
    void Pop()
    {
        if(isEmpty()==true)
        {
            cout<<"Empty Stack"<<endl;
        }
        else
        {
            node* temp=top;
            top=top->next;
            free(temp);
        }
    }
    node* Peek()
    {
        return top;
    }
    void Display()
    {
        node* temp=top;
        if(top==NULL)
        {
            cout<<"Stack is empty!";
        }
        else
        {
            while(temp!=NULL)
            {
                cout<<temp->data<<"  ";
                temp=temp->next;
            }
        }
    }
};

int main()
{
    LinkedList ob;
    int i, n, a[50];
    cout<<"How many numbers do you want to enter : ";
    cin>>n;
    cout<<"Enter "<<n<<" numbers in the list : "<<endl;
    for(i=0; i<n; i++)
    {
        cout<<i+1<<". ";
        cin>>a[i];
        ob.Push(a[i]);
    }
    cout<<"Elements in Stack after Push operation: ";
    ob.Display();
    cout<<endl;
    ob.Pop();
    cout<<"Elements in Stack after Pop operation: ";
    ob.Display();
}