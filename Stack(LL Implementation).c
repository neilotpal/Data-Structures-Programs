//Linked List Implementation of Stack
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct stack{
	int data;
	struct stack *next;
};
struct stack *top=NULL;
void push(int);
int pop();
int peek();
void display();

int main(){
	int value,ch;
	do{
		printf("\n****MENU****");
		printf("\n1. PUSH");
		printf("\n2. POP");
		printf("\n3. PEEK");
		printf("\n4. DISPLAY");
		printf("\n5. EXIT");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("\nEnter the value you want to push: ");
				   scanf("%d",&value);
				   push(value);
				   break;
			case 2: value=pop();
			        if(value!=-1)
				   printf("\nThe value deleted from the stack is: %d",value);
				   break;
			case 3: value=peek();
				   if(value!=-1)
				   printf("\nTopmost element of the stack is %d",value);
				   break;
			case 4: display();
				   break;
			case 5: exit(1);
		}
	}while(1);
	return 0;
}

void push(int value){
	struct stack *new_node;
	new_node=(struct stack *)malloc(sizeof(struct stack));
	new_node->data=value;
	if(top==NULL){
		new_node->next=NULL;
		top=new_node;
	}
	else{
		new_node->next=top;
		top=new_node;
	}
}

int pop(){
	struct stack *ptr;
	int num;
	ptr=top;
	if(top==NULL){
		printf("\nStack Underflow!!");
		return -1;
	}
	else{
		num=ptr->data;
		top=top->next;
		free(ptr);
		return num;	
	}
}

int peek(){
	struct stack *ptr;
	ptr=top;
	if(top==NULL){
		printf("\nStack Underflow!!");
		return -1;
	}
	else{
		int num=ptr->data;
		return num;
	}
}

void display(){
	struct stack *ptr;
	ptr=top;
	if(top==NULL){
		printf("\nStack Underflow!!");
	}
	else{
		printf("\nElements in the Stack are: \n");
		while(ptr!=NULL)
		{
			printf("\n%d ",ptr->data);
			ptr=ptr->next;
		}
	}
}
