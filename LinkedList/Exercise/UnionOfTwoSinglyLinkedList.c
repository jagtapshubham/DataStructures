#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *union_of_list(struct node *start1,struct node *start2,struct node *start3);

int main()
{
	struct node *start1 = NULL,*start2 = NULL,*start3 = NULL;

	printf("Enter list 1:\n");
	start1 = create_list(start1);
	printf("Enter list 2:\n");
	start2 = create_list(start2);

	printf("List 1:\n");
	display(start1);
	printf("List 2:\n");
	display(start2);

	start3 = union_of_list(start1,start2,start3);
	printf("Union of List 1 and List 2:\n");
	display(start3);

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
		printf("Enter valid number of nodes to insert.\n");
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
	printf("\n\n");
}

struct node *union_of_list(struct node *start1,struct node *start2,struct node *start3)
{
	struct node *newNode,*ptr1,*ptr2,*ptr3;
	int flag = 0;

	// copy unique elements from list 1
	for(ptr1=start1;ptr1!=NULL;flag=0,ptr1=ptr1->next)
	{
		for(ptr3=start3;ptr3!=NULL;ptr3=ptr3->next)
		{
			if(ptr1->info == ptr3->info)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			newNode = (struct node *)malloc(sizeof(struct node));
			newNode->info = ptr1->info;
			if(start3 == NULL)
			{
				newNode->next = start3;
				start3 = newNode;
			}
			else
			{
				ptr3 = start3;
				while(ptr3->next != NULL)
				{
					ptr3 = ptr3->next;
				}
				newNode->next = ptr3->next;
				ptr3->next = newNode;
			}
		}
		display(start3);
	}
	// copy unique elements from list 2
	for(ptr2=start2;ptr2!=NULL;flag=0,ptr2=ptr2->next)
	{
		for(ptr3=start3;ptr3!=NULL;ptr3=ptr3->next)
		{
			if(ptr2->info == ptr3->info)
			{
				flag=1;
				break;
			}
		}
		if(flag == 0)
		{
			newNode = (struct node *)malloc(sizeof(struct node));
			newNode->info = ptr2->info;
			if(start3 == NULL)
			{
				newNode->next = start3;
				start3 = newNode;
			}
			else
			{
				ptr3 = start3;
				while(ptr3->next != NULL)
				{
					ptr3 = ptr3->next;
				}
				newNode->next = ptr3->next;
				ptr3->next = newNode;
			}
		}
	}
	return start3;
}

