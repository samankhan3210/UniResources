#include<stdio.h>
int swap_largest_smallest(int a[], int x);     //function definition
int main()
{
	int x,a[50],i;
	printf("how many numbers you want to enter?");
	scanf("%d",&x);
	printf("Enter %d numbers:",x);
	for(i=0;i<x;i++)     //this loop is for storing the values entered by the user
	{
		scanf("%d",&a[i]);
	}
	printf("\tBefore Swapping\n");
	for(i=0;i<x;i++)     //this loop is to print the values stored in the array
	{
		printf("%d\t",a[i]);
	}
	printf("\n\tAfter Swapping\n");
	swap_largest_smallest(a,x);        //function calling
}

int swap_largest_smallest(int a[], int x)      //function declaration
{
	int i,max,min,MaxP,MinP,j;   //here max annd min are variables to store maximum an minimum values 
	max=min=a[0];               //and MaxP and MinP to store the position of maximum and minimum array
	for(i=0;i<x;i++)          //loop to simultaneously update and replace max and min values
	{
		if(a[i]>max)
		{
			max=a[i];
			MaxP=i;
		}
		if(a[i]<min)
		{
			min=a[i];
			MinP=i;
		}
	}
	j=a[MaxP];              //storing the value of max and min array in a temporary variable 
	a[MaxP]=a[MinP];
	a[MinP]=j;
		for(i=0;i<x;i++)            //this loop is for printing the values after the swap
	{
	   printf("%d\t",a[i]); 
    }
}
