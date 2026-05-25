#include<stdio.h>
int main()
{
	int a=10;
	int b;
	int c=a+b;	// BUG
				//
	printf("%d\n",c);
	return 0;
}

