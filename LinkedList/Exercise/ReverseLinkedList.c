#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *reverse(struct node *start);

int main()
{
	struct node *start = NULL,*revStart = NULL;

	start = create_list(start);
	display(start);
	revStart = reverse(start);
	display(revStart);
	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *newNode,*ptr;
	int data,createNode,i;

	printf("Enter number of nodes to create : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
	{
		printf("Enter valid number of nodes to create.\n");
		return start;
	}
	for(i=1;i<=createNode;i++)
	{
		printf("Enter element to insert in list : ");
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
	printf("\n");
	ptr = start;
	printf("Start");
	while(ptr != NULL)
	{
		printf("->| %d |",ptr->info);
		ptr = ptr->next;
	}
	printf("\n");
}

struct node *reverse(struct node *start)
{
	struct node *revStart = NULL,*ptr,*prev,*next,*newNode;

	if(start == NULL)
	{
		printf("List is empty, Nothing to reverse.\n");
		return start;
	}
	ptr = start;
	prev = NULL;
	while(ptr != NULL)
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = ptr->info;
		newNode->next = prev;
		prev = newNode;
		ptr = ptr->next;
	}
	revStart = prev;
	return revStart;
}

