#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};
class Queue
{
	node *front,*rear;
	int size;
	public:
	Queue()
	{
		front=rear=NULL;
		size=0;
	}
	void enQueue(int d)
	{
		node* temp=new node;
		temp->data=d;
		temp->next=NULL;
		if(isEmpty()==true)
		{
			front=temp;
			rear=temp;
		}
		else
		{
			rear->next=temp;
			rear=temp;
		}
		size++;
	}
	node* deQueue()
	{
		if(isEmpty()==true)
		{
			cout<<"Queue is empty\n";
			exit(1);
		}
		else
		{
			node *temp=front;
			if(getSize()==1)
			{
				front=rear=NULL;
			}
			else
			{
				front=front->next;
			}
			size--;
			return temp;
		}
	}
	int getSize()
	{
		return size;
	}
	bool isEmpty()
	{
		if(size==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	node* getFront()
	{
		return front;
	}
	void display()
	{
		node *temp=front;
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
};
class Graph
{
	int V;
	int** matrix;
	public:
	Graph(int V)
	{
		this->V=V;
		matrix=new int*[V];
		for(int i=0;i<V;i++)
		{
			matrix[i]=new int[V];
		}
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				matrix[i][j]=0;
			}
		}
	}
	void AddEdge(int x,int y)
	{
		matrix[x][y]=1;
		matrix[y][x]=1;
	}
	void AddVertex()
	{
		V++;
		Copy();
	}
	void Copy()
	{
		int **arr;
		arr=new int*[V];
		for(int i=0;i<V;i++)
		{
			arr[i]=new int[V];
		}
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				arr[i][j]=0;
			}
		}
		for(int i=0;i<V-1;i++)
		{
			for(int j=0;j<V-1;j++)
			{
				arr[i][j]=matrix[i][j];
			}
		}
		matrix=arr;
	}
	void BFS(int start)
	{
		bool visited[V]={false};
    	Queue q;
    	q.enQueue(start);
		visited[start] = true;
    	int vis;
    	while (!q.isEmpty())
		{
        	vis = q.getFront()->data;
        	cout << vis << " ";
        	q.deQueue();
        	for (int i = 0; i < V; i++) 
			{
            	if (matrix[vis][i] == 1 && (!visited[i])) 
				{
                	q.enQueue(i);
                	visited[i] = true;
            	}
        	}
    	}
	}
	void Display2()
	{
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				cout<<matrix[i][j]<<"  ";
			}
			cout<<endl;
		}
	}
};
int main()
{
	Graph ob(4);
	ob.AddEdge(0,1);
	ob.AddEdge(0,2);
	ob.AddEdge(2,3);
	ob.AddEdge(1,2);
	ob.Display2();
	ob.AddVertex();
	cout<<endl<<endl;
	cout<<"BFS:\n";
	ob.BFS(1);
}
