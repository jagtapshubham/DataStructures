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
	int choice,item;

	while(1)
	{
		printf("\n===== Stack Operation =====\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display item at top\n");
		printf("4.Display all items of the stack\n");
		printf("5.Quit\n");

		printf("\nEnter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter the item to be pushed : ");
				scanf("%d",&item);
				push(item);
				break;
			case 2:
				item = pop();
				printf("Popped item is %d\n",item);
				break;
			case 3:
				item = peek();
				printf("Item at top is %d\n",item);
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
	struct node *pop_node = NULL;
	int item;

	if(top == NULL)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	pop_node = top;
	item = pop_node->info;
	top = pop_node->next;
	free(pop_node);
	return(item);
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

void display()
{
	struct node *ptr = NULL;

	if(top == NULL)
	{
		printf("Stack is empty\n");
	}

	printf("\n===== Stack =====\n\n");
	ptr = top;
	while(ptr != NULL)
	{
		if(ptr == top)
		{
			printf("| %d |<-top\n",ptr->info);
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

