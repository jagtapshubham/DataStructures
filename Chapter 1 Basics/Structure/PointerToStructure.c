#include<stdio.h>

struct student {
	char name[20];
	int rollNo;
};

int main(void) {
	struct student stu = { "Shubs",19 };
	struct student* ptr = &stu;

	printf("Name of student : %s\n", ptr->name);
	printf("RollNo of student : %d\n", ptr->rollNo);

	return 0;
}