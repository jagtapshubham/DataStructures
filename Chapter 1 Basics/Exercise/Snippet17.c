#include <stdio.h>

struct tag
{
    int i;
    char c;
};

void func(struct tag v);

int main()
{

    struct tag var = {2, 's'};
    func(var);

    return 0;
}

void func(struct tag v)
{
    printf("%d\t%c\n", v.i, v.c);
}
