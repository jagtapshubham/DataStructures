#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *remove_duplicates(struct node *start);

int main()
{
	struct node *start = NULL;

	start = create_list(start);
	printf("List.\n");
	display(start);
	start = remove_duplicates(start);
	printf("List after removing duplicate elements.\n");
	display(start);

	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *newNode,*ptr;
	int i,data,createNode;

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

		if(start == NULL || data < start->info)
		{
			newNode->next = start;
			start = newNode;
		}
		else
		{
			ptr = start;
			while(ptr->next != NULL && data > ptr->next->info)
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

struct node *remove_duplicates(struct node *start)
{
	struct node *ptr,*pp,*deleteNode = NULL;
	
	pp = ptr = start;
	while(ptr != NULL)
	{
		if(ptr->info != pp->info)
		{
			pp->next = ptr;
			pp = ptr;
		}
		if(pp != ptr && pp->info == ptr->info)
		{
			deleteNode = ptr;
		}
		ptr = ptr->next;
		if(deleteNode != NULL)
		{
			free(deleteNode);
			deleteNode = NULL;
		}
	}
	return start;
}

