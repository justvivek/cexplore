#include<stdio.h>

int main() {
	int acct;
	char name[30];
	double balance;
	FILE *fptr;
	
	if( (fptr= fopen("sample.txt", "w+")) == NULL)
		printf("file could not be opened");
	else{
		printf("Enter the acct, name , balance");
		printf("enter the EOF to end the input");
		printf("?");
		scanf("%d%s%lf", &acct, name, &balance);
		while(!feof(stdin)){
			fprintf(fptr, "%d%s%lf", acct, name, balance);
			printf("?");
			scanf("%d%s%lf",&acct, name, &balance);
		
		}	
		fclose(fptr);

	}
	return 0;
}
