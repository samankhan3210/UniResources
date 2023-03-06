#include<stdio.h>
int Upper_half(int n, int a[n][n]);     //function definition
int main()
{
	int n,i,j;
	int a[i][j];
	printf("how many numbers you wnat you enter");
	scanf("%d",&n);
	for(i=0;i<n;i++)     //this loop is for storing the values entered by the user outer for rows and inner for columns
	{
		for(j=0;j<n;j++)
		{
			printf("Enter array in [%d][%d]:",i,j);
	    	scanf("%d",&a[i][j]);
	    }
	}
	printf("\tMatrix Form\n");
	for(i=0;i<n;i++)     //this loop is to print the values stored in the array
	{   	for(j=0;j<n;j++)
		{ 
	    	printf("%d\t",a[i][j]);
	    }
	     printf("\n");
	}
	printf("\n\tThe Output\n");
	Upper_half(n,a);        //function calling
}
int Upper_half(int n, int a[n][n])         //function declaration
{
	int i,j;
	for(i=0;i<n;i++)     //this loop is to print the values after the termination, which will orist upper half matrix
	{  		for(j=0;j<n;j++)
		{ 
		        if(i>j)
		        {	printf("\t");  }
		        else
		        {	printf("%d\t",a[i][j]);   }
	    }
	     printf("\n");
	}
}
