#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *copy_list(struct node *start,struct node *copyStart);

int main()
{
	struct node *start = NULL,*copyStart = NULL;
	
	start = create_list(start);
	printf("List:\n");
	display(start);

	copyStart = copy_list(start,copyStart);
	printf("Copied List:\n");
	display(copyStart);

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
	ptr = start;
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
	//display(start);
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

struct node *copy_list(struct node *start,struct node *copyStart)
{
	struct node *newNode,*ptr,*ptr2;
	
	copyStart = NULL;
	if(start == NULL)
	{
		printf("List is empty.\n");
		return start;
	}
	ptr = start;
	while(ptr != NULL)
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = ptr->info;

		if(copyStart == NULL)
		{
			newNode->next = copyStart;
			copyStart = newNode;
		}
		else
		{
			ptr2 = copyStart;
			while(ptr2->next != NULL)
			{
				ptr2 = ptr2->next;
			}
			newNode->next = ptr2->next;
			ptr2->next = newNode;
		}
		ptr = ptr->next;
	}
	return copyStart;
}

