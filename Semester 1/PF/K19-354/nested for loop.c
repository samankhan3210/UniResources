


#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int i, j;
	float x, a, b, c=2, sum=0;
	printf("Enter the value for x:- ");
	scanf("%f",&x);
	a=(x-1)/x;
	sum=a;
	for(i=2;i<=7;i++)
	{
		b=pow(a,i)/2;
		sum=sum+b;
	
}
	printf("%.2f is the sum of the series.", sum);
	getch();
	return 0;
}
