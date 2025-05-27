#include<stdio.h>

#define ROW 4
#define COLUMN 3

int main(int argc, char argv[],char envp[]) {
	int array[ROW][COLUMN],i=0,j=0;

	// Piece meal initalization
	array[0][0] = 10;
	array[0][1] = 20;
	array[0][2] = 30;

	array[1][0] = 40;
	array[1][1] = 50;
	array[1][2] = 60;

	array[2][0] = 70;
	array[2][1] = 80;
	array[2][2] = 90;

	array[3][0] = 100;
	array[3][1] = 110;
	array[3][2] = 120;

	for(i=0;i<ROW;i++) {
		for(j=0;j<COLUMN;j++) {
			printf("%5d",array[i][j]);
		}
		printf("\n");
	}
	return 0;
}

