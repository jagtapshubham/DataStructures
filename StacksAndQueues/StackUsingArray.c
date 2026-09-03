#include<stdio.h>
#include<stdlib.h>

#define MAX 100
// global variables
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
	int choice,item;
	while(1)
	{
		printf("\n===== Stack Menu =====\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display the top element\n");
		printf("4.Display all stack element\n");
		printf("5.Quit\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);
		printf("\n");

		switch(choice)
		{
			case 1:
				printf("Enter element to push : ");
				scanf("%d",&item);
				push(item);
				break;
			case 2:
				item = pop();
				printf("Popped item is %d\n",item);
				break;
			case 3:
				item = peek();
				printf("Item at the top is %d\n",item);
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
		printf("Stack Underflow\n");
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
	int i;
	if(is_empty())
	{
		printf("Stack is empty\n");
		return;
	}
	printf("Stack elements :\n\n");
	for(i=top;i>=0;i--)
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

