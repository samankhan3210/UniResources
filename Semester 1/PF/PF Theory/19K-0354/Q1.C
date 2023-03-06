/* C program to calculate the grosspay of several employees*/

#include<stdio.h>
int main()
{
	int hours, employees, x=1;
	float HourlyRate, GP, OTH, OTP, TP;
	/* here GP=gross pay , OTH= overtime hours, OTP= overtime pay , TP= total pay of overtime */
	printf("Enter the number of employees:");
	scanf("%d", &employees);
	while(x<=employees)
	{
    printf("\nEnter the number of hours:");
    scanf("%d", &hours);
	printf("\nEnter the number of HourlyRate:");
	scanf("%f", &HourlyRate);
    if(hours<=40)
	{
		GP=hours*HourlyRate;
		printf("\nSalary is $%f", GP);
	}
	if(hours>40)
	{
		GP=40*HourlyRate;
		OTH=hours-40;
		TP=OTH*OTP;
		GP=TP+GP;
		printf("Salary is $%f", GP);
	}
    }
}
