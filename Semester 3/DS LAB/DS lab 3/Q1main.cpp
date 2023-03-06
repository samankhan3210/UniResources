#include "Q1CLASS.cpp"
using namespace std; 

int main()
{
    OrderedDSA odsa(10);
	odsa.insertion(4);
	odsa.insertion(3);
	odsa.searching(2);
	UnorderedDSA udsa(6); 
	udsa.insertion(3,1);
	udsa.insertion(6,10);
	udsa.searching(5);
}