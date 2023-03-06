#include <iostream> 
#include <string> 
using namespace std; 
class Shape
{
    public:
    void Area(int l, int b)
    {
        cout<<"Area: "<<endl;
    }
}; 
class ShapeArea: public Shape
{
    public: 
    void Area(int l, int b)
    {
        cout<<"Area of the rectangle is: "<<(l*b)<<endl; 
    }
    void Area(int x)
    {
        cout<<"Area of the square is: "<< (x*x)<<endl; 
    }
}; 
int main ()
{
    int x, y, z; 
    cout<<"Enter the length of the rectangle: "; 
    cin>>x; 
    cout<<"Enter the width of the rectangle: "; 
    cin>>y;  
    ShapeArea S1;
    S1.Area(x,y); 
    cout<<"Enter the length of the side of the square: "; 
    cin>>z;
    ShapeArea S2;  
    S2.Area(z); 
}
