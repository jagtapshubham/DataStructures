#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void seprate_even_odd(struct node *start,struct node **startEven,struct node **startOdd);

int main()
{
	struct node *start = NULL,*startEven = NULL,*startOdd = NULL;

	start = create_list(start);
	
	seprate_even_odd(start,&startEven,&startOdd);
	printf("List :\n");
	display(start);
	printf("Even number list :\n");
	display(startEven);
	printf("Odd number list :\n");
	display(startOdd);

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
	while(ptr != NULL)
	{
		printf("->| %d |",ptr->info);
		ptr = ptr->next;
	}
	printf("\n\n");
}

void seprate_even_odd(struct node *start,struct node **startEven,struct node **startOdd)
{
	struct node *newNode = NULL,*ee = NULL,*oo = NULL,*ptr=NULL;

	ptr = start;
	while(ptr != NULL)
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = ptr->info;
		if(ptr->info %2 == 0)
		{
			if(*startEven == NULL)
			{
				newNode->next = *startEven;
				*startEven = newNode;
			}
			else
			{
				newNode->next = ee->next;
				ee->next = newNode;
			}
			ee = newNode;
		}
		else
		{
			if(*startOdd == NULL)
			{
				newNode->next = *startOdd;
				*startOdd = newNode;
			}
			else
			{
				newNode->next = oo->next;
				oo->next = newNode;
			}
			oo = newNode;
		}
		ptr = ptr->next;
	}
}

