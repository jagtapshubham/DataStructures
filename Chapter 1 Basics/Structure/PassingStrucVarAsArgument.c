#include<stdio.h>


struct student {
	char name[20];
	int rollNo;
	float marks;
};

void display(struct student);

int main() {
	struct student stu1 = { "Shubs",19,80 };
	struct student stu2 = { "Jags",20,90 };

	display(stu1);
	display(stu2);

	//printf("Name = %s\n", stu2.name);
	//printf("Roll No = %d\n", stu2.rollNo);
	//printf("Marks = %f\n\n", stu2.marks);
	return 0;
}

void display(struct student stu) {
	printf("Name = %s\n", stu.name);
	printf("Roll No = %d\n", stu.rollNo);
	printf("Marks = %f\n\n", stu.marks);

/*	stu.rollNo = 76;
	stu.marks = 77*/;
}
