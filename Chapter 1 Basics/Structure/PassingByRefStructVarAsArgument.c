#include<stdio.h>
#include<string.h>

struct student {
	char name[20];
	int marks;
};

void changeStructMembers(struct student*);
void display(struct student);

int main() {
	struct student stu1 = { "Shubs",80 };
	printf("Struct before changing\n");
	display(stu1);
	changeStructMembers(&stu1);
	printf("Struct after passing variable by reference\n");
	display(stu1);

	return 0;
}

void changeStructMembers(struct student* stu) {
	strcpy((stu->name), "Jags");
	((*stu).marks)++;
}

void display(struct student stu) {
	printf("Name: %s\n", stu.name);
	printf("Marks: %d\n", stu.marks);
}

