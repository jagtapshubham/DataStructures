#include <stdio.h>

int main()
{
    int i, arr[5] = {10, 20, 30, 40, 50}, *p;
    for (p = &arr[0]; p < arr + 5; p++)
    {
        printf("%d\n", *p);
    }
}
