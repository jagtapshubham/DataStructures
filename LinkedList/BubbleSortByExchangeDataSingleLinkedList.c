#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void bubble_sort(struct node *start);

int main()
{
	struct node *start = NULL;
	int choice;

	start = create_list(start);
	while(1)
	{
		printf("\n");
		printf("1.Create List.\n");
		printf("2.Display.\n");
		printf("3.Bubble Sort.\n");
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
				bubble_sort(start);
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

	printf("Enter number of nodes to insert : ");
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

void bubble_sort(struct node *start)
{
	struct node *ptr1,*ptr2,*end;
	int temp;

	for(end = NULL;end != start->next; end=ptr2)
	{
		for(ptr1=start; ptr1->next!=end; ptr1=ptr1->next)
		{
			ptr2 = ptr1->next;
			if(ptr1->info > ptr2->info)
			{
				temp = ptr1->info;
				ptr1->info = ptr2->info;
				ptr2->info = temp;
			}
		}
	}
}

