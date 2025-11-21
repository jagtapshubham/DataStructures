#include <stdio.h>

int swap(int x, int *y);

int main()
{
    int a = 2, b = 6;
    printf("Before swap a=%d b=%d\n", a, b);
    swap(a, &b);
    printf("After swap a=%d b=%d\n", a, b);

    return 0;
}

int swap(int x, int *y)
{
    int temp = x;
    x = *y;
    *y = temp;
}
