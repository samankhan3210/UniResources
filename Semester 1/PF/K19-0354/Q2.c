#include<stdio.h>
int rotate_right(float a[], int n);        //function definition
int main()
{
	int n,i;
	float a[n];
	printf("how many numbers you wnat you enter");
	scanf("%d",&n);
	printf("Enter %d numbers:",n);
	for(i=0;i<n;i++)     //this loop is for storing the values entered by the user
	{
		scanf("%f",&a[i]);
	}
	printf("\tBefore Rotation\n");
	for(i=0;i<n;i++)              //this loop is to print the values stored in the array
	{
		printf("%.1f\t",a[i]);
	}
	printf("\n\tAfter Rotation\n");
	rotate_right(a,n);        //function calling
}

int rotate_right(float a[] ,int n)    //function declaration
{
	int i;
	float x;
		for(i=n-1;i>0;i--)        //thi loop is to store the value of the array in a temporary variable 
	{                           //also sinultaneously updating it and its position
		x=a[i];         
		a[i]=a[i-1];      
		a[i-1]=x;
	}
	for(i=0;i<n;i++)      //this loop is for printing the values after rotation
	{
		printf("%.1f\t",a[i]);
}
}
