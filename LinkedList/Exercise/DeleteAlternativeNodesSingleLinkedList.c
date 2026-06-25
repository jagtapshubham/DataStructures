#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *delete_alternative_nodes(struct node *start);

int main()
{
	struct node *start = NULL;

	printf("Enter list :\n");
	start = create_list(start);
	printf("List :\n");
	display(start);
	start = delete_alternative_nodes(start);
	printf("After deleting alternative nodes from list :\n");
	display(start);

	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *newNode = NULL,*tail = NULL;
	int data,i,createNode;

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
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = data;

		if(start == NULL)
		{
			newNode->next = start;
			start = newNode;
		}
		else
		{
			newNode->next = tail->next;
			tail->next = newNode;
		}
		tail = newNode;
	}
	return start;
}

void display(struct node *start)
{
	struct node *ptr = NULL;

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

struct node *delete_alternative_nodes(struct node *start)
{
	struct node *ptr = NULL,*deleteNode = NULL;

	ptr = start;
	while(ptr->next != NULL)
	{
		printf("ptr = %d\n",ptr->info);
		deleteNode = ptr->next;
		ptr->next = deleteNode->next;
		printf("Delete node : %d\n",deleteNode->info);
		free(deleteNode);
		if(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
	}
	// display(start);
	return start;
}

