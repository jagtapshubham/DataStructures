#include<stdio.h>
#include<string.h>

struct student {
	char name[20];
	int rollNo;
	float marks;
};

int display(char name[], int* rollNo, float* marks);

int main() {
	struct student stu1 = { "Shubs",21,89 };

	printf("Name = %s\n", stu1.name);
	printf("Roll No = %d\n", stu1.rollNo);
	printf("Marks = %f\n", stu1.marks);

	display(stu1.name, &stu1.rollNo, &stu1.marks);

	printf("Name = %s\n", stu1.name);
	printf("Roll No = %d\n", stu1.rollNo);
	printf("Marks = %f\n", stu1.marks);

	return 0;
}

int display(char name[], int* rollNo, float* marks) {
	strcpy(name, "Jags");
	*rollNo = 30;
	*marks = 50;
}
