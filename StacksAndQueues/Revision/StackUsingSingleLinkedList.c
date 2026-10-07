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
int is_empty();
void display();

int main()
{
	int item,choice;

	while(1)
	{
		printf("\n===== Stack Menu =====\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Peek\n");
		printf("4.Display\n");
		printf("5.Exit\n");
	
		printf("\nEnter your choice : ");
		scanf("%d",&choice);

		printf("\n");
		switch(choice)
		{
			case 1:
				printf("Enter item to insert : ");
				scanf("%d",&item);
				push(item);
				break;
			case 2:
				printf("Popped item from stack is %d\n",pop());
				break;
			case 3:
				printf("Top item in stack is %d\n",peek());
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
		exit(1);
	}
	delete_node = top;
	item = delete_node->info;
	top = top->next;
	free(delete_node);

	return item;
}

int peek()
{
	if(is_empty())
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	return top->info;
}

void display()
{
	struct node *ptr = NULL;

	if(is_empty())
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	ptr = top;
	printf("\n===== Stack =====\n\n");
	while(ptr != NULL)
	{
		if(ptr == top)
		{
			printf("| %d |<-Top\n",ptr->info);
		}
		else
		{
			printf("| %d |\n",ptr->info);
		}
		printf("|____|\n");
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

