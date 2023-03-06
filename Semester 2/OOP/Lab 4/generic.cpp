#include<iostream>
using namespace std;

template<class T, int size>class MyList 
{
    T arr[size];
    public:
    MyList()
    {
        for(int i=0; i<size; i++)
        {
            arr[i]=i;
        }
    }
    void addElement(int index, T val)
    {
        arr[index]=val;
    }
    bool searchElement(T val)
    {
        for(int i=0; i<size; i++)
        {
            if(arr[i]==val)
            {
                return true;
            }
        
           {
               return false;
           }
           
        }
    }
};

int main()
{
    MyList<int,10> list1;
    bool result=list1.searchElement(5);  
    if(result)
    {
        cout<<"FOUND";
    }
    else
    {
        cout<<"NOT FOUND";
    }
    
}