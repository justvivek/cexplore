#include<stdio.h>
#include<stdlib.h>

typedef struct ClientData{
	char fname[30];
	char lname[30];
	int id;
	float salary;
}cdata;

int main(){
	cdata c1={"","",0,0};//create client data with default info.
	FILE *fptr;
	if((fptr=fopen("emp3.rec","wb"))==NULL) {printf("File cannot be opened"); return 0;}//fopen opens the file, exit if file cannot be 													opened
	else{
		int i=1;
		for(i;i<=100;i++){
//			c1.id=i;
			fwrite(&c1,sizeof(cdata),1,fptr);
		}	
//	printf("\nValue of i : %d\n",i);
	fclose(fptr);//fclose closes the file
	}
	return 0;
}
