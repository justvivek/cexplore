#include<stdio.h>
#include<string.h>
int main(){
  	char target[30][30];
        char line[1000],line1[1000];
        int  ntarget = 0;
	int total, single,i, match,flag[ntarget];
	float result;      
	scanf("%[^\n]", line);
        printf("%s\n", line);
        getchar();
        char *token = strtok(line, " \n\r");
        while (token != NULL) {
                strcpy(target[ntarget++], token);
                token = strtok(NULL, " \n\r");
	}
	while(scanf("%[^\n]",line) != EOF){

		getchar();
		for(i=0;i<ntarget;i++){
			flag[i]=0;
		}
		total=0;
		match=0;
		single=0;
		strcpy(line1, line);
		char * token=strtok(line, " \n\r");
		while(token != NULL){
			total++;
			for(int i=0;i<ntarget;i++){
				if(strcmp(token, target[i])==0)
				{
					
					if (flag[i]==0) {       
                                               	match++;
                                                flag[i]=1;
					}else{
						match++;
						single++;
					}
				}			
			}
			token=strtok(NULL, " \n\r");		
		}
		result=(float)match/(total+ntarget-single-match);
		printf("%0.2f:%s\n", result, line1);
	}
	return 0;
}
