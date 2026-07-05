#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void check_pallindrome(struct node *start);

int main()
{
	struct node *start = NULL;

	printf("Enter list :\n");
	start = create_list(start);
	printf("List :\n");
	display(start);
	check_pallindrome(start);

	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *newNode=NULL,*tail=NULL;
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
	struct node *ptr=NULL;

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

void check_pallindrome(struct node *start)
{
	struct node *newStart = NULL,*mid = NULL,*ptr = NULL,*ptr2 = NULL,*newNode = NULL,*deleteNode = NULL;
	int nodeCount = 0,n = 0,i,flag = 0;

	if(start == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	if(start->next == NULL)
	{
		printf("List is pallindrome.\n");
		return;
	}
	ptr = start;
	while(ptr != NULL)
	{
		nodeCount++;
		ptr = ptr->next;
	}
	n = nodeCount/2;
	ptr = start;
	for(i=1;i<n;i++)
	{
		ptr = ptr->next;
	}
	if(nodeCount % 2 == 0)
	{
		mid = ptr;
	}
	else
	{
		mid = ptr->next;
	}
	// second half list
	ptr = mid->next;
	while(ptr != NULL)
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = ptr->info;
		newNode->next = newStart;
		newStart = newNode;
		ptr = ptr->next;
	}
	// compare
	ptr = start;
	ptr2 = newStart;
	while(ptr2 != NULL)
	{
		if(ptr->info != ptr2->info)
		{
			flag = 1;
			break;
		}
		ptr = ptr->next;
		ptr2 = ptr2->next;
	}
	if(flag == 0)
	{
		printf("List is pallindrome.\n");
	}
	else
	{
		printf("List is not pallindrome.\n");
	}
	// free second list
	while(newStart != NULL)
	{
		deleteNode = newStart;
		newStart = deleteNode->next;
		free(deleteNode);
	}
}

