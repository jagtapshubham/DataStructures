#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *last);
void display(struct node *last);
struct node *concat(struct node *p1,struct node *p2);

int main()
{
	struct node *last1 = NULL,*last2 = NULL,*last = NULL;

	printf("Enter List 1 :\n");
	last1 = create_list(last1);
	printf("List 1 :\n");
	display(last1);
	printf("Enter List 2 :\n");
	last2 = create_list(last2);
	printf("List 2 :\n");
	display(last2);
	last = concat(last1,last2);
	printf("List after concatenation :\n");
	display(last);

	return 0;
}

struct node *create_list(struct node *last)
{
	struct node *newNode,*ptr;
	int data,i,createNode;

	printf("Enter number of nodes to create : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
	{
		printf("Enter valid node.\n");
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
	else
	{
		ptr = last->next;
		do
		{
			printf("->| %d |",ptr->info);
			ptr = ptr->next;
		}while(ptr != last->next);
	}
	printf("\n\n");
}

struct node *concat(struct node *p1,struct node *p2)
{
	struct node *temp;

	if(p1 == NULL)
	{
		return p2;
	}
	else if(p2 == NULL)
	{
		return p1;
	}
	else
	{
		temp = p1->next;
		p1->next = p2->next;
		p2->next = temp;
	}
	return p2;
}

