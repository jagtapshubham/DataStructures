#include<stdio.h>

#define ROW1 2
#define COLUMN1 2
#define ROW2 COLUMN1
#define COLUMN2 3

int main(int argc, char* argv[],char* envp[]) {
    // variable declarations
    int mat1[ROW1][COLUMN1];
    int mat2[ROW2][COLUMN2];
    int mat3[ROW1][COLUMN2];
    int i=0,j=0,k=0;

    printf("Enter the matrix1 (%dx%d) row-wise:\n",ROW1,COLUMN1);
    for(i=0;i<ROW1;i++) {
        for(j=0;j<COLUMN1;j++) {
            scanf("%d",&mat1[i][j]);
        }
    }
    printf("Enter the matrix2 (%dx%d) row--wise::\n",ROW2,COLUMN2);
    for(i=0;i<ROW1;i++) {
        for(j=0;j<COLUMN2;j++) {
            scanf("%d",&mat2[i][j]);
        }
    }

    // Matrix Multiplication
    for(i=0;i<ROW1;i++) {
        for(j=0;j<COLUMN2;j++) {
            mat3[i][j] = 0;
            for(k=0;k<COLUMN1;k++) {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("Matrix after multiplication:\n");
    for(i=0;i<ROW1;i++) {
        for(j=0;j<COLUMN2;j++) {
            printf("%5d",mat3[i][j]);
        }
        printf("\n");
    }

}
