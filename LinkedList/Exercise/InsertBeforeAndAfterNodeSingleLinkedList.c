#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *get_node_address(struct node *start,int data);
void insert_before_after_node(struct node *insertNode,int data);

int main()
{
	struct node *start = NULL,*nodePointer = NULL;
	int data;

	start = create_list(start);
	printf("List:");
	display(start);
	printf("Enter element to get address of : ");
	scanf("%d",&data);
	nodePointer = get_node_address(start,data);
	printf("Enter element to insert before and after : ");
	scanf("%d",&data);
	insert_before_after_node(nodePointer,data);
	printf("List after insertion before and after node.\n");
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
	ptr = start;
	printf("Start");
	while(ptr != NULL)
	{
		printf("->| %d |",ptr->info);
		ptr = ptr->next;
	}
	printf("\n\n");
}

struct node *get_node_address(struct node *start,int data)
{
	struct node *nodeAddress = NULL,*ptr;

	ptr = start;
	while(ptr != NULL)
	{
		if(ptr->info == data)
		{
			return ptr;
		}
		ptr = ptr->next;
	}
	printf("%d element not found in list.\n",data);
	return start;
}

void insert_before_after_node(struct node *insertNode,int data)
{
	struct node *newNode,*ptr;

	ptr = insertNode;
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = insertNode->info;
	
	newNode->next = insertNode->next;
	insertNode->next = newNode;
	insertNode->info = data;

	ptr = newNode;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;
	
	newNode->next = ptr->next;
	ptr->next = newNode;
}

