#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
#define size 100 

class Stack
{
    int top;
    public:
    int arr[size];
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
    int pop()
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
    int peek()
	{
		return arr[top];
	}
};
bool moveUp(char a[][7], int c, int r, int nr)
{
    if(r<0)
    {
        return false;
    }
    else if(a[r][c]=='e' || a[r][c]=='0' || a[r][c]=='s')
    {
        return true;
    }
    else
    {   
        return false;
    }
}

bool moveDown(char a[][7], int c, int r, int nr)
{
    if(r>=nr)
    {
        return false;
    }
    else if(a[r][c]=='e' || a[r][c]=='0' || a[r][c]=='s')
    {
        return true;
    }
    else
    {   
        return false;
    }
}

bool moveRight(char a[][7], int c, int r, int nc)
{
    if(c>=nc)
    {
        return false;
    }
    else if(a[r][c]=='e' || a[r][c]=='0' || a[r][c]=='s')
    {
        return true;
    }
    else
    {   
        return false;
    }
}

bool moveLeft(char a[][7], int c, int r, int nc)
{
    if(c<0)
    {
        return false;
    }
    else if(a[r][c]=='e' || a[r][c]=='0'  || a[r][c]=='s')
    {
        return true;
    }
    else
    {   
        return false;
    }
}

void SolveMaze(char a[][7], int c, int r, int nr, int nc)
{
    static int count=0;
    Stack obr;
    Stack obc;
    if(a[r][c]=='e')
    {
        obr.push(r);
        obc.push(c);
        // cout<<"("<<r<<","<<c<<") ";
        // cout<<"("<<obr.peek()<<","<<obc.peek()<<" ";
        do
        {
            cout<<"("<<obr.peek()<<","<<obc.peek()<<") ";
            obr.pop();
            obc.pop();
            cout<<"hi";
            //count++;
        }while(obr.isEmpty()==false);
        cout<<"Cost="<<count<<endl;
        count=0;
        // exit(1);
        SolveMaze(a,0,0,nr,nc);
    }
    else 
    {
        if(a[r][c]=='s')
        {
            obr.push(r);
            obc.push(c);
            cout<<c<<r<<endl;
            cout<<"hello";
            count++;
        }
        if(moveLeft(a,c-1,r,nc)==true)
        {
            obr.pop();
            obc.pop();
            cout<<c-1<<r<<endl;
            count--;
            a[r][c]='!';
            SolveMaze(a,c-1,r,nc,nr);
        }
        else if(moveDown(a,c,r+1,nr)==true)
        { 
            obr.push(r+1);
            obc.push(c);
            cout<<c<<r+1<<endl;
            count++;
            a[r][c]='!';
            SolveMaze(a,c,r+1,nc,nr); 
        }
        else if(moveRight(a,c+1,r,nc)==true)
        {
            obr.push(r);
            obc.push(c+1);
            cout<<c+1<<r<<endl;
            count++;
            a[r][c]='!';
            SolveMaze(a,c+1,r,nr,nc);
        } 
        else if(moveUp(a,c,r-1,nr)==true)
        {
            obr.pop();
            obc.pop();
            count--;
            cout<<c<<r-1<<endl;
            a[r][c]='!';
            SolveMaze(a,c,r-1,nc,nr);
        }
    }
}

int main()
{ 
    char arr[4][7]={{'s','0','0','0','0','0','1'},
                {'0','1','1','0','0','1','0'},
                {'0','1','1','1','0','1','0'},
                {'0','0','0','e','0','0','0'}};
    SolveMaze(arr,0,0,4,7);
}