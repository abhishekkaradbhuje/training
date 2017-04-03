#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node *next;
} NODE;

void add_element(int);
void search_element(int);
void delete_element(int);

NODE *head = NULL;
int main()
{
	int choice=1;
	while(choice!=0)
	{
		print("-Enter operation to perform-\n");
		printf("1-Add\n2-Search\n3-Delete\n4-Display\n0-Exit\n");
		scanf("%d",choice);
		if(choice==1)
		{
			int element;
			printf("Enter element to inseart : ");
			scanf("%d",&element);
			add_element(element);
		}
		else if(choice==2)
		{
			int element;
			printf("Enter Element to search :\n");
			scanf("%d",&element);
			search_element();
		}
		else if(choice==3)
		{
			delete_element();
		}
		else if(choice==4)
		{
			display();
		}
		else if(choice==0);
		else
			printf("Invalid operation");
	}
}

void add_element(int element)
{
	NODE *new_node = (NODE *) malloc(sizeof(NODE));
	if(head==NULL)
	{
		head = new_node;
		new_node->next = NULL;
	}
	else
	{
		NODE *temp;
		temp = head;
		while(temp->next!=NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->next = NULL;
	}
}

void display()
{
	NODE *temp;
	temp = head;
	printf("%d\n", head->next->data);
	while(temp->next!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("%d\t",temp->data);
}

void search(int element)
{
	NODE *temp;
	temp = head;
	while(temp->data==element)
	{
		if(temp->data==element)
		{
			tmp=1;
			break;
		}
		temp = temp->next;
	}
	while(temp->next!=NULL);
	if(tmp==0)
		printf("Element not present\n");
	else
		printf("Address of element : %u\n",temp);
	return temp;
}

void delete(int element)
{
	NODE *temp = search(element);
	
}
