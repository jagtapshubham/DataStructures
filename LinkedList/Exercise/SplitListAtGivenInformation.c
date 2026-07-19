#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
int split_list(struct node **start,struct node **secondList,int data);

int main()
{
	struct node *start = NULL,*secondList = NULL;
	int data,status = -1;

	start = create_list(start);
	if(start != NULL)
	{
		printf("List :\n");
		display(start);
		printf("Enter the number from where to split list : ");
		scanf("%d",&data);
		status = split_list(&start,&secondList,data);
	}

	if(status == 1)
	{
		printf("First List :\n");
		display(start);
		printf("Second List :\n");
		display(secondList);
	}
	else if(status == -1)
	{
		printf("List is empty.\n");
	}
	else
	{
		printf("List does not contain %d data.\n",data);
	}
	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *newNode = NULL,*tail = newNode;
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

int split_list(struct node **start,struct node **secondList,int data)
{
	struct node *ptr = NULL,*pp = NULL;

	if(*start == NULL)
	{
		return -1;
	}
	if((*start)->info == data)
	{
		*secondList = *start;
		*start = NULL;
		return 1;
	}
	pp = ptr = *start;
	while(ptr != NULL)
	{
		if(ptr->info == data)
		{
			pp->next = NULL;
			*secondList = ptr;
			return 1;
		}
		pp = ptr;
		ptr = ptr->next;
	}
	return 0;
}

