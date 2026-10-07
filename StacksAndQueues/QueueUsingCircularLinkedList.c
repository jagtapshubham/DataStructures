#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
}*rear = NULL;

void insert(int item);
int delete();
void display();
int peek();
int is_empty();

int main()
{
	int choice,item;
	while(1)
	{
		printf("\n===== Queue Menu =====\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Peek\n");
		printf("4.Display\n");
		printf("5.Quit\n");

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
				break;
		}
	}
	return 0;
}

void insert(int item)
{
	struct node *new_node = NULL;

	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->info = item;

	if(new_node == NULL)
	{
		printf("Memory not available\n");
		return;
	}
	if(is_empty())
	{
		rear = new_node;
		new_node->next = rear;
	}
	else
	{
		new_node->next = rear->next;
		rear->next = new_node;
		rear = new_node;
	}
}

int delete()
{
	int item;
	struct node *delete_node = NULL;

	if(is_empty())
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	if(rear->next == rear)	/* If only one element */
	{
		delete_node = rear;
		rear = NULL;
	}
	else
	{
		delete_node = rear->next;
		rear->next = rear->next->next;
	}
	item = delete_node->info;
	free(delete_node);
	return item;
}

int peek()
{
	if(is_empty())
	{
		printf("\nQueue Underflow\n");
		exit(1);
	}
	return rear->next->info;
}

int is_empty()
{
	if(rear == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void display()
{
	struct node *ptr = NULL;

	if(is_empty())
	{
		printf("\nQueue Underflow\n");
		exit(1);
	}
	printf("\n===== Circular Queue =====\n\n");
	ptr = rear->next;
	do
	{
		printf("| %d |<-",ptr->info);
		ptr = ptr->next;
	}while(ptr != rear->next);
	printf("\n\n");
}

