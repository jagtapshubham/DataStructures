#include <stdio.h>

int main()
{
    int arr[10] = {25, 30, 35, 40, 45, 50, 55, 60, 65, 75}, *p;
    for (p = arr + 9; p >= arr; p--)
    {
        printf("%d\n", *p);
    }
}
