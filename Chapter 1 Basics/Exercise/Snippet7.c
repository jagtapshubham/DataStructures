#include <stdio.h>

int main()
{
    int arr[5] = {25, 30, 35, 40, 45}, i;
    for (i = 0; i < 5; i++)
    {
        printf("%d \n", *arr);
        arr++; // lvalue require error, cannot reassign the base address of an array
    }
}