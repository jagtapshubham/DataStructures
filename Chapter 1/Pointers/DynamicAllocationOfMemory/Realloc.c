#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int i, *ptr;
	ptr = (int*)malloc(5 * sizeof(int));
	if (ptr == NULL) {
		printf("Memory not available\n");
		exit(0);
	}
	printf("Enter 5 integers :\n");
	for (i = 0; i < 5; i++) {
		scanf("%d", ptr + i);
	}
	// Allocate memory for 4 more integers
	ptr = (int*)realloc(ptr, 9 * sizeof(int));
	if (ptr == NULL) {
		printf("Memory not available\n");
		exit(0);
	}
	printf("Enter 4 more integers :\n");
	for (i = 5; i < 9; i++) {
		scanf("%d", ptr + i);
	}
	printf("All elements of array:\n");
	for (i = 0; i < 9; i++) {
		printf("%d element is %d\n", i, *(ptr + i));	
	}

	// Reduce the allocated memory by 2
	ptr = (int*)realloc(ptr, 7 * sizeof(int));
	if (ptr == NULL) {
		printf("Memory not available\n");
		exit(0);
	}
	printf("After reducing the array by 2\n");
	for (i=0; i < 7; i++) {
		printf("%d element is %d\n", i, *(ptr + i));
	}

	// Free the memory
	free(ptr);
	ptr = NULL;

	return 0;
}
