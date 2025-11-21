#include<stdio.h>

void func(float f[], int* i, char c[5]);

int main(int argc, char* argv[], char* envp[]) {
	// variable declarations
	float f_arr[] = { 1.2f,2.3f,3.4f,4.5f,5.5f };
	int i_arr[5] = { 1,2,3,4,5 };
	char c_arr[5] = { 'a','b','c','d','e' };
	// code
	printf("Inside main():\n");
	printf("Size of f_arr = %u\t", sizeof(f_arr));
	printf("Size of i_arr = %u\t", sizeof(i_arr));
	printf("Size of c_arr = %u\n", sizeof(c_arr));
	func(f_arr, i_arr, c_arr);

	return 0;
}

void func(float f[], int* i, char c[5]) {
	printf("Inside function():\n");
	printf("Size of f = %u\t", sizeof(f));
	printf("Size of i = %u\t", sizeof(i));
	printf("Size of c = %u\n", sizeof(c));
}
