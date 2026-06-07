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
void delete_node_by_address(struct node *deleteAddress);

int main()
{
	struct node *start = NULL,*deletePointer = NULL;
	int data;

	start = create_list(start);
	printf("List:\n");
	display(start);
	printf("Enter element to delete : ");
	scanf("%d",&data);
	deletePointer = get_node_address(start,data);
	//if(deletePointer != start)
	delete_node_by_address(deletePointer);
	printf("List after node deletion.\n");
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
		printf("Enter valid number of node to create.\n");
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
	struct node *ptr;

	ptr = start;
	while(ptr != NULL)
	{
		if(ptr->info == data)
		{
			return ptr;
		}
		ptr = ptr->next;
	}
	printf("%d element not present in list.\n",data);
	//return start;
}

void delete_node_by_address(struct node *deleteAddress)
{
	struct node *deleteNode;
	
	deleteNode = deleteAddress->next;
	deleteAddress->info = deleteNode->info;
	deleteAddress->next = deleteNode->next;
	free(deleteNode);
	// Here deletion of last node is not possible due to limited information as we do not have previous node pointer here in this case
}

