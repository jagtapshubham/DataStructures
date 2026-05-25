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
struct node *delete(struct node *head,int item);
struct node *reverse(struct node *head);

int main()
{
	int choice,data,item,position;
	struct node *head;
	head = (struct node *)malloc(sizeof(struct node));
	head->info = 0;
	head->next = NULL;
	head = create_list(head);
	while(1)
	{
		printf("1.Display.\n");
		printf("2.Add at end.\n");
		printf("3.Add before node.\n");
		printf("4.Add at position.\n");
		printf("5.Delete Node.\n");
		printf("6.Reverse.\n");
		printf("7.Quit.\n");
		
		printf("Enter your choice.\n");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				display(head);
				break;
			case 2:
				printf("Enter the element to be inserted : ");
				scanf("%d",&data);
				head = addatend(head,data);
				break;
			case 3:
				printf("Enter element before which to insert : ");
				scanf("%d",&item);
				printf("Enter element to be inserted : ");
				scanf("%d",&data);
				head = addbefore(head,data,item);
				break;
			case 4:
				printf("Enter position at which to insert : ");
				scanf("%d",&position);
				printf("Enter the element to be inserted : ");
				scanf("%d",&data);
				head = addatposition(head,data,position);
				break;
			case 5:
				printf("Enter element to be deleted : ");
				scanf("%d",&item);
				head = delete(head,item);
				break;
			case 6:
				head = reverse(head);
				break;
			case 7:
				exit(1);
			case 8:
				printf("Wrong choice.\n");
		}
	}
	return 0;
}

struct node *create_list(struct node *head)
{
	int i,createNode,data;
	printf("Enter the number of nodes : ");
	scanf("%d",&createNode);

	for(i=1;i<=createNode;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		head = addatend(head,data);
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
	printf("List is :\n");
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		ptr = ptr->next;
	}
	printf("\n");
}

struct node *addatend(struct node *head,int data)
{
	struct node *ptr,*newNode;
	newNode = (struct node *)malloc(sizeof(struct node *));
	newNode->info = data;

	ptr = head;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = newNode;
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

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	ptr=head;
	for(i=1;i<=position-1;i++)
	{
		ptr = ptr->next;
		if(ptr==NULL)
		{
			printf("There are less than %d elements.\n",position);
			return head;
		}
	}
	newNode->next = ptr->next;
	ptr->next = newNode;
	return head;
}

struct node *delete(struct node *head,int item)
{
	struct node *deleteNode,*ptr;
	ptr = head;
	while(ptr->next != NULL)
	{
		if(ptr->next->info == item)
		{
			deleteNode = ptr->next;
			ptr->next = deleteNode->next;
			free(deleteNode);
			return head;
		}
		ptr=ptr->next;
	}
	printf("Element %d not found.\n",item);
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

