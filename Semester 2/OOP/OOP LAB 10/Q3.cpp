//LAB 10 QUESTION#03
#include<iostream>
using namespace std;

class Shape
{
    public:
    Shape()
    {}
    virtual void RectangleArea(float l, float b)=0;
    virtual void CircleArea(int r)=0;
    virtual void SquareArea(int s)=0;
};

class Area: public Shape
{
    float RA, SA, CA;
    public:
    void RectangleArea(float length, float breadth)
    {
        RA=length*breadth;
        cout<<"AREA OF RECTANGLE : "<<RA<<endl;
    }
    void CircleArea(int radius)
    {
        CA=3.14*radius*radius;
        cout<<"AREA OF CIRCLE : "<<CA<<endl;
    }
    void SquareArea(int side)
    {
        SA=side*side;
        cout<<"AREA OF SQUARE : "<<SA<<endl;
    }
};

int main()
{
    int L, B, S, R;
    cout<<"Enter the length of rectangle : ";
    cin>>L;
    cout<<"Enter the breadth of rectangle : ";
    cin>>B;
    cout<<"Enter the radius of circle : ";
    cin>>R;
    cout<<"Enter the length of the side of square : ";
    cin>>S;
    Area A;
    A.RectangleArea(L,B);
    A.CircleArea(R);
    A.SquareArea(S);
}