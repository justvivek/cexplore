#include<stdio.h>
#include<stdlib.h>

typedef struct ClientData{
	char fname[30];
	char lname[30];
	int id;
	float salary;
}cdata;

int main(){
//Writing to random access file.
	cdata c1={"","",0,0};//create client data with default info.
	FILE *fptr;	
	if((fptr=fopen("emp3.rec","rb+"))==NULL) {printf("File cannot be opened"); return 0;}//fopen opens the file, exit if file cannot be 													opened
	else{
		printf("enter the id 1 to 100, 0 to end input \n? ");//
		scanf("%d",&c1.id);//user enters id which is copied to the file.
		while(c1.id != 0){
			printf("Enter the fname, lastname & salary\n? ");//user enter first name, last name and Salary.
			fscanf(stdin, "%s%s%f",c1.fname,c1.lname,&c1.salary);//set record fname, lname and salary.	
			fseek(fptr, (c1.id-1)*sizeof(cdata), SEEK_SET);//seek position in file to user specified record.
			fwrite(&c1, sizeof(cdata),1,fptr);//write user specified information in file.
			printf("Enter the id\n? ");
			scanf("%d",&c1.id);
			
		}//end while
	}//end else
	

	fclose(fptr);//fclose closes the file

//Reading data from random access file sequentially
	if((fptr=fopen("emp3.rec","rb"))==NULL) {printf("File cannot be opened"); return 0;}//fopen opens the file, exit if file cannot be 													opened
	else{
		printf("%-7s%-20s%-20s%15s\n","ID NO","First Name","Last Name","Salary");
		while(fread(&c1,sizeof(cdata),1,fptr) && !feof(fptr)){//read all records from untill EOF
			if(c1.id !=0){
				printf("%-7d%-20s%-20s%15.2f\n",c1.id,c1.fname,c1.lname,c1.salary);
			}
		}//end while
		fclose(fptr);
	}//end else
	return 0;
}
