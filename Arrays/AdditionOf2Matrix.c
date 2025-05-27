#include<stdio.h>

#define ROW 3
#define COLUMN 4

int main(int argc, char* argv[], char* envp[]) {
	// Variable declarations
	int mat1[ROW][COLUMN],mat2[ROW][COLUMN],mat3[ROW][COLUMN];
	int i=0,j=0;

	// code
	printf("Enter Matrix 1 values (%dx%d)row-wise :\n",ROW,COLUMN);
	for(i=0;i<ROW;i++) {
		for(j=0;j<COLUMN;j++) {
			scanf("%d",&mat1[i][j]);
		}
	}
	printf("Enter Matrix 2 values (%dx%d)row-wise :\n",ROW,COLUMN);
	for(i=0;i<ROW;i++) {
		for(j=0;j<COLUMN;j++) {
			scanf("%d",&mat2[i][j]);
		}
	}

	// Addition of Matrix
	for(i=0;i<ROW;i++) {
		for(j=0;j<COLUMN;j++) {
			mat3[i][j] = mat1[i][j] + mat2[i][j];
		}
	}

	// Display matrix
	printf("Addition of matrix:\n");
	for(i=0;i<ROW;i++) {
		for(j=0;j<COLUMN;j++) {
			printf("%5d",mat3[i][j]);
		}
		printf("\n");
	}
	return 0;
}

