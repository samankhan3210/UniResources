/*
* C program to find the time left for Procastination day.
*/
#include<stdio.h>
int main()
{
	int total=0, asked=0, days=0, minutes=0, seconds=0;
	printf("Enter today's date=");
	scanf("%d", &asked);
	printf("Enter expected date=");
	scanf("%d", &total);
	days=total-asked;
	minutes=days*24*60;
	seconds=minutes*60;
	printf("Dear Procastinator,");
	printf("you still have to wait for %d,days(%d,minutes and %d,seconds)before you can procastinate!", days, minutes, seconds);
}
