#include<stdio.h>
#include<stdlib.h>

// structure declaration
struct node
{
	int info;
	struct node *link;
};

// Function declaration
struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addbefore(struct node *start,int data,int item);
struct node *addafter(struct node *start,int data,int item);
struct node *addatpos(struct node *start,int data,int position);
struct node *delete(struct node *start,int data);
struct node *reverse(struct node *start);

int main()
{
	struct node *start=NULL;
	int choice,data,item,position;

	// code
	while(1)
	{
		printf("\n\n");
		printf("1.Create List\n");
		printf("2.Display\n");
		printf("3.Count\n");
		printf("4.Search\n");
		printf("5.Add to empty list / Add at beginning of list\n");
		printf("6.Add at end of list\n");
		printf("7.Add before the node\n");
		printf("8.Add after the node\n");
		printf("9.Add at position\n");
		printf("10.Delete the node\n");
		printf("11.Reverse the list\n");
		printf("12.Exit\n");
		
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
				count(start);
				break;
			case 4:
				printf("Enter element to be searched : ");
				scanf("%d",&data);
				search(start,data);
				break;
			case 5:
				printf("Enter element to be inserted : ");
				scanf("%d",&data);
				start = addatbeg(start,data);
				break;
			case 6:
				printf("Enter element to be inserted : ");
				scanf("%d",&data);
				start = addatend(start,data);
				break;
			case 7:
				printf("Enter element to be inserted : ");
				scanf("%d",&data);
				printf("Enter the list element before which to insert : ");
				scanf("%d",&item);
				start = addbefore(start,data,item);
				break;
			case 8:
				printf("Enter element to be inserted : ");
				scanf("%d",&data);
				printf("Enter the list element after which to insert : ");
				scanf("%d",&item);
				start = addafter(start,data,item);
				break;
			case 9:
				printf("Enter element to be inserted : ");
				scanf("%d",&data);
				printf("Enter the position in list at which to insert : ");
				scanf("%d",&position);
				start = addatpos(start,data,position);
				break;
			case 10:
				printf("Enter element to be deleted : ");
				scanf("%d",&data);
				start = delete(start,data);
				break;
			case 11:
				start = reverse(start);
				break;
			case 12:
				exit(1);
			default:
				printf("Wrong choice\n");
		} // End of switch
	}	// End of while
	
	return 0;
}	// End of main

void display(struct node *start)
{
	// code
	struct node *p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return;
	}
	p=start;
	printf("List is :\n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
	printf("\n\n");
}

void count(struct node *start)
{
	struct node *p;
	int count=0;

	// code
	p = start;
	while(p!=NULL)
	{
		p=p->link;
		count++;
	}
	printf("Number of nodes are %d\n",count);
}

void search(struct node *start,int item)
{
	struct node *p;
	int position = 1;
	
	// code
	p = start;
	while(p!=NULL)
	{
		if(p->info == item)
		{
			printf("Item %d found at position %d in list\n",item,position);
			return;
		}
		p=p->link;
		position++;
	}
	printf("Item %d not found in list\n",item);
}

struct node *addatbeg(struct node *start,int data)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;
	temp->link = start;
	start = temp;
	return start;
}

struct node *addatend(struct node *start,int data)
{
	struct node *temp,*p;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;
	p = start;
	while(p->link!=NULL)
	{
		p= p->link;
	}
	p->link = temp;
	temp->link = NULL;
	return start;
}

struct node *addbefore(struct node *start,int data,int item)
{
	struct node *temp,*p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
	/* If List is to be inserted before first node */
	if(item == start->info)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->info = data;
		temp->link = start;
		start = temp;
		return start;
	}
	p=start;
	while(p->link != NULL)
	{
		if(p->link->info == item)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->info = data;
			temp->link = p->link;
			p->link = temp;
			return start;
		}
		p = p->link;
		}
	printf("%d not present in the list\n",item);
	return start;
}

struct node *addafter(struct node *start,int data,int item)
{
	struct node *temp,*p;
	p = start;
	while(p != NULL)
	{
		if(p->info == item)
		{
			temp = (struct node*)malloc(sizeof(struct node));
			temp->info = data;
			temp->link = p->link;
			p->link = temp;
			return start;
		}
		p = p->link;
	}
}

struct node *addatpos(struct node *start,int data,int position)
{
	struct node *temp,*p;
	int i;

	// code
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;
	if(position == 1)
	{
		temp->link = start;
		start = temp;
		return start;
	}
	p=start;
	for(i=1;i<position-1 && p!=NULL;i++)
	{
		p = p->link;
	}
	if(p==NULL)
	{
		printf("There are less than %d elements\n",position);
	}
	else
	{
		temp->link = p->link;
		p->link = temp;
	}
	return start;
}

struct node *create_list(struct node *start)
{
	int i,n,data;
	printf("Enter the number of nodes :");
	scanf("%d",&n);
	start = NULL;
	if(n==0)
	{
		return start;
	}
	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	start = addatbeg(start,data);
	for(i=2;i<=n;i++)
	{
		printf("Enter the elements to be inserted : ");
		scanf("%d",&data);
		start = addatend(start,data);
	}
	return start;
}

struct node *delete(struct node *start,int data)
{
	struct node *temp, *p;
	// code
	if(start == NULL)
	{
		printf("List is empty\n");
		return start;
	}
	if(start->info == data)
	{
		temp = start;
		start = start->link;
		free(temp);
		return start;
	}
	p = start;	// Deletion in between or at the end nodes
	while(p->link!=NULL)
	{
		if(p->link->info == data)
		{
			temp = p->link;
			p->link = temp->link;
			free(temp);
			return start;
		}
		p=p->link;
	}
	printf("Element %d not found\n",data);
	return start;
}

struct node *reverse(struct node *start)
{
	struct node *prev, *ptr, *next;
	prev = NULL;
	ptr = start;

	// code
	while(ptr!=NULL)
	{
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
	}
	start = prev;
	return start;
}

