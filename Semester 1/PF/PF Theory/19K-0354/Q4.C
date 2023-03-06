/* Cprogram to calculate and print the electricity bill. */
#include<stdio.h>
int main()
{
	int ID, unit;
	char name[25];
	float TA, SC, NA;
	/* here TA= total amount , SC= surcgarge , NA= net amount */
	printf("Customer I.D NO:");
	scanf("%d", &ID);
	printf("Customer Name:");
	scanf("%s", &name);
	printf("Unit Consumed:");
	scanf("%d", &unit);
	if(unit<=199)
	{
		TA=1.20*unit;
		printf("\nAmount Charges @Rs. 1.20 per unit: %f",TA);
	}
	if(unit>=200&&unit<400)
	{
		TA=1.50*unit;
		printf("\nAmount Charges @Rs. 1.50 per unit: %f",TA);
	}
	if(unit>=400&&unit<400)
	{
		TA=1.80*unit;
		printf("\nAmount Charges @Rs. 1.80 per unit: %f",TA);
	}
	if(unit>=600)
	{
		TA=2.00*unit;
		printf("\nAmount Charges @Rs. 2.00 per unit: %f",TA);
	}
	if(TA<100)
	{
		printf("\nTotal Amount=100");
	}
	if(TA>400)
	{
		SC=TA*0.15;
		printf("\nSurcharge Amount:%f",SC);
		NA=SC+TA;
		printf("\nNet Amount=%f",NA);
	}
}
