#include<stdio.h>
#include<stdlib.h>

int main(void) {
	// variable declarations
	int* ptr;
	int n, i;
	// code
	printf("Enter number of element in Array : ");
	scanf("%d", &n);

	ptr = (int*)malloc(n * sizeof(int));
	
	for (i = 0; i < n; i++) {
		printf("Enter an integer : ");
		scanf("%d", ptr + i);
	}
	printf("\n\n");
	// Output
	for (i = 0; i < n; i++) {
		printf("%d element is %d\n", i, *(ptr + i));
	}

	free(ptr);
	ptr = NULL;

	return 0;
}
