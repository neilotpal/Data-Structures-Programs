//Circular Doubly Linked List

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;
};

struct node *start=NULL;
void create_cdll();
void display_cdll();
void insert_beg();
void insert_end();
void delete_beg();
void delete_end();
void delete_cdll();

int main(){
	int ch;
	do{
		printf("\n***Menu***");
		printf("\n1.Create a Circular Doubly Linked List");
		printf("\n2.Display Circular Doubly Linked List");
		printf("\n3.Insert a node at the beginning");
		printf("\n4.Insert a node at the end");
		printf("\n5.Delete a node at the beginning");
		printf("\n6.Delete a node at the end");
		printf("\n7.Delete the entire list");
		printf("\n8.Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: create_cdll();
				   printf("\nCircular Doubly Linked List Created!!");
				   break;
			case 2: display_cdll();
				   break;
			case 3: insert_beg();
				   break;
			case 4: insert_end();
				   break;
			case 5: delete_beg();
			        break;
			case 6: delete_end();
				   break;
			case 7: delete_cdll();
			        break;
			case 8: exit(1);
		}
	}while(1);
	return 0;
}

void create_cdll(){
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
			new_node->prev=new_node;
			new_node->next=new_node;
			start=new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=start)
				ptr=ptr->next;
			new_node->prev=ptr;
			ptr->next=new_node;
			new_node->next=start;
			start->prev=new_node;
		}
	}
}


void display_cdll(){
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
	new_node->prev=ptr;
	start->prev=new_node;
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
	new_node->prev=ptr;
	new_node->next=start;
	start->prev=new_node;
	start=new_node;
}

void delete_beg(){
	struct node *ptr,*temp;
	ptr=start;
	while(ptr->next!=start)
	{
		ptr=ptr->next;
	}
	ptr->next=start->next;
	temp=start;
	start=start->next;
	start->prev=ptr;
	free(temp);
}

void delete_end(){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start){
		ptr=ptr->next;
	}
	ptr->prev->next=start;
	start->prev=ptr->prev;
	free(ptr);
}

void delete_cdll(){
	struct node *ptr;
	ptr=start;
	while(ptr->next!=start)
		delete_end();
	free(start);
}
