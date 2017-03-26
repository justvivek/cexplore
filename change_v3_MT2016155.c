#include<stdio.h>

int main(){
	int currency[20];
	int change[10];
//	int S[10000];
	int loop=0,cnotes, cdenom;

	scanf("%d", &cnotes);
	scanf("%d", &cdenom);

	for(int j=0; j<cnotes; j++){
		scanf("%d", &currency[j]);
	}

	for(int i=0; i<cdenom; i++){
		scanf("%d", &change[i]);
	}

	for(int k=0; k<cnotes-1; k++)
		for(int l=k+1; l<cnotes; l++){
			if(currency[k]<currency[l]){
				int temp=currency[k];
				currency[k]=currency[l];
				currency[l]=temp;
			}
		}
	for(int j=0; j<cnotes; j++){
		if(j==0)printf("%d", currency[j]);
		else printf(" %d", currency[j]);	
	}printf("\n");

	for(int i=0; i<cdenom; i++){
		int C[change[i]+1], S[change[i]+1];
		int d=change[i];
		for(int j=1; j<=d; j++){
			C[0]=0;
			S[0]=-1;
			int min=20000;
			int coin=-1;
			for(int k=1;k<=cnotes;k++){
				if(currency[k-1] <= j){
					if(1+C[j-currency[k-1]] < min){
						min=1+C[j-currency[k-1]];
						coin=k-1;
					}
				}
			}
			C[j]=min;
			S[j]=coin;
		}
		int i=0;
		while(d>0){
			int count=0;
			if(S[d]==S[d-currency[S[d]]]) while(S[d]==S[d-currency[S[d]]]){d=d-currency[S[d]]; ++count;}
//			else {
				if(!i) {printf("%d:%d",currency[S[d]], ++count); i++;}
				else
					printf(",%d:%d",currency[S[d]], ++count);
					d=d-currency[S[d]]; 
//			}
//			printf("\n------ %d -------\n",d);
		}printf("\n");
		
	}



/*	for(int i=0; i<cdenom; i++){
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
*/	
return 0;
}
