#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int cDequeue_array[MAX];
int front = -1;
int rear = -1;

void insert_frontEnd(int item);
void insert_rearEnd(int item);
int delete_frontEnd();
int delete_rearEnd();
void display();
int is_empty();
int is_full();

int main()
{
	int item,choice;

	while(1)
	{
		printf("\n===== Queue Operation =====\n");
		printf("1.Insert at front end\n");
		printf("2.Insert at rear end\n");
		printf("3.Delete at front end\n");
		printf("4.Delete at rear end\n");
		printf("5.Display\n");
		printf("6.Quit\n");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter item to insert : ");
				scanf("%d",&item);
				insert_frontEnd(item);
				break;
			case 2:
				printf("Enter item to insert : ");
				scanf("%d",&item);
				insert_rearEnd(item);
				break;
			case 3:
				if(front == -1)
				{
					printf("Queue is empty\n");
				}
				else
				{
					printf("Deleted item from front is %d\n",delete_frontEnd());
				}
				break;
			case 4:
				if(rear == -1)
				{
					printf("Queue is empty\n");
				}
				else
				{
					printf("Deleted item from rear is %d\n",delete_rearEnd());
				}
				break;
			case 5:
				display();
				break;
			case 6:
				return 0;
			default:
				printf("Wrong choice : ");
				break;
		}
		printf("\n");
	}
	return 0;
}

void insert_frontEnd(int item)
{
	if(is_full())
	{
		printf("Queue Overflow\n");
		return;
	}
	if(front == -1)
	{
		front = 0;
		rear = 0;
	}
	else if(front == 0)
	{
		front = MAX-1;
	}
	else
	{
		front = front - 1;
	}
	cDequeue_array[front] = item;
}

void insert_rearEnd(int item)
{
	if(is_full())
	{
		printf("Queue Overflow\n");
		return;
	}
	if(rear == -1)
	{
		front = 0;
		rear = 0;
	}
	else if(rear == MAX-1)
	{
		rear = 0;
	}
	else
	{
		rear = rear + 1;
	}
	cDequeue_array[rear] = item;
}

int delete_frontEnd()
{
	int item;

	if(is_empty())
	{
		printf("Queue Underflow\n");
		return -1;
	}
	item = cDequeue_array[front];
	if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if(front == MAX-1)
	{
		front = 0;
	}
	else
	{
		front = front + 1;
	}
	return item;
}

int delete_rearEnd()
{
	int item;

	if(is_empty())
	{
		printf("Queue Underflow\n");
		return -1;
	}
	item = cDequeue_array[rear];
	if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if(rear == 0)
	{
		rear = MAX-1;
	}
	else
	{
		rear = rear - 1;
	}
	return item;
}

void display()
{
	int i;

	if(is_empty())
	{
		printf("Queue Underflow\n");
		return;
	}
	i = front;
	if(i <= rear)
	{
		while(i <= rear)
		{
			printf("| %d |-",cDequeue_array[i++]);
		}
	}
	else
	{
		while(i <= MAX-1)
		{
			printf("| %d |-",cDequeue_array[i++]);
		}
		i = 0;
		while(i <= rear)
		{
			printf("| %d |-",cDequeue_array[i++]);
		}
	}
	printf("\n");
}

int is_empty()
{
	if(front == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int is_full()
{
	if((front == 0 && rear == MAX-1) || front == rear+1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

