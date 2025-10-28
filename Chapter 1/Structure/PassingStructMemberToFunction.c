#include<stdio.h>
#include<string.h>

struct student {
	char name[20];
	int rollNo;
	float marks;
};

void display(char name[], int rollNo, float marks);

int main() {
	// code
	struct student stu1 = { "Shubs",11,24 };
	struct student stu2;
	strcpy(stu2.name,"Jags");
	stu2.rollNo = 12;
	stu2.marks = 25;

	display(stu1.name, stu1.rollNo, stu1.marks);
	display(stu2.name, stu2.rollNo, stu2.marks);

	return 0;
}

void display(char name[], int rollNo, float marks) {
	printf("Name = %s\n", name);
	printf("Roll No = %d\n", rollNo);
	printf("Marks = %f\n", marks);
}
