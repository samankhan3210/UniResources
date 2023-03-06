#include<iostream>
using namespace std;

template<class T>
class MyContainer
{
    T x;
    public:
    MyContainer(T a)
    {
        x=a;
    }
    T increase()
    {
        x=x+1;
        return x;
    }
};

template<>
class MyContainer <char>
{
    public:
    char x;
    MyContainer(char y)
    {
        x=y;
    }
    char upperCase()
    {
        if(x>='a'&&x<='z')
        {
            x=x+'A'-'a';
            return x;
        }    
    }
};

int main()
{
    MyContainer<int> c1(9);
    cout<<c1.increase()<<endl;
    MyContainer<char> c2('l');
    cout<<c2.upperCase()<<endl;
}