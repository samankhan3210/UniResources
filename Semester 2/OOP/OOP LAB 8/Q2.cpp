#include<iostream>
#include<string.h>
using namespace std;
class Rectangle
{
    public:
    int l, b;
    void Area(int l, int b)
    {
        cout<<"Area of the triangle = "<<(l*b)<<endl;
    }
};
class Rectangle2: public Rectangle
{
    public:
    void Area(int l, int b)
    {
        cout<<"Area = "<<(l*b)<<endl;
    }
};
int main()
{
    int L,B;
    cout<<"Enter the length of the triangle: ";
    cin>>L;
    cout<<"Enter the breadth of the triangle: ";
    cin>>B;
    Rectangle2 r1;
    r1.Area(L,B);
}