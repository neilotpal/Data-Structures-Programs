//Postfix Evaluation
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define MAX 100
float stack[MAX];
int top=-1;
void push(float value);
float pop();
float evaluatePostfix(char exp[]);

int main()
{
	char exp[100];
	float value;
	printf("Enter the Postfix Expression: \n");
	gets(exp);
	value=evaluatePostfix(exp);
	printf("Value of the Postfix Expression is: %.2f\n",value);
	return 0;
}
float evaluatePostfix(char exp[])
{
	int i=0;
	float op1,op2,value;
	while(exp[i]!='\0'){
		if(isdigit(exp[i]))
		{
			push((float)(exp[i]-'0'));
		}
		else
		{
			op2=pop();
			op1=pop();
			switch(exp[i]){
				case '+': value=op1+op2;
					     break;
				case '-': value=op1-op2;
					     break;
				case '*': value=op1*op2;
					     break;
				case '/': value=op1/op2;
					     break;
				case '^': pow(op1,op2);
				          break;
			}
			push(value);
		}
		i++;
	}
	return pop();
}

void push(float value){
	if(top==MAX-1)
	{
		printf("\nStack Overflow");
	}
	else
	{
		top++;
		stack[top]=value;
	}
}
float pop(){
	float val=-1;
	if(top==-1)
	{
		printf("\nStack Underflow");
	}
	else
	{
		val=stack[top];
		top--;
	}
	return val;
}
