#include<stdio.h>

struct student {
	char name[20];
	int rollNo;
	float marks;
};

int main(void) {
	int i;
	struct student stuArr[3] = {
		"Ram",12,98.2,
		"Laxman",13,96,
		"Shubs",14,89.69
	};
	/*struct student stuArr[3];

	for (i = 0; i < 3; i++) {
		printf("Enter name, rollNo and marks : ");
		scanf("%s%d%f", &stuArr[i].name, &stuArr[i].rollNo, &stuArr[i].marks);
	}*/
	printf("\nStudents Data:\n");
	for (i = 0; i < 3; i++) {
		printf("%s %d %.2f\n", stuArr[i].name, stuArr[i].rollNo, stuArr[i].marks);
	}
}
