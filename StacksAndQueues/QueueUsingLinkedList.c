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
int is_empty();
void display();

int main()
{
	int choice,item;
	while(1)
	{
		printf("\n===== Queue Operations =====\n\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display the element at the front\n");
		printf("4.Display all elements of the queue\n");
		printf("5.Quit\n");

		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		printf("\n");

		switch(choice)
		{
			case 1:
				printf("Enter element for adding in queue : ");
				scanf("%d",&item);
				insert(item);
				break;
			case 2:
				item = delete();
				printf("Deleted item is %d\n",item);
				break;
			case 3:
				item = peek();
				printf("Element at front of the queue is %d\n",item);
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
	if(new_node == NULL)
	{
		printf("Memory not available\n");
		return;
	}
	new_node->info = item;
	new_node->next = NULL;
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
	item = delete_node->info;
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
		printf("Queue_underflow\n");
		exit(1);
	}
	return front->info;
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

void display()
{
	struct node *ptr = NULL;
	ptr = front;
	if(is_empty())
	{
		printf("Queue_underflow\n\n");
		exit(1);
	}
	printf("Front");
	while(ptr != NULL)
	{
		printf("->| %d |",ptr->info);
		ptr = ptr->next;
	}
	printf("\n\n");
}

