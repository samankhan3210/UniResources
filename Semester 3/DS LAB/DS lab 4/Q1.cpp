#include<iostream>
using namespace std;

int Sum_Num(int *a, int size)
{
    if(size<0)
    {
        return 0;
    }
    else if(a[size]%2!=0)
    {
        return Sum_Num(a,size-1);
    }
    else
    {
        return a[size]+Sum_Num(a,size-1);
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
    cout<<"Array : ";
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl<<"Sum of even numbers in the array is : "<<Sum_Num(arr,n-1)<<endl;
} 