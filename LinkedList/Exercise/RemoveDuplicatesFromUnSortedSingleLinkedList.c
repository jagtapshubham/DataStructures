#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *remove_duplicates(struct node *start);

int main()
{
	struct node *start = NULL;

	start = create_list(start);
	printf("List:\n");
	display(start);
	start = remove_duplicates(start);
	printf("List after removing duplicates:\n");
	display(start);

	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *newNode,*ptr;
	int data,i,createNode;

	printf("Enter number of nodes to create : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
	{
		printf("Enter valid number of nodes.\n");
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
	while(ptr != NULL)
	{
		printf("->| %d |",ptr->info);
		ptr = ptr->next;
	}
	printf("\n\n");
}

struct node *remove_duplicates(struct node *start)
{
	struct node *ptr,*deleteNode,*current,*pp;

	for(pp=current=start;current->next != NULL;current = current->next)
	{
		for(pp=current,ptr=current->next;ptr != NULL;ptr=ptr->next)
		{
			if(current->info == ptr->info)
			{
				deleteNode = ptr;
				pp->next = ptr->next;
				ptr = pp;
				free(deleteNode);
			}
			else
			{
				pp = ptr;
			}
		}
	}
	return start;
}

