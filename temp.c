#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	char corpus[1000];
	char target[1000];
	char ctemp[1000];
	char ttemp[1000];
	char *c=corpus;
	char *t=target;
	size_t max=1000;
	int match,total;
	ssize_t l;
	l=getline(&t, &max, stdin);
	target[l-1]='\0';	
	while((l=getline(&c, &max, stdin)) >1){
		match=total=0;
		int tcount=0,ccount=0;
		char *str[20];		
		corpus[l-1]='\0';		
		strcpy(ctemp, corpus);
		char *corp=strtok(ctemp," ");
		int i=0;
		while(corp != NULL){
			++ccount;
			strcpy(str[i], corp);i++;
			corp=strtok(ctemp," ");	
	        }
		int j=0;
		for(j; j<i; j++){printf("%s\n", str[j]);}
/*		strcpy(ttemp, target);
		char *tar=strtok(ttemp," ");
		while(tar != NULL){
			++tcount;
			if(strcmp(corp, tar) != 0); 
			else {++match;}
				tar=strtok(NULL," ",&endtar);
		}	
		printf("%.2f:%s\n",((float)match)/(ccount+tcount-match),corpus); */
	}
	return 0;
}
