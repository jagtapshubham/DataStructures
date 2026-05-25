#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *head);
void display(struct node *head);
struct node *addatend(struct node *head,int data);
struct node *addbefore(struct node *head,int dat,int item);
struct node *addatposition(struct node *head,int data,int position);
struct node *delete(struct node *head,int data);
struct node *reverse(struct node *head);

int main()
{
	int data,item,position,choice;
	struct node *head;
	head = (struct node*)malloc(sizeof(struct node));
	head->info = 0;
	head->next = NULL;

	head = create_list(head);
	while(1)
	{
		printf("\n");
		printf("1.Display.\n");
		printf("2.Add at end.\n");
		printf("3.Add before.\n");
		printf("4.Add at position.\n");
		printf("5.Delete node.\n");
		printf("6.Exit.\n");
		printf("\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				display(head);
				break;
			case 2:
				printf("Enter data to insert : ");
				scanf("%d",&data);
				head = addatend(head,data);
				break;
			case 3:
				printf("Enter item before which to insert : ");
				scanf("%d",&item);
				printf("Enter element to insert : ");
				scanf("%d",&data);
				head = addbefore(head,data,item);
				break;
			case 4:
				printf("Enter position at which to insert : ");
				scanf("%d",&position);
				printf("Enter element to insert : ");
				scanf("%d",&data);
				head = addatposition(head,data,position);
				break;
			case 5:
				printf("Enter element to delete : ");
				scanf("%d",&data);
				head = delete(head,data);
				break;
			case 6:
				exit(1);
			default:
				printf("Wrong choice.\n");
				break;
		}
	}
	return 0;
}

struct node *create_list(struct node *head)
{
	struct node *newNode,*ptr;
	int data,createNode,i;

	printf("Enter number of nodes to insert : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
	{
		printf("%d nodes to insert.\n",createNode);
		return head;
	}
	for(i=1;i<=createNode;i++)
	{
		printf("Enter element to insert : ");
		scanf("%d",&data);
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = data;

		if(head->next == NULL)
		{
			head->next = newNode;
			newNode->next = head;
		}
		else
		{
			ptr = head;
			do
			{
				ptr = ptr->next;
			}while(ptr->next != head);
			newNode->next = ptr->next;
			ptr->next = newNode;
		}
	}
	return head;
}

void display(struct node *head)
{
	struct node *ptr;

	if(head->next == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	
	ptr = head->next;
	do
	{
		printf("->| %d |",ptr->info);
		ptr = ptr->next;
	}while(ptr != head);
}

struct node *addatend(struct node *head,int data)
{
	struct node *newNode,*ptr;

	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->info = data;
	
	if(head->next == NULL)
	{
		head->next = newNode;
		newNode->next = head;
	}
	else
	{
		ptr = head;
		do
		{
			ptr = ptr->next;
		}while(ptr->next != head);
		newNode->next = ptr->next;
		ptr->next = newNode;
	}
	return head;
}

struct node *addbefore(struct node *head,int data,int item)
{
	struct node *newNode,*ptr;

	if(head->next == NULL)
	{
		printf("List is empty");
		return head;
	}
	if(head->next->info == item)
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = data;

		newNode->next = head->next;
		head->next = newNode;
		return head;
	}
	ptr = head->next;
	do
	{
		if(ptr->next->info == item)
		{
			newNode = (struct node *)malloc(sizeof(struct node));
			newNode->info = data;

			newNode->next = ptr->next;
			ptr->next = newNode;
			return head;
		}
		ptr = ptr->next;
	}while(ptr->next != head);
	
	printf("%d element not present in list.\n",item);
	return head;
}

struct node *addatposition(struct node *head,int data,int position)
{
	struct node *newNode,*ptr;
	int i;

	if(position == 1)
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = data;

		newNode->next = head->next;
		head->next = newNode;
		return head;
	}
	ptr = head->next;
	for(i=1;i<position-1;i++)
	{
		printf("Inside loop i = %d.\n",i);
		ptr = ptr->next;
		if(ptr == head)
		{
			printf("%d position not present in list.\n",position);
			return head;
		}
	}
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	newNode->next = ptr->next;
	ptr->next = newNode;
	return head;
}

struct node *delete(struct node *head,int data)
{
	struct node *deleteNode,*ptr;

	if(head->next->info == data)
	{
		deleteNode = head->next;
		head->next = deleteNode->next;
		free(deleteNode);
		return head;
	}
	ptr = head->next;
	while(ptr != head)
	{
		if(ptr->next->info == data)
		{
			deleteNode = ptr->next;
			ptr->next = deleteNode->next;
			free(deleteNode);
			return head;
		}
		ptr = ptr->next;
	}
	printf("%d element not present in list.\n",data);
	return head;
}

