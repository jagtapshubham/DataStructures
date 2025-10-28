#include<stdio.h>
#include<string.h>

struct student {
	char name[20];
	int rollNo;
	struct date {
		int day;
		int month;
		int year;
	}birthdate;
};

int main() {
	struct student stu1;

	strcpy(stu1.name, "Shubham");
	stu1.rollNo = 19;
	stu1.birthdate.day = 19;
	stu1.birthdate.month = 10;
	stu1.birthdate.year = 2000;

	printf("Student 1 Details:\n");
	printf("Name = %s\n", stu1.name);
	printf("Roll No = %d\n", stu1.rollNo);
	printf("%d/%d/%d\n", stu1.birthdate.day, stu1.birthdate.month, stu1.birthdate.year);
}
