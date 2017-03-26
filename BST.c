#include<stdio.h>
#include<stdlib.h>

struct Node {
	int value;
	struct Node *l;
	struct Node *r;
}*root=NULL, *temp=NULL;

void create(int data){
//	int data;
//	scanf("Enter the Data%d ",&data );
	temp= (struct Node *)malloc(sizeof(struct Node));
	temp->value= data;
	printf("%d\t", temp->value);
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

void inorder(struct Node *t){
	if(t){
		if(t->l) inorder(t->l);
		printf("%d  ", t->value);
		if(t->r) inorder(t->r);	
	}
}
void main(){
	int arr[10]={10,6,7,9,11,20,16,13,19,21};
	int i=0;
	while(i!=10){
		create(arr[i]);
		if(root==NULL)
			root=temp;
		else
			search(root);
		++i;

	}
	inorder(root);

}


