#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *prev,*next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *swap_adjacent_data_by_link(struct node *start);

int main()
{
	struct node *start = NULL;

	start = create_list(start);
	printf("List :\n");
	display(start);
	start = swap_adjacent_data_by_link(start);
	printf("List after adjacent swap :\n");
	display(start);

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

		if(start == NULL)
		{
			newNode->prev = NULL;
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
			newNode->prev = ptr;
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
			printf("<->| %d |",ptr->info);
			ptr = ptr->next;
		}
	}
	printf("\n\n");
}

struct node *swap_adjacent_data_by_link(struct node *start)
{
	struct node *temp,*ptr,*q,*pp,*ptemp;

	ptr = start;
	while(ptr != NULL && ptr->next != NULL)
	{
		q = ptr->next;
		if(q->next != NULL)
		{
			q->next->prev = ptr;
		}
		// next pointer handling
		ptr->next = q->next;
		q->next = ptr;
		// prev pointer handling
		ptemp = ptr->prev;
		ptr->prev = q->prev;
		q->prev = ptemp;
		
		if(ptr != start)
		{
			pp->next = q;
		}
		if(start == ptr)
		{
			start = q;
		}
		temp = ptr;
		ptr = q;
		q = temp;
		pp = q;
		ptr = q->next;
	}
	return start;
}

