#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

void pop();
void push(int);
void display();

NODE *top = NULL;
int main()
{
	int choice=1;
	while(choice!=0)
	{
		printf("-Enter the operation-\n");
		printf("1-PUSH\n2-POP\n3-display\n0-EXIT\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			int element;
			printf("Enter element for push operation :");
			scanf("%d",&element);
			push(element);
		}
		else if(choice==2)
		{
			pop();
		}
		else if(choice==3)
		{
			display();
		}
		else if(choice==0);
		else
			printf("Invalid operation");
	}
	return 0;
}

void push(int element)
{
	
	if(top==NULL)
	{
		NODE *new_node = (NODE*) malloc (sizeof(NODE));
		new_node->data = element;
		new_node->next = NULL;
		top = new_node;
	}
	else
	{
		NODE *new_node = (NODE*) malloc (sizeof(NODE));
		new_node->data = element;
		new_node->next = top;
		top = new_node;
	}
	printf("%d is inserted\n",element);
}

void pop()
{
	if(top==NULL)
	{
		printf("Stack in empty pop operation not posible.\n");
	}
	else
	{
		NODE *temp;
		printf("%d is poped out from stack\n",top->data);
		temp = top;
		top = top->next;
		free(temp);
	}

}

void display()
{
	NODE *temp;
	if(top==NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		temp = top;
		while(temp->next!=NULL)
		{
			printf("%d\t",temp->data);
			temp = temp->next;
		}
		printf("%d\n",temp->data);
	}
}
