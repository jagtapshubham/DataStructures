#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	int priority;
	struct node *next;
}*front = NULL;

void insert(int item,int item_priority);
int delete();
void display();
int is_empty();

int main()
{
	int item,item_priority,choice;

	while(1)
	{
		printf("\n===== Priority Queue Operations =====\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter item to insert : ");
				scanf("%d",&item);
				printf("Enter item priority : ");
				scanf("%d",&item_priority);
				insert(item,item_priority);
				break;
			case 2:
				if(is_empty())
				{
					printf("Queue is empty\n");
				}
				else
				{
					printf("%d item deleted from queue\n",delete());
				}
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;
			default:
				printf("Wrong choice\n");
				break;
		}
	}
	return 0;
}

void insert(int item,int item_priority)
{
	struct node *new_node = NULL,*ptr = NULL;

	new_node = (struct node *)malloc(sizeof(struct node));
	if(new_node == NULL)
	{
		printf("Memory allocation failed");
	}
	new_node->info = item;
	new_node->priority = item_priority;
	if(is_empty() || item_priority <= front->priority)
	{
		new_node->next = front;
		front = new_node;
	}
	else
	{
		ptr = front;
		while(ptr->next != NULL && ptr->next->priority <= item_priority)
		{
			ptr = ptr->next;
		}
		new_node->next = ptr->next;
		ptr->next = new_node;
	}
}

int delete()
{
	struct node *delete_node = NULL;
	int item;

	if(is_empty())
	{
		printf("Queue is Underflow\n");
		return -1;
	}
	item = front->info;
	delete_node = front;
	front = front->next;
	free(delete_node);
	return item;
}

void display()
{
	struct node *ptr = NULL;
	ptr = front;
	if(is_empty())
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("Queue is :\n");
		printf("Priority	Item\n");
		while(ptr != NULL)
		{
			printf("%5d		%5d\n",ptr->priority,ptr->info);
			ptr = ptr->next;
		}
	}
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

