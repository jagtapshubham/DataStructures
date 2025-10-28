#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    int *iptr;
    iptr = &iptr;
    printf("Value stored in iptr = %p\n", *iptr);
    printf("iptr address = %p\n", &iptr);
}