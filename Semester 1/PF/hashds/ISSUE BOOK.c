#include<stdio.h>
#include<string.h>
int main()
{
FILE *fp;
int c;
char another ='Y';
struct Ibook
{
	char name[45];
	char aname[45];
	char cat[45];
	int code;
	int year;
};
struct student
{
	char name[45];
	char rollno[45];
	int days;
};
struct student s;
struct Ibook i;
fp=fopen ("FILE.txt","a+");
if (fp==NULL)
{
	puts ("Cannot Open File");
	return(1);
}
while (another =='Y')
{
	printf("Enter the book's code:- ");
	scanf("%d",c);
   	if(c==i.code)
	{
	printf("The book you want is found");
	printf("%s\t%s\t%s\t%d\t%d",i.name,i.aname,i.cat,i.code,i.year);
	printf("Enter the student's name:- ");
   	gets(s.name);
   	printf("Enter student's roll number:- ");
   	gets(s.rollno);
   	printf("How many days do you want to issue this book for? ");
   	scanf("%d",s.days);
   	printf("%s with roll number %s has issued %s for %d days",s.name,s.rollno,i.name,s.days);
	}
	else
	{
		printf("\nInvalid book code");
	}
   	
   	// if else statement regarrding the book's status whether its available or not
   	printf("\nDo you want to issue another book [Y/N]:");
    fflush(stdin);
   another= getche();
}
fclose(fp);
}
