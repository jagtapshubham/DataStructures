#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *InsertLastAtFirst(struct node *start);

int main()
{
	struct node *start = NULL;

	printf("Enter List:\n");
	start = create_list(start);
	printf("List:\n");
	display(start);
	start = InsertLastAtFirst(start);
	printf("List after entering last node at first.\n");
	display(start);

	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *newNode,*ptr;
	int createNode,i,data;

	printf("Enter number of nodes to create : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
	{
		printf("Enter valid number of nodes to create.\n");
		return start;
	}
	for(i=1;i<=createNode;i++)
	{
		printf("Enter element to insert : ");
		scanf("%d",&data);
		newNode = (struct node *)malloc(sizeof(struct node));;
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

struct node *InsertLastAtFirst(struct node *start)
{
	struct node *ptr,*last;

	ptr = start;
	while(ptr->next != NULL)
	{
		last = ptr;
		ptr = ptr->next;
	}
	last->next = NULL;
	ptr->next = start;
	start = ptr;

	return start;
}

