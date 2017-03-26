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
	int left=0, temp=0;
	strcpy(str1, str);	
	for(int i=0; str1[i] != '\0'; i++){
		if(str1[i]>='a' && str[i]<='z')
		   str1[i]=n+48;
	}
	for(int i=0; str1[i] != '\0'; i++){
		if(str1[i]=='('){ 
			++i;
			left=(str1[i]-'0');
			while(str[i] != ')'){
				++i;							
				if(str1[i]=='^'){
					left=pow(left, str1[++i]-'0'); 
				}
				else if(str[i]=='+'){
					left += (str1[++i]-'0') ;
				}
				else if(str1[i]=='/'){
					left /= (str1[++i]-'0');
				}
				else if(str1[i]=='-'){
					left -= (str1[++i]-'0');
				}
				else if(str1[i]=='*'){
					left *= (str1[++i]-'0');
				}
			}
		}
		
		else if(str1[i]=='^'&& str[i+1] != '('){
			left=pow(left, str1[++i]-'0');
		}
		else if(str[i]=='+' && str[i+1] != '('){
			left += (str1[++i]-'0') ;
		}	
		else if(str1[i]=='/' && str[i+1] != '('){
			left /= (str1	[++i]-'0');
		}
		else if(str1[i]=='-'&& str[i+1] != '('){
			left -= (str1[++i]-'0');
		}
		else if(str1[i]=='*' && str[i+1] != '('){
			left *= (str1[++i]-'0');
		}
		else if(str[i] != '(' && str[i] != '*' && str[i] != '-' && str[i] != '+' && str[i] != '/' && str[i] != '^'){
			left=str1[i]-'0';	
		}
		else{
			int j=i;
			if(str1[++j]=='('){ 
			++j;
			temp=str1[j++]-'0';
			while(str[j]!= ')'){
											
				if(str1[j]=='^'){
					temp=pow(temp, str1[++j]-'0');
					++j;
				}
				else if(str[j]=='+'){
					temp += (str1[++j]-'0') ;
					++j;
				}
				else if(str1[j]=='/'){
					temp /= (str1[++j]-'0');
					++j;					
				}
				else if(str1[j]=='-'){
					temp -= (str1[++j]-'0');
					++j;
				}
				else if(str1[j]=='*'){
					temp *= (str1[++j]-'0');
					++j;
				}
			}
			if(str1[i]=='^'){
				left=pow(left, temp);
				}
			else if(str1[i]=='+'){
					left += temp ;
				}
			else if(str1[i]=='/'){
					left /= temp;
				}
			else if(str1[i]=='-'){
					left -= temp;
				}
			else if(str1[i]=='*'){
					left *= temp;
				}
			i=j;
		  	}
			
		}
		
	}
		printf("%d\n", left);		
		scanf("%d",&n);
   }
}
