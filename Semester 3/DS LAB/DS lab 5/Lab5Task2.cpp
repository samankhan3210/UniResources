#include "Lab5Task2.h"
#include <iostream>
#include <iomanip>

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

node* LinkedList::getHead()
{
    return head;
}

node* LinkedList::getTail()
{
    return tail;
}
void Four(LinkedList &list, LinkedList &average)
{
    node *x=list.getHead();
    while(x!=NULL)
    {
        node* y=x;
        float sum=0;
        int i;
        for(i=0; i<4; i++)
        {
            sum=sum+y->data;
            y=y->next;
        }
        average.add_node(sum/4);
        if(y==NULL)
        {
            break;
        }
        x=x->next;
        cout<<endl;
    }
}

void LinkedList::Print()
{
    if(head==NULL)
    {
        cout<<"No element in the list. "<<endl;
        return;
    }
    struct node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<setprecision(2)<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}