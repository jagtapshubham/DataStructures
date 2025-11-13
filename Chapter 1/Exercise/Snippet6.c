#include <stdio.h>

int main()
{
    int i, arr[5] = {25, 30, 35, 40, 45}, *p;
    p = arr;
    for (i = 0; i < 5; i++)
    {
        printf("%d\t%d\n", *(p + i), p[i]);
    }
}