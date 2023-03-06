#include"Q1class.cpp"
#include<iostream>

using namespace std;

int main()
{
    DoublyLL ob1;
    int i, a[50], n, index;
    cout<<"How many numbers do you want to enter in the linked list : ";
    cin>>n;
    cout<<"Enter"<<n<<" numbers in the list : "<<endl;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        ob1.add_node(a[i]);
    }
    ob1.Print();
    cout<<"Enter the index you want to display the value of : ";
    cin>>index;
    cout<<"Value stored at "<<index<<" is  : "<<ob1.getNth(index)<<endl;
}