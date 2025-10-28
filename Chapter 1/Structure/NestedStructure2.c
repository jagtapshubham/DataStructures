#include<stdio.h>
#include<string.h>

struct date {
	int day;
	int month;
	int year;
};

int main(void) {
	struct student {
		char name[20];
		int rollNo;
		struct date birthdate;
	};

	struct person {
		struct date joindate;
	}p1;

	struct student stu1;

	strcpy(stu1.name, "Jags");
	stu1.rollNo = 21;
	stu1.birthdate.day = 19;
	stu1.birthdate.month = 10;
	stu1.birthdate.year = 1999;

	p1.joindate.day = 01;
	p1.joindate.month = 9;
	p1.joindate.year = 2025;

	printf("Student Details :\n");
	printf("Name : %s\n", stu1.name);
	printf("RollNo : %d\n", stu1.rollNo);
	printf("Birth date : %d/%d/%d\n", stu1.birthdate.day, stu1.birthdate.month, stu1.birthdate.year);
	printf("Join date : %d/%d/%d\n", p1.joindate.day, p1.joindate.month, p1.joindate.year);

	return 0;
}
