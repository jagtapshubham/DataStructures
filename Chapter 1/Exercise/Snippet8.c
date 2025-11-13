#include <stdio.h>

int main()
{
    int i, arr[5] = {5, 10, 15, 20, 25}, *p = arr;
    for (i = 0; i < 5; i++)
    {
        *p++;
        printf("%d\n", *p);
        p++;
    }
}
