#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char s[100],ch;
	int currency[20];
	int count[20];
	int change[10];
	int currnotes, currdenom;
	scanf("%d", &currnotes);
	scanf("%d", &currdenom);
	int i=0,j=0,count1=0;
	//taking the currency in form of denominaton:denomination_count for example 100:2 50:4 20:10 10:10 1:100
	while(i<currnotes && scanf("%d:%d", &currency[i], &count[i]) ==2) i++;
		
	while( j<currdenom && scanf("%d",&change[j]) ==1) j++;
//	for(int k=0; k<currdenom; k++){printf("%d \n", change[k]);} // printing the currency for which we need change;

	for(int k=0; k<currnotes-1; k++)
		for(int l=k+1; l<currnotes; l++){
			if(currency[k]<currency[l]){
				int temp=currency[k];
				currency[k]=currency[l];
				currency[l]=temp;
				int tempcount=count[k];
				count[k]=count[l];
				count[l]=tempcount;
			}
		}
		
	//Printing the currency which we have
	for(int k=0;k<currnotes;k++){
		if(!k)
			printf("%d:%d", currency[k],0);
		else 
			printf(",%d:%d", currency[k],0);
	}printf("\n");	

	for(int k=0; k<currdenom; k++){
		int temp= change[k];
		int loop=0;
		for(int l=0; l<currnotes; l++){
			if(temp){
				if(temp/currency[l]){
					count1=temp/currency[l];
					if(count[l]){
						if(count1>count[l]){
							temp= temp - currency[l]*count[l];
							if(loop==0){printf("%d:%d",currency[l],count[l]); ++loop;}
							else printf(",%d:%d",currency[l],count[l]);
							count[l]=0;
						}
						else{
							temp=temp%currency[l];
							count[l]-=count1;
							if(loop==0){printf("%d:%d",currency[l],count1); ++loop;}
							else printf(",%d:%d",currency[l],count1);	
						}	
					}
				}
			}		
		}printf("\n");
		
	}	
	return 0;
}
