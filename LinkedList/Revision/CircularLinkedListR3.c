#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *last);
void display(struct node *last);
struct node *addatbeg(struct node *last,int data);
struct node *addatend(struct node *last,int data);
struct node *addbefore(struct node *last,int data,int item);
struct node *addafter(struct node *last,int data,int item);
struct node *delete(struct node *last,int data);

int main()
{
	struct node *last = NULL;
	int choice,data,item;

	while(1)
	{
		printf("\n");
		printf("1.Create List.\n");
		printf("2.Display.\n");
		printf("3.Add at beginning.\n");
		printf("4.Add at end.\n");
		printf("5.Add before node.\n");
		printf("6.Delete node.\n");
		printf("7.Exit\n");
		printf("\n");
		
		printf("Enter your choice : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				last = create_list(last);
				break;
			case 2:
				display(last);
				break;
			case 3:
				printf("Enter element to insert : ");
				scanf("%d",&data);
				last = addatbeg(last,data);
				break;
			case 4:
				printf("Enter element to insert : ");
				scanf("%d",&data);
				last = addatend(last,data);
				break;
			case 5:
				printf("Enter item before which to insert : ");
				scanf("%d",&item);
				printf("Enter element to insert : ");
				scanf("%d",&data);
				last = addbefore(last,data,item);
				break;
			case 6:
				printf("Enter elemen to delete : ");
				scanf("%d",&data);
				last = delete(last,data);
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

struct node *create_list(struct node *last)
{
	struct node *newNode,*ptr;
	int data,createNode,i;

	printf("Enter number of nodes to create : ");
	scanf("%d",&createNode);
	
	if(createNode <= 0)
	{
		printf("%d nodes to create.\n",createNode);
		return last;
	}
	for(i=1;i<=createNode;i++)
	{
		printf("Enter element to insert : ");
		scanf("%d",&data);
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = data;

		if(last == NULL)
		{
			last = newNode;
			newNode->next = last;
		}
		else
		{
			newNode->next = last->next;
			last->next = newNode;
			last = newNode;
		}
	}
	return last;
}

void display(struct node *last)
{
	struct node *ptr;

	if(last == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	ptr = last->next;
	do
	{
		printf("->| %d |",ptr->info);
		ptr = ptr->next;
	}while(ptr != last->next);
}

struct node *addatbeg(struct node *last,int data)
{
	struct node *newNode;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	newNode->next = last->next;
	last->next = newNode;

	return last;
}

struct node *addatend(struct node *last,int data)
{
	struct node *newNode;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	newNode->next = last->next;
	last->next = newNode;
	last = newNode;

	return last;
}

struct node *addbefore(struct node *last,int data,int item)
{
	struct node *newNode,*ptr;

	ptr = last;
	do
	{
		if(ptr->next->info == item)
		{
			newNode = (struct node *)malloc(sizeof(struct node));
			newNode->info = data;

			newNode->next = ptr->next;
			ptr->next = newNode;
			return last;
		}
		ptr = ptr->next;
	}while(ptr != last);
	printf("%d element not present in list.\n",item);
	return last;
}

struct node *delete(struct node *last,int data)
{
	struct node *deleteNode,*ptr;

	ptr = last;
	do
	{
		if(ptr->next->info == data)
		{
			deleteNode = ptr->next;
			ptr->next = deleteNode->next;

			if(ptr->next == last)
			{
				last = ptr;
			}
			return last;
		}
		ptr = ptr->next;
	}while(ptr != last);
	printf("%d element not present in list.\n",data);
	return last;
}

