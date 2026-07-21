// Write a function to split a single Linked List into two list such that the alternate nodes(even numbered nodes) go to new List

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void split_list_even_nodes(struct node **start,struct node **evenList);

int main()
{
	struct node *start = NULL,*evenList = NULL;

	start = create_list(start);
	printf("List :\n");
	display(start);
	split_list_even_nodes(&start,&evenList);
	printf("Odd Nodes List :\n");
	display(start);
	printf("Even Nodes List :\n");
	display(evenList);

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
		printf("Enter valid number of nodes to enter\n");
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

void split_list_even_nodes(struct node **start,struct node **evenList)
{
	struct node *ptr1 = NULL,*ptr2 = NULL,*evenStart = NULL,*evenTail = NULL;

	if(*start == NULL || (*start)->next == NULL)
	{
		return;
	}
	ptr1 = *start;
	ptr2 = (*start)->next;
	evenTail = evenStart = ptr2;
	while(ptr2 != NULL && ptr2->next != NULL)
	{
		ptr1->next = ptr2->next;
		ptr2->next = ptr2->next->next;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		if(ptr2 != NULL)
		{
			evenTail = ptr2;
		}
	}
	ptr1->next = NULL;
	evenTail->next = NULL;
	*evenList = evenStart;
}

