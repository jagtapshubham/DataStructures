#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void selection_sort(struct node *start);

int main()
{
	struct node *start = NULL;
	int choice;
	start = create_list(start);

	while(1)
	{
		printf("\n");
		printf("1.Create_List.\n");
		printf("2.Display.\n");
		printf("3.Selection Sort.\n");
		printf("4.Exit.\n");
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
				selection_sort(start);
				break;
			case 4:
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
	int data,i,createNode;

	printf("Enter number of nodes to create : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
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
	while(ptr != NULL)
	{
		printf("->| %d |",ptr->info);
		ptr = ptr->next;
	}
}

void selection_sort(struct node *start)
{
	struct node *ptr1,*ptr2;
	int temp;

	if(start == NULL)
	{
		printf("List is empty.\n");
		return;
	}

	for(ptr1 = start;ptr1->next != NULL;ptr1 = ptr1->next)
	{
		for(ptr2 = ptr1;ptr2 != NULL;ptr2 = ptr2->next)
		{
			if(ptr1->info > ptr2->info)
			{
				temp = ptr1->info;
				ptr1->info = ptr2->info;
				ptr2->info = temp;
			}
		}
	}
}

