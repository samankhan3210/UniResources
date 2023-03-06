#include"Q2.cpp"
#include<iostream>

using namespace std;

int main()
{
    List L1;
    List L2;
    int l[12];
    cout<<"Enter 12 numbers : "<<endl;
    for(int i=0; i<12; i++)
    {
        cin>>l[i];
        cout<<endl;
        L1.add_node(l[i]);
    }
    Func_Four(L1,L2);
    cout<<"Old List   : ";
    L1.Show();
    cout<<"New List  : ";
    L2.Show();
}