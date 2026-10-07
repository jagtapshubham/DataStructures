#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int queue_array[MAX];
int rear = -1;
int front = -1;

void insert(int item);
int delete();
int peek();
void display();
int is_empty();
int is_full();

int main()
{
	int item,choice;

	while(1)
	{
		printf("\n");
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
				printf("Item delete is %d\n",delete());
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
		printf("\n");
	}
	return 0;
}

void insert(int item)
{
	if(is_full())
	{
		printf("Queue Overflow\n");
		exit(1);
	}
	if(front == -1)
	{
		front++;
	}
	rear++;
	queue_array[rear] = item;
}

int delete()
{
	int item;

	if(is_empty())
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	item = queue_array[front];
	front = front + 1;
	return item;
}

int peek()
{
	if(is_empty())
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	return queue_array[front];
}

void display()
{
	int i;

	if(is_empty())
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	printf("\n===== Queue =====\n");
	for(i=front;i<=rear;i++)
	{
		printf("| %d |-",queue_array[i]);
	}
	printf("\n");
}

int is_empty()
{
	if(front == -1 || front > rear)
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
	if(rear == MAX-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

