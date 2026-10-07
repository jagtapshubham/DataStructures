#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
}*front = NULL,*rear = NULL;

void insert(int item);
int delete();
int peek();
void display();
int is_empty();

int main()
{
	int item,choice;

	while(1)
	{
		printf("\n");
		printf("===== Queue Operation =====\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Peek\n");
		printf("4.Display\n");
		printf("5.Quit\n");
		printf("\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		
		printf("\n");
		switch(choice)
		{
			case 1:
				printf("Enter item to insert : ");
				scanf("%d",&item);
				insert(item);
				break;
			case 2:
				printf("Item deleted is %d\n",delete());
				break;
			case 3:
				printf("Item at front is %d\n",peek());
				break;
			case 4:
				display();
				break;
			case 5:
				return 0;
			default:
				printf("Wrong choice\n");
		}
		printf("\n");
	}
	return 0;
}

void insert(int item)
{
	struct node *new_node = NULL;

	new_node = (struct node *)malloc(sizeof(struct node));
	if(new_node == NULL)
	{
		printf("Queue Overflow\n");
		exit(1);
	}
	new_node->info = item;
	if(front == NULL)
	{
		front = new_node;
	}
	else
	{
		rear->next = new_node;
	}
	rear = new_node;
}

int delete()
{
	struct node *delete_node = NULL;
	int item;

	if(is_empty())
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	delete_node = front;
	item = front->info;
	front = front->next;
	if(front == NULL)
	{
		rear = NULL;
	}
	free(delete_node);
	return item;
}

int peek()
{
	if(is_empty())
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	return front->info;
}

void display()
{
	struct node *ptr = NULL;

	if(is_empty())
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	printf("\n===== Queue =====\n");
	ptr = front;
	while(ptr != NULL)
	{
		printf("| %d |-",ptr->info);
		ptr = ptr->next;
	}
	printf("\n");
}

int is_empty()
{
	if(front == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

