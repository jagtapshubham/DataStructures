#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void swapAdjacentByInfo(struct node *start);
struct node *swapAdjacentByLink(struct node *start);

int main()
{
	struct node *start = NULL,*swapStart = NULL;

	start = create_list(start);
	printf("List:\n");
	display(start);
	swapAdjacentByInfo(start);
	printf("List after adjacent info swap :\n");
	display(start);
	swapStart = swapAdjacentByLink(start);
	printf("List after adjacent link swap :\n");
	display(swapStart);

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

void swapAdjacentByInfo(struct node *start)
{
	struct node *ptr,*q;
	int temp;

	ptr = start;
	while(ptr != NULL && ptr->next != NULL)
	{
		q = ptr->next;

		temp = ptr->info;
		ptr->info = q->info;
		q->info = temp;
		ptr = q->next;
	}
}

struct node *swapAdjacentByLink(struct node *start)
{
	struct node *ptr,*q,*temp,*pp;

	pp=ptr = start;
	while(ptr != NULL && ptr->next != NULL)
	{
		q = ptr->next;
		ptr->next = q->next;
		q->next = ptr;
		if(ptr != start)
		{
			pp->next = q;
		}
		if(start == ptr)
		{
			start = q;
		}
		temp = ptr;
		ptr = q;
		q = temp;
		pp = q;
		ptr = q->next;
	}
	return start;
}

