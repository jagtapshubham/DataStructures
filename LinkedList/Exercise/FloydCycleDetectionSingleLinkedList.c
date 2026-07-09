#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void create_cycle(struct node *start,int position);
void detect_and_remove_cycle(struct node *start);

int main()
{
	struct node *start = NULL;
	int position = 0;
	char choice;

	printf("Enter List :\n");
	start = create_list(start);
	printf("List without cycle :\n");
	display(start);
	
	printf("Enter position from where to start cycle : ");
	scanf("%d",&position);
	// cycle creation function
	create_cycle(start,position);
	
	// detect and remove cycle formed in list
	detect_and_remove_cycle(start);

	display(start);
	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *newNode = NULL,*tail = NULL;
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
			newNode->next = tail->next;
			tail->next = newNode;
		}
		tail = newNode;
	}
	return start;
}

void display(struct node *start)
{
	struct node *ptr = NULL;
	
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

void create_cycle(struct node *start,int position)
{
	struct node *posNode = NULL,*ptr = NULL;
	int i,count=1;

	if(start == NULL)
	{
		printf("List is empty");
	}
	ptr = start;
	i = 1;
	while(ptr->next != NULL)
	{
		if(i == position)
		{
			posNode = ptr;
		}
		ptr = ptr->next;
		i++;
	}
	if(position <= 0 || posNode == NULL)
	{
		printf("Position exceeds the list.\n");
		return;
	}
	ptr->next = posNode;
	
	// Display list after cycle creation
	
	ptr = start;
	printf("Start");
	while(1)
	{
		printf("->| %d |",ptr->info);
		if(ptr == posNode)
		{
			count++;
			if(count == 4)
			{
				break;
			}
		}
		ptr = ptr->next;
	}
	printf("...");
	printf("\n\n");
}

void detect_and_remove_cycle(struct node *start)
{
	struct node *slow = NULL,*fast = NULL,*ptr1 = NULL,*ptr2 = NULL,*meetpoint = NULL,*pp = NULL;

	if(start == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	if(start->next == start)
	{
		printf("Cycle detected with one node.\n");
		start->next = NULL;
		return;
	}
	slow = fast = start;
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		// finding the meeting point of slow and fast inside the loop
		if(slow == fast)
		{
			ptr1 = start;
			ptr2 = slow;
			// getting cycle start point
			while(ptr1 != ptr2)
			{
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
			}
			printf("Cycle starts at %d\n",ptr1->info);
			while(ptr2->next != ptr1)
			{
				ptr2 = ptr2->next;
			}
			// break the cycle
			ptr2->next = NULL;
			return;
		}
	}
	printf("No cycle detected in list.\n");
}

