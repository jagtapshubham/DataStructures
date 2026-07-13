#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *delete_nth_node_from_last(struct node *start,int position);

int main()
{
	struct node *start = NULL;
	int position = 0;

	start = create_list(start);
	printf("List :\n");
	display(start);
	printf("Enter nth position to delete : ");
	scanf("%d",&position);
	start = delete_nth_node_from_last(start,position);
	display(start);

	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *newNode = NULL,*tail = NULL;
	int data,i,createNode;

	printf("Enter number of nodes to create node : ");
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

struct node *delete_nth_node_from_last(struct node *start,int position)
{
	struct node *ptr = NULL,*k = NULL,*pp = NULL,*deleteNode = NULL;
	int i,count=0;

	if(start == NULL || position <= 0)
	{
		printf("Nothing to delete.\n");
		return start;
	}

	for(i=1,ptr=start;ptr!=NULL && i<=position;i++,ptr=ptr->next)
	{
		count++;
	}
	if(ptr == NULL)
	{
		if(count == position)
		{
			deleteNode = start;
			start = deleteNode->next;
			free(deleteNode);
			return start;
		}
		printf("%d position exceeds the list.\n",position);
		return start;
	}
	k = ptr;
	ptr = start;
	while(k!=NULL && ptr != NULL)
	{
		pp = ptr;
		ptr = ptr->next;
		k = k->next;
	}
	printf("ptr = %d\n",ptr->info);
	deleteNode = ptr;
	pp->next = deleteNode->next;
	free(deleteNode);

	return start;
}

