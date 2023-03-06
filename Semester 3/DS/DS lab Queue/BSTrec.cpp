#include<iostream>
using namespace std;

struct node
{
    int key;
    node *left, *right;
};

class BST
{
    public:
    BST()
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

    node* SearchBST(node *root, int d)
    {
        if(root==NULL)
        {
            return NULL;
        }
        else if(root->key==d)
        {
            return root;
        }
        else if(root->key < d)
        {
            return SearchBST(root->right, d);
        }
        else 
        {
            return SearchBST(root->left, d);
        }
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
    int n, num, arr[50];
    cout<<"Enter the elements you want to enter in the BST: ";
    cin>>n;
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    BST ob;
    node *root=NULL;
    for(int i=0; i<n; i++)
    {
        root=ob.insertBST(root,arr[i]);
    }
    
    cout<<"INORDER TRAVERSAL : ";
    ob.InOrder(root);
    cout<<endl<<"POSTORDER TRAVERSAL : ";
    ob.PostOrder(root); 
    cout<<endl<<"PREORDER TRAVERSAL : ";
    ob.PreOrder(root); 
    cout<<endl<<"Enter the number you want to search : ";
    cin>>num;
    node *temp=new node;
    temp=ob.SearchBST(root,num);
    if(temp==NULL)
    {
        cout<<"The number does not exist in the tree!"<<endl;
    }
    else
    {
        cout<<"Number found "<<temp->key<<endl;
    } 
}