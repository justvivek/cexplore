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
/*	for(int i=0; i<currnotes; i++){
		scanf("%d:%d", &currency[i], &count[i]);
		printf("%d  %d \n", currency[i],count[i]);
	}
*/int i=0;
	while(i<currnotes && scanf("%d:%d", &currency[i], &count[i]) ==2) i++;
	for(int k=0;k<currnotes;k++){if(!k)printf("%d:%d", currency[k],count[k]);else printf(",%d:%d", currency[k],count[k]);}	
/*
//	scanf("%[^\n]s", s);
//	int k=0;
//	while((ch=getchar())!=EOF && ch !='\n'){s[k++]=ch;}
//	fgets(s,100,stdin);
//	if ((strlen(s)>0) && (s[strlen (s) - 1] == '\n'))
 //       {s[strlen (s) - 1] = '\0'; printf("inside str");}
	for(int l=0; l<currdenom; l++){
		printf("taking change");
		scanf("%d ", &change[l]);
		printf("%d\n", change[l]);
		
	}
*/	int j=0;
	while( j<currdenom && scanf("%d",&change[j]) ==1) j++;
	for(int k=0; k<currdenom; k++){printf("%d \n", change[k]);}
/*	int i=0,j=0,temp;
	while (s[i]!='\0'){
		printf("inside while");
		temp=0;
		if(s[i]>='0' && s[i]<='9'){
			while(s[i] != ':'){
				temp=temp*10+s[i];
				i++;
			}currency[j]=temp;
		}
		if(s[i]==':'){
			while(s[i] != ' ' || s[i] != '\0'){
				temp=temp*10+s[i];
				i++;
			}count[j++]=temp;
		}
		if(s[i]==' '){
			while(s[i] != ':'){
				temp=temp*10+s[i];
				i++;
			}currency[j]=temp;
		}
	}
	for(int l=0; l<j; l++){
			if(l==0) printf("%d:%d", currency[l],count[l]);
			else printf(",%d:%d", currency[l],count[l]);	
		}printf("\n");	

*/return 0;
}
