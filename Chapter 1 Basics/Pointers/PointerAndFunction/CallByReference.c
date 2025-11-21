#include<stdio.h>

void reference(int* x, int* y);

int main(int argc, char* argv[], char* envp[]) {
	int a = 10, b = 20;

	printf("Values before function call a = %d, b = %d\n",a,b);
	reference(&a, &b);
	printf("Values after function call a = %d, b = %d\n", a, b);
	
	return 0;
}

void reference(int* x, int* y) {
	(*x)++;
	(*y)++;
	printf("Values in function x = %d, y = %d\n", *x, *y);
}
