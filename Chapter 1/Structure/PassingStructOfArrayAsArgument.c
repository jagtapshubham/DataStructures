#include<stdio.h>

struct student {
	char name[20];
	int rollNo;
	int marks;
};

void display(struct student);

void decrement_marks(struct student stuarr[]);

int main() {
	int i;
	struct student stuarr[3] = {
		{"Shubham",12,98},
		{"Jags",13,95},
		{"Shubs",14,90}
	};

	decrement_marks(stuarr);
	for (i = 0; i < 3; i++) {
		printf("\nStudent %d Info:\n", i+1);
		display(stuarr[i]);
	}

	return 0;
}

void decrement_marks(struct student stuarr[]) {
	for (int i = 0; i < 3; i++) {
		stuarr[i].marks = stuarr[i].marks - 10;
	}
}

void display(struct student str) {
	printf("Name = %s\n", str.name);
	printf("Roll No = %d\n", str.rollNo);
	printf("Marks = %d\n", str.marks);
}
