#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int stack_array[MAX];
int top = -1;

void push(int item);
int pop();
int peek();
int is_empty();
int is_full();
void display();

int main()
{
	int item,choice;

	while(1)
	{
		printf("\n===== Stack Menu =====\n\n");
		printf("1.Push\n");
		printf("2.Pop\n");
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
				push(item);
				break;
			case 2:
				printf("Popped item is %d\n",pop());
				break;
			case 3:
				printf("Top item on stack is %d\n",peek());
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

void push(int item)
{
	if(is_full())
	{
		printf("\nStack Overflow\n");
		exit(1);
	}
	top = top + 1;
	stack_array[top] = item;
}

int pop()
{
	int item;

	if(is_empty())
	{
		printf("\nStack Underflow\n");
		exit(1);
	}
	item = stack_array[top];
	top = top - 1;
	return item;
}

int peek()
{
	if(is_empty())
	{
		printf("\nStack Underflow\n");
		exit(1);
	}
	return stack_array[top];
}

int is_empty()
{
	if(top == -1)
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
	if(top == MAX-1)
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
	if(is_empty())
	{
		printf("\nStack Underflow\n");
		exit(1);
	}
	for(int i=top ; i>=0 ; i--)
	{
		if(i==top)
		{
			printf("| %d |<-Top\n",stack_array[i]);
			printf("|____|\n");
		}
		else
		{
			printf("| %d |\n",stack_array[i]);
			printf("|____|\n");
		}
	}
}

