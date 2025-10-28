#include<stdio.h>

void returnSumDiffProduct(int, int, int*, int*, int*);

int main(int argc, char* argv[], char* envp[]) {
	int a=1, b=2, sum=0, prod=0, diff=0;

	returnSumDiffProduct(a, b, &sum, &diff, &prod);
	printf("Sum of %d and %d = %d\n", a, b, sum);
	printf("Difference of %d and %d = %d\n", a, b, diff);
	printf("Product of %d and %d = %d\n", a, b, prod);

	return 0;
}

void returnSumDiffProduct(int x, int y, int* add, int* sub, int* mul) {
	*add = x + y;
	*sub = x - y;
	*mul = x * y;
}
