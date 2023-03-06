/*
* C prpgram to swap two numbers without using temporary variable.
*/
#include<stdio.h>
int main()
{
	int x, y;
	printf("Enter the value of x:");
	scanf("%d", &x);
	printf("Enter the value of y:");
	scanf("%d", &y);
	printf("Before swapping x=%d, y=%d", x, y);
	/*
	* Swapping process
	*/
	x=x+y;
	y=x-y;
	x=x-y;
	printf("After swapping x=%d, y=%d", x, y);
	getche();
}
