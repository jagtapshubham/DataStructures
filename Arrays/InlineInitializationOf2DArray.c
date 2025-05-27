#include<stdio.h>

#define ROW 4
#define COLUMN 3

int main(int argc, char* argv[], char* envp[]) {
	// code 

	// Inline Initialization of array
	
	// Inititalization way 1
	//int array[ROW][COLUMN] = {{11,12,13},{14,15,16},{17,18,19},{20,21,22}};
	
	// Initialization way 2	
	int array[ROW][COLUMN] = {11,12,13,14,15,16,17,18,19,20,21,22};

	for(int i=0;i<ROW;i++) {
		for(int j=0;j<COLUMN;j++) {
			printf("%5d",array[i][j]);
		}
		printf("\n");
	}
	return 0;
}

