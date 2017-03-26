#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAX 100
int main()
{
	int n=0;
	char str[MAX], str1[MAX];
	scanf("%s", str);
	scanf("%d", &n);
	while(n != 1000){
	int left=0;
	strcpy(str1, str);	
	for(int i=0; str1[i] != '\0'; i++){
		if(str1[i]>='a' && str1[i]<='z'){
			str1[i]=n+48;	
			printf("value of str %c \n",str1[i] );		
		}			
		else if(str1[i]=='^'){
			left=pow(str1[i-1]-'0', str1[i+1]-'0');
			++i;
		}
		else if(str[i]=='+'){
			if(str1[i+1]=='x')
			str1[i+1]=n+48;
			left += (str1[++i]-'0') ;
		}
		else if(str1[i]=='/'){
			if(str1[i+1]=='x')
			str1[i+1]=n+48;
			left /= (str1[++i]-'0');
		}
		else if(str1[i]=='-'){
			if(str1[i+1]=='x')
			str1[i+1]=n+48;
			left -= (str1[++i]-'0');
		}
		else if(str1[i]=='*'){
			if(str1[i+1]=='x')
			str1[i+1]=n+48;
			left *= (str1[++i]-'0');
		}

	}
		printf("%d", n, left);		
		scanf("%d",&n);
   }
}





