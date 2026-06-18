#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void remove_duplicates(struct node *start);
struct node *intersection_list(struct node *start1,struct node *start2,struct node *start3);

int main()
{
	struct node *start1 = NULL, *start2 = NULL,*start3 = NULL;
	
	printf("Enter List 1 elements:\n");
	start1 = create_list(start1);
	printf("Enter List 2 elements:\n");
	start2 = create_list(start2);
	printf("List 1.\n");
	display(start1);
	printf("List 2.\n");
	display(start2);
	
	start3 = intersection_list(start1,start2,start3);
	printf("Intersection List:\n");
	display(start3);

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
		printf("Enter valid number of nodes to creat.\n");
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
	printf("\n\n");
}

struct node *intersection_list(struct node *start1,struct node *start2,struct node *start3)
{
	struct node *newNode,*ptr1,*ptr2,*ptr3;
	int flag=0;

	for(ptr1 = start1;ptr1!=NULL;flag=0,ptr1=ptr1->next)
	{
		for(ptr3=start3;ptr3!=NULL;ptr3=ptr3->next)
		{
			if(ptr1->info == ptr3->info)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			for(ptr2=start2;ptr2!=NULL;ptr2=ptr2->next)
			{
				if(ptr1->info == ptr2->info)
				{
					if(start3 == NULL)
					{
						newNode = (struct node *)malloc(sizeof(struct node));
						newNode->info = ptr1->info;

						newNode->next = start3;
						start3 = newNode;
						break;
					}
					else
					{
						ptr3 = start3;
						while(ptr3->next != NULL)
						{
							ptr3 = ptr3->next;
						}
						newNode = (struct node *)malloc(sizeof(struct node));
						newNode->info = ptr1->info;
						newNode->next = ptr3->next;
						ptr3->next = newNode;
						break;
					}
				}
			}
		}
	}
	return start3;
}

