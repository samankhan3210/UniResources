#include<iostream>
using namespace std;

// template<class T>class myList 
// {
//     T arr[10];  //now we won't have to make different arrays for different datatypes
//     T var;
//     public:
//     myList(){}
//     void setVar(T var)
//     {
//         this->var=var;
//     }
//     void showVar()
//     {
//         cout<<var<<endl;
//     }
//};

// template<class T1, class T22>class myList //second generic type (we can sepcify more than one generic type)
// {
//     T1 arr[10];  
//     T2 var;
//     public:
//     myList(){}
//     void setVar(T var)
//     {
//         this->var=var;
//     }
//     void showVar()
//     {
//         cout<<var<<endl;
//     }
// };

template<class T, int size>class myList 
{
    T arr[size];
    public:
    myList(){}
    void showList()
    {
        for(int i=0; i<size; i++)
        {
            cout<<arr[i]<<endl;
        }
    }
    void setVal(int index, T val)
    {
        arr[index]=val;
    }
};
int main()
{
    // myList<int> ob1;  //replace the place holder with integer
    // ob1.setVar(35);
    // ob1.showVar();
    // myList<char> ob2;  //replace the place holder with char
    // ob1.setVar('H');
    // ob1.showVar();
    // myList<char*> ob3;  //replace the place holder with string
    // myList<int, char> ob1;  //for second class
    // ob1.setVar('a');
    // ob1.showVar();
    myList<char, 15> list1; //third class, we are also passing the size of array
    list1.setVal(1,'H');
    list1.showList();
    myList<int, 10> list2;
    list2.setVal(3,100);
    list2.showList();
}