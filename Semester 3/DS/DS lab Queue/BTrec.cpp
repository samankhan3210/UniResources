#include<iostream>
using namespace std;

struct node
{
    int key;
    node *left, *right;
};

class BT
{
    public:
    BT()
    {
        left==NULL;
        right==NULL;
    }

    node* insertBT()
    {
        node* root=new node; 
        int d;
        cout<<"(Enter -1 if you dont want to enter any data) : "; //if the user enters -1 then the node will not be inserted
        cin>>d;
        if(d==-1)
        {
            return 0;
        }
        root->key=d;
        cout<<"Enter left child of "<<d<<endl;
        root->left=insertBT(); //recursive call which will create sub trees of left child
        cout<<"Enter right child of "<<d<<endl;
        root->right=insertBT(); //recursive call which will create sub trees of right child
        return root;
    }

    node* SearchBT(node *root, int d)
    {
        if(root==NULL)
        {
            return NULL;
        }
        else if(root->key==d)
        {
            return root;
        }
        return SearchBT(root->right, d);
        return SearchBT(root->left, d);
    }

    void InOrder(node *root)
    {
        if(root==NULL)
        {
            return;
        }
        InOrder(root->left);
        cout<<root->key<<" ";
        InOrder(root->right);
    }

    void PostOrder(node *root)
    {
        if(root==NULL)
        {
            return;
        }
        InOrder(root->left);
        InOrder(root->right);
        cout<<root->key<<" ";
    }

    void PreOrder(node *root)
    {
        if(root==NULL)
        {
            return;
        }
        cout<<root->key<<" ";
        InOrder(root->left);
        InOrder(root->right);
    }
};

int main()
{
    int num;
    BT ob;
    node *root=NULL;
    root=ob.insertBT();
    cout<<"INORDER TRAVERSAL : ";
    ob.InOrder(root);
    cout<<endl<<"POSTORDER TRAVERSAL : ";
    ob.PostOrder(root);
    cout<<endl<<"PREORDER TRAVERSAL : ";
    ob.PreOrder(root);  
    cout<<endl<<"Enter the number you want to search : ";
    cin>>num;
    node *temp=new node;
    temp=ob.SearchBT(root,num);
    if(temp==NULL)
    {
        cout<<"The number does not exist in the tree!"<<endl;
    }
    else
    {
        cout<<"Number found "<<temp->key<<endl;
    } 
}