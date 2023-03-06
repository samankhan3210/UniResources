#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
#define size 100 

class Stack
{
    int top;
    public:
    char arr[size];
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
		if(top==size-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
    void push(char x)
    {
      	if(isFull()==true) 
		{
      	    cout<<"Stack Overflow!";
		}
		else 
		{
		   arr[++top]=x;
		}
	}
    char pop()
    {
	    if(isEmpty()==true) 
	    {
		    cout<<"Stack Underflow!!";
		    return 0;
	    }
		else 
		{
	       	int val=arr[top--];
	      	return val;
	    }
	}
    char peek()
	{
		return arr[top];
	}
};

int CheckPrecedence(char lw)
{
    if(lw=='^')
    {
        return 3;
    }
    else if(lw=='*' || lw=='/')
    {
        return 2;
    }
    else if(lw=='+' || lw=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }    
}

char Associativity(char c)
{
    if(c=='*' || c=='+')
    {
        return 'R';
    }
    else
    {
        return 'L';
    }
}
void InfixToPrefix(string str)
{ 
    Stack ob;
    string str2=string(str.rbegin(),str.rend()); 
    int len=str2.length();
    string newstr;
    char n;
    for(int i=0; i<len; i++)
    {
        if(str2[i]>='a' && str2[i]<='z' || str2[i]>='A' && str2[i]<='Z' || str2[i]>='0')
        {
           newstr=newstr+str2[i];
        }
        else if(str2[i]==')' || str2[i]==']' || str2[i]=='}')
        {
            ob.push(str2[i]);
        }
        else if(str2[i]=='(')
        {
            while(ob.peek()!=')')  
            {
                n=ob.pop();
                newstr=newstr+n;
            }
            ob.pop();
        }
        else if(str2[i]=='[')
        {
            while(ob.peek()!=']')  
            {
                n=ob.pop();
                newstr=newstr+n;
            } 
            ob.pop();
        }
        else if(str2[i]=='{')
        {
            while(ob.peek()!='}')  
            {
                n=ob.pop();
                newstr=newstr+n;
            } 
            ob.pop();
        }
        else if(ob.isEmpty()==true)
		{
			ob.push(str[i]);
		}
        else 
        {
            if(CheckPrecedence(str2[i]) > CheckPrecedence(ob.peek()))
            {
                ob.push(str2[i]);
            }
            else if(CheckPrecedence(str2[i]) < CheckPrecedence(ob.peek()))
            {
                while(CheckPrecedence(str2[i]) <= CheckPrecedence(ob.peek()))
                {
                    n=ob.pop();
                    newstr=newstr+n;
                }
                ob.push(str2[i]);
            }
            else if(CheckPrecedence(str2[i]) == CheckPrecedence(ob.peek()))
            {
                int c=CheckPrecedence(ob.peek());
                if(c==3)
                {
                    ob.push(str2[i]);
                }
                else if(c==2 || c==1)
                {
                    if(Associativity(str2[i])=='L' && Associativity(ob.peek())=='R')
                    {
                            n=ob.pop();
                            newstr=newstr+n;
                            ob.push(str2[i]);
                    }
                    else 
                    {
                        ob.push(str2[i]);
                    }
                }
        }
    }
    while(ob.isEmpty()!=true)
    {
        n=ob.pop();
        newstr=newstr+n;
    }
    string pref=string(newstr.rbegin(),newstr.rend()); 
    cout<<"Prefix expression : "<<pref;
}

void InfixToPostfix(string str)
{
    Stack ob;
	int len=str.length();
    string newstr;
    char n;
    for(int i=0; i<len; i++)
    {
		if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z' || str[i]>='0')
        {
           newstr=newstr+str[i];
        }
        else if(str[i]=='(' || str[i]=='[' || str[i]=='{')
        {
            ob.push(str[i]);
        }
        else if(str[i]==')')
        {
            while(ob.peek()!='(')  
            {
                n=ob.pop();
                newstr=newstr+n;
            }
            ob.pop();
        }
        else if(str[i]==']')
        {
            while(ob.peek()!='[')  
            {
                n=ob.pop();
                newstr=newstr+n;
            } 
            ob.pop();
        }
        else if(str[i]=='}')
        {
            while(ob.peek()!='{')  
            {
                n=ob.pop();
                newstr=newstr+n;
            } 
            ob.pop();
        }
        else 
        {
            if(CheckPrecedence(str[i]) > CheckPrecedence(ob.peek()))
            {
                ob.push(str[i]);
            }
            else if(CheckPrecedence(str[i]) < CheckPrecedence(ob.peek()))
            {
                while(CheckPrecedence(str[i]) <= CheckPrecedence(ob.peek()))
                {
                    n=ob.pop();
                    newstr=newstr+n;
                }
                ob.push(str[i]);
            }
            else if(CheckPrecedence(str[i]) == CheckPrecedence(ob.peek()))
            {
                int c=CheckPrecedence(ob.peek());
                if(c==3)
                {
                    ob.push(str[i]);
                }
                else if(c==2 || c==1)
                {
                    if(Associativity(str[i])=='L' && Associativity(ob.peek())=='R')
                    {
                        //while(Associativity(str[i])=='L' && Associativity(ob.peek())=='R')
                        //{
                            n=ob.pop();
                            newstr=newstr+n;
                        //}
                        ob.push(str[i]);
                    }
                    else 
                    {
                        ob.push(str[i]);
                    }
                }
            }
        }
    }
    while(ob.isEmpty()!=true)
    {
        n=ob.pop();
        newstr=newstr+n;
    }
   cout<<"Postfix expression : "<<newstr<<endl;
}
int main()
{
    string s;
    //ifstream os("Q3input.txt");
    cout<<"Enter the expression : ";
    cin>>s;
    //os>>s;
    // char *c=new char[50];
    // os.read(c,50);
    // os.close();
    // int sl=os.gcount();
    // for(int i=0; i<sl; i++)
    // {
    //     s=s+c[i];
    // }   
    cout<<"Your expression is : "<<s<<endl;
    InfixToPostfix(s);
    InfixToPrefix(s);
}