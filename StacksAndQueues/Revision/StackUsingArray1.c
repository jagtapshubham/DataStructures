#include<stdio.h>

#define MAX 5

int stack_array[MAX];
int top = -1;

void push(int item);
int pop();
int peek();
void display();
int is_empty();
int is_full();

int main()
{
	int item,choice;

	while(1)
	{
		printf("\n===== Stack operation =====\n");
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
				if(is_empty())
				{
					printf("Stack empty\n");
				}
				else
				{
					printf("%d item deleted from the list\n",pop());
				}
				break;
			case 3:
				if(top == -1)
				{
					printf("Stack Underflow\n");
				}
				else
				{
					printf("Item at top is %d\n",stack_array[top]);
				}
				break;
			case 4:
				display();
				break;
			case 5:
				return 0;
			default:
				printf("Wrong choice\n");
		}
	}
	return 0;
}

void push(int item)
{
	if(is_full())
	{
		printf("Stack Overflow\n");
		return;
	}
	top = top + 1;
	stack_array[top] = item;
}

int pop()
{
	int item;

	if(is_empty())
	{
		printf("Stack Underflow\n");
		return -1;
	}
	item = stack_array[top];
	top = top - 1;
	return item;
}

int peek()
{
	if(is_empty())
	{
		printf("Stack Underflow\n");
		return -1;
	}
	return stack_array[top];
}

void display()
{
	int i;

	if(is_empty())
	{
		printf("Stack Underflow\n");
		return;
	}
	for(i = top; i >= 0; i--)
	{
		printf("| %d |\n",stack_array[i]);
	}
	printf("\n");
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

