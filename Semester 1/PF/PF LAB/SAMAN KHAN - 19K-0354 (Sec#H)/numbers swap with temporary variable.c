/*
* C program to swap two numbers using temporary variable.
*/
#include<stdio.h>
int main()
{
	int a, b, c;
	printf("Enter the value of a:");
	scanf("%d", &a);
	printf("Enter the value of b:");
	scanf("%d", &b);
	printf("Before Swapping a=%d, b=%d", a, b);
	/*
	* Swapping logic
	*/
	c=a;
	a=b;
	b=c;
	printf("After Swapping a=%d, b=%d", a, b);
}
