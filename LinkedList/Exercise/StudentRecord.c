/* 
	Construct a linked list in which each node has the following information about a student rollno,name,marks in 3 subjects.
	Enter records of different students in list. Traverse this list and calculate the total marks,percentage of each student. Count the number of students who scored passing marks(above 40 percent).
*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node
{
	int roll_no;
	char name[30];
	float marks[3];

	struct node *prev,*next;
};

struct node *create_list(struct node *start);
void display_student(struct node *start);
void calculate_result(struct node *start);
void free_list(struct node *start);

int main()
{
	struct node *start = NULL;

	start = create_list(start);
	calculate_result(start);
	free_list(start);

	return 0;
}

struct node *create_list(struct node *start)
{
	struct node *new_node = NULL,*tail = NULL;
	int i,total_student_node,is_blank = 1,j;

	printf("Enter number of students to create : ");
	scanf("%d",&total_student_node);
	
	if(total_student_node <= 0)
	{
		printf("Enter valid number of nodes to create\n");
		return start;
	}
	for(i=1;i<=total_student_node;i++)
	{
		//printf("i = %d\n",i);
		new_node = (struct node *)malloc(sizeof(struct node));
		// check malloc memory allocation
		if(new_node == NULL)
		{
			printf("Memory allocation failed\n");
			return start;
		}
		printf("\n\n===== Enter Student Details =====\n\n");
		// check name should not be empty or contain only spaces
		getchar();
		do
		{
			is_blank = 1;
			printf("Enter name of student : ");
			fgets(new_node->name,sizeof(new_node->name),stdin);
			for(j=0;new_node->name[j]!='\0';j++)
			{
				if(!isspace((unsigned char)new_node->name[j]))
				{
					is_blank = 0;
					break;
				}
			}
			if(is_blank)
			{
				printf("Name cannot be empty or have only spaces\n");
			}
		}while(is_blank);
		// enter roll number
		printf("\nEnter roll number : ");
		scanf("%d",&new_node->roll_no);
		// enter subject marks
		for(j=0;j<3;j++)
		{
			do
			{
				printf("\nEnter subject %d marks : ",j+1);
				scanf("%f",&new_node->marks[j]);
				if(new_node->marks[j] < 0 || new_node->marks[j] > 100)
				{
					printf("Enter marks between range 0 to 100\n");	
				}
			}while(new_node->marks[j] < 0 || new_node->marks[j] > 100);
		}

		if(start == NULL)
		{
			new_node->prev = NULL;
			new_node->next = NULL;
			start = new_node;
		}
		else
		{
			new_node->prev = tail;
			new_node->next = NULL;
			tail->next = new_node;
		}
		tail = new_node;
	}
	return start;
}

void display_student(struct node *start)
{
	struct node *ptr = NULL;
	int i;

	if(start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	ptr = start;
	printf("\n\n===== Student details =====\n");
	printf("Name : %s\n",ptr->name);
	printf("Roll No : %d\n",ptr->roll_no);
	for(i=0;i<3;i++)
	{
		printf("Subject %d marks : %f\n",i+1,ptr->marks[i]);
	}
	printf("\n\n");
}

void calculate_result(struct node *start)
{
	struct node *ptr = NULL;
	float percentage,total;
	int pass_count = 0,i;

	ptr = start;
	while(ptr != NULL)
	{
		total = 0;
		for(i=0;i<3;i++)
		{
			total = total + ptr->marks[i];	
		}
		percentage = (total/300)*100;
		display_student(ptr);
		printf("Total = %.2f/300\n",total);
		printf("Percentage = %.2f\n",percentage);
		if(percentage >= 40)
		{
			pass_count++;
		}
		ptr = ptr->next;
	}
	printf("\n%d student passed by scoring 40 percentage and above\n",pass_count);
}

void free_list(struct node *start)
{
	struct node *delete_node = NULL;

	while(start != NULL)
	{
		delete_node = start;
		start = start->next;
		free(delete_node);
	}
}

