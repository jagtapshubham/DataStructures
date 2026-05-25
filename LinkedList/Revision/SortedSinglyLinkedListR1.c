#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *insert(struct node *start,int data);
void display(struct node *start);

int main()
{
	struct node *start=NULL;
	int choice,data;

	while(1)
	{
		printf("\n");
		printf("1.Insert.\n");
		printf("2.Display.\n");
		printf("3.Exit.\n");
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
				exit(1);
			default:
				printf("Wrong choice.\n");
				exit(1);
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
	ptr = start;
	while(ptr->next!=NULL)
	{
		if(data >= ptr->info && data < ptr->next->info)
		{
			newNode->next = ptr->next;
			ptr->next = newNode;
			return start;
		}
		ptr = ptr->next;
	}
	newNode->next = ptr->next;
	ptr->next = newNode;
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
	while(ptr!=NULL)
	{
		printf("->| %d |",ptr->info);
		ptr = ptr->next;
	}
}

