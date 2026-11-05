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
int peek();
void display();
int is_empty();

int main()
{
	int item,priority,choice;

	while(1)
	{
		printf("\n===== Priority Queue Operations =====\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Peek\n");
		printf("4.Display\n");
		printf("5.Quit\n");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter item to insert : ");
				scanf("%d",&item);
				printf("Enter item priority : ");
				scanf("%d",&priority);
				insert(item,priority);
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
				if(is_empty())
				{
					printf("Queue is empty\n");
				}
				else
				{
					printf("%d item is at front\n",peek());
				}
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

void insert(int item,int item_priority)
{
	struct node *new_node = NULL,*ptr = NULL;

	new_node = (struct node *)malloc(sizeof(struct node));
	if(new_node == NULL)
	{
		printf("Memory not available\n");
		return;
	}
	new_node->info = item;
	new_node->priority = item_priority;
	if(is_empty() || item_priority < front->priority)
	{
		new_node->next = front;
		front = new_node;
	}
	else
	{
		ptr = front;
		while(ptr->next != NULL || ptr->next->priority > item_priority)
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
		printf("Queue is empty\n");
		return -1;
	}
	item = front->info;
	delete_node = front;
	front = front->next;
	free(delete_node);
	return item;
}

int peek()
{
	if(is_empty())
	{
		printf("Queue is empty\n");
		return -1;
	}
	return front->info;
}

void display()
{
	struct node *ptr = NULL;

	if(is_empty())
	{
		printf("Queue is empty\n");
		return;
	}
	ptr = front;
	printf("\nItem		Priority\n");
	while(ptr != NULL)
	{
		printf("%d		%d\n",ptr->info,ptr->priority);
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

