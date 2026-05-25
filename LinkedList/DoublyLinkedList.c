#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *addtoempty(struct node *start,int data);
struct node *addtobeg(struct node *start,int data);
struct node *addtoend(struct node *start,int data);
struct node *addbefore(struct node *start,int data,int item);
struct node *addafter(struct node *start,int data,int item);
struct node *delete(struct node *start,int item);
struct node *reverse(struct node *start);

int main()
{
	int choice,data,item;
	struct node *start=NULL;

	while(1)
	{
		print("\n");
		printf("1.Create List.\n");
		printf("2.Display.\n");
		printf("3.Add to empty list.\n");
		printf("4.Add at beginning.\n");
		printf("5.Add at end.\n");
		printf("6.Add before.\n");
		printf("7.Add after.\n");
		printf("8.Delete.\n");
		printf("9.Reverse.\n");
		printf("10.Exit.\n");

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
				printf("Enter the element to be inserted : ");
				scanf("%d",&data);
				start = addtoempty(start,data);
				break;
			case 4:
				printf("Enter the element to be inserted : ");
				scanf("%d",&data);
				start = addatbeg(start,data);
				break;
			case 5:
				printf("Enter the element to be inserted : ");
				scanf("%d",&data);
				start = addatend(start,data);
				break;
			case 6:
				printf("Enter the element to be inserted : ");
				scanf("%d",&data);
				printf("Enter the item before which to enter : ");
				scanf("%d",&item);
				start = addbefore(start,data,item);
				break;
			case 7:
				printf("Enter the element to be inserted : ");
				scanf("%d",&data);
				printf("Enter the item after which to enter : ");
				scanf("%d",&item);
				start = addafter(start,data,item);
				break;
			case 8:
				printf("Enter the element to be deleted : ");
				scanf("%d",&item);
				start = delete(start,item);
				break;
			case 9:
				start = reverse(start);
				break;
			case 10:
				exit(1);
			default:
				printf("Wrong choice.\n");
				break;
		}
	}
	return 0;
}

void display(struct node *start)
{
	struct node *p;

	if(start == NULL)
	{
		printf("List is empty.\n");
		return;
	}
	p=start;
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->next;
	}
	printf("\n");
}

struct node *addatbeg(struct node *start,int data)
{
	struct node *temp;

	// code
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;

	temp->prev = NULL;
	temp->next = start;
	start->prev = temp;
	start = temp;
	return start;
}

struct node *addtoempty(struct node *start,int data)
{
	struct node *temp;

	// code
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;

	temp->prev = NULL;
	temp->next = NULL;
	start = temp;
	return start;
}

struct node *addtoend(struct node *start,int data)
{
	struct node *temp,*p;

	// code
	p=start;

	while(p->next != NULL)
	{
		p = p->next;	
	}
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;

	temp->next = NULL;
	p->next = temp;
	temp->prev = p;
	return start;
}

struct node *addafter(struct node *start,int data,int item)
{
	struct node *newNode,*ptr;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->info = data;

	ptr=start
	while(ptr != NULL)
	{
		if(ptr->info == item)
		{
			newNode->prev = ptr;
			newNode->next = ptr->link;
			if(ptr->next != NULL)
			{
				ptr->next->prev = newNode;
			}
			ptr->next = newNode;
			return start;
		}
		ptr=ptr->next;
	}
	printf("%d not present in the list.\n",item);
	return start;
}

struct node *addbefore(struct node *start,int data,int item)
{
	struct node *newNode,*ptr;

	if(start == NULL)
	{
		printf("List is empty.\n");
		return start;
	}
	if(start->info == item)
	{
		newNode = (struct node*)malloc(sizeof(struct node));
		newNode->info = data;

		newNode->next = start;
		newNode->prev = NULL;
		start->prev = newNode;
		start = newNode;
		return start;
	}
	ptr = start;
	while(ptr!=NULL)
	{
		if(ptr->info == item)
		{
			newNode = (struct node*)malloc(sizeof(struct node));
			newNode->info = data;

			newNode->prev = ptr->prev;
			newNode->next = ptr;
			ptr->prev->next = newNode;
			ptr->prev = newNode;
			return start;
		}
		ptr=ptr->next;
	}
	printf("%d element not present in list.\n",item);
	return start;
}

struct node *create_list(struct node *start)
{
	int i,nodes,data;

	printf("Enter number of nodes to be inserted : ");
	scanf("%d",&nodes);

	start = NULL;
	if(nodes == 0)
	{
		printf("%d nodes to insert.\n",nodes);
		return start;
	}
	printf("Enter element to be inserted : ");
	scanf("%d",&data);
	start=addtoempty(start,data);
	for(i=2;i<=nodes;i++)
	{
		printf("Enter element to be inserted : ");
		scanf("%d",&data);
		start = addtoend(start,data);
	}
	return start;
}

struct node *delete(struct node *start,int item)
{
	struct node *deleteNode;

	if(start == NULL)
	{
		printf("List is empty.\n");
		return start;
	}
	/* Deletion of ONLY NODE  */
	if(start->next == NULL)
	{
		if(start->info == item)
		{
			deleteNode = start;
			start = NULL;
			free(deleteNode);
			return start;
		}
	}
	/* Deletion of FIRST NODE  */
	if(start->info == item)
	{
		deleteNode = start;
		start = start->next;
		start->prev = NULL;
		free(deleteNode);
		return start;
	}
	/* Deletion of in between nodes  */
	deleteNode = start->next;
	while(deleteNode->next!=NULL)
	{
		if(deleteNode->info == item)
		{
			deleteNode->prev->next = deleteNode->next;
			deleteNode->next->prev = deleteNode->prev;
			free(deleteNode);
			return start;
		}
		deleteNode = deleteNode->next;
	}
	/* Deletion of last node  */
	if(deleteNode->info == item)
	{
		deleteNode->prev->next = NULL;
		free(deleteNode);
		return start;
	}
	printf("%d element not present in list.\n",item);
	return start;
}

struct node *reverse(struct node *start)
{
	struct node *p1,*p2;
	p1=start;
	p2=p1->next;
	p1->next = NULL;
	p1->prev = p2;
	while(p2!=NULL)
	{
		p2->prev = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p2->prev;
	}
	start = p1;
	return start;
}

