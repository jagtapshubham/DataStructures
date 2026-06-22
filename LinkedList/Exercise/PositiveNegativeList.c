#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void seprate_positive_negative(struct node **start,struct node **startP,struct node **startN);

int main()
{
	struct node *start = NULL,*startN = NULL,*startP = NULL;

	printf("Enter positive and negative number list :\n");
	start = create_list(start);

	printf("List with positive and negative list :\n");
	display(start);
	
	seprate_positive_negative(&start,&startP,&startN);

	printf("Original List :\n");
	display(start);
	printf("\nPositve List :\n");
	display(startP);
	printf("\nNegative List :\n");
	display(startN);

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

void seprate_positive_negative(struct node **start,struct node **startP,struct node **startN)
{
	struct node *ptr,*pp,*nn;

	while(*start != NULL)
	{
		ptr = *start;
		*start = ptr->next;

		if(ptr->info >= 0)
		{
			if(*startP == NULL)
			{
				*startP = ptr;
				pp = ptr;
				pp->next = NULL;
			}
			else
			{
				pp->next = ptr;
				pp = ptr;
				pp->next = NULL;
			}
		}
		else
		{
			if(*startN == NULL)
			{
				*startN = ptr;
				nn = ptr;
				nn->next = NULL;
			}
			else
			{
				nn->next = ptr;
				nn = ptr;
				nn->next = NULL;
			}
		}
	}
}

