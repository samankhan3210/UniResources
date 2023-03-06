#include<iostream>
using namespace std;
class Vector
{
    int x,y;
	public:
		Vector(int x, int y)
		{
			this->x=x;
            this->y=y;
        }
        Vector()
        {

        }
        void show()
        {
            cout<<"X= "<<x<<"\t"<<"Y= "<<y<<endl;
        }
       // Vector& operator + (Vector ob)  //operator overload which will be performing addition
       //{
       //     this->x= this->x + ob.x;  //v1.x = v1.x + v2.x
       //     this->y= this->y + ob.y;  //v1.y = v1.y + v2.y
       //     return *this;
       // }
	//   Vector operator++(int)
	//   {
	// 	Vector temp;
	// 	 temp.x= this->x +1;
	// 	temp.y= this->y +1;
	//     return temp;
	//   }	  
	//    void operator++(int)   //post increment
	//    {
	// 	   this->x= this->x +1;
	// 	   this->y= this->y +1;
	//    }
	//    void operator++()   //pre increment
	//    {
	// 	   this->x= this->x +1;
	// 	   this->y= this->y +1;
	//    }
	friend ostream& operator << (ostream& o, Vector ob);
};
//gloabal operator overload
ostream& operator << (ostream& o, Vector ob)
{
	o << "x: "<< ob.x <<"\t"<< "y: " << ob.y << endl;
}

int main()
{
    Vector v1(2,3);
    Vector v2(4,5);
	Vector v3(3,2);
	Vector v4;
	// ++v1;
    // cout<<"V1 : ";
    // v1.show();
	// v2++;
    // cout<<"V2 : ";
    // v2.show();
	//cout<<"V3 : ";
    //v3.show();
    //v4=v1+v2+v3;
    //cout<<"V4 : ";
    //v4.show();
	//cout<<"NEW V1 : ";
   // v1.show();
   cout << v1;   //cout is an object ogf ostream class

}
