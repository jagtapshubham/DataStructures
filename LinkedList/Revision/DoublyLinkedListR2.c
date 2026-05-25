#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *prev,*next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int item);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addbefore(struct node *start,int data,int item);
struct node *addafter(struct node *start,int data,int item);
struct node *addatposition(struct node *start,int data,int position);
struct node *delete(struct node *start,int item);
struct node *reverse(struct node *start);

int main()
{
	struct node *start = NULL;
	int data,item,position,choice;

	while(1)
	{
		printf("\n");
		printf("1.Create List.\n");
		printf("2.Display.\n");
		printf("3.Count.\n");
		printf("4.Search.\n");
		printf("5.Add at beginning.\n");
		printf("6.Add at end.\n");
		printf("7.Add before.\n");
		printf("8.Add after.\n");
		printf("9.Add at position.\n");
		printf("10.Delete node.\n");
		printf("11.Reverse.\n");
		printf("12.Exit.\n");
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
				count(start);
				break;
			case 4:
				printf("Enter element to be searched : ");
				scanf("%d",&item);
				search(start,item);
				break;
			case 5:
				printf("Enter element to insert : ");
				scanf("%d",&data);
				start = addatbeg(start,data);
				break;
			case 6:
				printf("Enter element to insert : ");
				scanf("%d",&data);
				start = addatend(start,data);
				break;
			case 7:
				printf("Enter item before which to insert : ");
				scanf("%d",&item);
				printf("Enter element to insert : ");
				scanf("%d",&data);
				start = addbefore(start,data,item);
				break;
			case 8:
				printf("Enter item before which to insert : ");
				scanf("%d",&item);
				printf("Enter element to insert : ");
				scanf("%d",&data);
				start = addafter(start,data,item);
				break;
			case 9:
				printf("Enter position at which to insert : ");
				scanf("%d",&position);
				printf("Enter element to insert : ");
				scanf("%d",&data);
				start = addatposition(start,data,position);
				break;
			case 10:
				printf("Enter element to delete : ");
				scanf("%d",&item);
				start = delete(start,item);
				break;
			case 11:
				start = reverse(start);
				break;
			case 12:
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
	struct node *newNode;
	int data,i,createNode;

	printf("Enter number of nodes to create : ");
	scanf("%d",&createNode);

	if(createNode == 0)
	{
		printf("%d nodes to create.\n",createNode);
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
			newNode->prev = NULL;
			start = newNode;
		}
		else
		{
			ptr=start;
			while(ptr->next != NULL)
			{
				ptr=ptr->next;
			}
			newNode->next = ptr->next;
			newNode->prev = ptr;
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

	ptr=start;
	printf("Start");
	while(ptr!=NULL)
	{
		printf("<=>| %d |",ptr->info);
		ptr=ptr->next;
	}
}

void count(struct node *start)
{
	struct node *ptr;
	int nodeCount=0;

	ptr=start;
	while(ptr!=NULL)
	{
		nodeCount++;
		ptr=ptr->next;
	}
	printf("%d nodes are present in list.\n",nodeCount);
}

void search(struct node *start,int item)
{
	struct node *ptr;
	int postion = 0;

	ptr=start;
	while(ptr!=NULL)
	{
		position++;
		if(ptr->info == item)
		{
			printf("%d element found at %d position in list.\n",item,position);
			return;
		}
		ptr=ptr->next
	}
	printf("%d element not present in list.\n",item);
}

struct node *addatbeg(struct node *start,int data)
{
	struct node *newNode;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	newNode->next = start;
	newNode->prev = NULL;
	start = newNode;

	if(newNode->next != NULL)
	{
		newNode->next->prev = newNode;
	}
	return start;
}

struct node *addatend(struct node *start,int data)
{
	struct node *newNode,*ptr;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	ptr=start;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	newNode->next = NULL;
	newNode->prev = ptr;
	ptr->next = newNode;
	return start;
}

