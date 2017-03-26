#include<stdio.h>

int main(){
	int n, sum=0;
	scanf("%d", &n);
	for(int i=n; i<0; i-- ){
	int temp=i;
	do{sum += (temp%10);
		temp=temp/10;
	} while(temp>0);
     }
printf("\n %d", sum);

}
