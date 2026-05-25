#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void search(struct node *start,int data);
void count(struct node *start);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addbefore(struct node *start,int data,int item);
struct node *addafter(struct node *start,int data,int item);
struct node *addatpos(struct node *start,int data,int pos);
struct node *delete(struct node *start,int data);
struct node *reverse(struct node *start);

int main()
{
	struct node *start=NULL;
	int data,item,position,choice;

	while(1)
	{
		printf("\n");
		printf("1.Create List.\n");
		printf("2.Display.\n");
		printf("3.Search.\n");
		printf("4.Count.\n");
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
				printf("Enter element to search : ");
				scanf("%d",&data);
				search(start,data);
				break;
			case 4:
				count(start);
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
				printf("Enter element to insert : ");
				scanf("%d",&data);
				printf("Enter item before which to insert : ");
				scanf("%d",&item);
				start = addbefore(start,data,item);
				break;
			case 8:
				printf("Enter element to insert : ");
				scanf("%d",&data);
				printf("Enter item after which to insert : ");
				scanf("%d",&item);
				start = addafter(start,data,item);
				break;
			case 9:
				printf("Enter element to insert : ");
				scanf("%d",&data);
				printf("Enter position at which to enter : ");
				scanf("%d",&position);
				start = addatpos(start,data,position);
				break;
			case 10:
				printf("Enter element to be deleted : ");
				scanf("%d",&data);
				start = delete(start,data);
				break;
			case 11:
				start = reverse(start);
				break;
			case 12:
				exit(1);
			default:
				printf("Wrong choice entered.\n");
				break;
		}
	}
	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *newNode,*ptr;
	int data,nodes,i;

	printf("Enter number of nodes to insert : ");
	scanf("%d",&nodes);

	if(nodes == 0)
	{
		printf("%d nodes to enter.\n",nodes);
		return start;
	}
	
	printf("Enter the element to insert : ");
	scanf("%d",&data);

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	if(start == NULL)
	{
		newNode->link = start;
		start = newNode;
	}

	ptr = start;
	for(i=2;i<=nodes;i++)
	{
		printf("Enter the element to insert : ");
		scanf("%d",&data);

		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = data;

		newNode->link = ptr->link;
		ptr->link = newNode;

		ptr = ptr->link;
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

	printf("Element in the list are :\n");
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		ptr=ptr->link;
	}
	printf("\n");
}

void search(struct node *start,int data)
{
	struct node *ptr;

	ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->info == data)
		{
			printf("%d element found in list.\n",data);
			return;
		}
		ptr=ptr->link;
	}
	printf("%d element not found in list.\n",data);
}

void count(struct node *start)
{
	struct node *ptr;
	int count = 0;

	ptr=start;
	while(ptr!=NULL)
	{
		ptr = ptr->link;
		count++;
	}
	printf("Number of nodes count in list are %d\n",count);
}

struct node *addatbeg(struct node *start,int data)
{
	struct node *newNode,*ptr;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	newNode->link = start;
	start = newNode;
	return start;
}

struct node *addatend(struct node *start,int data)
{
	struct node *newNode,*ptr;

	if(start == NULL)
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = data;

		newNode->link = start;
		start = newNode;
		return start;
	}
	ptr = start;
	while(ptr->link != NULL)
	{
		ptr=ptr->link;
	}
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	newNode->link = ptr->link;
	ptr->link = newNode;
	return start;
}

struct node *addatpos(struct node *start,int data,int pos)
{
	struct node *newNode,*ptr;
	int i;

	if(pos == 1)
	{
		newNode = (struct node*)malloc(sizeof(struct node));
		newNode->info = data;

		newNode->link = start;
		start = newNode;
		return start;
	}
	
	ptr=start;
	for(i=1;i<pos-1 && ptr!=NULL;i++)
	{
		ptr=ptr->link;
	}
	if(ptr==NULL)
	{
		printf("There are less than %d elementss\n",pos);
	}
	else
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = data;

		newNode->link = ptr->link;
		ptr->link = newNode;
	}
	return start;
}

struct node *addbefore(struct node *start,int data,int item)
{
	struct node *newNode,*ptr;

	if(start->info == item)
	{
		newNode = (struct node*)malloc(sizeof(struct node));
		newNode->info = data;

		newNode->link = start;
		start = newNode;
		return start;
	}
	ptr=start;
	while(ptr->link!=NULL)
	{
		if(ptr->link->info == item)
		{
			newNode = (struct node*)malloc(sizeof(struct node));
			newNode->info = data;

			newNode->link = ptr->link;
			ptr->link = newNode;
			return start;
		}
		ptr = ptr->link;
	}
	printf("%d element does not exist in list.\n",item);
	return start;
}

struct node *addafter(struct node *start,int data,int item)
{
	struct node *newNode,*ptr;

	ptr=start;
	while(ptr!=NULL)
	{	
		if(ptr->info == item)
		{
			newNode = (struct node*)malloc(sizeof(struct node));
			newNode->info = data;

			newNode->link = ptr->link;
			ptr->link = newNode;
			return start;
		}
		ptr=ptr->link;
	}
	printf("%d element not found in list.\n",item);
	return start;
}

struct node *delete(struct node *start,int data)
{
	struct node *newNode, *ptr;

	if(start->info == data)
	{
		newNode = (struct node*)malloc(sizeof(struct node));

		newNode = start;
		start = newNode->link;
		free(newNode);
		return start;
	}

	ptr = start;
	while(ptr != NULL)
	{
		if(ptr->link->info == data)
		{
			newNode = (struct node*)malloc(sizeof(struct node));

			newNode = ptr->link;
			ptr->link = newNode->link;
			free(newNode);
			return start;
		}
		ptr=ptr->link;
	}
	printf("%d element does not present in list.\n",data);
	return start;
}

struct node *reverse(struct node *start)
{
	
	return start;
}

