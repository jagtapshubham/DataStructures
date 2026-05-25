#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *prev,*next;
};

struct node *create_list(struct node *head);
void display(struct node *head);
struct node *addatbeg(struct node *head,int data);
struct node *addatend(struct node *head,int data);
struct node *addbefore(struct node *head,int data,int item);
struct node *delete(struct node *head,int data);

int main()
{
	int data,choice,item,position;
	struct node *head;
	head = (struct node *)malloc(sizeof(struct node));
	head->info = 0;
	head->prev = NULL;
	head->next = NULL;

	while(1)
	{
		printf("\n");
		printf("1.Create List.\n");
		printf("2.Display.\n");
		printf("3.Add at beginning.\n");
		printf("4.Add at end.\n");
		printf("5.Add before node.\n");
		printf("6.Delete.\n");
		printf("7.Exit.\n");
		printf("\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				head = create_list(head);
				break;
			case 2:
				display(head);
				break;
			case 3:
				printf("Enter element to insert : ");
				scanf("%d",&data);
				head = addatbeg(head,data);
				break;
			case 4:
				printf("Enter element to insert : ");
				scanf("%d",&data);
				head = addatend(head,data);
				break;
			case 5:
				printf("Enter item before which to insert : ");
				scanf("%d",&item);
				printf("Enter element to insert : ");
				scanf("%d",&data);
				head = addbefore(head,data,item);
				break;
			case 6:
				printf("Enter element to delete : ");
				scanf("%d",&data);
				head = delete(head,data);
				break;
			case 7:
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
	struct node *newNode;
	int i,createNode,data;

	printf("Enter number of nodes to create : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
	{
		printf("%d nodes to create.\n",createNode);
		return head;
	}
	for(i=1;i<=createNode;i++)
	{
		printf("Enter data to insert : ");
		scanf("%d",&data);

		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = data;

		if(head->next == NULL)
		{
			head->next = newNode;
			head->prev = newNode;
			newNode->next = head;
			newNode->prev = head;
		}
		else
		{
			newNode->prev = head->prev;
			head->prev->next = newNode;
			newNode->next = head;
			head->prev = newNode;
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
	printf("Head");
	while(ptr != head)
	{
		printf("<->| %d |",ptr->info);
		ptr = ptr->next;
	}
}

struct node *addatbeg(struct node *head,int data)
{
	struct node *newNode;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;
	if(head->next == NULL)
	{
		head->next = newNode;
		head->prev = newNode;
		newNode->next = head;
		newNode->prev = head;
	}
	else
	{
		newNode->next = head->next;
		newNode->prev = head->prev;
		head->next = newNode;
	}
	return head;
}

struct node *addatend(struct node *head,int data)
{
	struct node *newNode;
	
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;
	if(head->next == NULL)
	{
		head->next = newNode;
		head->prev = newNode;
		newNode->next = head;
		newNode->prev = head;
	}
	else
	{
		newNode->prev = head->prev;
		newNode->next = head;
		head->prev->next = newNode;
		head->prev = newNode;
	}
	return head;
}

struct node *addbefore(struct node *head,int data,int item)
{
	struct node *newNode,*ptr;
	
	if(head->next->info == item)
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = data;

		newNode->next = head->next;
		newNode->prev = head;
		head->next->prev = newNode;
		head->next = newNode;
		return head;
	}
	ptr = head->next;
	while(ptr->next != head)
	{
		if(ptr->next->info == item)
		{
			newNode = (struct node *)malloc(sizeof(struct node));
			newNode->info = data;

			newNode->next = ptr->next;
			newNode->prev = ptr;
			ptr->next->prev = newNode;
			ptr->next = newNode;
			return head;
		}
		ptr = ptr->next;
	}
	printf("%d element not present in list.\n",item);
	return head;
}

struct node *delete(struct node *head,int data)
{
	struct node *deleteNode,*ptr;

	if(head->next->info == data)
	{
		deleteNode = head->next;
		head->next = deleteNode->next;
		deleteNode->next->prev = head;
		return head;
	}
	ptr = head->next->next;
	while(ptr != head)
	{
		if(ptr->info == data)
		{
			deleteNode = ptr;
			if(ptr->next == head)
			{
				head->prev = ptr->prev;
			}
			else
			{
				ptr->next->prev = ptr->prev;
			}
			ptr->prev->next = ptr->next;
			free(deleteNode);
			return head;
		}
		ptr = ptr->next;
	}
	printf("%d element not present in list.\n",data);
	return head;
}

