#include<iostream>
using namespace std;

void SortArray(int a[], int size)
{
    if(size<0)
    {
        return ;
    }
    else
    {
        int temp;
        for(int i=0; i<size; i++)
        {
            if(a[i]>a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }  
        }
        SortArray(a,size-1);
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
    cout<<"\t\t\t\tBefore Sorting the Array"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<"\t";
    }
    SortArray(arr,n-1);
    cout<<endl<<"\t\t\t\tAfter Sorting the Array"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<"\t";
    }
}