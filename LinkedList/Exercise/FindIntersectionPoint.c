// Suppose there are two NULL-terminated singly linked lists which merge at a given point and share all the nodes after that merge point (Y-shaped list). Write a function to find that merge point (intersection point).

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *create_list(struct node *start,struct node **lastNode);
void display(struct node *start);
struct node *find_merge_point(struct node *start1,struct node *start2);

int main()
{
	struct node *start1 = NULL,*start2 = NULL,*start3 = NULL,*mergePoint = NULL,*list1LastNode = NULL,*list2LastNode = NULL,*list3LastNode = NULL;

	printf("Enter list 1 :\n");
	start1 = create_list(start1,&list1LastNode);
	printf("Enter list 2 :\n");
	start2 = create_list(start2,&list2LastNode);
	printf("Enter comman elements for list1 and list2 :\n");
	start3 = create_list(start3,&list3LastNode);
	if(start3 != NULL)
	{
		if(start1 == NULL)
		{
			start1 = start3;
		}
		else
		{
			list1LastNode->next = start3;
		}
		if(start2 == NULL)
		{
			start2 = start3;
		}
		else
		{
			list2LastNode->next = start3;
		}
	}
	mergePoint = find_merge_point(start1,start2);
	if(mergePoint != NULL)
	{
		printf("Merge Point of both list is %d\n",mergePoint->info);
	}
	else
	{
		printf("There is no merge point in lists.\n");
	}
	return 0;
}

struct node *create_list(struct node *start,struct node **lastNode)
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
		*lastNode = tail = newNode;
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

struct node *find_merge_point(struct node *start1,struct node *start2)
{
	struct node *ptr1 = NULL,*ptr2 = NULL,*mergePoint = NULL;
	int nStep = 0,length1 = 0,length2 = 0,flag = 0,i;

	if(start1 == NULL || start2 == NULL)
	{
		return mergePoint;
	}

	ptr1 = start1;
	while(ptr1 != NULL)
	{
		length1++;
		ptr1 = ptr1->next;
	}
	ptr2 = start2;
	while(ptr2 != NULL)
	{
		length2++;
		ptr2 = ptr2->next;
	}
	if(length1 > length2)
	{
		flag = 1;
		nStep = length1 - length2;
	}
	else if(length2 > length1)
	{
		flag = 2;
		nStep = length2 - length1;
	}	
	printf("nStep = %d\n",nStep);
	if(flag == 1)
	{
		ptr1 = start1;
		ptr2 = start2;
		for(i=0;i<nStep;i++)
		{
			ptr1 = ptr1->next;
		}
	}
	else if(flag == 2)
	{
		ptr1 = start1;
		ptr2 = start2;
		for(i=0;i<nStep;i++)
		{
			ptr2 = ptr2->next;
		}
	}
	else
	{
		ptr1 = start1;
		ptr2 = start2;
	}
	
	while(ptr1 != NULL && ptr2 != NULL)
	{
		printf("ptr1 = %d\n",ptr1->info);
		printf("ptr2 = %d\n",ptr2->info);
		if(ptr1 == ptr2)
		{
			mergePoint = ptr1;
			return mergePoint;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return mergePoint;
}

