#include<stdio.h>
#include<string.h>

struct student
{
    char name[20];
    int rollNo;
    float marks;
};

int main()
{
    struct student stud1 = {"Shubs", 12, 68.89};
    struct student stud2, stud3;

    strcpy(stud2.name, "SJ");
    stud2.rollNo = 14;
    stud2.marks = 67.0;

    stud3 = stud1;
    //printf("Enter name of student :");
    //scanf("%s", &stud3.name);
    //printf("Enter roll no :");
    //scanf("%d", &stud3.rollNo);
    //printf("Enter marks :");
    //scanf("%f", &stud3.marks);
    
    printf("Student1 : Name : %s, RollNo : %d, Marks : %.2f\n", stud1.name, stud1.rollNo, stud1.marks);
    printf("Student2 : Name : %s, RollNo : %d, Marks : %.2f\n", stud2.name, stud2.rollNo, stud2.marks);
    printf("Student3 : Name : %s, RollNo : %d, Marks : %.2f\n", stud3.name, stud3.rollNo, stud3.marks);
}