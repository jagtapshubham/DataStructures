#include<stdio.h>

#define SIZE 5

void arrayFunc(int *);

int main(int argc, char* argv[], char* envp) {
	// variable declaration
	int array[] = { 1,2,3,4,5 };
	// code
	arrayFunc(array);
	printf("\nArray After function call.\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d\n", array[i]);
	}

	return 0;
}

void arrayFunc(int* arr) {
	printf("Array changes inside the function.\n");
	for (int i = 0; i < SIZE; i++) {
		*(arr + i) = *(arr + i) + 2;
		printf("%d\n", *(arr+i));
	}
}
