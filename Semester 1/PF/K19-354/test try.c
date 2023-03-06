#include<stdio.h>
	 int modify(int *);
	 int main()
	 {
	   int i;
	   int a[10]={1,2,3,4,5,6,7,8,9,10};
	   modify(a);
	  for(i=0;i<10;i++)
	   {
	     printf("%d\n",a[i]);
	   }
	   return 0;
	 }
	   int modify(int *a)
	   {
	     int i;
	     for(i=0;i<10;i++)
	     {
	      a[i]=a[i]*3;
	      }

	  }  

