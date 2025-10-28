#include<stdio.h>

int main(int argc, char* argv[], char* envp[]) {
	int a = 5;
	int* pa = &a;
	int** ppa = &pa;

	printf("Values of a (a, *pa, **ppa) = %d,%d,%d\n", a, *pa, **ppa);
	printf("Address of a (&a, pa, *ppa) = %zu,%zu,%zu\n", &a, pa, *ppa);
	printf("Values of pa (&a, pa, *ppa) = %zu,%zu,%zu\n", &a, pa, *ppa);
	printf("Address of pa (&pa, ppa) = %zu,%zu\n", &pa, ppa);
	printf("Value of ppa (&pa, ppa) = %zu,%zu\n", &pa, ppa);
	printf("Address of ppa (&ppa) = %zu\n", &ppa);

	return 0;
}
