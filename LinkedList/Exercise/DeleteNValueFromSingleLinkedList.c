#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *deleteNValueNode(struct node *start,int data);

int main()
{
	struct node *start = NULL;
	int data;

	start = create_list(start);
	printf("List :\n");
	printf("Enter element to delete : ");
	scanf("%d",&data);
	start = deleteNValueNode(start,data);
	printf("List after deleting %d node :\n",data);
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

void display(struct node *start)
{
	struct node *ptr;

	if(start == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	else
	{
		ptr = start;
		printf("Start");
		while(ptr != NULL)
		{
			printf("->| %d |",ptr->info);
			ptr = ptr->next;
		}
	}
	printf("\n\n");
}

struct node *deleteNValueNode(struct node *start,int data)
{
	struct node *pp,*ptr,*deleteNode;

	pp = start;
	ptr = start->next;

	while(ptr != NULL)
	{
		if(ptr->info == data)
		{
			deleteNode = ptr;
			pp->next = deleteNode->next;
			ptr = pp->next;
			free(deleteNode);
		}
		else
		{
			pp = ptr;
			ptr = ptr->next;
		}
	}
	if(start->info == data)
	{
		deleteNode = start;
		start = deleteNode->next;
	}
	return start;
}

