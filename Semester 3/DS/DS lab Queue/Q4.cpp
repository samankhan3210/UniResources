#include <iostream>
#include "stack.cpp"
#define size 50
using namespace std;
 
class Queue 
{
    public:
    Stack s1, s2;
    void enQueue(int x)
    {
        while(s1.SEmpty()!=true) 
        { 
            s2.Push(s1.Pop()); 
        } 
        s1.Push(x); 
        while(s2.SEmpty()!=true) 
        { 
            s1.Push(s2.Pop()); 
        } 
    }
    int deQueue() 
    { 
        if(s1.SEmpty()==true) 
        { 
            cout<<"Queue is Empty"; 
            exit(0); 
        } 
        int val=s1.Pop();  
        return val; 
    } 
};

int main()
{
	Queue ob;
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
	cout<<"Queue : ";
    for(int i=0; i<n; i++)
	{
		int a=ob.deQueue();
        cout<<a<<" ";
	}
}