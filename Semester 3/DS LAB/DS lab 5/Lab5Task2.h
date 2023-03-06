#ifndef LAB5TASK2_H
#define LAB5TASK2_H

using namespace std;

struct node
{
	float data;
	node *next;
};

class LinkedList
{
	node *head, *tail;
	public:
	LinkedList();
	void add_node(int n);
    node* getHead();
    node* getTail();
    void Print();
};

#endif