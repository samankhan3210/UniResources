#include<iostream>
using namespace std;

//generic function or template function
// template<class T> void display(T a)  //single parameter
// {
//     cout<<"This is:"<<a<<endl;
// }
// template<class T1, class T2> void display(T1 a, T2 b) //double parameter
// {
//     cout<<"This is:"<<a<<endl;
//     cout<<"This is:"<<b<<endl;
// }
// template<class T1> void display(T1 a, int b) //double with parameter with one being template and other any other data type
// {
//     cout<<"This is:"<<a<<endl;
//     cout<<"This is:"<<b<<endl;
// }
//we can overload template functions but not with same parameter or same number of parameter

//perform some different operation for some specific integer
template<class T> void display(T a)  
{
    cout<<"For all other types:"<<a<<endl;
}
//explicit specializtion
// void display(int a)  
// {
//     cout<<"For int:"<<a<<endl;
// }
template<> void display<int>(int a)  //explicit specialization
{
    cout<<"For int:"<<a<<endl;
}
//in generic function we perform same function for different types of inputs
//in function overloading we perform different function for different types of inputs
int main()
{
   // display(30);         //function 1 will be called
   // display(30,"saman"); //function 2 will be called
   // display('B',30);    //function 3 will be called
   display(30);           //function 5 will be called
   display("Hello");      //function 4 will be called
}