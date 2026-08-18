// Check if list is pallindrome or not
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void pallindrome_check(struct node *start);
void free_list(struct node *start);

int main()
{
	struct node *start = NULL;

	start = create_list(start);
	printf("List :\n");
	display(start);
	pallindrome_check(start);
	free_list(start);
	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *newNode = NULL,*tail = NULL;
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
		if(newNode == NULL)
		{
			printf("Malloc Memory allocation fail\n");
			return start;
		}
		newNode->info = data;

		if(start == NULL)
		{
			newNode->next = NULL;
			start = newNode;
		}
		else
		{
			newNode->next = NULL;
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
		printf("List is empty\n");
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

void pallindrome_check(struct node *start)
{
	struct node *fast = NULL,*slow = NULL,*ptr1 = NULL,*ptr2 = NULL,*start2 = NULL,*current = NULL;
	int flag = 0;

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
	if(fast == NULL)
	{
		ptr2 = slow;
	}
	else
	{
		ptr2 = slow->next;
		slow->next = NULL;
	}
	while(ptr2 != NULL)
	{
		if(start2 == NULL)
		{
			start2 = ptr2;
			ptr2 = ptr2->next;
			start2->next = NULL;
		}
		else
		{
			current = ptr2;
			ptr2 = ptr2->next;
			current->next = start2;
			start2 = current;
		}
	}
	ptr1 = start;
	ptr2 = start2;
	while(ptr2 != NULL)
	{
		if(ptr1->info != ptr2->info)
		{
			flag = 1;
			break;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	if(flag == 0)
	{
		printf("List is pallindrome\n");
	}
	else
	{
		printf("List is not pallindrome\n");
	}
	free_list(start2);
}

void free_list(struct node *start)
{
	struct node *deleteNode = NULL;

	while(start != NULL)
	{
		deleteNode = start;
		start = start->next;
		free(deleteNode);
	}
}

