#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
struct tool 
	{
		int rec; 
		char name[30];
		int quantity; 
		float cost;
	}t;
void add_data()
{
FILE *fp;
char another='y';	
fp=fopen("hardware.doc.txt","a+");
if(fp==NULL)
{
	puts("Cannot Open File");
	exit(1);
}
else
{
		while(another=='y')
		{
			printf("Enter the record number: ");
	        scanf("%d", &t.rec);
	    	printf("\nEnter the tool's name: ");
	        scanf("%s", t.name);
	        printf("Enter the quantity of tools: ");
	        scanf("%d", &t.quantity);
	        printf("Enter the tools's cost: ");
		    scanf("%f", &t.cost);
	        fprintf(fp, "\n%d\t%s\t\t%d\t%.2f\t", t.rec, t.name, t.quantity, t.cost); 
	        printf("\nDo you want to add another tool? (y/n)");
	        fflush (stdin);
	        another=getche();
	        fclose(fp);
	    }
}
}
void list_data()
{
	FILE *fp;
    fp=fopen("hardware.doc.txt", "r");
	if(fp==NULL)
{
	puts("Cannot Open File");
	exit(1);
}
		rewind(fp); ///this moves file cursor to start of the file
        while(fscanf(fp, "%d %s %d %.2f", &t.rec, &t.name, &t.quantity, &t.cost) != EOF) /// read the file and fetch the record one record per fetch
        {
            printf("\n%d\t%s\t\t%d\t%.2f\t", t.rec, t.name, t.quantity, t.cost); /// print the name, age and basic salary
        }
        fclose(fp);	
}
void delete_tool()
{
	FILE *fp;
	FILE *fpt;
	int x;
	char another = 'y';
	fp = fopen("hardware.doc.txt","a");
    if(fp == NULL || fpt==NULL)
	{
            printf("Connot open file");
            exit(1);
    }
    else
	{
	while(another== 'y')
    {
        printf("\nEnter record number of the tool to delete:");
        scanf("%d", &x);
        fpt = fopen("temp.txt","w");  /// create a intermediate file for temporary storage
        rewind(fp); /// move record to starting of file
        while(fscanf(fp, "%d %s %d %.2f ", t.rec, t.name, t.quantity, t.cost) != EOF)  /// read all records from file
        {
            if(t.rec!=x)  /// if the entered record match
                {
                    fprintf(fp,"\n%d\t%s\t\t%d\t%.2f\t", t.rec, t.name, t.quantity, t.cost);
                    // fwrite(&e,sizeof(e),1,fp2); /// move all records except the one that is to be deleted to temp file
                }
        }/// remove the orginal file
            rename("temp.txt","hardware.doc.txt"); /// rename the temp file to original file name
            fp = fopen("hardware.doc.txt", "r");
            printf("Do you want to delete another record(y/n) ");
            fflush(stdin);
            fclose(fp);
            remove("hardware.doc.txt"); 
            another = getche();
            fclose(fpt);
    }
}
}
void update_data()
{
	int z, k;
	char another = 'y';
	FILE *fp;
	FILE *fp2;
	fp = fopen("hardware.doc.txt","r");
	fp2 = fopen("extra.txt","w");
	if(fp==NULL || fp2==NULL)
	{
	    printf("Connot open file");
        exit(1);	
	}
	else
	{
	while(another== 'y')
    {
	printf("Enter the record number of the tool that you want to edit:- ");
	scanf("%d",&k);
	while(fscanf(fp, "%d %s %d %.2f ", t.rec, t.name, t.quantity, t.cost) != EOF)
	{
		if(t.rec==z)
		{
			printf("Enter the record number: ");
	        scanf("%d", &t.rec);
	    	printf("\nEnter the tool's name: ");
	        scanf("%s", t.name);
	        printf("Enter the quantity of tools: ");
	        scanf("%d", &t.quantity);
	        printf("Enter the tools's cost: ");
		    scanf("%f", &t.cost);
	        fprintf(fp, "\n%d\t%s\t\t%d\t%.2f\t", t.rec, t.name, t.quantity, t.cost); 
		}
		else
		{
			fprintf(fp2, "\n%d\t%s\t\t%d\t%.2f\t", t.rec, t.name, t.quantity, t.cost); 
		}
	}
		    rename("extra.txt","hardware.doc.txt"); /// rename the temp file to original file name
            fp = fopen("hardware.doc.txt", "r");
            printf("Do you want to update another record(y/n) ");
            fflush(stdin);
            fclose(fp);
            remove("hardware.doc.txt"); 
            another = getche();
            fclose(fp2);
	}
}
}
int main()
{
	int a,tool;
	FILE *fp;
	fp = fopen("hardware.doc.txt","a");
    if(fp == NULL)
	{
            printf("Connot open file");
            exit(1);
    }
    else
	{
	fprintf(fp,"Record#\tTool Name\t\tQuantity\tCost\n");
	fprintf(fp,"3\tElectric sander\t\t7\t57.98\n");
	fprintf(fp,"17\tHammer\t\t76\t11.9\n");
	fprintf(fp,"24\tJigsaw\t21\t11.00\n");
	fprintf(fp,"39\tLawn mower\t\t3\t79.50\n");
	fprintf(fp,"56\tPower saw\t\t18\t99.99\n");
	fprintf(fp,"68\tScrewdriver\t\t106\t6.99\n");
	fprintf(fp,"77\tSledge hammer\t\t11\t21.50\n");
	fprintf(fp,"83\tWrench\t\t34\t7.50\n");
	fclose(fp);
}
	printf("\n\t\tSelect your choice");
	printf("\n1. Add Tool\n2. List the Data\n3. Delete a Tool\n4. Update the Data\n5. Exit");
	printf("\nEnter your choice: ");
	scanf("%d",&a);
	switch (a)
	{
		case 1:
			{ 
			    add_data();
			    break;
			}
		case 2:
			{
				list_data();
				break;
			}
		case 3:
			{
				delete_tool();
				break;
			}
		case 4:
			{
				update_data();
				break;
			}
	    case 5:
	    	{
	    		exit(1);
	    		break;
			}
		default:
		{
	        printf("Invalid Choice!");
			break;
		}
	}
}

