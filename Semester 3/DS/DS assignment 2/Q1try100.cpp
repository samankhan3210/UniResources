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
    char peek()
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
    else if(a[r][c]=='e' || a[r][c]=='0')
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
    else if(a[r][c]=='e' || a[r][c]=='0')
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
    else if(a[r][c]=='e' || a[r][c]=='0')
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
    else if(a[r][c]=='e' || a[r][c]=='0')
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
    int temp[50], temp2[50];
    static int count=0;
    Stack obr;
    Stack obc;
    if(a[r][c]=='e')
    {
        int i=0;
        while(i<count)
        {
            cout<<temp[i]<<" "<<temp2[i]<<endl;
            i++;
        }
        cout<<"Cost="<<count;
        //SolveMaze(a,0,0,nr,nc);
    }
    else 
    {
        if(a[r][c]=='s')
        {
            temp[count]=r;
            temp2[count]=c;
            count++;
            cout<<r<<c<<endl;
        }
        if(moveRight(a,c+1,r,nc)==true)
        {
            temp[count]=r;
            temp2[count]=c+1;
            count++;
            obr.push(r);
            obc.push(c+1);
            cout<<r<<c+1<<endl;
            count++;
            if(moveDown(a,c+1,r+1,nr)==true)
            {
                temp[count]=r+1;
                temp2[count]=c+1; 
                cout<<r+1<<c<<endl;
                count++;
                SolveMaze(a,c+1,r+1,nc,nr);       
            }
            else
            {
                SolveMaze(a,c++,r,nr,nc);
            }
        } 
        else if(moveDown(a,c,r+1,nr)==true)
        { 
            temp[count]=r+1;
            temp2[count]=c;
            cout<<r+1<<c<<endl;
            count++;
            //SolveMaze(a,c,r+1,nc,nr); 
            if(moveLeft(a,c-1,r+1,nc)==true)
            {
                temp[count]=r+1;
                temp2[count]=c-1;
                cout<<r+1<<c-1<<endl;
                count--;
                SolveMaze(a,c-1,r+1,nc,nr);      
            }
            else
            {
                SolveMaze(a,c,r+1,nc,nr); 
            }
            
        }
        else if(moveLeft(a,c-1,r,nc)==true)
        {
            count--;
            temp[count]=r+1;
            temp2[count]=c-1;
            cout<<r<<c-1<<endl;
            //SolveMaze(a,c-1,r,nc,nr);
            if(moveLeft(a,c-2,r,nc)==true)
            {
                count--;
                temp[count]=r;
                temp2[count]=c-2;
                cout<<r<<c-2<<endl;
                SolveMaze(a,c-2,r,nc,nr);
            }
            else if(moveDown(a,c-1,r+1,nr)==true)
            { 
                count++;
                temp[count]=r+1;
                temp2[count]=c-1;
                cout<<r+1<<c-1<<endl;
                SolveMaze(a,c-1,r+1,nc,nr);       
            }
            else if(moveUp(a,c-1,r-1,nr)==true)
            {
                count--;
                temp[count]=r-1;
                temp2[count]=c-1;
                cout<<c-1<<r-1<<endl;
                SolveMaze(a,c-1,r-1,nc,nr);
            }
            else
            {
                SolveMaze(a,c-1,r,nc,nr);
            }
            
        }
        // else if(moveUp(a,c,r-1,nr)==true)
        // {
        //     obr.pop();
        //     obc.pop();
        //     cout<<c<<r-1<<endl;
        //     SolveMaze(a,c,r-1,nc,nr);
        // }
    }
}

int main()
{ 
    char arr[4][7]={{'s','0','0','0','0','0','1'},{'0','1','1','0','0','1','0'},{'0','1','1','0','0','1','0'},{'0','0','0','e','0','0','0'}};
    SolveMaze(arr,0,0,4,7);
}