#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *last);
void display(struct node *last);
struct node *addtoempty(struct node *last,int data);
struct node *addatbeg(struct node *last,int data);
struct node *addatend(struct node *last,int data);
struct node *addafter(struct node *last,int data,int item);
struct node *delete(struct node *last,int data);

int main()
{
	struct node *last=NULL;
	int choice,data,item;

	while(1)
	{
		printf("\n");
		printf("1.Create List.\n");
		printf("2.Display.\n");
		printf("3.Add to empty.\n");
		printf("4.Add to beginning.\n");
		printf("5.Add to end.\n");
		printf("6.Add after.\n");
		printf("7.Delete.\n");
		printf("8.Exit.\n");
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
				last = addtoempty(last,data);
				break;
			case 4:
				printf("Enter element to insert : ");
				scanf("%d",&data);
				last = addatbeg(last,data);
				break;
			case 5:
				printf("Enter element to insert : ");
				scanf("%d",&data);
				last = addatend(last,data);
				break;
			case 6:
				printf("Enter item after which to insert : ");
				scanf("%d",&item);
				printf("Enter element to insert : ");
				scanf("%d",&data);
				last = addafter(last,data,item);
				break;
			case 7:
				printf("Enter element to delete : ");
				scanf("%d",&data);
				last = delete(last,data);
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

struct node *create_list(struct node *last)
{
	struct node *newNode,*ptr;
	int data,createNode=0,i;

	printf("Enter number of node to insert : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
	{
		printf("%d number of nodes to insert.\n",createNode);
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
		printf("| %d |->",ptr->info);
		ptr = ptr->next;
	}while(ptr != last->next);
	printf("\n");
}

struct node *addtoempty(struct node *last,int data)
{
	struct node *newNode,*ptr;
	
	if(last!=NULL)
	{
		printf("List is not empty.\n");
		return last;
	}
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	last = newNode;
	newNode->next = last;
	return last;
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

struct node *addafter(struct node *last,int data,int item)
{
	struct node *newNode,*ptr;

	ptr = last->next;
	do
	{
		if(ptr->info == item)
		{
			newNode = (struct node *)malloc(sizeof(struct node));
			newNode->info = data;

			newNode->next = ptr->next;
			ptr->next = newNode;

			if(ptr == last)
			{
				last = newNode;
			}
			return last;
		}
		ptr = ptr->next;
	}while(ptr!=last->next);
	printf("%d element not present in list.\n",item);
	return last;
}

struct node *delete(struct node *last,int data)
{
	struct node *deleteNode,*ptr;
	
	ptr = last->next;
	do
	{
	 if(ptr->info == data)
	 {
		deleteNode = ptr;
		
		if(ptr->next == last)
		{
			last = NULL;
		}
		else
		{
			last->next = ptr->next; 
		}
		free(deleteNode);
		return last;
	 }
	 else
	 {
		if(ptr->next->info == data)
		{
			deleteNode = ptr->next;
			ptr->next = deleteNode->next;

			if(deleteNode == last)
			{
				last = ptr;
			}
			free(deleteNode);
			return last;
		}
	 }
	 ptr = ptr->next;
	}while(ptr != last->next);
}

