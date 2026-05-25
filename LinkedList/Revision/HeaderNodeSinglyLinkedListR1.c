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
struct node *addbefore(struct node *head,int data,int item);
struct node *addatposition(struct node *head,int data,int position);
struct node *delete(struct node *head,int data);
struct node *reverse(struct node *head);

int main()
{
	int choice,data,item,position;

	struct node *head = NULL;
	head = (struct node *)malloc(sizeof(struct node));
	head->info = 0;
	head->next = NULL;
	head = create_list(head);

	while(1)
	{
		printf("\n");
		printf("1.Create List.\n");
		printf("2.Display.\n");
		printf("3.Add at end.\n");
		printf("4.Add before node.\n");
		printf("5.Add at position.\n");
		printf("6.Delete node.\n");
		printf("7.Reverse.\n");
		printf("8.Exit.\n");
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
				head = addatend(head,data);
				break;
			case 4:
				printf("Enter item before which to insert : ");
				scanf("%d",&item);
				printf("Enter element to insert : ");
				scanf("%d",&data);
				head = addbefore(head,data,item);
				break;
			case 5:
				printf("Enter position at which to insert : ");
				scanf("%d",&position);
				printf("Enter element to insert : ");
				scanf("%d",&data);
				head = addatposition(head,data,position);
				break;
			case 6:
				printf("Enter element to be delete : ");
				scanf("%d",&data);
				head = delete(head,data);
				break;
			case 7:
				head = reverse(head);
				break;
			case 8:
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
	int data,i,createNode;

	printf("Enter number of nodes to create : ");
	scanf("%d",&createNode);

	if(createNode<=0)
	{
		printf("Enter valid number of nodes to create.\n");
		return head;
	}
	for(i=1;i<=createNode;i++)
	{
		printf("Enter element to insert : ");
		scanf("%d",&data);
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = data;
		head->info = head->info + 1;

		if(head->next == NULL)
		{
			newNode->next = head->next;
			head->next = newNode;
		}
		else
		{
			ptr = head;
			while(ptr->next != NULL)
			{
				ptr = ptr->next;
			}
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
	printf("Number of elements in list are %d.\n",head->info);
	printf("\n");
	printf("Head");
	while(ptr != NULL)
	{
		printf("->| %d |",ptr->info);
		ptr = ptr->next;
	}
	printf("\n");
}

struct node *addatend(struct node *head,int data)
{
	struct node *newNode,*ptr;
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;
	
	if(head->next == NULL)
	{
		newNode->next = head->next;
		head->next = newNode;
		head->info = head->info + 1;
		return head;
	}
	ptr = head->next;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	newNode->next = ptr->next;
	ptr->next = newNode;
	head->info = head->info + 1;
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
			head->info = head->info + 1;

			newNode->next = ptr->next;
			ptr->next = newNode;
			return head;
		}
		ptr = ptr->next;
	}
	printf("%d element not present in list.\n",item);
	return head;
}

struct node *addatposition(struct node *head,int data,int position)
{
	struct node *newNode,*ptr;
	int i;

	ptr = head->next;
	for(i=1;i<position-1 && ptr!=NULL;i++)
	{
		ptr = ptr->next;
	}
	if(ptr == NULL)
	{
		printf("%d position exceeds the list.\n",position);
		return head;
	}
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->info = data;
	head->info = head->info + 1;
	newNode->next = ptr->next;
	ptr->next = newNode;
	return head;
}

struct node *delete(struct node *head,int data)
{
	struct node *deleteNode,*ptr;

	ptr = head;
	while(ptr->next != NULL)
	{
		if(ptr->next->info == data)
		{
			deleteNode = ptr->next;
			ptr->next = deleteNode->next;
			head->info = head->info - 1;
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
		prev = ptr;
		ptr = next;
	}
	head->next = prev;
	return head;
}

