#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student {
	char name[20];
	int rollNo;
	int marks;
};

void display(struct student *);
struct student* func();
struct student* ptr;

int main() {
	struct student* stuptr;
	stuptr = func();
	display(stuptr);
	free(stuptr);

	return 0;
}

struct student* func() {
	ptr = (struct student*)malloc(sizeof(struct student));
	strcpy(ptr->name, "Shubs");
	ptr->rollNo = 19;
	(*ptr).marks = 85;
}

void display(struct student* stuptr) {
	printf("Student Info:\n");
	printf("Name = %s\n", stuptr->name);
	printf("Roll No = %d\n", stuptr->rollNo);
	printf("Marks = %d\n", stuptr->marks);
}
