#include<iostream>
#include<stdlib.h>
#include<malloc.h>

using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *front=NULL;
NODE *rear=NULL;

class queue
{
    private :

	NODE *new_node,*temp;
	int create()
	{
		int element;

		new_node = (NODE*) malloc (sizeof(NODE));
		cout<<"Enter element to insert\n";
		cin>>element;
		new_node->data = element;
		new_node->next = NULL;
	}
    public :
	int insert_element()
	{
		if(front==NULL&&rear==NULL)
		{
			create();
			front = new_node;
			rear = new_node;		
		}
		else
		{
			create();
			if ( front == rear )
			{
				front->next = new_node;
				rear = new_node;
			}
			else
			{
				rear->next = new_node;
			}
		}
	}
	int delete_element()
	{
		if ( front == NULL && rear == NULL )
		{
			cout<<"Queue is empty";
		}
		else
		{
			temp = front;
			front = front->next;
			cout<<temp->data<< "is deleted\n";
			free(temp);
		}
	}
	int find(int element)
	{
		int flag=0;
		temp = front;
		while(temp!=rear)
		{
			if(temp->data==element)
			{
				flag=1;
				break;
			}
			temp = temp->next;
		}
		if(flag==0)
			cout<<"Element not present\n";
		else
			cout<<"Element address is :"<<temp->next;
	}
	int display()
	{
		if( front == NULL && rear == NULL )
			cout<<"Queue is empty";
		else
		{
			temp = front;
			while( temp == rear )
			{
				cout<<temp -> data<< "<---"; 
				temp = temp -> next;
			}
			cout<<temp<<"test"<<rear;
		}
	}
};

int main()
{
	int choice = 1;

	queue que_obj;
	while(choice!=0)
	{
		cout<<"-Enter operation to perform-\n";
		cout<<"1-Insert\n2-Delete\n3-Find\n4-Display\n0-Exit\n";
		cin>>choice;
		if ( choice == 1)
		{
			que_obj.insert_element();
		}
		else if ( choice == 2)
		{
			que_obj.delete_element();
		}
		else if ( choice == 3 )
		{
			int element;

			cout<<"Inseart element to find\n";
			cin>>element;
			que_obj.find(element);
		}
		else if ( choice == 4 )
		{
			que_obj.display();
		}
		else if ( choice == 0 );
		else
		{
			cout<<"Invalid Operation\n";
		}
	}
}
