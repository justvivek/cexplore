#include<stdio.h>
#include<stdlib.h>
struct Node {
	int value;
	struct Node *l;
	struct Node *r;
}*root=NULL, *temp=NULL;

void create(){
	int data;
	printf("print data");
	scanf("%d",&data );
	temp= (struct Node *)malloc(sizeof(struct Node));
	temp->value= data;
	temp->l=temp->r=NULL;
}
void search(struct Node *t){
	if((temp->value > t->value) && t->r !=NULL)
		search(t->r);
	else if((temp->value > t->value) && t->r ==NULL)
		t->r=temp;
	else if((temp->value < t->value) && t->l !=NULL)
		search(t->l);
	else if((temp->value < t->value) && t->l ==NULL)
		t->l=temp;	
}

void printpreorder(struct Node *t){
	if(t){
		printf("%d \n", t->value);
		printpreorder(t->l);
		printpreorder(t->r);	
	}
}
void main(){
	char ch;
	printf("To enter the values press y then values u want to enter like 1 2 3 4 5 6 7 8 9 to end it press enter");
	while((ch=getchar())!=EOF && ch !='\n'){
/*		printf("Insert element in BST  2015024, to Continue press Y end press  N \n");
		clrscr();
                ch= getchar();
		if(ch == 'Y')	
*/			create();
			if(root==NULL)
				root=temp;
			else
				search(root);
/*		else 
			break;
*/	}
	printpreorder(root);
}
