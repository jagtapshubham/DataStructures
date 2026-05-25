#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *bubble_sort(struct node *start);

int main()
{
	struct node *start = NULL;
	int choice;

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
				start = bubble_sort(start);
				break;
			default:
				printf("Wrong choice.\n");
		}
	}
	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *newNode,*ptr;
	int createNode,data,i;

	printf("Enter number of nodes to create : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
	{
		printf("Enter valid number of nodes to create.\n");
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

struct node *bubble_sort(struct node *start)
{
	struct node *ptr,*end,*q;
	int temp;

	for(end = NULL; end != start->next;end = q)
	{
		for(ptr = start;ptr->next != end;ptr = ptr->next)
		{
			q = ptr->next;
			if(ptr->info > q->info)
			{
				temp = ptr->info;
				ptr->info = q->info;
				q->info = temp;
			}
		}
	}
	return start;
}



