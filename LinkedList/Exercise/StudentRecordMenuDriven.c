/*
 Write a Student record program(Name,Rollno,3 subject marks) so that the names are inserted in alphabetical order in this list.Make this program menu driven with the following menu.
 1.Create List 2.Insert 3.Delete 4.Modify 5.Display Record 6.Display Result
 Delete menu should have the facility of entering name of the student and the record of that student should be deleted.
 Display record menu should ask for the roll no of a student and display all the information.
 Display result should display the number of students who have passed. Modify menu has the facility of modifying a record given the roll number
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node
{
	int roll_no;
	float marks[3];
	char name[30];
	struct node *prev,*next;
};

struct node *create_student_list(struct node *start);
struct node *insert_student_detail(struct node *start);
struct node *delete_student_record(struct node *start);
struct node *sort_list_by_names(struct node *start,struct node *name_pointer);
struct node *modify_student_record(struct node *start);
void display_student_record(struct node *start);
void display_student_result(struct node *start);
void display_all_student_records(struct node *start);
void free_list(struct node *start);

int main()
{
	struct node *start = NULL;
	int choice;

	while(1)
	{
		printf("\n===== Menu =====\n");
		printf("1.Create list\n");
		printf("2.Insert student details\n");
		printf("3.Delete student record\n");
		printf("4.Modify student record\n");
		printf("5.Display student record\n");
		printf("6.Display student result\n");
		printf("7.Display all student records\n");
		printf("8.Exit\n");
		printf("\n");

		printf("Enter choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				start = create_student_list(start);
				break;
			case 2:
				start = insert_student_detail(start);
				break;
			case 3:
				start = delete_student_record(start);
				break;
			case 4:
				start = modify_student_record(start);
				break;
			case 5:
				display_student_record(start);
				break;
			case 6:
				display_student_result(start);
				break;
			case 7:
				display_all_student_records(start);
				break;
			case 8:
				free_list(start);
				return 0;
			default:
				printf("Wrong choice\n");
				break;
		}
		printf("\n");
	}
	return 0;
}

struct node *create_student_list(struct node *start)
{
	int i,total_students;

	printf("Enter number of students record to create : ");
	scanf("%d",&total_students);

	if(total_students <= 0)
	{
		printf("Enter valid number of students to enter\n");
		return start;
	}
	for(i=1;i<=total_students;i++)
	{
		start = insert_student_detail(start);
	}
	return start;
}

struct node *insert_student_detail(struct node *start)
{
	struct node *new_node = NULL;
	int i,is_blank = 0;

	new_node = (struct node *)malloc(sizeof(struct node));
	if(new_node == NULL)
	{
		printf("Failed to allocated memory by malloc\n");
		return start;
	}
	// Get student name
	printf("\n");
	getchar();
	do
	{
		is_blank = 1;
		printf("Enter name  : ");
		fgets(new_node->name,sizeof(new_node->name),stdin);
		for(i=0;new_node->name[i] != '\0';i++)
		{
			if(!isspace(new_node->name[i]))
			{
				is_blank = 0;
				break;
			}
		}
		if(is_blank == 1)
		{
			printf("Name cannot contain space or empty character\n");
		}
	}while(is_blank);
	// Get student roll no
	printf("Enter Roll no : ");
	scanf("%d",&new_node->roll_no);
	// Get marks
	for(i=0;i<3;i++)
	{
		do
		{
			printf("Enter subject %d marks : ",i+1);
			scanf("%f",&new_node->marks[i]);
			if(new_node->marks[i] < 0 || new_node->marks[i] > 100)
			{
				printf("Enter valid marks between 0 to 100\n");
			}
		}while(new_node->marks[i] <= -1 || new_node->marks[i] >= 101);
	}
	// sort the list in alphabetical order of student name
	if(start == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		start = new_node;
	}
	else
	{
		start = sort_list_by_names(start,new_node);
	}
	return start;
}

struct node *sort_list_by_names(struct node *start,struct node *name_pointer)
{
	struct node *pp = NULL,*ptr = NULL;

	if(start == NULL)
	{
		name_pointer->prev = NULL;
		name_pointer->next = NULL;
		start = name_pointer;
		return start;
	}
	pp = ptr = start;
	while(ptr != NULL)
	{
		if(strcmp(name_pointer->name,ptr->name) <= 0)
		{
			if(ptr == start)
			{
				name_pointer->prev = NULL;
				name_pointer->next = start;
				ptr->prev = name_pointer;
				start = name_pointer;
			}
			else
			{
				name_pointer->prev = pp;
				name_pointer->next = ptr;
				ptr->prev = name_pointer;
				pp->next = name_pointer;
			}
			return start;
		}
		pp = ptr;
		ptr = ptr->next;
	}
	name_pointer->prev = pp;
	name_pointer->next = pp->next;
	pp->next = name_pointer;

	return start;
}

struct node *delete_student_record(struct node *start)
{
	struct node *ptr = NULL,*delete_node = NULL;
	char stud_name[30];
	int flag = 0;

	getchar();
	printf("Enter student name : ");
	fgets(stud_name,sizeof(stud_name),stdin);
	
	ptr = start;
	while(ptr != NULL)
	{
		if(strcmp(ptr->name,stud_name) == 0)
		{
			delete_node = ptr;
			if(ptr == start)
			{
				if(start->next != NULL)
				{
					start->next->prev = NULL;
				}
				start = start->next;
			}
			else
			{
				ptr->prev->next = ptr->next;
				if(ptr->next != NULL)
				{
					ptr->next->prev = ptr->prev;
				}
			}
			flag = 1;
			break;
		}
		ptr = ptr->next;
	}
	if(flag == 0)
	{
		printf("No matching student name record found to delete.\n");
	}
	free(delete_node);
	return start;
}

struct node *modify_student_record(struct node *start)
{
	struct node *ptr = NULL;
	int stud_roll_no,choice,subject;

	printf("Enter Roll_no : ");
	scanf("%d",&stud_roll_no);

	ptr = start;
	while(ptr != NULL)
	{
		if(ptr->roll_no == stud_roll_no)
		{
			while(1)
			{
				printf("\n===== Modify record =====\n");
				printf("1.Change roll no\n");
				printf("2.Change name\n");
				printf("3.Change subject marks 1,2,3\n");
				printf("4.Exit\n");
				printf("Enter choice : ");
				scanf("%d",&choice);

				switch(choice)
				{
					case 1:
						printf("Enter new roll no : ");
						scanf("%d",&ptr->roll_no);
						break;
					case 2:
						printf("Enter new name of student : ");
						getchar();
						fgets(ptr->name,sizeof(ptr->name),stdin);
						struct node *new_node = ptr;
						if(ptr == start)
						{
							if(ptr->next != NULL)
							{
								ptr->next->prev = NULL;
								start = ptr->next;
							}
							else
							{
								start = NULL;
							}
						}
						else
						{
							ptr->prev->next = ptr->next;
							if(ptr->next != NULL)
							{
								ptr->next->prev = ptr->prev;
							}
						}
						new_node->prev = NULL;
						new_node->next = NULL;
						start = sort_list_by_names(start,new_node);
						break;
					case 3:
						do
						{
							printf("Which subject (1,2,3) : ");
							scanf("%d",&subject);
							if(subject <= 0 || subject >= 4)
							{
								printf("Enter subject number between 1 to 3\n");
							}
						}while(subject <= 0 || subject >= 4);
						printf("Enter marks for %d subject : ",subject);
						scanf("%f",&ptr->marks[subject-1]);
						break;
					case 4:
						return start;
					default:
						printf("Wrong choice\n");
						break;
				}
			}
		}
		ptr = ptr->next;
	}
	printf("%d roll number does not exist\n",stud_roll_no);

	return start;
}

void display_student_record(struct node *start)
{
	struct node *ptr;
	int stud_roll_no;

	printf("Enter student roll no : ");
	scanf("%d",&stud_roll_no);

	ptr = start;
	while(ptr != NULL)
	{
		if(ptr->roll_no == stud_roll_no)
		{
			printf("\n==== Student Record =====\n");
			printf("Roll No : %d\n",ptr->roll_no);
			printf("Name : %s",ptr->name);
			for(int i=0;i<3;i++)
			{
				printf("Subject %d marks %.2f\n",i+1,ptr->marks[i]);
			}
			return;
		}
		ptr = ptr->next;
	}
	printf("Student roll number and record not found\n");
	printf("\n\n");
}

void display_student_result(struct node *start)
{
	struct node *ptr = NULL;
	int pass_count = 0,i;
	float total,percentage;

	ptr = start;
	while(ptr != NULL)
	{
		total = 0.0f;
		for(i=0;i<3;i++)
		{
			total = total + ptr->marks[i];
		}
		percentage = (total/300)*100;
		if(percentage >= 40)
		{
			pass_count++;
		}
		ptr = ptr->next;
	}
	printf("Total number of students passed are %d\n",pass_count);
}

void display_all_student_records(struct node *start)
{
	struct node *ptr = NULL;
	int i,j;
	
	i=0;
	j=1;
	ptr = start;
	while(ptr != NULL)
	{
		printf("\n===== Student %d =====\n",j++);
		printf("Roll No : %d\n",ptr->roll_no);
		printf("Name : %s\n",ptr->name);
		for(i=0;i<3;i++)
		{
			printf("Subject %d marks : %.2f\n",i+1,ptr->marks[i]);
		}
		ptr = ptr->next;
	}
	printf("\n\n");
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

