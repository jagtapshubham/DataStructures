#include <stdio.h>

struct tag
{
    int i;
    char c;
};
void func(struct tag *);

int main()
{
    struct tag var = {20, 'c'};
    func(&var);
    printf("%d\n", var.i);
}

void func(struct tag *ptr)
{
    ptr->i++;
    // (*ptr).i++;
}
