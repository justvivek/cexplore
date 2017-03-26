#include<stdio.h>
#include<stdlib.h>

//Entering the data in the File

/*
int main(){
	FILE *fptr;
	char name[20];
	int age;
	float salary;
	fptr= fopen("emp1.rec", "w");
	if(fptr==NULL){
		printf("file doesnot exist");
		return 0;
	}
	printf("enter the name,age and salary\n");	
	printf("?  ");
	scanf("%s%d%f",name,&age,&salary);
	while(!feof(stdin)){
		fprintf(fptr,"%s %d %.2f\n", name, age, salary);
		printf("? ");
		scanf("%s%d%f",name,&age,&salary);	
	}
//	scanf("%s", name);
//	fprintf(fptr,"Name=  %s\n", name);
//	scanf("%d",&age);
//	fprintf(fptr,"Age=  %d\n", age);
//	scanf("%f",&salary);
//	fprintf(fptr,"Salary=  %.2f\n", salary);

	fclose(fptr);
	return 0;
}

*/

//Reading and printing the Data from the Sequential File
int main(){
	FILE *fptr;
	char name[20];
	int age;float salary;
	char fname[50];
	scanf("%s", fname);

	if((fptr=fopen(fname,"r"))== NULL){
		printf("file cannot be opened");
		 return 0;
	}
	else{
		printf("%-10s%-13s%s\n","Name","Age","Salary");
		fscanf(fptr,"%s%d%f",name,&age,&salary);
	}
	while(!feof(fptr)){
		printf("%-10s%-13d%7.2f\n",name,age,salary);
		fscanf(fptr,"%s%d%f",name,&age,&salary);
	}
	fclose(fptr);
//Reading the file stored on the disk character wise.
/*	fptr=fopen(fname, "r");
	if(fptr==NULL){printf("file cannot be opened"); return 0;}
	
	char ch = fgetc(fptr);
	while(ch != EOF){ printf("%c", ch); ch=fgetc(fptr);}
	fclose(fptr);
*/
	return 0;
	
}

