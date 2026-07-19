#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void split_list(struct node *start,struct node **secondHalf);

int main()
{
	struct node *start = NULL,*secondHalf = NULL;

	start = create_list(start);
	printf("List :\n");
	display(start);
	split_list(start,&secondHalf);
	printf("\nFirst Half List.\n");
	display(start);
	printf("\nSecond Half List.\n");
	display(secondHalf);

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
		printf("List is empty\n");
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

void split_list(struct node *start,struct node **secondHalf)
{
	if(start == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	if(start->next == NULL)
	{
		*secondHalf = NULL;
		return;
	}
	struct node *slow = NULL,*fast = NULL,*pp = NULL;
	
	slow = fast = start;
	while(fast != NULL && fast->next != NULL)
	{
		pp = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	pp->next = NULL;
	*secondHalf = slow;
}
