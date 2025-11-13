#include <stdio.h>

int main()
{
    struct A
    {
        int marks;
        char grade;
    };
    struct A A1, B1;
    A1.marks = 90;
    A1.grade = 'A';

    printf("A1.marks = %d\n", A1.marks);
    printf("A1.grade = %c\n", A1.grade);

    B1 = A1;

    printf("B1.marks = %d\n", B1.marks);
    printf("B1.grade = %c\n", B1.grade);

    return 0;
}
