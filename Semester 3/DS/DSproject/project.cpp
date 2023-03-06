#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct node
{
    string data;
    node *next;
};

class linked_list
{
    public:
    node *head,*tail;
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(string n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    
    int personality1()
    {
        ifstream of1("Personality1.txt");
        string str;
        int points=0, ch;
        while(!of1.eof())
        {
            while(getline(of1, str))
            {
                cout<<str<<endl;
                cout<<"1. Agree     2. Disagree"<<endl;
                cin>>ch;
                if(ch==1)
                {
                    points++;
                }
                else if(ch!=1 || ch!=2)
                {
                    cout<<"inavlid choice, enter your choice again :";
                    cin>>ch;
                }
            }
        }
        return points;
    }
    void print()
    {
    	node *temp;
    	temp=head;
    	while(temp!=NULL)
    	{
    		cout<<temp->data<<endl;
    		temp=temp->next;
		}
	}
};
