/*
* C program to calculate area and perimeter of a rectangle.
*/
#include<stdio.h>
int main()
{
	int length, breadth, area, perimeter;
	printf("Enter the Length of Rectangle:");
	scanf("%d", &length);
	printf("Enter the Breadth of Rectangle;");
	scanf("%d", &breadth);
	area=length*breadth;
	perimeter=2*(length+breadth);
	printf("Area of Rectange:%d", area);
	printf("Perimeter of Rectangle:%d", perimeter);
}
