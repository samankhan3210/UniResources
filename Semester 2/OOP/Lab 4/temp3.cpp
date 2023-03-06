#include<iostream>
#include<string.h>
using namespace std;

template<class T, int size>
class AddArray
{   
    T arr[size];
    public:
    AddArray()
    {
        for(int i=0; i<size; i++)
        {
            arr[i]=i;
        }
    }
    void input(int index, T x)
    {
        arr[index]=x;
    }
    void output(int ss)
    {
        for(int i=0; i<ss; i++)
        {
            cout<<arr[i]<<", ";
        }
    }
    void displaySum(int sz)
    {
        T sum=0;
        for(int i=0; i<sz; i++)
        {
            sum=sum+arr[i];
        }
        cout<<"Sum = "<<sum<<endl;
    }
};

int main()
{
    cout<<"For INT"<<endl;
    int s;
    cout<<"Enter the size of integer array : ";
    cin>>s;
    AddArray<int,10> a1;
    cout<<"Enter integer values into the array : ";
    for(int i=0; i<s; i++)
    {
        int num;
        cin>>num;
        a1.input(i,num);
    }
    a1.output(s);
    a1.displaySum(s);
    cout<<"For FLOAT"<<endl;
    int s2;
    cout<<"Enter the size of float array : ";
    cin>>s2;
    AddArray<float,20> a2;
    cout<<"Enter integer values into the array : ";
    for(int i=0; i<s2; i++)
    {
        float num2;
        cin>>num2;
        a2.input(i,num2);
    }
    a2.output(s2);
    a2.displaySum(s2);
}