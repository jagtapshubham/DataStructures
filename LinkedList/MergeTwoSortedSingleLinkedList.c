#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *insert_sorted(struct node *start,int data);
struct node *insert(struct node *start,int data);
void merge(struct node *p1, struct node *p2);

int main()
{
	struct node *start1 = NULL,*start2 = NULL;
	printf("Enter List 1:\n");
	start1 = create_list(start1);
	printf("Enter List 2:\n");
	start2 = create_list(start2);
	printf("List 1 : \n");
	display(start1);
	printf("List 2 : \n");
	display(start2);
	merge(start1,start2);

	return 0;
}

struct node *create_list(struct node *start)
{
	int i,createNode,data;
	
	printf("Enter number of nodes to create : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
	{
		printf("%d nodes to insert : ",createNode);
		return start;
	}
	for(i=1;i<=createNode;i++)
	{
		printf("Enter element to insert : ");
		scanf("%d",&data);
		start = insert_sorted(start,data);
	}
	return start;
}

struct node *insert_sorted(struct node *start,int data)
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
		while(ptr->next != NULL && data > ptr->next->info)
		{
			ptr = ptr->next;
		}
		newNode->next = ptr->next;
		ptr->next = newNode;
	}
	return start;
}

struct node *insert(struct node *start,int data)
{
	struct node *newNode,*ptr;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	if(start == NULL)
	{
		newNode->next = start;
		start = newNode;
		return start;
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
	printf("\n");
}

void merge(struct node *p1,struct node *p2)
{
	struct node *start3 = NULL;

	while(p1 != NULL && p2 != NULL)
	{
		if(p1->info < p2->info)
		{
			start3 = insert(start3,p1->info);
			p1 = p1->next;
		}
		else if(p2->info < p1->info)
		{
			start3 = insert(start3,p2->info);
			p2 = p2->next;
		}
		else if(p1->info == p2->info)
		{
			start3 = insert(start3,p1->info);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	// If second list has finished
	while(p1 != NULL)
	{
		start3 = insert(start3,p1->info);
		p1 = p1->next;
	}

	// If first list has finished
	while(p2 != NULL)
	{
		start3 = insert(start3,p2->info);
		p2 = p2->next;
	}
	printf("Merged List :\n");
	display(start3);
}

