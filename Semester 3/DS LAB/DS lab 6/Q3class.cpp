#include "Q3class.h"
#include <iostream>
#include <iomanip>

using namespace std;

CircularLL::CircularLL()
{
	head=NULL;
	tail=NULL;
}

void CircularLL::insertBeg(int x)
{
    node *temp=new node;
    temp->data=x;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        tail->next=head;
    }
    else
    {
        tail->next=temp;
        temp->next=head;
        head=temp;
    }
}

void CircularLL::insertEnd(int x)
{
    node *temp=new node;
    temp->data=x;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        tail->next=head;;
    }
    else
    {
        temp->next=tail->next;
        tail->next=temp;
        tail=temp;
    }
}

void CircularLL::DelBeg()
{
    node *ptr1=head; 
    node *ptr2=head; 
    if(head->next==head)
    {
        head=NULL; 
        return; 
    }
    while(ptr1->next!=head)
    {
        ptr1=ptr1->next; 
    }
    ptr1->next=ptr2->next; 
    head=ptr1->next; 
    free(ptr2); 
    return; 
}

void CircularLL::DelEnd()
{
    node *ptr=head; 
    node *ptr2=new node; 
    if(head->next==head)
    {
        head=NULL; 
        return; 
    }
    while(ptr->next!=head)
    {
        ptr2=ptr; 
        ptr=ptr->next; 
    }
    ptr2->next=ptr->next; 
}

void CircularLL::Print()
{
    node *ptr=head;
    if(head==NULL)
    {
        cout<<"Empty"<<endl;
    }
    else
    {
        while(ptr->next!=head)
        {
            cout<<ptr->data<<" "<<endl;
            ptr=ptr->next;
        }
        cout<<" "<<ptr->data;
    }
}
