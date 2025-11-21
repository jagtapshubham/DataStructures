#include<stdio.h>

int main(int argc, char* argv[], char* envp[]) {
	int array[] = { 10,20,30,40,50 };
	int i = 0;
	// code
	// It shows that elements of array are stored in consecutive manner
	for (i = 0; i < 5; i++) {
		printf("Value of array[%d] = %d\n", i, *(array+i));	// array[i] is also written as *(array+i)
		printf("Address of array[%d] = %zu\n", i, array+i); // &array[i] is array+i) 
	}
	return 0;
}
