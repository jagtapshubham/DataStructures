#include<stdio.h>

// function declaration
int* func(int* ptr, int n);

int main(int argc, char* argv, char* envp[]) {
	// variable declaration
	int array[] = {1,2,3,4,5,6,7,8,9,10}, n, * ptr;
	n = 5;
	// code
	ptr = func(array, n);

	printf("arr = %p, ptr = %p, *ptr = %d\n", array, ptr, *ptr);

	return 0;
}

int* func(int* ptr, int n) {
	// code
	ptr = ptr + n;

	return ptr;
}









// Function pointer of this type should not be written

//int *func();
//int main(int argc, char* argv[], char* envp[]) {
//	int* ptr;
//	ptr = func();
//	printf("*ptr = %d\n", *ptr);
//
//	return 0;
//}
//int *func() {
//	int x = 1;
//	int* p = &x;
//
//	return p;
//}
