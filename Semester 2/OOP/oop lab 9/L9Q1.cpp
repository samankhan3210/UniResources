#include<iostream>
using namespace std;
class Complex
{
    int a,b;
	public:
		void setComplex(int a, int b)
		{
			this->a=a;
            this->b=b;
        }
        Complex()
        {

        }
        void show()
        {
            cout<<a<<"+"<<b<<"i"<<endl;
        }
        Complex operator + (Complex ob) 
        {
            Complex temp;
            temp.a= this->a + ob.a;  
            temp.b= this->b + ob.b;  
            return temp;
        }
	
};
int main()
{
    int p,q,r,s;
    cout<<"Enter real part of first number: ";
    cin>>p;
    cout<<"Enter imaginary part of first number: ";
    cin>>q;
    Complex c1;
    c1.setComplex(p,q);
    cout<<"Enter real part of second number: ";
    cin>>r;
    cout<<"Enter imaginary part of second number: ";
    cin>>s;
    Complex c2;
    c2.setComplex(r,s);
    cout<<"First Number : ";
    c1.show();
    cout<<"Second Number : ";
    c2.show();
    Complex c3=c1+c2;
    cout<<"Number After Addition : ";
    c3.show();
}
