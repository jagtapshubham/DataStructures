#include<stdio.h>

int main(int argc, char* argv[], char* envp[]) {
	int a = 9;
	int* p1 = &a;

	printf("*p1 = %d\n", *p1);
	printf("++(*p1) = %d\n", ++(*p1));

	return 0;
}
