//Doubly Linked List

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
	struct node *prev;
	int data;
	struct node *next;
};

struct node *start=NULL;
void create_dll();
void display_dll();
void insert_beg();
void insert_end();
void insert_before();
void insert_after();
void delete_beg();
void delete_end();
void delete_after();
void delete_before();
void delete_dll();

int main(){
	int ch;
	do{
		printf("\n***MENU***");
		printf("\n1.Create a Doubly Linked List");
		printf("\n2.Display the list");
		printf("\n3.Insert a node at the beginning of the list");
		printf("\n4.Insert a node at the end of the list");
		printf("\n5.Insert a node before a given node");
		printf("\n6.Insert a node after a given node");
		printf("\n7.Delete a node from beginning of the list");
		printf("\n8.Delete a node from end of the list");
		printf("\n9.Delete a node before a given node");
		printf("\n10.Delete a node after a given node");
		printf("\n11.Delete the entire list");
		printf("\n12.Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: create_dll();
				   printf("\nDoubly Linked List Created!!");
				   break;
			case 2: display_dll();
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
			case 9: delete_before();
				   break;
			case 10: delete_after();
				    break;
			case 11: delete_dll();
				    break;
			case 12: exit(1);
		}
	}while(1);
	return 0;
}

void create_dll(){
	start=NULL;
	int n,num,i;
	struct node *ptr,*new_node;
	printf("\nEnter the number of nodes you want to enter: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter data: ");
		scanf("%d",&num);
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=num;
		if(start==NULL){
			new_node->prev=NULL;
			new_node->next=NULL;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=new_node;
			new_node->prev=ptr;
			new_node->next=NULL;
		}
	}
}

void display_dll()
{
	struct node *ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("\t%d",ptr->data);
		ptr=ptr->next;
	}
}

void insert_beg()
{
	struct node *new_node;
	int num;
	printf("\nEnter data: ");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	start->prev=new_node;
	new_node->data=num;
	new_node->prev=NULL;
	new_node->next=start;
	start=new_node;
}

void insert_end(){
	struct node *new_node,*ptr;
	int num;
	printf("\nEnter data: ");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->prev=ptr;
	new_node->next=NULL;
}

void insert_before(){
	struct node *new_node,*ptr;
	int num,value;
	printf("\nEnter data: ");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	printf("\nEnter the value of the node you want to insert before: ");
	scanf("%d",&value);
	ptr=start;
	while(ptr->data!=value)
	{
		ptr=ptr->next;
	}
	new_node->next=ptr;	
	new_node->prev=ptr->prev;
	ptr->prev->next=new_node;
	ptr->prev=new_node;
}

void insert_after(){
	struct node *new_node,*ptr;
	int num,value;
	printf("\nEnter data: ");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	printf("\nEnter the value of the node you want to insert after: ");
	scanf("%d",&value);
	ptr=start;
	while(ptr->data!=value)
	{
		ptr=ptr->next;
	}
	new_node->prev=ptr;
	new_node->next=ptr->next;
	ptr->next=new_node;
	ptr->next->prev=new_node;
}

void delete_beg(){
	struct node *ptr;
	ptr=start;
	start=start->next;
	start->prev=NULL;
	free(ptr);
}

void delete_end(){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->prev->next=NULL;
	free(ptr);
}

void delete_before(){
	struct node *ptr,*temp;
	int value;
	ptr=start;
	printf("\nEnter the value you want to delete before: ");
	scanf("%d",&value);
	while(ptr->data!=value)
	{
		ptr=ptr->next;
	}
	temp=ptr->prev;
	if(temp==start){
		delete_beg();
	}
	else{
		ptr->prev=temp->prev;
		temp->prev->next=ptr;
	}
	free(temp);
}

void delete_after(){
	struct node *ptr,*temp;
	int value;
	ptr=start;
	printf("\nEnter the value you want to delete after: ");
	scanf("%d",&value);
	while(ptr->data!=value)
	{
		ptr=ptr->next;
	}
	temp=ptr->next;
	ptr->next=temp->next;
	temp->next->prev=ptr;
	free(temp);
}

void delete_dll()
{
	struct node *temp;
	while(start!=NULL){
		temp=start;
		start=start->next;
		free(temp);
	}
}
