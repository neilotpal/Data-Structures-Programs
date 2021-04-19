//Prefix Evaluation
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define MAX 100
int stack[MAX];
int top=-1;
void push(int);
int pop();

int main()
{
	char exp[100];
	int value,op1,op2,i,len;
	printf("Enter the Prefix Expression: \n");
	gets(exp);
	len=strlen(exp);
	for(i=len-1;i>=0;i--){
		if(isdigit(exp[i]))
		{
			push((int)(exp[i]-'0'));
		}
		else
		{
			op1=pop();
			op2=pop();
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
	}
	printf("Value of the Postfix Expression is: %d\n",pop());
	return 0;
}
/*float evaluatePostfix(char exp[])
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
*/
void push(int value){
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
int pop(){
	int val=-1;
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
