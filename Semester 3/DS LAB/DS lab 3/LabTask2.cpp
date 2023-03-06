#include "LabTask2.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
	head=NULL;
	tail=NULL;
}

void LinkedList::add_node(int n)
{
    node *temp = new node;
    temp->data = n;
    temp->next = NULL;
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = tail->next;
    }
}

void LinkedList:: count(int n)
{
	int count=0;
	node *temp=head;
	while(temp!=NULL)
	{
		if(temp->data==n)
		{
			count++;
				
		}
		temp=temp->next;
		
	}
	cout << "Occurences: " << count << endl;
}

int main()
{
	
	LinkedList ob;
	ob.add_node(1);
	ob.add_node(2);
	ob.add_node(3);
	ob.add_node(3);
	ob.add_node(3);
	ob.add_node(4);
	ob.count(3);
	return 0; 

}