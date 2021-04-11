#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *start;
void create_ll();
void display_ll();
void insert_beg();
void insert_end();
void insert_before();
void insert_after();
void delete_beg();
void delete_end();
void delete_node();
void delete_after();
void delete_ll();
void sort_ll();

int main()
{
	int option;
	do{
		printf("\n********Main Menu********\n");
		printf("\n1.Create a Linked List");
		printf("\n2.Display the Linked List");
		printf("\n3.Add a node at the beginning");
		printf("\n4.Add a node at the end");
		printf("\n5.Add a node before a given node");
		printf("\n6.Add a node after a given node");
		printf("\n7.Delete a node from the beginning");
		printf("\n8.Delete a node from the end");
		printf("\n9.Delete a given node");
		printf("\n10.Delete a node after a given node");
		printf("\n11.Delete the entire Linked List");
		printf("\n12.Sort the Linked List");
		printf("\n13.Exit");
		printf("\nEnter your choice :\n");
		scanf("%d",&option);
		switch(option){
			case 1: create_ll();
				   printf("Linked List Created");
				   break;
			case 2: display_ll();
				   break;
			case 3: insert_beg();
				   break;
			case 4: insert_end();
			        break;
			case 5: insert_before();
				   break;
			case 6: insert_after();
				   break;
			case 7: delete_beg();
				   break;
			case 8: delete_end();
				   break;
			case 9: delete_node();
				   break;
			case 10: delete_after();
				    break;
			case 11: delete_ll();
				    break;
			case 12: sort_ll();
			         break;
			case 13: exit(1);
		}
	}while(1);
	return 0;
}
void create_ll(){
	struct node *new_node,*ptr;
	start=NULL;
	int num,n,i;
	printf("\nEnter the number of elements: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\nEnter the data: ");
		scanf("%d",&num);
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=num;
		if(start==NULL)
		{
			new_node->next=NULL;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=new_node;
			new_node->next=NULL;
		}
	
	}
}

void display_ll(){
	struct node *ptr;
	ptr=start;
	printf("\nThe Elements in the Linked List are: \n");
	while(ptr!=NULL)
	{
		printf("%d\t", ptr->data);
		ptr=ptr->next;
	}
}

void insert_beg(){
	int num;
	struct node *new_node;
	printf("Enter the data: ");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=start;
	start=new_node;
}

void insert_end(){
	int num;
	struct node *new_node,*ptr;
	printf("\nEnter the data: ");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=new_node;
	new_node->next=NULL;
}

void insert_before(){
	int data,value,num;
	struct node *new_node,*ptr,*preptr;
	printf("\nEnter the data: ");
	scanf("%d",&num);
	printf("\nEnter the value of the node: ");
	scanf("%d",&value);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->data!=value){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
}

void insert_after(){
	int data,value,num;
	struct node *new_node,*ptr,*preptr;
	printf("\nEnter the data: ");
	scanf("%d",&num);
	printf("\nEnter the value of the node: ");
	scanf("%d",&value);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(preptr->data!=value)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
}

void delete_beg(){
	struct node *ptr;
	ptr=start;
	start=start->next;
	free(ptr);
}

void delete_end(){
	struct node *preptr,*ptr;
	ptr=start;
	while(ptr->next!=NULL){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
	free(ptr);
}

void delete_node(){
	int value;
	printf("\nEnter the value you want to delete: ");
	scanf("%d",&value);
	struct node *ptr,*preptr;
	ptr=start;
	if(ptr->data==value)
	{
		delete_beg();
	}
	else
	{
		while(ptr->data!=value)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		preptr->next=ptr->next;
		free(ptr);
	}
}

void delete_after(){
	int value;
	printf("\nEnter the value you want to delete: ");
	scanf("%d",&value);
	struct node *ptr,*preptr;
	ptr=start;
	while(preptr->data!=value)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
}

void delete_ll()
{
	struct node *ptr;
	if(start!=NULL){
		ptr=start;
		while(ptr!=NULL)
		{
			printf("\n%d is to be deleted next",ptr->data);
			delete_beg();
			ptr=start;	
		}
	}
	
}

void sort_ll()
{
	struct node *ptr1,*ptr2;
	ptr1=start;
	int temp;
	while(ptr1->next!=NULL)
	{
		ptr2=ptr1->next;
		while(ptr2!=NULL){
			if(ptr1->data>ptr2->data)
			{
				temp=ptr1->data;
				ptr1->data=ptr2->data;
				ptr2->data=temp;
			}
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
	}
}
