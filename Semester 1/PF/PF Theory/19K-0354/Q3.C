/*
* C program to read temperaturein centigrade and display a message.
*/
#include<stdio.h>
int main()
{
	int T;
	printf("Enter the temperature in Centigrade:");
	scanf("%d", &T);
	if(T<0)
	{
		printf("Freezing weather");
	}
	if(T>=0&&T<=10)
    {
    	printf("Very Cold weather");
    }
    if(T>10&&T<=20)
    {
    	printf("Cold weather");
	}
	if(T>20&&T<=30)
	{
	    printf("Normal in Temp");
    }
    if(T>30&&T<40)
    {
    	printf("It's Hot");
	}
	if(T>=40)
	{
		printf("It's very hot");
	}
}
