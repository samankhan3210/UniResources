#ifndef LAB6TASK1_H
#define LAB6TASK1_H

using namespace std;

struct node
{
	float data;
	node *next;
    node *prev;
};

class DoublyLL
{
	node *head, *tail;
	public:
	DoublyLL();
	void add_node(int n);
    node* getHead();
    node* getTail();
    int getSize();
    int getNth(int n);
    void Print();
};

#endif