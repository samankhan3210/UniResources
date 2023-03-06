#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>

struct employee
{
	char name[35];
	char dob[15]; 
	int ID;
	char dep[35];
	float salary;
}e;

void add_emp()
{
FILE *fp;
char another='Y';	
fp=fopen("EmpManSys.txt","a+");
if(fp==NULL)
{
	puts("Cannot Open File");
	exit(1);
}
while(another=='Y')
{
	printf("\nEnter the employee name: ");
	scanf("%s",e.name);
	printf("Enter the employee's date of birth: ");
	scanf("%s",e.dob);
	printf("Enter the employee's ID: ");
	scanf("%d",&e.ID);
	printf("Enter the employee's department: ");
	scanf("%s",e.dep);
	printf("Enter the employee's salary: ");
	scanf("%f",&e.salary);
	fprintf(fp,"%s\t%s\t%d\t%s\t%.2f\n",e.name,e.dob,e.ID,e.dep,e.salary);
	printf("Do you want to add another employee's information?[Y/N] ");
	fflush(stdin);
	another=getche();
	if(another=='Y')
	{   continue;   }
	else
	{      main();    }
}
fclose(fp);
}
void display_emp()
{
FILE *fp;
char another='Y';	
fp=fopen("EmpManSys.txt","r");
if(fp==NULL)
{
	puts("Cannot Open File");
	exit(1);
}
while(another=='Y')
{
	fscanf(fp,"\n%s\t%s\t%d\t%s\t%.2f\n",e.name,e.dob,&e.ID,e.dep,&e.salary);
	printf("\n%s\t%s\t%d\t%s\t%.2f\n",e.name,e.dob,e.ID,e.dep,e.salary);
	printf("Do you want to add another employee's information?[Y/N] ");
	fflush(stdin);
	another=getche();
	if(another=='Y')
	{   continue;   }
	else
	{      main();    }
}
fclose(fp);
}
void delete_emp()
{
	FILE *fp;
	FILE *fpx;
	int a,ch;
	printf("Enter the id of the employee whose record you want to delete");
	scanf("%d",&ch);
	fp=fopen("EmpManSys.txt","r");
	fpx=fopen("EmployeeEX.txt","w");
if(fp==NULL)
{
	puts("Cannot Open File");
	exit(1);
}
else
{	while(fscanf(fp,"\n%s\t%s\t%d\t%s\t%.2f\n", e.name, e.dob,&e.ID,e.dep,&e.salary) != EOF)
{ 	
	if(ch!=e.ID)
	{
		fprintf(fpx,"\n%s\t%s\t%d\t%s\t%.2f",e.name,e.dob,e.ID,e.dep,e.salary);
	}
}
	printf("\nRecord Deleted\n");
	fclose(fp);
	fclose(fpx);
	remove("EmpManSys.txt");
	rename("EmployeeEX.txt", "EmpManSys.txt");
}
}
int main()
{
	int a,ch;
	printf("\n\t\tSelect your choice");
	printf("\n1. Add Employee\n2. Display Employee\n3. Delete Employee\n4. Exit");
	printf("\nEnter your choice: ");
	scanf("%d",&a);
	switch (a)
	{
		case 1:
			{ 
			    add_emp();
			    break;
			}
		case 2:
			{
				display_emp();
				break;
			}
		case 3:
			{
				delete_emp();
				break;
			}
	    case 4:
	    	{
	    		exit(1);
	    		break;
			}
		default:
		{
	        printf("Invalid Choice!\n Try Again");
			break;
		}
	}
	printf("Do you wish to return to the main menu?[Y/N] ");
	scanf("%c",&ch);
	if(ch == 'Y')
	{
		system("cls");
		main();
	}
	else if(ch == 'N')
	{
		printf("\n< THIS EMPLOYEE MANAGEMENT SYSTEM IS MADE BY SAMAN KHAN >");
	}
}
