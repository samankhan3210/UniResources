#include<iostream>
#include<list>
using namespace std;

struct node
{
	int data;
	node *next;
};
class Graph;
class LinkedList
{
	struct node *head,*tail;
	public:
	friend class Graph;
	LinkedList()
	{
		head=NULL;
		tail = NULL;
	}
	void insertion(int d)
	{
		node *temp=new node;
		temp->data=d;
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		else
		{
			tail->next=temp;
			tail=temp;
		}
	}
	void insertion2(node* temp)
	{
		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		else
		{
			tail->next=temp;
			tail=temp;
		}
	}
	void insetion3(int d)
	{
		node *temp=new node;
		temp->data=d;
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		else
		{
			temp->next=head;
			head=temp;
		}
	}
	node* deletion()
	{
		if(head==NULL)
		{
			cout<<"Link List is empty\n";
			return 0;
		}
		node* temp=new node;
		*temp=*head;
		if(head==tail)
		{
			head=tail=NULL;
		}
		else
		{
			head=head->next;
		}
		return temp;
	}
	node* getHead()
	{
		return head;
	}
	node* getTail()
	{
		return tail;
	}
	void display()
	{
		if(head==NULL)
		{
			cout<<"Linked List is empty\n";
			return;
		}
		node* iterator1=head;
		while(iterator1!=NULL)
		{
			cout<<iterator1->data<<", ";
			iterator1=iterator1->next;
		}
	}
};

class Graph
{
	int V;
	LinkedList *ob;
	public:
	Graph(int V)
	{
		this->V=V;
		ob=new LinkedList[V];
	}
	void AddEdge(int x,int y)
	{
		ob[x].insetion3(y);
		ob[y].insetion3(x);
	}
	void AddVertex()
	{
		V++;
		Copy();
	}
	void Copy()
	{
		LinkedList *l2=new LinkedList[V];
		for(int i=0;i<V-1;i++)
		{
			l2[i].insertion2(ob[i].deletion());
		}
		ob=l2;
	}
	void CallDFS(int v)
	{
    	bool* visited = new bool[V];
    	for (int i=0;i<V;i++)
    	    visited[i] = false;	
    	DFS(v, visited);
	}
	void DFS(int v, bool* visited)
	{
    	visited[v] = true;
    	cout << v << " ";
    	node* temp=ob[v].getHead();
    	while(temp!=NULL)
    	{
    		if(!visited[temp->data])
    			DFS(temp->data,visited);
    		temp=temp->next;
		}
	}
	void Display2()
	{
		for(int i=0;i<V;i++)
		{
			cout<<"Vertex "<<i<<"->";
			ob[i].display();
			cout<<endl;
		}
	}
};
int main()
{
	Graph ob(5);
	ob.AddEdge(3,4);
	ob.AddEdge(2,0);
	ob.AddEdge(1,3);
	ob.AddEdge(5,0);
	ob.AddVertex();
	ob.AddEdge(4,1);
	ob.AddEdge(5,3);
	ob.Display2();
	cout<<endl<<endl;
	cout<<"DFS: ";
	ob.CallDFS(0);
}
