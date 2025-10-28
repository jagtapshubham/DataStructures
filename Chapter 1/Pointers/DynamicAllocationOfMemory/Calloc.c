#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int* ptr;
	int n;
	printf("Enter size of array elements : ");
	scanf("%d", &n);

	ptr = (int*)calloc(5, sizeof(int));

	for (int i = 0; i < n; i++) {
		printf("Address: %p of default element of array = %d\n",ptr+i, *(ptr + i));
	}

	free(ptr);
	ptr = NULL;

	return 0;
}
