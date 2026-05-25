#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);

int main()
{
	struct node *start = NULL;

	start = create_list(start);
	display(start);	
	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *newNode,*ptr;
	int i,data,createNode;

	printf("Enter number of elements to create : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
	{
		printf("Enter valid number of nodes to create.\n");
		return start;
	}
	else
	{
		for(i=1;i<=createNode;i++)
		{
			printf("Enter element to insert : ");
			scanf("%d",&data);
			newNode = (struct node *)malloc(sizeof(struct node));
			newNode->info = data;
			if(start == NULL || data < start->info)
			{
				newNode->next = start;
				start = newNode;
			}
			else
			{
				ptr = start;
				while(ptr->next != NULL && data > ptr->next->info)
				{
					ptr = ptr->next;
				}
				newNode->next = ptr->next;
				ptr->next = newNode;
			}
		}
	}
	return start;
}

void display(struct node *start)
{
	struct node *ptr;
	int min,max;
	if(start == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	printf("\n");
	ptr = start;
	printf("Start");
	while(ptr != NULL)
	{
		printf("->| %d |",ptr->info);
		if(ptr->next == NULL)
		{
			min = start->info;
			max = ptr->info;
		}
		ptr = ptr->next;
	}
	printf("\n");
	printf("Smallest number in the list is %d.\n",min);
	printf("Largest number in the list is %d.\n",max);
}

