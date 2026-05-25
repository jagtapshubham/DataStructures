#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *insert_sort(struct node *start,int data);
struct node *insert(struct node *start,int data);
void merge(struct node *start1,struct node *start2);

int main()
{
	struct node *start1 = NULL, *start2 = NULL;

	printf("Enter List 1 :\n");
	start1 = create_list(start1);
	
	printf("Enter List 2 :\n");
	start2 = create_list(start2);

	printf("List 1 :\n");
	display(start1);

	printf("List 2 :\n");
	display(start2);

	printf("List after merge :\n");
	merge(start1,start2);

	return 0;
}

struct node *create_list(struct node *start)
{
	int createNode,data,i;
	
	printf("Enter number of nodes to create : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
	{
		printf("Enter valid nodes to create.\n");
		return start;
	}
	for(i=1;i<=createNode;i++)
	{
		printf("Enter element to insert : ");
		scanf("%d",&data);
		start = insert_sort(start,data);
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

struct node *insert_sort(struct node *start,int data)
{
	struct node *newNode,*ptr;
	
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	if(start == NULL || data<start->info)
	{
		newNode->next = start;
		start = newNode;
		return start;
	}
	ptr = start;
	while(ptr->next != NULL && data > ptr->next->info)
	{
		ptr = ptr->next;
	}
	newNode->next = ptr->next;
	ptr->next = newNode;
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
	ptr = start;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	newNode->next = ptr->next;
	ptr->next = newNode;
	return start;
}

void merge(struct node *start1,struct node *start2)
{
	struct node *start3 = NULL;

	while(start1 != NULL && start2 != NULL)
	{
		if(start1->info < start2->info)
		{
			start3 = insert(start3,start1->info);
			start1 = start1->next;
		}
		else if(start2->info < start1->info)
		{
			start3 = insert(start3,start2->info);
			start2 = start2->next;
		}
		else if(start1->info == start2->info)
		{
			start3 = insert(start3,start1->info);
			start1 = start1->next;
			start2 = start2->next;
		}
	}
	// If Second list is empty
	while(start1 != NULL)
	{
		start3 = insert(start3,start1->info);
		start1 = start1->next;
	}
	// If first list is empty
	while(start2 != NULL)
	{
		start3 = insert(start3,start2->info);
		start2 = start2->next;
	}
	printf("\n");
	display(start3);
}

