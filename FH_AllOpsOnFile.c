#include<stdio.h>
#include<stdlib.h>

typedef struct ClientData{
	char fname[30];
	char lname[30];
	int id;
	float salary;
}cdata;

int  enterchoice();
void textFile(FILE *readptr);
void updateRecord(FILE *fptr);
void newRecord(FILE *fptr);
void deleteRecord(FILE *fptr);

int main(){
	FILE *efptr;
	int choice;
	if((efptr=fopen("emp3.rec","rb+"))==NULL){
		printf("File cannot be opened\n");
		return 0;
	}
	else{
		while((choice= enterchoice()) != 5){
			switch(choice){
				
			case 1:
				textFile(efptr);
				break;
			case 2:
				updateRecord(efptr);
				break;
			case 3:
				newRecord(efptr);
				break;
			case 4:
				deleteRecord(efptr);
				break;
			default:
				printf("Wrong Choice\n");
				break;
			}//end switch
		}//end while
	}//end else	
	fclose(efptr);
	return 0;
}//end main

void textFile(FILE *readptr){
	FILE *wfptr;
	cdata c2={"","",0,0};
	if((wfptr=fopen("acc.txt","w+"))==NULL){
		printf("file cannot be opened");
	}
	else{
//		fscanf(readptr, "%s%s%d%f", c2.fname,c2.lname,&c2.id,&c2.salary);
		rewind(readptr);
		fprintf(wfptr,"%-15s%-15s%-5s%10s\n","First Name","Last Name","ID","Salary");
		while(!feof(readptr)){
			fread(&c2 , sizeof(cdata),1,readptr);
			if(c2.id != 0){
			fprintf(wfptr,"%-15s%-15s%-5d%10.2f\n",c2.fname,c2.lname,c2.id,c2.salary);			
			}//end if
		}//end while
		fclose(wfptr);
	}//end else	
}

void updateRecord(FILE *fptr){
	cdata c2={"","",0,0};
	int iden; float sal;
	printf("Enter the id for salary updation");
	scanf("%d",&iden);
	fseek(fptr,(iden-1)*sizeof(cdata),SEEK_SET);
	fread(&c2,sizeof(cdata),1,fptr);
	if(c2.id == 0){
		printf("\nAccount:%d has no info\n",iden);
	}
	else{
		printf("%-15s%-15s%-5d%10.2f",c2.fname,c2.lname,c2.id,c2.salary);
		printf("Enter the amount to be updated in salary\n");
		scanf("%f",&sal);
		c2.salary += sal;
		printf("%-15s%-15s%-5d%10.2f",c2.fname,c2.lname,c2.id,c2.salary);
		fseek(fptr,(iden-1)*sizeof(cdata),SEEK_SET);
		fwrite(&c2,sizeof(cdata),1,fptr);
	}				
}//end functionality of update record

void newRecord(FILE *fptr){
	cdata c2={"","",0,0};
	int iden;
	printf("Enter the account no(1-100)\n");
	scanf("%d",&iden);
	fseek(fptr, (iden-1)*sizeof(cdata),SEEK_SET);
	fread(&c2, sizeof(cdata),1,fptr);
	if(c2.id != 0){printf("Account: %d already contains information\n",iden);}
	else{
		printf("\nEnter the first, last name, & salary\n");
		scanf("%s%s%f",c2.fname,c2.lname,&c2.salary);
		c2.id=iden;
		fseek(fptr, (c2.id-1)*sizeof(cdata),SEEK_SET);
		fwrite(&c2,sizeof(cdata),1,fptr);
	}
}//end functionality of new record

void deleteRecord(FILE *fptr){
	cdata c2;
	cdata c3={"","",0,0};
	int iden;
	printf("Enter the acct no to delete(1-100)\n");
	scanf("%d",&iden);
	fseek(fptr,(iden-1)*sizeof(cdata),SEEK_SET);
	fread(&c2, sizeof(cdata),1,fptr);
	if(c2.id==0){printf("Account: %d does not exist\n", iden);}
	else{
		fseek(fptr,(iden-1)*sizeof(cdata),SEEK_SET);
		fwrite(&c3,sizeof(cdata),1,fptr);
	}
}//end functionality of delete record
int enterchoice(){
	int option;
	printf("\nEnter your choice\n"
		"1. Store formatted file account acct.txt for printing\n"
		"2. Update account\n"
		"3. New Account\n"
		"4. Delete Account\n"
		"5. End the Program\n");
	scanf("%d", &option);
	return option;
}
