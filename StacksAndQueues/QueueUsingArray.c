#include<stdio.h>
#include<stdlib.h>
#define MAX 10

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
	int choice,item;
	
	while(1)
	{
		printf("\n===== Queue Menu =====\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display element at front\n");
		printf("4.Display all element in queue\n");
		printf("5.Quit\n");
		
		printf("\nEnter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter item to insert : ");
				scanf("%d",&item);
				insert(item);
				break;
			case 2:
				item = delete();
				printf("Item delete is  %d\n",item);
				break;
			case 3:
				item = peek();
				printf("Item at front is %d\n",item);
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
	if(is_full())
	{
		printf("Queue Overflow\n");
		exit(1);
	}
	if(front == -1)
	{
		front = 0;
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

void display()
{
	int i;
	if(is_empty())
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	for(i=front;i<=rear;i++)
	{
		if(front == rear)
		{
			printf("| %d | ",queue_array[i]);
			printf("front - rear\n");
		}
		else if(i == front)
		{
			printf("| %d | ",queue_array[i]);
			printf("front\n");
		}
		else if(i == rear)
		{
			printf("| %d | ",queue_array[i]);
			printf("rear\n");
		}
		else
		{
			printf("| %d |\n",queue_array[i]);
		}
	}
	printf("\n\n");
}

