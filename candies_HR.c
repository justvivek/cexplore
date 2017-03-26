#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int i,num;
	scanf("%d",&num);
	int stud[num];
	i=0;
	while(i<num){
		scanf("%d\n", &stud[i]);
		++i;	
	}	
	for(int i=0; i<num;i++){
	printf("%d\n",stud[i]);
	}
	int pos[num];
	for(int i=0; i<num; i++){pos[i]=i;}

	for (int c = 0 ; c < ( num - 1 ); c++){
		    for (int d = 0 ; d < num - c - 1; d++)
		    {
		      if (stud[pos[d]] > stud[pos[d+1]]) 
		      {
			int swap   = pos[d];
			pos[d]   = pos[d+1];
			pos[d+1] = swap;
		      }
		    }
	}	
	int candies[num];
	for(int i=0; i<num; i++){candies[i]=0;}
	for(int i=1; i<num; i++){
		if(candies[pos[i]-1]==0 && candies[pos[i]+1==0]){candies[pos[i]]=1;}
		else if (ratings)	
	}

	return 0;
}
