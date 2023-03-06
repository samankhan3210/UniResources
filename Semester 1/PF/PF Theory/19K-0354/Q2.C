/*
* C program to find the eligibility of admission for a professional course.
*/
#include<stdio.h>
int main()
{
	int M, P, C, Total;
	printf("Enter the marks obtained in Physics:");
	scanf("%d", &P);
	printf("Enter the marks obtained in Chemistry:");
	scanf("%d", &C);
	printf("Enter the marks obtained in Mathematics:");
	scanf("%d", &M);
	Total=M+P+C;
	if(M>=65 && P>=55 && C>=50 && Total>=180)
	{
		printf("The candidate is eligible for admission.\n");
	}
}
