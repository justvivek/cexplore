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
		corpus[l-1]='\0';		
		strcpy(ctemp, corpus);
		char *endcorp;
		char *corp=strtok_r(ctemp," ", &endcorp);
		while(corp != NULL){
			++ccount;
			tcount=0;
			strcpy(ttemp, target);
			char *endtar;
			char *tar=strtok_r(ttemp," ", &endtar);
			while(tar != NULL){
				++tcount;
				if(strcmp(corp, tar) != 0); 
				else {++match;}
				tar=strtok_r(NULL," ",&endtar);
			}	
			corp=strtok_r(NULL," ",&endcorp);	
	     }
		printf("%.2f:%s\n",((float)match)/(ccount+tcount-match),corpus);
	}
	return 0;
}	
