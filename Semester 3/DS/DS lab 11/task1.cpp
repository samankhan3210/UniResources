#include<iostream>
#include<queue>
#include<stack>
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

    bool BFS(node *root, int d)
    {
        queue<node *> q;
        q.push(root);
        while(q.empty()==false)
        {
            node *temp=new node;
            temp=q.front();
            q.pop();
            if(temp->key==d)
            {
                cout<<temp->key;
                return true;
                break;
            }
            if(temp->left!=NULL)
            {   
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {   
                q.push(temp->right);
            }
        }
        return false;
    }

    bool DFS(node *root, int d)
    {
        int sum=0, i=0;
        stack<node *> s;
        s.push(root);
        while(s.empty()==false)
        {
            node *temp=new node;
            temp=s.top();
            s.pop();
            if(temp->key==d)
            {
                cout<<temp->key;
                return true;
                break;
            }
            if(temp->left!=NULL)
            {   
                s.push(temp->left);
            }
            if(temp->right!=NULL)
            {   
                s.push(temp->right);
            }
        }
        return false;
    }
};

int main()
{
    int n, i=0, arr[50], num1, num2;
    cout<<"Enter the elements you want to enter in the BST: ";
    cin>>n;
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    BinarySearchTree ob;
    node *root=NULL;
    for(int i=0; i<n; i++)
    {
        root=ob.insertBST(root,arr[i]);
    }
    cout<<"Using Breadth First Search!"<<endl;
    cout<<"Enter the number you want to search : ";
    cin>>num1;
    if(ob.BFS(root,num1)==true)
    {
        cout<<" FOUND."<<endl;
    }
    else
    {
        cout<<"Number does not exist in the tree."<<endl;
    }
    cout<<"Using Depth First Search!"<<endl;
    cout<<"Enter the number you want to search : ";
    cin>>num2;
    if(ob.DFS(root,num2)==true)
    {
        cout<<" FOUND."<<endl;
    }
    else
    {
        cout<<"Number does not exist in the tree."<<endl;
    }
}