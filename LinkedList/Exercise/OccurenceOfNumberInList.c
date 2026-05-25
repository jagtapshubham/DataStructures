#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct count
{
	int info;
	int count;
	struct count *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void display2(struct count *start2);
struct count *count_element(struct node *start);

int main()
{
	struct node *start = NULL;
	struct count *start2 = NULL;

	start = create_list(start);
	printf("List : ");
	display(start);
	printf("Element and its count present in list :\n");
	start2 = count_element(start);
	display2(start2);

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
			while(ptr->next != NULL && data > ptr->next->info)
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
	printf("\n");
	ptr = start;
	printf("Start");
	while(ptr!=NULL)
	{
		printf("->| %d |",ptr->info);
		ptr = ptr->next;
	}
	printf("\n");
}

void display2(struct count *start2)
{
	struct count *ptr;

	printf("inside display2");
	if(start2 == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	
	printf("\n");
	ptr = start2;
	printf("Start");
	while(ptr != NULL)
	{
		printf("->| %d-%d |",ptr->info,ptr->count);
		ptr = ptr->next;
	}
	printf("\n");
}

struct count *count_element(struct node *start)
{
	struct node *ptr;
	struct count *newNode,*start2 = NULL,*ptr2;
	int count=0,prev=0;

	ptr = start;
	prev = ptr->info;
	while(ptr!=NULL)
	{
		if(ptr->info == prev)
		{
			count++;
			prev = ptr->info;
			ptr = ptr->next;
		}
		else
		{
			newNode = (struct count *)malloc(sizeof(struct count));
			newNode->info = prev;
			newNode->count = count;

			if(start2 == NULL)
			{
				newNode->next = start2;
				start2 = newNode;
			}
			else
			{
				ptr2 = start2;
				while(ptr2->next != NULL)
				{
					ptr2 = ptr2->next;
				}
				newNode->next = ptr2->next;
				ptr2->next = newNode;
			}
			prev = ptr->info;
			count = 0;
		}
		if(ptr == NULL)
		{
			newNode = (struct count *)malloc(sizeof(struct count));
			newNode->info = prev;
			newNode->count = count;

			if(start2 == NULL)
			{
				newNode->next = start2;
				start2 = newNode;
			}
			else
			{
				ptr2 = start2;
				while(ptr2->next != NULL)
				{
					ptr2 = ptr2->next;
				}
				newNode->next = ptr2->next;
				ptr2->next = newNode;
			}
		}
	}
	return start2;
}

