#ifndef Q2_H
#define Q2_H

using namespace std;

struct node
{
	int data;
	node *next;
};

class List
{
	node *head, *tail;
	public:
	List();
	void add_node(int n);
    void Show();
    node* ReturnHead();
    node* ReturnTail();
};

#endif