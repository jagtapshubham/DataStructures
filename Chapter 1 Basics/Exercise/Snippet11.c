#include <stdio.h>

int main()
{
    int i, arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int *ptr = arr + 9;
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", *ptr--);
    }
}
