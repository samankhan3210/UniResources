#ifndef LAB6TASK3_H
#define LAB6TASK3_H

using namespace std;

struct node
{
	float data;
	node *next;
};

class CircularLL
{
	node *head, *tail;
	public:
	CircularLL();
	void insertBeg(int x);
    void insertEnd(int x);
    void DelBeg();
    void DelEnd();
    void Print();
};

#endif