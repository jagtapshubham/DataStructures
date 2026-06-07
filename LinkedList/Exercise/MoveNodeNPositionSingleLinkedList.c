#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *move_n_position(struct node *start,int data,int Nposition);

int main()
{
	struct node *start = NULL;
	int position,data;

	printf("Enter List:\n");
	start = create_list(start);
	printf("List:\n");
	display(start);
	printf("Enter element to move : ");
	scanf("%d",&data);
	printf("Enter number of position to move node : ");
	scanf("%d",&position);
	start = move_n_position(start,data,position);
	printf("List after moving node n position.\n");
	display(start);

	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *newNode,*ptr;
	int data,createNode,i;

	printf("Enter number of node to create : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
	{
		printf("Enter valid number of nodes to create.\n ");
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

struct node *move_n_position(struct node *start,int data,int Nposition)
{
	struct node *ptr,*element;
	int i;

	ptr = start;
	while(ptr->next != NULL)
	{
		if(start->info == data || (ptr->next->info == data && ptr->next->next != NULL))
		{
			if(start->info == data)
			{
				element = start;
				start = element->next;
				ptr = start;
			}
			else
			{
				element = ptr->next;
				ptr->next = element->next;
				ptr = ptr->next;
			}
			for(i=1;i<Nposition && ptr->next != NULL;i++)
			{
				ptr = ptr->next;
			}
			element->next = ptr->next;
			ptr->next = element;
			return start;
		}
		ptr = ptr->next;
	}
	printf("%d element not present in list.\n",data);
	return start;
}

