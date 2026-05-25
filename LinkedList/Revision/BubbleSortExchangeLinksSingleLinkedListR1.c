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
	while(ptr!=NULL)
	{
		printf("->| %d |",ptr->info);
		ptr = ptr->next;
	}
}

struct node *bubble_sort(struct node *start)
{
	struct node *p,*pp,*q,*end,*temp;

	for(end = NULL; end != start->next; end = q)
	{
		for(pp=p=start;p->next != end;pp=p,p = p->next)
		{
			q = p->next;
			if(p->info > q->info)
			{
				p->next = q->next;
				q->next = p;

				if(p != start)
				{
					pp->next = q;
				}
				if(p == start)
				{
					pp = q;
					start = q;
				}
				temp = p;
				p = q;
				q = temp;
			}
		}
	}
	return start;
}

