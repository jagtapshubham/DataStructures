#include<stdio.h>

struct student {
	char name[20];
	int* ptrmem;
};

int main() {
	struct student stu = {"Shubs"}, *stuptr = &stu;
	int value = 10;
	stu.ptrmem = &value;
	printf("Name = %s\n", stu.name);
	printf("Name = %s\n", stuptr->name);
	printf("Value at Ptrmem = %d\n", *stuptr->ptrmem);
	printf("Value at Ptrmem = %d\n", *stu.ptrmem);
	return 0;
}	