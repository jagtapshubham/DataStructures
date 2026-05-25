#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *concat(struct node *start1,struct node *start2);

int main()
{
	struct node *start = NULL,*start1 = NULL,*start2 = NULL;
	
	printf("Enter List 1 :\n");
	start1 = create_list(start1);

	printf("Enter List 2 :\n");
	start2 = create_list(start2);
	// Concatenation of list
	start = concat(start1,start2);

	printf("List 1 :\n");
	display(start1);
	printf("List 2 :\n");
	display(start2);
	printf("List after Concatenation :\n");
	display(start);

	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *newNode,*ptr;
	int data,i,createNode;

	printf("Enter number of nodes to create : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
	{
		printf("Enter valid number.\n");
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
	ptr = start;
	printf("Start");
	while(ptr != NULL)
	{
		printf("->| %d |",ptr->info);
		ptr = ptr->next;
	}
	printf("\n\n");
}

struct node *concat(struct node *start1,struct node *start2)
{
	struct node *ptr;	
	if(start2 == NULL)
	{
		return start1;
	}
	else if(start1 == NULL)
	{
		return start2;
	}
	else
	{
		ptr = start1;
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = start2;
	}
	return start1;
}

