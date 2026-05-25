#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *insert(struct node *start,int data);
void search(struct node *start,int data);
void display(struct node *start);

int main()
{
	struct node *start = NULL;
	int choice,data;

	while(1)
	{
		printf("\n");
		printf("1.Insert.\n");
		printf("2.Display.\n");
		printf("3.Search.\n");
		printf("4.Exit.\n");
		printf("\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("Enter element to insert : ");
				scanf("%d",&data);
				start = insert(start,data);
				break;
			case 2:
				display(start);
				break;
			case 3:
				printf("Enter element to seatch in list : ");
				scanf("%d",&data);
				search(start,data);
				break;
			case 4:
				exit(1);
			default:
				printf("Wrong choice.\n");
				break;
		}
	}
	return 0;
}

struct node *insert(struct node *start,int data)
{
	struct node *newNode,*ptr;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	if(start == NULL || data < start->info)
	{
		newNode->next = start;
		start = newNode;
		return start;
	}
	else
	{
		ptr = start;
		while(ptr->next != NULL && ptr->next->info < data)
		{
			ptr = ptr->next;
		}
		newNode->next = ptr->next;
		ptr->next = newNode;
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
}

void search(struct node *start,int data)
{
	struct node *ptr;
	int position = 0;

	if(start == NULL || data < start->info)
	{
		printf("%d not present in list.\n",data);
		return;
	}

	ptr = start;
	position = 1;
	while(ptr != NULL && ptr->info <= data)
	{
		if(ptr->info == data)
		{
			printf("%d found at %d position.\n",data,position);
			return;
		}
		position++;
		ptr = ptr->next;
	}
	printf("%d not found in list.\n",data);
}

