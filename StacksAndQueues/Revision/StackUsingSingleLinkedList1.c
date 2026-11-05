#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
}*top = NULL;

void push(int item);
int pop();
int peek();
void display();
int is_empty();

int main()
{
	int item,choice;

	while(1)
	{
		printf("\n===== Stack Operations =====\n");
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
					printf("Stack is empty\n");
				}
				else
				{
					printf("%d item deleted from the stack\n",pop());
				}
				break;
			case 3:
				if(is_empty())
				{
					printf("Stack is empty\n");
				}
				else
				{
					printf("%d item is at top\n",peek());
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

void push(int item)
{
	struct node *new_node = NULL;
	
	new_node = (struct node *)malloc(sizeof(struct node));
	if(new_node == NULL)
	{
		printf("Stack Overflow\n");
		return;
	}
	new_node->info = item;
	new_node->next = top;
	top = new_node;
}

int pop()
{
	struct node *delete_node = NULL;
	int item;

	if(is_empty())
	{
		printf("Stack Underflow\n");
		return -1;
	}
	item = top->info;
	delete_node = top;
	top = top->next;
	free(delete_node);
	return item;
}

int peek()
{
	if(is_empty())
	{
		printf("Stack Underflow\n");
		return -1;
	}
	return top->info;
}

void display()
{
	struct node *ptr = NULL;

	if(is_empty())
	{
		printf("Stack Underflow\n");
		return;
	}
	ptr = top;
	while(ptr != NULL)
	{
		printf("| %d |\n",ptr->info);
		ptr = ptr->next;
	}
	printf("\n");
}

int is_empty()
{
	if(top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
} 

