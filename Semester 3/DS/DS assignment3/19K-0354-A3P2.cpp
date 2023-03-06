#include<iostream>
#include<stack>
#include<fstream>
using namespace std;

struct node
{
    int key;
    node *left, *right;
};

class BinarySearchTree
{
    public:
    BinarySearchTree()
    {
        left==NULL;
        right==NULL;
    }
    node* insertBST(node *root, int key)
    {
        if(root==NULL)
        {
            node* temp=new node; 
            temp->key=key;
            temp->left=NULL;
            temp->right=NULL; 
            return temp;
        }
        if(key < root->key) 
        {
            root->left=insertBST(root->left, key); 
        }
        else if(key > root->key) 
        {
            root->right=insertBST(root->right, key); 
        }
        return root;
    }
    stack<node *> PrintSum(stack<node *> &s)
    {
        ofstream of("Q2output.txt", std::ofstream::out | std::ofstream::app);
        int sum=0;
        stack<node *> s2;
        while(s.empty()!=true)
        {
            node* temp=s.top();
            s.pop();
            sum=sum+temp->key;
            s2.push(temp);
        }
        of<<sum<<"-";
        cout<<sum<<"-";
        while(s2.empty()!=true)
        {
            node* temp2=s2.top();
            s2.pop();
            s.push(temp2);
        }
        of.close();
        return s;
    }
    void PathSum(node *root, stack<node *> &s)
    {
        if(root==NULL)
        {
            return;
        }
        s.push(root);
        PathSum(root->left,s);
        if(root->left==NULL && root->right==NULL)
        {
            s=PrintSum(s);
        }
        PathSum(root->right,s);
        s.pop();
    }
};

int main()
{
    int n, i=0, arr[50];
    ifstream of1("Q2input.txt");
    while(!of1.eof())
    {
        of1>>arr[i];
        i++;
    }
    n=i;
    BinarySearchTree ob;
    node *root=NULL;
    for(int i=0; i<n; i++)
    {
        root=ob.insertBST(root,arr[i]);
    }
    stack<node *> ob1;
    ob.PathSum(root,ob1);
    of1.close();
}