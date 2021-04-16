//Parentheses Checker
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
int top=-1;
char stack[MAX];
void push(char);
char pop();
int main(){
	char exp[MAX],temp;
	int i,flag=1;
	printf("Enter the expression: \n");
	gets(exp);
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='{'||exp[i]=='['||exp[i]=='(')
		push(exp[i]);
		if(exp[i]=='}'||exp[i]==']'||exp[i]==')')
		{
			if(top==-1)
				flag=0;
			else
			{
				temp=pop();
				if(exp[i]==')' && (temp=='{' || temp=='['))
					flag=0;
				if(exp[i]=='}' && (temp=='(' || temp=='['))
					flag=0;
				if(exp[i]==']' && (temp=='{' || temp=='('))
					flag=0;
			}
		}
	}
	if(top>=0)
		flag=0;
	if(flag==1)
	{
		printf("\nIt is a valid expression");
	}
	else
	{
		printf("\nIt is an invalid expression");
	}
	return 0;
}
void push(char ch){
	if(top==MAX-1)
	{
		printf("Stack Overflow");
		exit(1);
	}	
	else{
		top++;
		stack[top]=ch;
	}
}
char pop(){
	if(top==-1)
	{
		printf("Stack Underflow");
	}
	else{
		return(stack[top--]);
	}
}
