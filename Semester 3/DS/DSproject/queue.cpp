#include <iostream>
#include <fstream>
#define max 9
using namespace std;

class Queue 
{
	int scores[max], front, rear;
	float array_percentage[max];
    string names[max];
	public:
	Queue()
	{
		front=-1;
		rear=-1;
	}
	int getScores()
	{
		return scores[front];
	}
	string getNames()
	{
		return names[front];
	}
	bool isEmpty()
	{
		if(front==-1)
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
		if(front==0 && rear==max - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void enQueue(string x, int y)
	{
		if(isFull()==true)
		{
			cout<<"Queue is full"<<endl;
		}
		else
		{
			if(front==-1)
			{
				front++;
			}
            ++rear;
			names[rear]=x;
            scores[rear]=y;
		}
	}
	void deQueue()
	{
		if(isEmpty()==true)
		{
			cout<<"Queue is empty"<<endl;
		}
		else
		{	 
			if(front==rear)
			{
				front=-1;
				rear=-1;
			}
			else
			{
				front++;
			}
		}
	}
	void SortScores()
	{
		int i, j, key; 
		string key_el;
		for(i=1; i<max; i++)
        {  
            key=scores[i];  
            key_el=names[i];
            j=i-1;    
            while(j>=0 && scores[j]<key)
            {  
                scores[j+1]=scores[j];
		        names[j+1]=names[j];
			    j=j-1;  
            }
			scores[j+1]=key;
		    names[j+1]=key_el;  
        }
	}
	
	void calculate_percentage(float sum)
	{
	    float temp;
	    for(int i=0;i<max-1;i++)
	    {
	    	temp=(scores[i]/sum);
	    	array_percentage[i]=temp*100;
		}
	}
	    
	    void display()
	    {
	    	cout<<"\t*** RESULTS BY ORDER OF POINTS ***\n"<<endl;
	        for(int i=0; i<max-1; i++)
	        {
		        cout<<names[i]<<" = "<< array_percentage[i]<<"%"<<endl;
	        }
	        
	        cout<<"\n\t*** PERSONALITY TYPE ***"<<endl;
	        
	        string var1;
	        var1=names[0];
	        string var2;
	        var2=names[1];
	        string var3;
	        var3=names[2];
	        string var4;
	        var4=names[3];
	        cout<<"\n"<<var1[0]<<var2[0]<<var3[0]<<var4[0]<<endl;
	    }
};
