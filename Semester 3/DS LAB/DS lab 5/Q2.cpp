#include "Q2.h"
#include <iostream>
using namespace std;

List::List()
{
	head=NULL;
	tail=NULL;
}

void List::add_node(int n)
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


node* List::ReturnHead()
{
    return head;
}

node* List::ReturnTail()
{
    return tail;
}

void List::Show()
{
    if(head==NULL)
    {
        cout<<"No element in the list. "<<endl;
        return;
    }
    struct node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"   ";
        temp=temp->next;
    }
    cout<<endl;
}

void Func_Four(List &oldL, List &newL)
{
    node *a=oldL.ReturnHead();
    while(a!=NULL)
    {
        node* b=a;
        int i, sum=0;
        for(i=0; i<4; i++)
        {
            sum=sum+b->data;
            b=b->next;
        }
        newL.add_node(sum/4);
        if(b==NULL)
        {
            break;
        }
        a=a->next;
        cout<<endl;
    }
}
