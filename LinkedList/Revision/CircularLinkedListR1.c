#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *last);
void display(struct node *last);
void count(struct node *last);
void search(struct node *last,int item);
struct node *addtoempty(struct node *last,int data);
struct node *addatbeg(struct node *last,int data);
struct node *addatend(struct node *last,int data);
struct node *addafter(struct node *last,int data,int item);
struct node *delete(struct node *last,int item);

int main()
{
	struct node *last=NULL;
	int data,item,choice;

	while(1)
	{
		printf("\n");
		printf("1.Create List.\n");
		printf("2.Display.\n");
		printf("3.Count.\n");
		printf("4.Search.\n");
		printf("5.Add to empty list.\n");
		printf("6.Add at beginning.\n");
		printf("7.Add at end.\n");
		printf("8.Add after.\n");
		printf("9.Delete node.\n");
		printf("10.Exit.\n");
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
				count(last);
				break;
			case 4:
				printf("Enter item to search : ");
				scanf("%d",&item);
				search(last,item);
				break;
			case 5:
				printf("Enter element to insert : ");
				scanf("%d",&data);
				last = addtoempty(last,data);
				break;
			case 6:
				printf("Enter element to insert : ");
				scanf("%d",&data);
				last = addatbeg(last,data);
				break;
			case 7:
				printf("Enter element to insert : ");
				scanf("%d",&data);
				last = addatend(last,data);
				break;
			case 8:
				printf("Enter item after which to insert : ");
				scanf("%d",&item);
				printf("Enter element to insert : ");
				scanf("%d",&data);
				last = addafter(last,data,item);
				break;
			case 9:
				printf("Enter item to delete : ");
				scanf("%d",&item);
				last = delete(last,item);
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

struct node *create_list(struct node *last)
{
	struct node *newNode,*ptr;
	int data,i,nodeNum=0;

	printf("Enter number of nodes to insert : ");
	scanf("%d",&nodeNum);

	if(nodeNum <= 0)
	{
		printf("%d number of nodes to insert.\n",nodeNum);
		return last;
	}
	for(i=1;i<=nodeNum;i++)
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

	ptr=last->next;
	do
	{
		printf("| %d |->",ptr->info);
		ptr=ptr->next;
	}while(ptr!=last->next);
}

void count(struct node *last)
{
	struct node *ptr;
	int nodeCount=0;

	if(last == NULL)
	{
		printf("%d nodes present in list.\n",nodeCount);
		return;
	}
	ptr=last->next;
	do
	{
		nodeCount++;
		ptr=ptr->next;
	}while(ptr!=last->next);
	printf("%d nodes are present in list.\n",nodeCount);
}

void search(struct node *last,int item)
{
	struct node *ptr;

	ptr=last->next;
	do
	{
		if(ptr->info == item)
		{
			printf("%d element found in list.\n",item);
			return;
		}
		ptr=ptr->next;
	}while(ptr!=last->next);

	printf("%d element not present in list.\n",item);
}

struct node *addtoempty(struct node *last,int data)
{
	struct node *newNode;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	if(last == NULL)
	{
		last = newNode;
		newNode->next = last;
		return last;
	}
	else
	{
		newNode->next = last->next;
		last->next = newNode;
		last = newNode;
	}
	return last;
}

struct node *addatbeg(struct node *last,int data)
{
	struct node *newNode;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	if(last == NULL)
	{
		last = newNode;
		newNode->next = last;
		return last;
	}
	else
	{
		newNode->next = last->next;
		last->next = newNode;
	}
	return last;
}

struct node *addatend(struct node *last,int data)
{
	struct node *newNode;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = data;

	if(last == NULL)
	{
		last = newNode;
		newNode->next = last;
		return last;
	}
	else
	{
		newNode->next = last->next;
		last->next = newNode;
		last = newNode;
	}
	return last;
}

struct node *addafter(struct node *last,int data,int item)
{
	struct node *newNode,*ptr;

	ptr=last->next;
	do
	{
		if(ptr->info == item)
		{
			newNode = (struct node *)malloc(sizeof(struct node));
			newNode->info = data;

			if(ptr == last)
			{
				last = newNode;
			}
			newNode->next = ptr->next;
			ptr->next = newNode;
			return last;
		}
		ptr=ptr->next;
	}while(ptr!=last->next);

	printf("%d element not present in list.\n",item);
	return last;
}

struct node *delete(struct node *last,int item)
{
	struct node *deleteNode,*ptr;
	
	if(last == NULL)
	{
		printf("List is empty.\n");
		return last;	
	}
	/* Deletion of only node */
	if(last->next == last && last->info == item)
	{
		deleteNode = last;
		last = NULL;
		free(deleteNode);
		return last;
	}
	/* Deletion of first node */
	if(last->next->info == item)
	{
		deleteNode = last->next;
		last->next = deleteNode->next;
		free(deleteNode);
		return last;
	}
	ptr=last->next;
	while(ptr->next!=last)
	{
		if(ptr->next->info == item)
		{
			deleteNode = ptr->next;
			ptr->next = deleteNode->next;
			free(deleteNode);
			return last;
		}
		ptr = ptr->next;
	}
	if(last->info == item)
	{
		deleteNode = last;
		ptr->next = last->next;
		last = ptr;
		free(deleteNode);
		return last;
	}
	printf("%d element not present in list.\n",item);
	return last;
}

