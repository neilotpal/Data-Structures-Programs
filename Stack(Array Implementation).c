// Array Implementation of Stacks

#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX],top=-1;
void push(int[],int);
int pop(int[]);
int peek(int[]);
void display(int[]);

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
				   push(stack,value);
				   break;
			case 2: value=pop(stack);
			        if(value!=-1)
				   printf("\nThe value deleted from the stack is: %d",value);
				   break;
			case 3: value=peek(stack);
				   if(value!=-1)
				   printf("\nTopmost element of the stack is %d",value);
				   break;
			case 4: display(stack);
				   break;
			case 5: exit(1);
		}
	}while(1);
	return 0;
}

void push(int stack[],int val)
{
	if(top==MAX-1)
	{
		printf("\nStack Overflow!!");
	}
	else{
		top++;
		stack[top]=val;
	}
}

int pop(int stack[])
{
	int num;
	if(top==-1)
	{
		printf("\nStack Underflow!!");
		return -1;
	}
	else{
		num=stack[top];
		top--;
		return num;
	}
}

int peek(int stack[]){
	int num;
	if(top==-1)
	{
		printf("\nStack Underflow!!");
		return -1;
	}
	else{
		num=stack[top];
		return num;
	}
}

void display(int stack[]){
	int i;
	if(top==-1)
	{
		printf("\nStack is Empty");
	}
	else{
	
	for(i=top;i>=0;i--)
	printf("\n\t%d",stack[i]);
	printf("\n");
	
	}
}
