#include<stdio.h>
#include<stdlib.h>

struct node
{
	float coef;
	int expo;
	struct node *next;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *insert_t(struct node *start,float co,int ex);
struct node *insert(struct node *start,float co,int ex);
void poly_add(struct node *p1,struct node *p2);
void poly_mult(struct node *p1,struct node * p2);

int main()
{
	struct node *start1 = NULL,*start2 = NULL;
	printf("Enter polynomial 1 : \n");
	start1 = create_list(start1);
	printf("Enter polynomial 2 : \n");
	start2 = create_list(start2);
	poly_add(start1,start2);
	poly_mult(start1,start2);
	return 0;
}

struct node *create_list(struct node *start)
{
	int i,term,ex;
	float co;

	printf("Enter the number of terms : ");
	scanf("%d",&term);
	for(i=1;i<=term;i++)
	{
		printf("Enter coeficient for term %d : ", i);
		scanf("%f",&co);
		printf("Enter exponent for term %f : ",co);
		scanf("%d",&ex);
		start = insert_t(start,co,ex);
	}
	return start;
}

struct node *insert_s(struct node *start,float co,int ex)
{
	struct node *newNode,*ptr;

	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->coef = co;
	newNode->expo = ex;

	if(start == NULL || ex > start->expo)
	{
		newNode->next = start;
		start = newNode;
	}
	else
	{
		ptr = start;
		while(ptr->next != NULL && ptr->next->expo >= ex)
		{
			ptr = ptr->next;
		}
		newNode->next = ptr->next;
		ptr->next = newNode;
	}
	return start;
}

struct node *insert(struct node *start,float co,int ex)
{
	struct node *newNode,*ptr;
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->coef = co;
	newNode->expo = ex;

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
	printf("\n");
	printf("Start");
	while(ptr != NULL)
	{
		printf("->( %.1fx^%d)",ptr->coef,ptr->expo);
		ptr = ptr->next;
		if(ptr!=NULL)
		{
			printf(" + ");
		}
		else
		{
			printf("\n");
		}
	}
	printf("\n");
}

void poly_add(struct node *p1,struct node *p2)
{
	struct node *start3 = NULL;

	while(p1!=NULL && p2!=NULL)
	{
		if(p1->expo > p2->expo)
		{
			start3 = insert(start3,p1->coef,p1->expo);
			p1 = p1->next;
		}
		else if(p2->expo > p1->expo)
		{
			start3 = insert(start3,p2->coef,p2->expo);
			p2 = p2->next;
		}
		else if(p1->expo == p2->expo)
		{
			start3 = insert(start3,p1->coef+p2->coef,p1->expo);
			p1 = p1->next;
			p2 = p2->next;
		}
	}

	/* if poly2 has finished and elements left in poly1 */
	while(p1 != NULL)
	{
		start3 = insert(start3,p1->coef,p1->expo);
		p1 = p1->next;
	}
	/* if poly1 has finished and elements left in poly2 */
	while(p2 != NULL)
	{
		start3 = insert(start3,p2->coef,p2->expo);
		p2 = p2->next;
	}
	printf("Added polynomial is : ");
	display(start3);
}

void poly_mult(struct node *p1,struct node *p2)
{
	struct node *start3 = NULL;
	struct node *p2_beg = p2;

	if(p1 == NULL || p2 == NULL)
	{
		printf("Mulitplied polynomial is zero polynomial.\n");
		return;
	}
	while(p1 != NULL)
	{
		p2 = p2_beg;
		while(p2 != NULL)
		{
			start3 = insert_t(start3,p1->coef * p2->coef,p1->expo + p2->expo);
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	printf("Multiplied polynomial is : ");
	display(start3);
}

