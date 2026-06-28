#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *delete_last_nth_node(struct node *start,int n);

int main()
{
	struct node *start = NULL;
	int n=0;

	start = create_list(start);
	printf("List :\n");
	display(start);
	printf("Enter the last nth node to delete : ");
	scanf("%d",&n);
	start = delete_last_nth_node(start,n);
	printf("\nAfter deleting last nth node form list :\n");
	display(start);

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

struct node *delete_last_nth_node(struct node *start,int n)
{
	struct node *ptr = NULL,*deleteNode = NULL,*pp = NULL,*k = NULL;
	int i,count=0;

	if(n <= 0 || start == NULL)
	{
		printf("Nothing to delete.\n");
		return start;
	}

	if(n==1 && start->next == NULL)
	{
		deleteNode = start;
		start = NULL;
		free(deleteNode);
		return start;
	}
	for(i=1,ptr=start;i<=n && ptr!=NULL;i++,ptr=ptr->next)
	{
		count++;
	}
	if(ptr == NULL)
	{
		if(count == n)
		{
			deleteNode = start;
			start = deleteNode->next;
			free(deleteNode);
			return start;
		}
		printf("\n%d position exceeds the list.\n",n);
		return start;
	}
	else
	{
		k = ptr;
	}
	for(pp=ptr=start; k!=NULL && ptr!= NULL;pp=ptr,k=k->next,ptr=ptr->next)
	{
		;
	}
	deleteNode = ptr;
	pp->next = deleteNode->next;
	free(deleteNode);
	return start;
}

