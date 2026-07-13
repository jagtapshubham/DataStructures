#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void find_middle_node(struct node *start);

int main()
{
	struct node *start = NULL;

	start = create_list(start);
	printf("List :\n");
	display(start);
	find_middle_node(start);

	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *newNode = NULL,*tail = NULL;
	int data,i,createNode;

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

void find_middle_node(struct node *start)
{
	struct node *slow = NULL,*fast = NULL;

	if(start == NULL)
	{
		printf("List is empty\n");
		return;
	}

	slow = fast = start;
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	printf("Middle element of list is %d\n",slow->info);
}

