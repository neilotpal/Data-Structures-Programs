//Circular Linked List

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
	int data;
	struct node *next;
};

struct node *start=NULL;
void create_cll();
void display_cll();
void insert_beg();
void insert_end();
void delete_beg();
void delete_end();
void delete_cll();

int main(){
	int ch;
	do{
		printf("\n***Menu***");
		printf("\n1.Create a Circular Linked List");
		printf("\n2.Display Circular Linked List");
		printf("\n3.Insert a node at the beginning");
		printf("\n4.Insert a node at the end");
		printf("\n5.Delete a node at the beginning");
		printf("\n6.Delete a node at the end");
		printf("\n7.Delete the entire list");
		printf("\n8.Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: create_cll();
				   printf("\nCircular Linked List Created!!");
				   break;
			case 2: display_cll();
				   break;
			case 3: insert_beg();
				   break;
			case 4: insert_end();
				   break;
			case 5: delete_beg();
			        break;
			case 6: delete_end();
				   break;
			case 7: delete_cll();
			        break;
			case 8: exit(1);
		}
	}while(1);
	return 0;
}

void create_cll(){
	start=NULL;
	struct node *ptr,*new_node;
	int n,num,i;
	printf("\nEnter the number of elements you want to enter: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter data: ");
		scanf("%d",&num);
		new_node=(struct node *)malloc(sizeof(struct node));
		new_node->data=num;
		if(start==NULL)
		{
			new_node->next=new_node;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
				ptr=ptr->next;
			ptr->next=new_node;
			new_node->next=start;
		}
	}
}

void display_cll(){
	struct node *ptr;
	ptr=start;
	printf("\n The Linked List is: ");
	while(ptr->next!=start)
	{
		printf("\t%d",ptr->data);
		ptr=ptr->next;
	}
	printf("\t%d",ptr->data);
}

void insert_end(){
	struct node *ptr,*new_node;
	int num;
	printf("\nEnter the value you want to insert: ");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->next=start;
}

void insert_beg(){
	struct node *ptr,*new_node;
	int num;
	printf("\nEnter the value you want to insert: ");
	scanf("%d",&num);
	new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->next=start;
	start=new_node;
}

void delete_beg(){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=start->next;
	free(start);
	start=ptr->next;
}

void delete_end(){
	struct node *ptr,*preptr;
	ptr=start;
	while(ptr->next!=start){
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=ptr->next;
	free(ptr);
}

void delete_cll(){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
	{
		delete_end();
	}
	free(start);
}
