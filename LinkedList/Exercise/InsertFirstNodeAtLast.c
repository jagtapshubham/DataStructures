#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *InsertFirstAtLast(struct node *start);

int main()
{
	struct node *start = NULL;

	printf("Enter List:\n");
	start = create_list(start);
	printf("List:\n");
	display(start);
	start = InsertFirstAtLast(start);
	printf("After Moving First element to last.\n");
	display(start);
}

struct node *create_list(struct node *start)
{
	struct node *newNode,*ptr;
	int data,i,createNode;

	printf("Enter number of nodes to create : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
	{
		printf("Enter valid number of node to create.\n");
		return start;
	}
	for(i=1;i<=createNode;i++)
	{
		printf("Enter element to insert : ");
		scanf("%d",&data);
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = data;

		if(start == NULL)
		{
			newNode->next = start;
			start = newNode;
		}
		else
		{
			ptr = start;
			while(ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			newNode->next = ptr->next;
			ptr->next = newNode;
		}
	}
	return start;
}

void display(struct node *start)
{
	struct node *ptr;

	if(start == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	ptr = start;
	printf("Start");
	while(ptr != NULL)
	{
		printf("->| %d |",ptr->info);
		ptr = ptr->next;
	}
	printf("\n\n");
}

struct node *InsertFirstAtLast(struct node *start)
{
	struct node *last,*ptr;

	if(start->next == NULL)
	{
		return start;
	}
	last = start;
	ptr = start;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	start = last->next;
	last->next = ptr->next;
	ptr->next = last;
	return start;
}

