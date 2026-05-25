#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addbefore(struct node *start,int data,int item);
struct node *addafter(struct node *start,int data,int item);
struct node *addatposition(struct node *start,int data,int position);
struct node *delete(struct node *start,int data);
struct node *reverse(struct node *start);

int main()
{
	struct node *start=NULL;
	int data,item,choice,position;

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
		printf("10.Delete.\n");
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
				printf("Enter element to search : ");
				scanf("%d",&data);
				search(start,data);
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
				printf("Enter item after which to insert : ");
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
				scanf("%d",&data);
				start = delete(start,data);
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
	struct node *newNode,*ptr;
	int createNode,i,data;

	printf("Enter number of nodes to create : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
	{
		printf("%d nodes to insert.\n",createNode);
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
			ptr=start;
			while(ptr->next!=NULL)
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

	ptr=start;
	printf("Start");
	while(ptr!=NULL)
	{
		printf("->| %d |",ptr->info);
		ptr = ptr->next;
	}
}

void count(struct node *start)
{
	struct node *ptr;
	int nodeCount=0;

	ptr = start;
	while(ptr!=NULL)
	{
		nodeCount++;
		ptr = ptr->next;
	}
	printf("%d nodes are present in list.\n",nodeCount);
}

void search(struct node *start,int data)
{
	struct node *ptr;
	int position=0;
	ptr = start;
	while(ptr!=NULL)
	{
		position++;
		if(ptr->info == data)
		{
			printf("%d element found at %d position in list.\n",data,position);
			return;
		}
		ptr = ptr->next;
	}
	printf("%d element not present in list.\n",data);
}

struct node *addatbeg(struct node *start,int data)
{
	struct node *newNode;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	newNode->next = start;
	start = newNode;

	return start;
}

struct node *addatend(struct node *start,int data)
{
	struct node *newNode,*ptr;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	ptr = start;
	while(ptr->next!=NULL)
	{
		ptr = ptr->next;
	}
	newNode->next = ptr->next;
	ptr->next = newNode;

	return start;
}

struct node *addbefore(struct node *start,int data,int item)
{
	struct node *newNode,*ptr;
	
	if(start->info == item)
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = data;

		newNode->next = start;
		start = newNode;
		return start;
	}

	ptr = start;
	while(ptr->next != NULL)
	{
		if(ptr->next->info == item)
		{
			newNode = (struct node *)malloc(sizeof(struct node));
			newNode->info = data;

			newNode->next = ptr->next;
			ptr->next = newNode;
			return start;
		}
		ptr = ptr->next;
	}
	printf("%d element not present in list.\n",item);
	return start;
}

struct node *addafter(struct node *start,int data,int item)
{
	struct node *newNode,*ptr;

	ptr = start;
	while(ptr!=NULL)
	{
		if(ptr->info == item)
		{
			newNode = (struct node *)malloc(sizeof(struct node));
			newNode->info = data;

			newNode->next = ptr->next;
			ptr->next = newNode;
			return start;
		}
		ptr = ptr->next;
	}
	printf("%d element not present in list.\n",item);
	return start;
}

struct node *addatposition(struct node *start,int data,int position)
{
	struct node *newNode,*ptr;
	int i;

	if(position == 1)
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = data;

		newNode->next = start;
		start = newNode;
		return start;
	}
	else
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = data;
		ptr = start;
		for(i=1;i<position-1 && ptr!=NULL;i++)
		{
			ptr = ptr->next;
		}
		if(ptr == NULL)
		{
			printf("%d position not present in list.\n",position);
			return start;
		}
		newNode->next = ptr->next;
		ptr->next = newNode;
		return start;
	}
}

struct node *delete(struct node *start,int data)
{
	struct node *deleteNode,*ptr;

	if(start->info == data)
	{
		deleteNode = start;
		start = start->next;
		free(deleteNode);
		return start;
	}

	ptr = start;
	while(ptr->next != NULL)
	{
		if(ptr->next->info == data)
		{
			deleteNode = ptr->next;
			ptr->next = deleteNode->next;
			free(deleteNode);
			return start;
		}
		ptr = ptr->next;
	}
	printf("%d element not present in list.\n",data);
	return start;
}

struct node *reverse(struct node *start)
{
	struct node *prev,*ptr,*next;

	prev = NULL;
	ptr = start;

	while(ptr!=NULL)
	{
		next = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = next;
	}
	start = prev;
	return start;
}

