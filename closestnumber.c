#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int num;
	scanf("%d", &num);
	if(num==0) return 0;
	long long a[num];
	for(int i=0; i<num;i++){scanf("%lld", &a[i]);}
/*	for(int i=0; i<num;i++){printf("%d", a[i]);}	
	for(int i=0;i<num-1;i++){
		for(int j=i+1;j<num;j++){
			if(a[i]>a[j]){int temp; temp=a[j]; a[j]=a[i]; a[i]=a[j];}			
		}	
	}
*/
	 for (int c = 0 ; c < ( num - 1 ); c++)
	  {
	    for (int d = 0 ; d < num - c - 1; d++)
	    {
	      if (a[d] > a[d+1]) 
	      {
		long long swap   = a[d];
		a[d]   = a[d+1];
		a[d+1] = swap;
	      }
	    }
	  }

	long long min= abs(a[1]-a[0]);
	for(int i=1; i<num; i++){long long min1=abs(a[i-1]-a[i]); if(min1<min){min=min1;}}
	for(int i=1;i<num; i++ ){if(abs(a[i-1]-a[i])==min) printf("%lld %lld ",a[i-1],a[i]);}
//	for(int i=0; i<num;i++){printf("%lld", a[i]);}
	return 0;
}
