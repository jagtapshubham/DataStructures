#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *create_s(struct node *start);
void print_element_by_position(struct node *start1,struct node *start2);

int main()
{
	struct node *start1 = NULL,*start2 = NULL;

	printf("Enter List 1\n");
	start1 = create_s(start1);
	printf("List 1:\n");
	display(start1);
	printf("Enter List 2\n");
	start2 = create_list(start2);
	printf("List 2:\n");
	display(start2);
	print_element_by_position(start1,start2);
	return 0;
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

struct node *create_s(struct node *start)
{
	struct node *newNode,*ptr;
	int data,createNode,i;

	printf("Enter number of nodes to create : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
	{
		printf("Enter valid number of nodes to enter.\n");
		return start;
	}
	for(i=1;i<=createNode;i++)
	{
		printf("Enter element to insert : ");
		scanf("%d",&data);
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = data;
		
		if(start == NULL || data < start->info)
		{
			newNode->next = start;
			start = newNode;
		}
		else
		{
			ptr = start;
			while(ptr->next != NULL && data >= ptr->next->info)
			{
				ptr = ptr->next;
			}
			if(ptr->info != data)
			{
				newNode->next = ptr->next;
				ptr->next = newNode;
			}
		}
	}
	return start;
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

void print_element_by_position(struct node *start1,struct node *start2)
{
	struct node *ptr1,*ptr2;
	int i = 1;
	ptr1 = start1;
	ptr2 = start2;

	while(ptr1 != NULL && ptr2 != NULL)
	{
		if(i == ptr1->info)
		{
			printf("%d ",ptr2->info);
			ptr1 = ptr1->next;
		}
		i++;
		//ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	printf("\n");
}

