#include<stdio.h>

struct student {
	char name[20];
	int rollNo;
	int marks;
};

void display(struct student);
struct student change(struct student stu);

int main() {
	struct student stu1 = { "Shubs",80,98 };

	display(stu1);
	stu1 = change(stu1);
	display(stu1);

	return 0;
}

struct student change(struct student stu) {
	stu.marks = stu.marks + 5;
	stu.rollNo = stu.rollNo - 10;

	return stu;
}

void display(struct student stu) {
	printf("Name: %s\n", stu.name);
	printf("RollNo: %d\n", stu.rollNo);
	printf("Marks: %d\n", stu.marks);
}
