#include<stdio.h>

int main() {
	int *iptr, age = 25;
	float *fptr, salary = 28000.89f;
	int* p1;

	iptr = &age;
	fptr = &salary;
	p1 = iptr;

	printf("Address of age variable(&age) : %p\n", &age);
	printf("Address of salary variable(&salary) : %p\n", &salary);
	printf("Value of age variable(*iptr) : %p\n", iptr);
	printf("Value of salary variable(*fptr) : %p\n", fptr);
	printf("Address stored at p1 : %p\n", p1);
	printf("Value of age by *p1 : %d\n", *p1);

	p1 = NULL;
	printf("Value at *p1 : %d\n", p1);

	return 0;
}
