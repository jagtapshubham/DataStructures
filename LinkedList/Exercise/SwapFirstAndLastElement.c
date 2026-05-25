#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *swap_first_last_data(struct node *start);
struct node *swap_first_last_link(struct node *start);

int main()
{
	struct node *start = NULL;
	
	start = create_list(start);
	printf("List :\n");
	display(start);
	start = swap_first_last_data(start);
	printf("List after swap by info :\n");
	display(start);
	start = swap_first_last_link(start);
	printf("List after swap by link :\n");
	display(start);

	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *newNode,*ptr;
	int createNode,data,i;

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
	ptr = start;
	printf("Start");
	while(ptr != NULL)
	{
		printf("->| %d |",ptr->info);
		ptr = ptr->next;
	}
	printf("\n\n");
}

struct node *swap_first_last_data(struct node *start)
{
	struct node *ptr;
	int temp;

	ptr = start;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	temp = ptr->info;
	ptr->info = start->info;
	start->info = temp;

	return start;
}

struct node *swap_first_last_link(struct node *start)
{
	struct node *ptr,*temp;

	printf("Inside swap.\n");
	ptr = start;
	while(ptr->next->next != NULL)
	{
		ptr = ptr->next;
	}
	temp = ptr->next;
	ptr->next = start;
	temp->next = start->next;
	start->next = NULL;
	start = temp;

	return start;
}

