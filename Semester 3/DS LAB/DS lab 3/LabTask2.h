#ifndef LABTASK2_H
#define LABTASK2_H

using namespace std;

struct node
{
	int data;
	node *next;
};

class LinkedList
{
	node *head, *tail;
	public:
	LinkedList();
	void add_node(int n);
	void Four(int n);
};

#endif