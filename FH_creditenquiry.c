#include<stdio.h>
#include<stdlib.h>

int main(){
	char name[30];
	int request,accno;
	float balance;
	FILE *fptr;
	//Inserting the data into the file emp2.rec
	if((fptr=fopen("emp2.rec","a+"))==NULL){
		printf("File cannot be opened");
		return 0;
	}
	else{
		printf("Enter the name, account no & balance\n");	
		printf("? ");
		scanf("%s%d%f",name,&accno,&balance);
		while(!feof(stdin)){
			fprintf(fptr,"%s %d %.2f\n",name,accno,balance);
			printf("? ");
			scanf("%s%d%f",name,&accno,&balance);		
		}
	}
	fclose(fptr);
	
//fetching the data from the sequential file emp2.rec
	if((fptr=fopen("emp2.rec","r"))==NULL){
		printf("File cannot be opened");
		return 0;
	}
	else{
		printf("Enter Request\n"
			"1.Account with zero balance\n"
			"2.Account with credit balance\n"
			"3.Account with debit balance\n"
			"4.End of run\n"		);
		scanf("%d",&request);
		while(request!=4){
			fscanf(fptr,"%s%d%f",name,&accno,&balance);
			switch(request){
				case 1:
					printf("\nAccount with zero balance\n");	
					while(!feof(fptr)){
						if(balance==0){
							printf("%-13s%-10d%10.2f\n",name,accno,balance);
						}
						fscanf(fptr,"%s%d%f",name,&accno,&balance);						
					}
					break;				
				case 2:
					printf("\nAccount with credit balance\n");	
					while(!feof(fptr)){
						if(balance<0){
							printf("%-13s%-10d%10.2f\n",name,accno,balance);
						}
						fscanf(fptr,"%s%d%f",name,&accno,&balance);						
					}
					break;	
				case 3:
					printf("\nAccount with debit balance\n");	
					while(!feof(fptr)){
						if(balance>0){
							printf("%-13s%-10d%10.2f\n",name,accno,balance);
						}	
						fscanf(fptr,"%s%d%f",name,&accno,&balance);						
					}
					break;
			}//end switch
		rewind(fptr);//return fptr to the begining of the file.
		printf("\n? ");
		scanf("%d",&request);	
		}//end while
	}//end of else
	printf("End of run!!");
	fclose(fptr);			
	return 0;
}
