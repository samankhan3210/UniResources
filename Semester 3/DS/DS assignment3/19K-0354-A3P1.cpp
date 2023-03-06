#include<iostream>
#include<queue>
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

    void LevelSum(node *root)
    {
        ofstream of("Q1output.txt", std::ofstream::out | std::ofstream::app);
        int sum=0, i=0;
        queue<node *> q;
        q.push(root);
        while(q.empty()==false)
        {
            i=q.size();
            sum=0;
            while(i!=0)
            {
                node *temp=new node;
                temp=q.front();
                q.pop();
                sum=sum+temp->key;
                if(temp->left!=NULL)
                {   
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {   
                    q.push(temp->right);
                }
                i--;
            }
            cout<<sum<<"-";
            of<<sum<<"-";
        }
        of.close();
    }
};

int main()
{
    int n, i=0, arr[50];
    ifstream of1("Q1input.txt");
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
    ob.LevelSum(root);
    of1.close();
}