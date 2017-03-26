#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){

	int d;
	scanf("%d",&d);
	char str[100100];
	while(d){
		
		scanf("%s", str);
		int n= strlen(str);
		int i=0, j=n-1,k=-1,first=-1;		
		while(i<j){
			if (k== -1 && str[i] != str[j]) {
                	k = i;
               		 i++;
           		 } 
			else if (k != -1 && str[i] != str[j]) {
                	first = n-k-1;
               		 break;
            		}
            		else {
               			 i++;
               			 j--;
            		}
 	      	 }	

        if (k== -1) {
            printf("-1\n");
        }
        else if (first== -1) {
            printf("%d\n", k);
        } 
	else {
            printf("%d\n", n - k - 1);
	}
	--d;
    }
	return 0;
}
