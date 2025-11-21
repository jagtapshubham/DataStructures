#include<stdio.h>
#include<string.h>

struct student {
	char name[20];
	int rollNo;
	float submarks[3];
};

int main(void) {
	struct student stu1, stu2[3];
	strcpy(stu1.name, "Shubs");
	stu1.rollNo = 12;
	stu1.submarks[0] = 40;
	stu1.submarks[1] = 50;
	stu1.submarks[2] = 60;

	printf("Student 1:\n Name : %s\n RollNo : %d\n", stu1.name, stu1.rollNo);
	printf("Subject 1 : %f\n Subject 2 : %f\n Subject3 : %f\n", stu1.submarks[0], stu1.submarks[1], stu1.submarks[2]);
	
	// Student 2
	strcpy(stu2[0].name, "Alis");
	stu2[0].rollNo = 29;
	stu2[0].submarks[0] = 55;
	stu2[0].submarks[1] = 56;
	stu2[0].submarks[2] = 57;
	
	strcpy(stu2[1].name, "Caps");
	stu2[1].rollNo = 30;
	stu2[1].submarks[0] = 65;
	stu2[1].submarks[1] = 66;
	stu2[1].submarks[2] = 67;

	strcpy(stu2[2].name, "Thanos");
	stu2[2].rollNo = 30;
	stu2[2].submarks[0] = 76;
	stu2[2].submarks[1] = 77;
	stu2[2].submarks[2] = 78;

	printf("\nStudents:\n");
	for (int i = 0; i < 3; i++) {
		printf("Student %d\n", i + 1);
		printf("Name : %s\n RollNo : %d\n");
		for (int j = 0; j < 3; j++) {
			printf("Subject %d = %f\t", j + 1, stu2[i].submarks[j]);
		}
		printf("\n");
	}
}