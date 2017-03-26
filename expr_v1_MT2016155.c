#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

char oterstack[MAX];
int  orandstack[MAX],result[MAX];
char input[MAX],t[MAX];
int topr=-1;
int topd=-1;
int var=0,restemp=0;
void pushorand(int item);
int poporand();
void pushoter(char item);
char popoter();
void calculate();

int main(){
	scanf("%s", t);
	scanf("%d", &var);
	while(var !=1000) {
	strcpy(input, t);
	topr=topd=-1;
	for (int i=0; input[i] != '\0'; i++){
		if(input[i]>='0' && input[i]<='9'){
			if(input[i-1]>='0' && input[i-1]<='9'){
				int temp= poporand();
				pushorand(temp*10+(input[i]-'0'));
			}
			else{
				pushorand(input[i]-'0');
			}
		}
		else if(input[i]>='a' && input[i]<= 'z')
			pushorand(var);
		else if(input[i] =='*' || input[i] =='+' || input[i] =='-' || input[i] =='/' || input[i] =='^'){
			if(topr != -1 && oterstack[topr] != '('){
					calculate();
					pushoter(input[i]);
			}
			else
				pushoter(input[i]);
		}
		else
			calculate();
	}
	while(topr>=0){
		calculate();

	}
	result[restemp++]=orandstack[topd];	
	scanf("%d", &var);
 }
	for(int i=0;i<restemp; i++){printf("%d\n", result[i]);}
	return 0;
}

void pushorand(int item){
	orandstack[++topd]= item;
}

int poporand(){
	int temp = orandstack[topd--];
	return temp;	
}

void pushoter(char item){
	oterstack[++topr]=item;
}

char popoter(){
	char temp = oterstack[topr--];
	return temp;
}

void calculate(){
	int value1, value2;
	char operation;
	value1= poporand();
	value2= poporand();
	operation= popoter();

	switch(operation){
		case '*':
			value2 *= value1;
			break;
		case '/':
			if(value1)
			value2 /= value1;
			else exit(0);
			break;
		case '-':
			value2 -= value1;
			break;
		case '+':
			value2 += value1;
			break;
		case '^':
			value2= pow(value2,value1);
			break;
	}		
	pushorand(value2);
}

