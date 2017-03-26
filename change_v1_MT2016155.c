#include<stdio.h>

int main(){
	int currency[20];
	int change[10];
	int count=0,loop=0,cnotes, cdenom;

	scanf("%d", &cnotes);
	scanf("%d", &cdenom);

	for(int j=0; j<cnotes; j++){
		scanf("%d", &currency[j]);
	}

	for(int i=0; i<cdenom; i++){
		scanf("%d", &change[i]);
	}
	for(int j=0; j<cnotes; j++){
		if(j==0) printf("%d", currency[j]);
		else printf(",%d", currency[j]);	
	}printf("\n");
	for(int i=0; i<cdenom; i++){
		int temp= change[i];
		int loop=0;
		for(int j=0; j<cnotes; j++){
			if(temp){
				if(temp/currency[j]){
					count=temp/currency[j];
					temp=temp%currency[j];
					if(loop==0){printf("%d:%d",currency[j],count); ++loop;}
					else printf(",%d:%d",currency[j],count);
				}
			}		
		}printf("\n");
		
	}	
return 0;
}
