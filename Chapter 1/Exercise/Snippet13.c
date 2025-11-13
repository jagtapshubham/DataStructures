#include <stdio.h>

int change1(int *p);
int change2(int **pp);

int a = 5, b = 10;

int main()
{
    // code
    int x = 20, *ptr = &x;

    printf("*ptr = %d\n", *ptr);
    change1(ptr);
    printf("*ptr after change1() = %d\n", *ptr);
    change2(&ptr);
    printf("*ptr after change2() = %d\n", *ptr);

    return 0;
}

int change1(int *p)
{
    // code
    p = &a;
    printf("In func change1 = %d\n", *p);
}

int change2(int **pp)
{
    // code
    *pp = &b;
}
