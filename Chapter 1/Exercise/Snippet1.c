#include <stdio.h>

#define SIZE 5

int main()
{
    int i, size = 5, arr[SIZE];
    printf("Enter the numbers:\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nDisplay\n");
    for (i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}