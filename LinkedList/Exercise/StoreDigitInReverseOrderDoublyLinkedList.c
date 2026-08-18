/* Create a double linked list in which info part o each node contains a digit of given number. The digit should be stored in reverse order,i.e the least signigicant digit should be stored in the first node and most significant digit in last node. If number is 5468132 then linked list should be 2->3->1->8->6->4->5. Write a function to add two numbers represented by linked list  */
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *prev,*next;
};

struct node *create_list(struct node *start,int num);
void display(struct node *start);
struct node *add_linked_list(struct node *list1,struct node *list2);
void free_list(struct node **start);

int main()
{
	struct node *start1 = NULL,*start2 = NULL,*addList = NULL;
	int number1,number2;

	printf("Enter integer 1 for linked list : ");
	scanf("%d",&number1);
	start1 = create_list(start1,number1);
	printf("Enter integer 2 for linked list : ");
	scanf("%d",&number2);
	start2 = create_list(start2,number2);

	printf("List 1 :\n");
	display(start1);
	printf("List 2 :\n");
	display(start2);

	addList = add_linked_list(start1,start2);
	printf("Addition of two linked list :\n");
	display(addList);

	free_list(&start1);
	free_list(&start2);
	free_list(&addList);
	return 0;
}

struct node *create_list(struct node *start,int num)
{
	struct node *newNode = NULL,*tail = NULL;
	int data,i,quotient,remainder,number;

	number = num;

	while(number != 0)
	{
		quotient = number/10;
		remainder = number % 10;
		number = quotient;

		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = remainder;
		if(start == NULL)
		{
			newNode->prev = NULL;
			newNode->next = start;
			start = newNode;
		}
		else
		{
			newNode->next = tail->next;
			newNode->prev = tail;
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

struct node *add_linked_list(struct node *list1,struct node *list2)
{
	struct node *ptr1 = NULL,*ptr2 = NULL,*newNode = NULL,*addList = NULL,*tail = NULL;
	int carry = 0,add = 0,num = 0;
	
	if(list1 == NULL)
	{
		while(list2 != NULL)
		{
			newNode = (struct node *)malloc(sizeof(struct node));
			newNode->info = list2->info;
			if(addList == NULL)
			{
				newNode->prev = NULL;
				newNode->next = NULL;
				addList = newNode;
			}
			else
			{
				newNode->prev = tail;
				newNode->next = NULL;
				tail->next = newNode;
			}
			tail = newNode;
			list2 = list2->next;
		}
		return addList;
	}
	if(list2 == NULL)
	{
		while(list1 != NULL)
		{
			newNode = (struct node *)malloc(sizeof(struct node));
			newNode->info = list1->info;
			if(addList == NULL)
			{
				newNode->prev = NULL;
				newNode->next = NULL;
				addList = newNode;
			}
			else
			{
				newNode->prev = tail;
				newNode->next = NULL;
				tail->next = newNode;
			}
			tail = newNode;
			list1 = list1->next;
		}
		return addList;
	}

	ptr1 = list1;
	ptr2 = list2;

	while(ptr1 != NULL && ptr2 != NULL)
	{
		add = ptr1->info + ptr2->info + carry;
		carry = 0;
		if(add >= 10)
		{
			carry = add / 10;
			add = add % 10;
		}
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = add;
		if(addList == NULL)
		{
			newNode->prev = NULL;
			newNode->next = NULL;
			addList = newNode;
		}
		else
		{
			newNode->prev = tail;
			newNode->next = tail->next;
			tail->next = newNode;
		}
		tail = newNode;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	// If ptr1 list is not NULL
	if(ptr1 != NULL)
	{
		while(ptr1 != NULL)
		{
			if(carry != 0)
			{
				add = ptr1->info + carry;
				carry = 0;
				if(add >= 10)
				{
					carry = add / 10;
					add = add % 10;
				}
				newNode = (struct node *)malloc(sizeof(struct node));
				newNode->info = add;
				newNode->prev = tail;
				newNode->next = NULL;
				tail->next = newNode;
			}
			else
			{
				newNode = (struct node *)malloc(sizeof(struct node));
				newNode->info = ptr1->info;
				newNode->prev = tail;
				newNode->next = NULL;
				tail->next = newNode;
			}
			tail = newNode;
			ptr1 = ptr1->next;
		}
	}
	// If ptr2 list is not NULL
	if(ptr2 != NULL)
	{
		while(ptr2 != NULL)
		{
			if(carry != 0)
			{
				add = ptr2->info + carry;
				carry = 0;
				if(add >= 10)
				{
					carry = add / 10;
					add = add % 10;
				}
				newNode = (struct node *)malloc(sizeof(struct node));
				newNode->info = add;

				newNode->prev = tail;
				newNode->next = NULL;
				tail->next = newNode;
			}
			else
			{
				newNode = (struct node *)malloc(sizeof(struct node));
				newNode->info = ptr2->info;

				newNode->prev = tail;
				newNode->next = NULL;
				tail->next = newNode;
			}
			tail = newNode;
			ptr2 = ptr2->next;
		}
	}
	if(carry != 0)
	{
		newNode = (struct node *)malloc(sizeof(struct node));
		newNode->info = carry;
		newNode->prev = tail;
		newNode->next = tail->next;
		tail->next = newNode;
		tail = newNode;
	}

	return addList;
}

void free_list(struct node **start)
{
	struct node *deleteNode = NULL;

	while(*start != NULL)
	{
		deleteNode = *start;
		*start = (*start)->next;
		free(deleteNode);
	}
}

