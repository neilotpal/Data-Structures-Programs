#include<stdio.h>
#include<stdlib.h>
#define max 10
int i,arr[max];

void display(int arr[10],int n1)
{
	for(i=0;i<n1;i++)
	printf("%d ",arr[i]);
}

void Insert(int index,int item,int arr[10],int *n)
{   *n=*n+1;
	for(i=*n;i>=index;i--)
	{
		arr[i+1]=arr[i];
	}
	arr[index]=item;
	printf("\n");
	display(arr,*n);
}

int main()
{    int size, flag=0;
	int ch,item,index;
	printf("Enter the number of elements in the array: \n");
	scanf("%d",&size);
	printf("Entering the elements in the array: \n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	do{
		printf("\nEnter the element to be inserted: \n");
		scanf("%d",&item);
		printf("\n1.Insert at Beginning\n");
		printf("2.Insert at End\n");
		printf("3.Insert at kth index\n");
		printf("4.Insert before a given index\n");
		printf("5.Insert after a given index\n");
		printf("6.Insert in a sorted array\n");
		printf("7.Display\n");
		printf("8.Exit\n");
		printf("Enter your choice: \n");
		scanf("%d",&ch);
		switch(ch){
			case 1: Insert(0,item,arr,&size);
				   break;
			case 2: Insert(size,item,arr,&size);
				   break;
			case 3: printf("Enter the index: \n");
				   scanf("%d",&index);
				   Insert(index,item,arr,&size);
				   break;
			case 4: printf("Enter the index: \n");
				   scanf("%d",&index);
				   Insert(index-1,item,arr,&size);
				   break;
			case 5: printf("Enter the index: \n");
				   scanf("%d",&index);
				   Insert(index+1,item,arr,&size);
				   break;
			case 6: for(i=0;i<size;i++)
			        {
			        	if(arr[i]>item)
			        	{
			        		Insert(i,item,arr,&size);
						break;	
					}
				   }
				   break;
			case 7: display(arr,size);
			        break;
		     case 8: exit(0);
		}
		
	}while(ch!=7);
	return 0;
}
