#include <iostream>
using namespace std;

struct node
{
	int key;
	int height;
	node *left;
	node *right;
};

class AVL
{
	public:
	node* root;
	AVL()
	{
		root = NULL;
	}
	node* insertion(node* newnode, int key)
	{
		node* temp = NULL;
		if(!newnode)
		{
			temp = new node;
			temp->key = key;
			temp->height = 1; // by default
			temp->left = temp->right= NULL;
			return temp;
		}
		if(newnode->key > key)
		{
			newnode->left = insertion(newnode->left,key);
		}
		else if(newnode->key < key)
		{
			newnode->right = insertion(newnode->right,key);
		}
		newnode->height = getHeight(newnode);
		if(getBalance(newnode)==2 && getBalance(newnode->left)==1) 
		{
			return rotateLeft(newnode);
		}
		else if (getBalance(newnode)==2 && getBalance(newnode->left)==-1) 
		{
			return rotateLeftRight(newnode);
		}
		else if (getBalance(newnode)==-2 && getBalance(newnode->right)==-1)
		{
			return rotateRight(newnode);
		}
		else if (getBalance(newnode)==-2 && getBalance(newnode->right)==1)
		{
			return rotateRightLeft(newnode);
		}
		return newnode;
	}
	node* rotateLeft(node* newnode)
	{
		node *temp1 = newnode->left;
		node *temp2 = temp1->right;
		temp1->right = newnode;
		newnode->left = temp2;
		newnode->height = getHeight(newnode) ;
		temp1->height = getHeight(temp1);
		if(newnode==root)
		{
			root = temp1;
		}
		return temp1;
	}
	
	node* rotateRight(node* newnode)
	{
		node *temp1 = newnode->right;
		node *temp2 = temp1->left;		
		temp1->left = newnode;
		newnode->right = temp2;
		newnode->height = getHeight(newnode) ;
		temp1->height = getHeight(temp1);		
		if(newnode==root)
		{
			root = temp1;
		}
		return temp1;
	}
	node* rotateRightLeft(node* newnode)
	{
		node* temp1 = newnode->right;
		node* temp2 = temp1->left;
		newnode->right = temp2->right;
		temp1->left = temp2->left;
		temp2->left= newnode;
		temp2->right= temp1;
		temp1->height = getHeight(temp1);
		newnode->height = getHeight(newnode);
		temp2->height = getHeight(temp2);
		if(root==newnode)
		{
			root = temp2;
		}
		return temp2;
	}
	
	node* rotateLeftRight(node* newnode)
	{
		node *temp1= newnode->left;
		node *temp2= temp1->right;
		
		
		temp1->right = temp2->left;
		newnode->left = temp2->right;
		temp2->left= temp1;
		temp2->right= newnode;
		
		temp1->height = getHeight(temp1);
		newnode->height = getHeight(newnode);
		temp2->height = getHeight(temp2);
		
		if(root==newnode)
		{
			root= temp2;
		}
		return temp2;
	}
	
	int getHeight(node* newnode)
	{
		int hl, hr;
		hl = newnode && newnode->left? newnode->left->height:0;
		hr = newnode && newnode->right? newnode->right->height:0;
		return hl>hr ? hl+1 : hr+1;
	}
	
	int getBalance(node* newnode)
	{
		int hl, hr;
		hl = newnode && newnode->left? newnode->left->height:0;
		hr = newnode && newnode->right? newnode->right->height:0;
		return hl-hr;
	}
	
    node* Searching(node *newnode, int d)
    {
        if(newnode==NULL)
        {
            return NULL;
        }
        else if(newnode->key==d)
        {
            return newnode;
        }
        else if(newnode->key < d)
        {
            return Searching(newnode->right, d);
        }
        else 
        {
            return Searching(newnode->left, d);
        }
    }
    
	void PreOrder(node *newnode)
	{
		if(newnode==NULL)
		{
			return;
		}
        cout << newnode->key << " ";
		PreOrder(newnode->left);
		PreOrder(newnode->right);
	}
	
    void InOrder(node *newnode)
    {
        if(newnode==NULL)
        {
            return;
        }
        InOrder(newnode->left);
        cout<<newnode->key<<" ";
        InOrder(newnode->right);
    }

    void PostOrder(node *newnode)
    {
        if(newnode==NULL)
        {
            return;
        }
        PostOrder(newnode->left);
        PostOrder(newnode->right);
        cout<<newnode->key<<" ";
    }
    node* minNode(node* newnode)  
    {  
        node *temp=newnode;  
        while (temp->left != NULL)  
        {
            temp=temp->left;  
        }
        return temp;
    }  
    node* deletion(node *newnode, int d)
    {
        if (newnode==NULL)  
        {
            return newnode;  
        }
        if (d < newnode->key)
        {  
            newnode->left=deletion(newnode->left, d);  
        }
        else if(d > newnode->key)  
        {
            newnode->right=deletion(newnode->right, d);  
        } 
        else
        {  
            if( (newnode->left == NULL) || (newnode->right == NULL) )  
            {  
                node *temp=newnode->left ? newnode->left : newnode->right;  
                if (temp==NULL)  
                {  
                    temp=newnode;  
                    newnode=NULL;  
                }  
                else 
                {  
                    *newnode = *temp; 
                } 
                free(temp);  
            }  
            else
            {  
                node* temp=minNode(newnode->right);  
                newnode->key=temp->key;   
                newnode->right=deletion(newnode->right, temp->key);  
            }  
        }  
        if (newnode==NULL) 
        { 
            return newnode;  
        } 
        newnode->height = getHeight(newnode);
		if(getBalance(newnode)==2 && getBalance(newnode->left)==1) 
		{
			return rotateLeft(newnode);
		}
		else if (getBalance(newnode)==2 && getBalance(newnode->left)==-1) 
		{
			return rotateLeftRight(newnode);
		}
		else if (getBalance(newnode)==-2 && getBalance(newnode->right)==-1)
		{
			return rotateRight(newnode);
		}
		else if (getBalance(newnode)==-2 && getBalance(newnode->right)==1)
		{
			return rotateRightLeft(newnode);
		}
		return newnode;
    } 
};

int main()
{
    int n, num, arr[50], num2;
    cout<<"Enter the elements you want to enter in the AVL tree: ";
    cin>>n;
    cout<<"Enter "<<n<<" numbers : ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    AVL ob;
    for(int i=0; i<n; i++)
    {
        ob.root=ob.insertion(ob.root,arr[i]);
    }
    cout<<endl<<"Enter the number you want to search : ";
    cin>>num;
    node *temp=new node;
    temp=ob.Searching(ob.root,num);
    if(temp==NULL)
    {
        cout<<"The number does not exist in the AVL tree!"<<endl;
    }
    else
    {
        cout<<"Number found "<<temp->key<<endl;
    } 
    cout<<"INORDER TRAVERSAL : ";
    ob.InOrder(ob.root);
    cout<<endl<<"POSTORDER TRAVERSAL : ";
    ob.PostOrder(ob.root); 
    cout<<endl<<"PREORDER TRAVERSAL : ";
    ob.PreOrder(ob.root); 
    cout<<endl<<"Enter the number you want to delete : ";
    cin>>num2;
    temp=ob.deletion(ob.root,num2);
    cout<<num2<<" succsessfully deleted!"<<endl;
    cout<<endl<<"PREORDER TRAVERSAL AFTER DELETION: ";
    ob.PreOrder(ob.root); 
}