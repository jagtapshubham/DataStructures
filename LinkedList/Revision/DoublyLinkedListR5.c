#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next,*prev;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addbefore(struct node *start,int data,int item);
struct node *addafter(struct node *start,int data,int item);
struct node *addatposition(struct node *start,int data,int position);
struct node *delete(struct node *start,int data);
struct node *reverse(struct node *start);

int main()
{
	struct node *start = NULL;
	int data,item,choice,position;

	while(1)
	{
		printf("\n");
		printf("1.Create List.\n");
		printf("2.Display.\n");
		printf("3.Add at beginning.\n");
		printf("4.Add at end.\n");
		printf("5.Add before node.\n");
		printf("6.Add after node.\n");
		printf("7.Add at position.\n");
		printf("8.Delete Node.\n");
		printf("9.Reverse.\n");
		printf("10.Exit.\n");
		printf("\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				start = create_list(start);
				break;
			case 2:
				display(start);
				break;
			case 3:
				printf("Enter element to insert : ");
				scanf("%d",&data);
				start = addatbeg(start,data);
				break;
			case 4:
				printf("Enter element to insert : ");
				scanf("%d",&data);
				start = addatend(start,data);
				break;
			case 5:
				printf("Enter item before which to insert : ");
				scanf("%d",&item);
				printf("Enter element to insert : ");
				scanf("%d",&data);
				start = addbefore(start,data,item);
				break;
			case 6:
				printf("Enter item after which to insert : ");
				scanf("%d",&item);
				printf("Enter element to insert : ");
				scanf("%d",&data);
				start = addafter(start,data,item);
				break;
			case 7:
				printf("Enter position at which to insert : ");
				scanf("%d",&position);
				printf("Enter element to insert : ");
				scanf("%d",&data);
				start = addatposition(start,data,position);
				break;
			case 8:
				printf("Enter element to delete : ");
				scanf("%d",&data);
				start = delete(start,data);
				break;
			case 9:
				start = reverse(start);
				break;
			case 10:
				exit(1);
			default:
				printf("Wrong choice.\n");
				break;
		}
	}
	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *newNode,*ptr;
	int data,createNode,i;

	printf("Enter number of nodes to create : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
	{
		printf("Enter valid number of nodes to create.\n");
		return start;
	}
	for(i=1;i<=createNode;i++)
	{
		printf("Enter element to create : ");
		scanf("%d",&data);

		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = data;

		if(start == NULL)
		{
			newNode->next = start;
			newNode->prev = NULL;
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
			mewNode->prev = ptr;
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
	while(ptr!=NULL)
	{
		printf("<->| %d |",ptr->info);
		ptr = ptr->next;
	}
}

struct node *addatbeg(struct node *start,int data)
{
	struct node *newNode;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	newNode->prev = NULL;
	newNode->next = start;
	start->prev = newNode;
	start = newNode;
	return start;
}

