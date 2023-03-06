#include<stdio.h>
int subtotal(float a[], int n);  //function definition
int main()
{
	int n,i;    
	float a[n];
	printf("how many numbers you want to enter?");
	scanf("%d",&n);
	printf("Enter %d numbers:",n);
	for(i=0;i<n;i++)     //this loop is for storing the values entered by the user
	{
		scanf("%f",&a[i]);
	}
	printf("\tBefore Update\n");
	for(i=0;i<n;i++)             //this loop is to print the values stored in the array
	{
		printf("%.1f\t",a[i]);
	}
	subtotal(a,n);            //function calling
}
int subtotal(float a[], int n)    //function declaration
{
	int i;
	printf("\n\tAfter Update\n");
	for(i=0;i<n;i++)         //this loop is for printing the values after update
	{
		if(i==0)               // this condition is to print the first value
		{
		   printf("%.1f\t",a[i]);     //i used these condition so the first value of the array doesnot get ptinted repeatedly
  	    }
		else            // this condition is to print the rest of the values 
		{
			a[i]=a[i]+a[i-1];
		    printf("%.1f\t",a[i]);
		}
	}
}
