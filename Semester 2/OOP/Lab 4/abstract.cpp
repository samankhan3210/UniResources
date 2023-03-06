#include<iostream>
using namespace std;
//pre C++ 11 but it was before now we can easily stop inheritance
//by adding the keyword friend infront of super class w/o any dummy class
class Dummy
{
    private:
    Dummy()
    {}
    friend class A;
};
class A: virtual Dummy
{
};
class B: public A
{
};
int main()
{
    B ob;
}