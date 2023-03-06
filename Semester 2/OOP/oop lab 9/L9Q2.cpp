#include<iostream>
using namespace std;
class Vector
{
    int x,y;
	public:
		void setVector(int x, int y)
		{
			this->x=x;
            this->y=y;
        }
        Vector()
        {

        }
        void show()
        {
            cout<<"X component= "<<x<<"\t"<<"Y component= "<<y<<endl;
        }
        Vector operator + (Vector ob)  //operator overload which will be performing addition
        {
            Vector temp;
            temp.x= this->x + ob.x;  //v3.x = v1.x + v2.x
            temp.y= this->y + ob.y;  //v3.y = v1.y + v2.y
            return temp;
        }
	
};
int main()
{
    int a,b,c,d;
    cout<<"Enter x component for vector 1: ";
    cin>>a;
    cout<<"Enter x component for vector 1: ";
    cin>>b;
    Vector v1;
    v1.setVector(a,b);
    cout<<"Enter x component for vector 2: ";
    cin>>c;
    cout<<"Enter x component for vector 2: ";
    cin>>d;
    Vector v2;
    v2.setVector(c,d);
    cout<<"Vector V1 : ";
    v1.show();
    cout<<"Vector V2 : ";
    v2.show();
    Vector v3=v1+v2;
    cout<<"Vector V3 : ";
    v3.show();
}
