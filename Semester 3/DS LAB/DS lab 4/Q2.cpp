#include<iostream>
using namespace std;

void Reverse(int a[], int size)
{
    if(size<=1)
    {
        return ;
    }
    else
    {
        int temp;
        temp=a[0];
        a[0]=a[size-1];
        a[size-1]=temp;
        Reverse(a+1, size-2);
    }
}

int main()
{
    int i, n, arr[50];
    cout<<"How many numbers you want to enter : ";
    cin>>n;
    cout<<"Enter "<<n<<" numbers : ";
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"\t\t\t\tBefore Reversing the Array"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<"\t";
    }
    Reverse(arr,n);
    cout<<endl<<"\t\t\t\tAfter Reversing the Array"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<"\t";
    }
}