#include "Q1CLASS.h"
#include <iostream>
#include<fstream>
#include <stdio.h>
#include <string>
#include<cstdlib> 

using namespace std; 
DSA::DSA()
{
}
DSA::DSA(int x)
{
    size=x ;
    data= new int[size]; 
}
DSA::DSA(const DSA & dsa)
{
    this->size= dsa.size;
    this->data= new int[size];
}
int DSA::getsize() const
{
	return size;
}
DSA::~DSA()
{
    if(data!=0)
    {
        cout<<"Array Destroyed"<<endl;
        delete [] data;
        data=0;
        size=0; 
    }
}
void DSA::resize(int res)
{
    if(size!=res)
    {
        int i;
        int *temp=new int[size];
        for(i=0; i<size; i++)
        {
            temp[i]=*(data+i);
        }
        delete [] data;
        data=0;
        data=new int[res];
        for(i=0; i<size; i++)
        {
            *(data+i)=temp[i];
        }
        size=res;
        delete [] temp;
        temp=0;
    }
}
DSA &DSA::operator=(const DSA & dsa)
{
    if (this!=&dsa)
    { 
        int a=dsa.getsize();
        this->size=a;
        this->data=new int[a];
    }
    return (*this);
}
void DSA::insertion(int val, int index)
{	
	if(index<0 || index>=size)
	{
		cout<<"index is out of bounds\n";
		exit(0);
	}
	*(data+index)=val;
}
void DSA::searching(int val)
{
	int flag=0;
	for(int i=0;i<size;i++)
	{
		if(*(data+i)==val)
	    cout<<"Found at index: "<<i<<"\n";
		flag=1;
	}
	if(flag==0)
	cout<<"Entry not found\n";
}
OrderedDSA::OrderedDSA(int x)
{
    size=x;
    data= new int[size]; 
}
void OrderedDSA::insertion(int val)
{
	int temp;
	data[size-1]=val;
	for(int i=0;i<size;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(data[i]==data[j])
			{
				continue;
			}
            if(data[i]>data[j])
			{
				temp=data[i];
		     	data[i]=data[j];
				data[j]=temp;
			}
		}
    }
}
void OrderedDSA::searching(int val)
{
	int flag=0;
	for(int i=0;i<size;i++)
	{
		if(*(data+i)==val)
		cout<<"Found at index: "<<i<<"\n";
		flag=1;
	}
	if(flag==0)
	cout<<"Entry not found\n";
}
UnorderedDSA::UnorderedDSA(int x)
{
    size=x ;
    data=new int[size]; 
}
void UnorderedDSA::insertion(int val, int index)
{	
	if(index<0 || index>=size)
	{
		cout<<"index is out of bounds\n";
		exit(0);
	}
	data[index]=val;
}
void UnorderedDSA::searching(int val)
{
	int flag=0;
	for(int i=0;i<size;i++)
	{
		if(*(data+i)==val)
		cout<<"Found at index: "<<i<<"\n";
		flag=1;
	}
	if(flag==0)
	cout<<"Entry not found\n";
}	