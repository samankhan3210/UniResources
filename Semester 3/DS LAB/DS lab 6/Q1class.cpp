#include "Q1class.h"
#include <iostream>
#include <iomanip>

using namespace std;

DoublyLL::DoublyLL()
{
	head=NULL;
	tail=NULL;
}

void DoublyLL::add_node(int n)
{
    node *temp = new node;
    temp->data = n;
    temp->next = NULL;
    temp->prev = NULL;
    if(head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
    }
}

node* DoublyLL::getHead()
{
    return head;
}

node* DoublyLL::getTail()
{
    return tail;
}

void DoublyLL::Print()
{
    if(head==NULL)
    {
        cout<<"No element in the list. "<<endl;
        return;
    }
    node *temp=head;
    cout<<"List : \t";
    while(temp!=NULL)
    {
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}

int DoublyLL::getSize()
{
    node *temp=head;
    int size=0;
    while(temp!=NULL)
    {
        size++;
    }
    return size;
}
int DoublyLL::getNth(int n)
{
    if(n<0 && n>getSize())
    {
        cout<<"Invalid position! "<<endl;
        return 0;
    }
    else
    {
        node *temp=head;
        for(int i=0; i<n && temp!=NULL ; i++)
        {
            temp=temp->next;
            if(temp==NULL)
            {
                return 0;
            }
        }
        return temp->data;
    }
    
}