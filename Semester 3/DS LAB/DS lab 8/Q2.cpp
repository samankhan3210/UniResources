#include<iostream>
#include<string>
using namespace std;
  
#define MAX 50 //max size for stack
  
class Stack
{
   int top;
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
		   arr[++top] = x;
		   cout<<x<<endl;
		   return true;
		}
	}
	
   int pop()
   {
	   if (isEmpty()==true) 
	   {
		    cout << "Stack Underflow!!";
		    return 0;
	   }
		else 
		{
	       	int item = arr[top--];
	      	return item;
	    }
	}

    int peek()
	{
		return arr[top];
	}

    void GroupingSymbols(string str)
    {
		int len=str.length();
        for(int i=0; i<len; i++)
        {
			if(str[i]=='{' || str[i]=='[' || str[i]=='(')
            {
               push(str[i]);
			   top++;
            }
             else if(str[i]=='}' || str[i]==']' || str[i]==')')
            {
                pop();
				top--;
				
            }
        }
        if(top==-1)
   		{
       		cout<<"Expression contains matching group symbols";
		}
		else
		{
			cout<<"Expression does not contain matching group symbols";
		}
    }
};

int main()
{
   string s;
   cout<<"Enter the expression : ";
   getline(cin,s);
   cout<<"Your expression is : "<<s<<endl;
   Stack st;
   st.GroupingSymbols(s);   
}