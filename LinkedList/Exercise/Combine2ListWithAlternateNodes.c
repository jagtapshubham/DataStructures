// Write a function to combine the alternate node of two null terminated single linked list and then the second list should be empty.If both list are not same length then the remaining nodes of the longer list are taken in combined list.
// E.g.- List1: 1->2->3->4 and List2: 5->7 = 1->5->2->7->3->4

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *join_alternate_nodes(struct node *start1,struct node *start2);

int main()
{
	struct node *start1 = NULL,*start2 = NULL;

	printf("Enter List 1:\n");
	start1 = create_list(start1);
	printf("Enter List 2:\n");
	start2 = create_list(start2);
	printf("List 1:\n");
	display(start1);
	printf("List 2:\n");
	display(start2);

	start1 = join_alternate_nodes(start1,start2);
	start2 = NULL;
	display(start1);

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

struct node *join_alternate_nodes(struct node *start1,struct node *start2)
{
	struct node *ptr1 = NULL,*ptr2 = NULL,*pp = NULL,*pp1 = NULL;
	
	if(start1 == NULL)
	{
		return start2;
	}
	if(start2 == NULL)
	{
		return start1;
	}
	ptr1 = start1;
	ptr2 = start2;

	while(ptr1 != NULL && ptr2 != NULL)
	{
		pp = ptr2;
		ptr2 = ptr2->next;
		pp->next = ptr1->next;
		ptr1->next = pp;
		pp1 = ptr1->next;
		ptr1 = ptr1->next->next;
	}
	if(ptr2 != NULL)
	{
		pp1->next = ptr2;
	}
	return start1;
}

