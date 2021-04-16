//Implementing Multiple Stacks
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int topA=-1;
int topB=MAX;
int stack[MAX];
void pushA(int[],int);
int popA(int[]);
int peekA(int[]);
void displayA(int[]);
void pushB(int[],int);
int popB(int[]);
int peekB(int[]);
void displayB(int[]);

int main(){
	int value,ch;
	do{
		printf("\n****MENU****");
		printf("\n1. PUSH-A");
		printf("\n2. POP-A");
		printf("\n3. PEEK-A");
		printf("\n4. DISPLAY-A");
		printf("\n5. PUSH-B");
		printf("\n6. POP-B");
		printf("\n7. PEEK-B");
		printf("\n8. DISPLAY-B");
		printf("\n9. EXIT");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("\nEnter the value you want to push in Stack-A: ");
				   scanf("%d",&value);
				   pushA(stack,value);
				   break;
			case 2: value=popA(stack);
			        if(value!=-1)
				   printf("\nThe value deleted from the Stack-A is: %d",value);
				   break;
			case 3: value=peekA(stack);
				   if(value!=-1)
				   printf("\nTopmost element of the Stack-A is %d",value);
				   break;
			case 4: printf("\nElements of Stack-A are: \n");
				   displayA(stack);
				   break;
			case 5: printf("\nEnter the value you want to push in Stack-B: ");
				   scanf("%d",&value);
				   pushB(stack,value);
				   break;
			case 6: value=popB(stack);
			        if(value!=-1)
				   printf("\nThe value deleted from the Stack-B is: %d",value);
				   break;
			case 7: value=peekB(stack);
				   if(value!=-1)
				   printf("\nTopmost element of the Stack-B is %d",value);
				   break;
			case 8: printf("\nElements of Stack-B are: \n");
				   displayB(stack);
				   break;
			case 9: exit(1);
		}
	}while(1);
	return 0;
}

void pushA(int stack[],int val)
{
	if(topA==topB-1)
	{
		printf("\nStack Overflow!!");
	}
	else{
		topA++;
		stack[topA]=val;
	}
}

int popA(int stack[])
{
	int num;
	if(topA==-1)
	{
		printf("\nStack-A Underflow!!");
		return -1;
	}
	else{
		num=stack[topA];
		topA--;
		return num;
	}
}

int peekA(int stack[]){
	int num;
	if(topA==-1)
	{
		printf("\nStack-A Underflow!!");
		return -1;
	}
	else{
		num=stack[topA];
		return num;
	}
}

void displayA(int stack[]){
	int i;
	if(topA==-1)
	{
		printf("\nStack is Empty");
	}
	else{
	
	for(i=topA;i>=0;i--)
	printf("\n\t%d",stack[i]);
	printf("\n");
	
	}
}

void pushB(int stack[],int val)
{
	if(topB-1==topA)
	{
		printf("\nStack Overflow!!");
	}
	else{
		topB--;
		stack[topB]=val;
	}
}

int popB(int stack[])
{
	int num;
	if(topB==MAX)
	{
		printf("\nStack-B Underflow!!");
		return -1;
	}
	else{
		num=stack[topB];
		topB++;
		return num;
	}
}

int peekB(int stack[]){
	int num;
	if(topB==MAX)
	{
		printf("\nStack-B Underflow!!");
		return -1;
	}
	else{
		num=stack[topB];
		return num;
	}
}

void displayB(int stack[]){
	int i;
	if(topB==MAX)
	{
		printf("\nStack-B is Empty");
	}
	else{
		for(i=topB;i<MAX;i++)
		printf("\n\t%d",stack[i]);
		printf("\n");
	}
}
