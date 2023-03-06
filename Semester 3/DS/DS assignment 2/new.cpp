#include<iostream>
#include<string.h>

#define MAX 50

using namespace std;

class conversion_stack
{
	private:
		int top;
		char array[MAX];
		
	public:
		stack()
		{
			top=-1;
		}
		
		bool isfull()
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
		
		bool isempty()
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
		
		void push(char val)
		{
			if(isfull()==true)
			{
				cout<<"OVERFLOW."<<endl;
			}
			
			else
			{
				array[++top]=val;
			}
		}
		
		char pop()
		{
			int alpha;
			
			if(isempty()==true)
			{
				cout<<"UNDERFLOW."<<endl;
			}
			
			else
			{
				alpha=array[top--];
				return alpha;
			}
		}
		
		char peek()
		{
			return array[top];
		}
		
		int precedence(char x)
		{
			int y;
			
			if(x=='^')
			{	
				return 5;
			}
			
			else if(x=='*')
			{	
				return 4;
			}
			
			else if(x=='/')
			{	
				return 3;
			}
			
			else if(x=='+')
			{	
				return 2;
			}
			
			else if(x=='-')
			{
				return 1;
			}
			
			else
			{
				y=0;
				
				return y;
			}
		}
		
		void conversion()
		{
			
};

int main()
{
	conversion_stack CS;
			
			int i=0;
			int j=0;
			char original[50];
			char postfix[50];
			char pop_val;
			
			cout<<"Enter the infix expression : "<<endl;
			cin>>original;
			
			while(original[i++]!=0)
			{
				
			}
			
			original[i+1]='\0';
			original[i--]=')';
			while(i>0)
			{
				original[i]=original[i-1];
				i--;
			}
			original[i]='(';
			//cout<<original<<endl;
			
			while(original[i]!='\0')
			{
				if(original[i]=='(')
				{
					CS.push(original[i]);
				}
				
				else if(original[i]>='A' && original[i]<='Z' && original[i]>='a' && original[i]<='z' && original[i]>='0')
				{
					postfix[j+1]=original[i];
				}
				
				else if(original[i]=='^' && original[i]=='*' && original[i]=='/' && original[i]=='+' && original[i]=='-')
				{
					while(CS.peek()=='^' || CS.peek()=='*' || CS.peek()=='/' || CS.peek()=='+' || CS.peek()=='-')
					{
						if(CS.precedence(CS.peek())>=CS.precedence(original[i]))
						{
							postfix[j++]=CS.pop();
						}
						
						else
						{
							break;
						}
					}
					
					CS.push(original[i]);
				}
				
				else if(original[i]==')')
				{
					while(pop_val=CS.pop()!='(')
					{
						postfix[j++]=pop_val;
					}
				}
				
				i++;
			}
			
			postfix[j]='\0';
			cout<<"POSTFIX : "<<postfix<<endl;
	
	return 0;
	
}