#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *selection_sort(struct node *start);

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
				start = selection_sort(start);
				break;
			case 4:
				exit(1);
			default:
				printf("Wrong choice.\n");
		}
	}
	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *newNode,*ptr;
	int createNode,i,data;

	printf("Enter number of nodes to insert : ");
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
	while(ptr!=NULL)
	{
		printf("->| %d |",ptr->info);
		ptr = ptr->next;
	}
}

struct node *selection_sort(struct node *start)
{
	struct node *pp,*p,*qq,*q,*temp;

	for(pp=p=start; p->next!=NULL; pp=p,p=p->next)
	{
		for(qq=q=p->next; q!=NULL; qq=q,q=q->next)
		{
			if(p->info > q->info)
			{
				// for adjacent node
				if(p->next == q)
				{
					p->next = q->next;
					q->next = p;
				}
				// for non-adjacent node
				else
				{
					temp = p->next;
					p->next = q->next;
					q->next = temp;
					qq->next = p;
				}
				// Here below if sequence is important
				if(p != start)
				{
					pp->next = q;
				}
				if(p == start)
				{
					start = q;
					pp = q;
				}
				temp = p;
				p = q;
				q = temp;
			}
		}
	}
	return start;
}

