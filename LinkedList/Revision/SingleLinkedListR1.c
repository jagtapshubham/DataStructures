#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start, int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addafter(struct node *start,int data,int item);
struct node *addbefore(struct node *start,int data,int item);
struct node *addatpos(struct node *start,int data,int pos);
struct node *del(struct node *start,int data);
struct node *reverse(struct node *start);

int main()
{
	struct node *start=NULL;
	int choice,data,item,pos;

	// code
	while(1)
	{
		printf("\n");
		printf("1.Create List.\n");
		printf("2.Display.\n");
		printf("3.Count.\n");
		printf("4.Search.\n");
		printf("5.Add to empty list / Add at beginning.\n");
		printf("6.Add at end.\n");
		printf("7.Add before a node.\n");
		printf("8.Add after a node.\n");
		printf("9.Add at position.\n");
		printf("10.Delete a node.\n");
		printf("11.Reverse a list.\n");
		printf("12.Exit.\n");
		printf("\n");
		printf("Enter a choice : ");
		scanf("%d",&choice);
		printf("\n");

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
				printf("Enter the element to be searched : ");
				scanf("%d",&data);
				search(start,data);
				break;
			case 5:
				printf("Enter the element to be inserted : ");
				scanf("%d",&data);
				start = addatbeg(start,data);
				break;
			case 6:
				printf("Enter the element to be inserted : ");
				scanf("%d",&data);
				start = addatend(start,data);
				break;
			case 7:
				printf("Enter the element to be inserted : ");
				scanf("%d",&data);
				printf("Enter the element before which to be inserted : ");
				scanf("%d",&item);
				start = addbefore(start,data,item);
				break;
			case 8:
				printf("Enter the element to be inserted : ");
				scanf("%d",&data);
				printf("Enter the element after which to be inserted : ");
				scanf("%d",&item);
				start = addafter(start,data,item);
				break;
			case 9:
				printf("Enter the element to be inerted : ");
				scanf("%d",&data);
				printf("Enter the position at which to inserted : ");
				scanf("%d",&item);
				start = addatpos(start,data,item);
				break;
			case 10:
				printf("Enter the element to be deleted : ");
				scanf("%d",&data);
				start = del(start,data);
				break;
			case 11:
				start = reverse(start);
				break;
			case 12:
				exit(1);
			default :
				printf("Wrong choice\n");
		} // End of switch
	} // End of while
} // End of main

struct node create_list(struct node *start)
{
	struct node *temp,*p;
	int nodes,data;

	printf("Enter the number of node : ");
	scanf("%d",&nodes);
	
	if(nodes==0)
	{
		return;
	}
	printf("Enter element to be inserted : ");
	scanf("%d",&data);
	start = addatbeg(start,data);
	for(i=2;i<=nodes;i++)
	{
		printf("Enter element to be inserted : ");
		scanf("%d",&data);
		start = addatend(start,data);
	}
	return start;
}

void display(struct node *start)
{
	struct node *p;
	if(start == NULL)
	{
		printf("List is empty");
		return;
	}
	p=start;
	printf("List is :\n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->link;
	}
}

void count(struct node *start)
{
	struct node *p;
	int count=0;

	p=start;
	while(p!=NULL)
	{
		p=p->link;
		count++;
	}
	printf("Number of elements in list are : %d\n",count);
}

void search(struct node *start,int data)
{
	struct node *p;
	int pos = 1;
	// code
	p = start;
	while(p!=NULL)
	{
		if(p->info == data)
		{
			printf("%d element found at position %d\n",data,pos);
			return;
		}
		pos++;
		p = p->link;
	}
	printf("%d element not found in list\n",data);
}

struct node *addatbeg(struct node *start,int data)
{
	struct node *temp;

	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;
	temp->link = start;
	start = temp;
	return start;
}

struct node *addatend(struct node *start,int data)
{
	struct node *temp,*p;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;

	p = start;
	while(p->link != NULL)
	{
		p=p->link;
	}
	p->link = temp;
	temp->link = NULL;
	return start;
}

struct node *addafter(struct node *start,int data,int item)
{
	struct node *temp,*p;

	p = start;
	while(p!=NULL)
	{
		if(p->info == item)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->info = data;
			temp->link = p->link;
			p->link = temp;
			return start;
		}
		p=p->link;
	}
	printf("%d not present in the list.\n",item);
	return start;
}

struct node *addbefore(struct node *start,int data,int item)
{
	struct node *temp,*p;
	
	// code
	if(start==NULL)
	{
		printf("List is empty.\n");
		return;
	}
	// If data to be inserted befire first node
	if(item == start->info)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->info = data;
		temp->link = start;
		start = temp;
		return start;
	}
	p=start;
	while(p->link!=NULL)
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
	printf("%d not present in list.\n",item);
	return start;
}

struct node *addatpos(struct node *start,int data,int pos)
{	
	struct node *temp,*p;
	int i;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->info = data;

	if(pos == 1)
	{
		temp->link = start;
		start = temp;
		return start;
	}
	p=start;
	for(i=1;i<pos-1 && p!=NULL;i++)
	{
		p=p->link;
	}
	if(p==NULL)
	{
		printf("There are less than %d elements in list.\n",pos);
	}
	else
	{
		temp->link = pos->link;
		pos->link = temp;
	}
	return start;
}

struct node *del(struct node *start,int data)
{
	struct node *p, *temp;

	if(start == NULL)
	{
		printf("List is empty\n");
		return start;
	}
	// Deletion of first node
	if(start->info == data)
	{
		temp = start;
		start = temp->link;
		free(temp);
		return start;
	}
	// Deletion in between or end node
	p = start;
	while(p->link != NULL)
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
	printf("%d element not present in list.\n",data);
	return start;
}

struct node *reverse(struct node *start)
{
	struct node *prev,*ptr,*next;
	prev = NULL;
	ptr = start;

	while(ptr != NULL)
	{
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
	}
	start = prev;
	return start;
}

