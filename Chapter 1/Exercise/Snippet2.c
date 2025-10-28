#include <stdio.h>

int main()
{
    int arr[4] = {2, 4, 8, 16}, i = 3, j;
    while (i)
    {
        j = arr[i] + i;
        printf("i = %d\n", i);
        printf("arr[i] = %d\n", arr[i]);
        printf("j = %d\n", j);
        i--;
    }
    printf("j = %d\n", j);
}