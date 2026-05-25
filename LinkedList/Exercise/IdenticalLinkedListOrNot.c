#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *head);
void display(struct node *head);
void check_for_identical_list(struct node *head1,struct node *head2);

int main()
{
	struct node *head1=NULL,*head2=NULL;

	head1 = (struct node *)malloc(sizeof(struct node));
	head1->info = 0;
	head1->next = NULL;

	printf("Enter List 1 elements:\n");
	head1 = create_list(head1);

	head2 = (struct node *)malloc(sizeof(struct node));
	head2->info = 0;
	head2->next = NULL;

	printf("\nEnter List 2 elements:\n");
	head2 = create_list(head2);

	printf("\nList 1:\n");
	display(head1);
	printf("\nList 2:\n");
	display(head2);

	check_for_identical_list(head1,head2);
}

struct node *create_list(struct node *head)
{
	struct node *newNode,*ptr;
	int data,createNode,i;

	printf("Enter number of elements to create : ");
	scanf("%d",&createNode);

	if(createNode <= 0)
	{
		printf("Enter valid numbe of nodes to create.\n");
		return head;
	}

	for(i=1;i<=createNode;i++)
	{
		printf("Enter element to insert : ");
		scanf("%d",&data);

		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = data;
		head->info = head->info + 1;

		if(head->next == NULL || data < head->next->info)
		{
			newNode->next = head->next;
			head->next = newNode;
		}
		else
		{
			ptr = head;
			while(ptr->next != NULL && data > ptr->next->info)
			{
				ptr = ptr->next;
			}
			newNode->next = ptr->next;
			ptr->next = newNode;
		}
	}
	return head;
}

void display(struct node *head)
{
	struct node *ptr;

	if(head->next == NULL)
	{
		printf("List is empty.\n");
	}
	printf("List had %d nodes.\n",head->info);
	printf("\n");
	ptr = head->next;
	printf("Head");
	while(ptr != NULL)
	{
		printf("->| %d |",ptr->info);
		ptr = ptr->next;
	}
	printf("\n");
}

void check_for_identical_list(struct node *head1,struct node *head2)
{
	struct node *ptr1,*ptr2;
	if(head1->info != head2->info)
	{
		printf("\nElements count in both list are not same.\n");
		return;
	}
	ptr1 = head1->next;
	ptr2 = head2->next;

	while(ptr1 != NULL || ptr2 != NULL)
	{
		if(ptr1->info == ptr2->info)
		{
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		else
		{
			printf("\nList 1 and List 2 are not identical.\n");
			return;
		}
	}
	printf("\nList 1 and List 2 are identical.\n");
}

