#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *prev,*next;
};

struct node *create_list(struct node *head);
void display(struct node *head);
struct node *addatend(struct node *head,int data);
struct node *addbefore(struct node *head,int data,int item);
struct node *addatposition(struct node *head,int data,int position);
struct node *delete(struct node *head,int data);
struct node *reverse(struct node *head);

int main()
{
	int choice,data,item,position;
	struct node *head;
	head = (struct node *)malloc(sizeof(struct node));
	head->info = 0;
	head->prev = NULL;
	head->next = NULL;
	
	head = create_list(head);
	while(1)
	{
		printf("\n");
		printf("1.Display.\n");
		printf("2.Add at end.\n");
		printf("3.Add before node.\n");
		printf("4.Add at position.\n");
		printf("5.Delete node.\n");
		printf("6.Reverse.\n");
		printf("7.Exit.\n");
		printf("\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				display(head);
				break;
			case 2:
				printf("Enter element to insert : ");
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
				head = reverse(head);
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
	struct node *newNode,*ptr;
	int data,createNode,i;

	printf("Enter number of element to create : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
	{
		printf("%d nodes to create.\n",createNode);
		return head;
	}
	for(i=1;i<=createNode;i++)
	{
		printf("Enter element to insert : ");
		scanf("%d",&data);

		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = data;

		ptr = head;
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = newNode;
		newNode->prev = ptr;
		newNode->next = NULL;
	}
	return head;
}

void display(struct node *head)
{
	struct node *ptr;
	
	if(head == NULL)
	{
		printf("List is empty.\n");
		return;
	}

	ptr = head->next;
	printf("Head");
	while(ptr!=NULL)
	{
		printf("->| %d |",ptr->info);
		ptr = ptr->next;
	}
}

struct node *addatend(struct node *head,int data)
{
	struct node *newNode,*ptr;
	
	ptr = head;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	ptr->next = newNode;
	newNode->prev = ptr;
	newNode->next = NULL;
	return head;
}

struct node *addbefore(struct node *head,int data,int item)
{
	struct node *newNode,*ptr;

	ptr = head;
	while(ptr->next != NULL)
	{
		if(ptr->next->info == item)
		{
			newNode = (struct node *)malloc(sizeof(struct node));
			newNode->info = data;
			newNode->prev = ptr;
			newNode->next = ptr->next;
			ptr->next->prev = newNode;
			ptr->next = newNode;
			return head;
		}
		ptr=ptr->next;
	}
	printf("%d element not present in list.\n",item);
	return head;
}

struct node *addatposition(struct node *head,int data,int position)
{
	struct node *newNode,*ptr;
	int i;

	ptr = head;
	for(i=1;i<=position-1 && ptr!=NULL;i++)
	{
		ptr = ptr->next;
	}
	printf("ptr = %p\n",ptr);
	if(ptr == NULL)
	{
		printf("There are less than %d elements in list.\n",position);
		return head;
	}
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	newNode->prev = ptr;
	newNode->next = ptr->next;

	ptr->next->prev = newNode;
	ptr->next = newNode;

	return head;
}

struct node *delete(struct node *head,int data)
{
	struct node *deleteNode,*ptr;

	ptr = head;
	while(ptr!=NULL)
	{
		if(ptr->next->info == data)
		{
			deleteNode = ptr->next;
			if(deleteNode->next != NULL)
			{
				deleteNode->next->prev = ptr;
			}
			ptr->next = deleteNode->next;
			free(deleteNode);
			return head;
		}
		ptr = ptr->next;
	}
	printf("%d element not present in list.\n",data);
	return head;
}

struct node *reverse(struct node *head)
{
	struct node *prev,*ptr,*next;
	prev = NULL;
	ptr = head->next;

	while(ptr!=NULL)
	{
		next = ptr->next;
		ptr->next = prev;
		ptr->prev = next;
		prev = ptr;
		ptr = next;
	}
	head->next = prev;
	return head;
}

