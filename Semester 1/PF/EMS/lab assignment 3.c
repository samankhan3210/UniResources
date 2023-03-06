#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <windows.h>
struct employee{
	char name[35];
	char dob[15];
	int employeeID;
	char dept[35];
	float bs;
} e;

void add_emp(){
	FILE *fp;
	long int sizeOfobject;
	char another = 'Y';
	fp = fopen("employee.txt","r+");
    if(fp == NULL){
        fp = fopen("employee.txt","w+");
        if(fp == NULL){
            printf("Connot open file");
            exit(1);
        }
    }
    sizeOfobject = sizeof(e);
	fseek(fp,0,SEEK_END);
    while(another == 'Y'){ 
        fflush(stdin);
        printf("\nEnter name: ");
        gets(e.name);
		printf("\nEnter employeeID: ");
        scanf("%d", &e.employeeID);
        fflush(stdin);
        
        printf("\nEnter dob of birth: ");
        gets(e.dob);
        printf("\nEnter department: ");
        gets(e.dept);
		printf("\nEnter basic salary: ");
        scanf("%f", &e.bs);
		
        fwrite(&e,sizeOfobject,1,fp); 
        

        printf("\nAdd another record(Y/N) ");
        fflush(stdin);
        scanf("\n%c", &another);
	}
}

void display_emp(){
	FILE *fp;
	long int sizeOfobject;
	char another = 'Y';
	fp = fopen("employee.txt","r+");
    if(fp == NULL){
        fp = fopen("employee.txt","w+");
        if(fp == NULL){
            printf("Connot open file");
            exit(1);
        }
    }
    sizeOfobject = sizeof(e);
	rewind(fp); 
    while(fread(&e,sizeOfobject,1,fp)==1){ 
        printf("\n%d\t%s\t%s\t%s  %.2f\n",e.employeeID,e.name,e.dob,e.dept,e.bs); 
    }
}

void delete_emp(){
	FILE *fp,*ft;
	long int sizeOfobject;
	char another = 'Y';
	char empname[40];
	
	fp = fopen("employee.txt","r+");
    if(fp == NULL){
        fp = fopen("employee.txt","w+");
        if(fp == NULL){
            printf("Connot open file");
            exit(1);
        }
    }
    sizeOfobject = sizeof(e);
	
	while(another == 'Y'){
	    
	    fflush(stdin);
	    printf("\nEnter name of employee to delete: ");
	    gets(empname);
	    ft = fopen("Temp.txt","wb+");
	    rewind(fp); 
	    while(fread(&e,sizeOfobject,1,fp) == 1){ 
	        if(strcmp(e.name,empname) != 0){ 
	        
	            fwrite(&e,sizeOfobject,1,ft); 
	        }
	        else{
	        	printf("Record Deleted\n");
			}
	    }
	    fclose(fp);
	    fclose(ft);
	    remove("employee.txt");
	    rename("Temp.txt","employee.txt"); 
	    fp = fopen("employee.txt", "rb+");
	    printf("Delete another record(y/n)");
	    fflush(stdin);
	    scanf("\n%c", &another);
	}
}

void main(){
	
	char choice;
	char another = 'Y';
	printf("\n\t\tSelect your choice");
	printf("\n1. Add Employee\n2. Display Employee\n3. Delete Employee\n4. Exit");
    printf("\nYour Choice: ");
    fflush(stdin);
    scanf("\n%c", &choice);
    switch(choice){
        case '1': {
        	add_emp();
			break;
		}
        case '2':{                
            display_emp();
            break;
		}
        case '3':{                
            delete_emp();
            break;
		}
		case '4':
           {   printf("\nTHANK YOU FOR USING EMPLOYEE MANAGEMENT SYSTEM MADE BY SAMAN KHAN");
		   exit(0);  }
        default:
		{
	        printf("Invalid Choice!\n Try Again");
			main();
		}		
    }

}

