#include<iostream>
#include<string>
#include<stack>
using namespace std;
  
#define MAX 50 //max size for stack
  
class Stack
{
   int top;
   static int size;
   public:
   char arr[MAX]; //stack array
  
   Stack() 
   { 
   		top = -1; 
	}

	bool isEmpty()
   {
   		if(top<0)
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
		if(top==MAX-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
   bool push(int x)
   {
      	if (isFull()==true) 
		{
      	    cout << "Stack Overflow!!!";
      	    return false;
		}
		else 
		{
            size++;
            arr[++top] = x;
            cout<<x<<" ";
            return true;
		}
	}
	
   int pop()
   {
	    if(isEmpty()==true) 
	    {
		    cout << "Stack Underflow!!";
		    return 0;
	    }
		else 
		{
            size--;
	       	int item = arr[top--];
	      	return item;
	    }
	}

    int peek()
	{
		return arr[top];
	}

    static int getSize()
    {
        return size;
    }

    friend bool operator==(Stack& ob1, Stack& ob2);
};
int Stack::size=0;

bool operator==(Stack& obj1, Stack& obj2)
{
    bool flag;
    if(obj1.getSize()==obj2.getSize())
    {
        flag=true;
        while(obj1.isEmpty()!=true && obj2.isEmpty()!=true)
        {
            if(obj1.peek()==obj2.peek())
            {
                obj1.pop();
                obj2.pop();
                flag=true;
            }
            else
            {
                flag=false;
                break;
            }
        }
        return flag;
    }
    else
    {
        return false;
    }
    
}

int main()
{
    int a[20], b[20], n1, n2, i;
    Stack ob1;
    Stack ob2;
    cout<<"Enter the size of first stack : ";
    cin>>n1;
    cout<<"Enter "<<n1<<" elements in Stack 1 : ";
    for(i=0; i<n1; i++)
    {
        cin>>a[i];
    }
    cout<<endl;
    for(i=0; i<n1; i++)
    {
        ob1.push(a[i]);
    }
    cout<<endl;
    cout<<"Enter the size of second stack : ";
    cin>>n2;
    cout<<"Enter "<<n2<<" elements in Stack 1 : ";
    for(i=0; i<n2; i++)
    {
        cin>>b[i];
    }
    cout<<endl;
    for(i=0; i<n2; i++)
    {
        ob2.push(b[i]);
    }
    cout<<endl;
    if(ob1==ob2)
    {
        cout<<"Stack 1 and Stack 2 are of same type!";
    }
    else
    {
        cout<<"Stack 1 and Stack 2 are not of same type!";
    }
}