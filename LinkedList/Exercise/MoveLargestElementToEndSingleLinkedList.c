#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *large_at_end(struct node *start);

int main()
{
	struct node *start = NULL;

	start = create_list(start);
	printf("List :\n");
	display(start);
	start = large_at_end(start);
	printf("Largest element at end.\n");
	display(start);

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

struct node *large_at_end(struct node *start)
{
	struct node *ptr,*ptemp,*pp,*max;

	ptemp=max=pp = start;
	ptr = start->next;
	while(ptr != NULL)
	{
		if(ptr->info > max->info)
		{
			max = ptr;
			pp = ptemp;
		}
		ptemp = ptr;
		ptr = ptr->next;
	}
	if(start == max)
	{
		start = max->next;
		max->next = ptemp->next;
		ptemp->next = max;
		return start;
	}
	if(ptemp != max)
	{
		pp->next = max->next;
		max->next = ptemp->next;
		ptemp->next = max;
		return start;
	}
	return start;
}

