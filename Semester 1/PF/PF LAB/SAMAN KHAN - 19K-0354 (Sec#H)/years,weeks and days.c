/*
* C program to convert given number of days into years, weeks and days.
*/
#include<stdio.h>
int main()
{
	int NoOfDays, year, week, days;
	printf("Enter the Number of Days"),
	scanf("%d", &NoOfDays);
	year=NoOfDays/365;
	week=(NoOfDays%365)/7;
	days=(NoOfDays%365)%7;
	printf("%d is equal to %d year, %d week and %d days", NoOfDays, year, week, days);
}
