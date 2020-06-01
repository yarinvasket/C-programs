#include <stdlib.h>
#include <stdio.h>
#include "Matrix.h"
#define MAT_COL 2
#define MAT_ROW 5
int** create2DArray(int,int,int);
void free2DArray(int** arr,int,int);

int main() {
	//intializing two empty matrixes
	Matrix* mat1 = newMatrix(MAT_COL, MAT_ROW);
	Matrix* mat2 = newMatrix(MAT_COL, MAT_ROW);
	//creating two 2d arrays to copy into the Matrixes
	int** arr1 = create2DArray(4, MAT_COL, MAT_ROW);
	int** arr2 = create2DArray(26, MAT_COL, MAT_ROW);
	//copying the 2d arrays into the Matrixes
	copy2DArrayToMatrix(mat1,arr1 , MAT_COL, MAT_ROW);
	copy2DArrayToMatrix(mat2, arr2, MAT_COL, MAT_ROW);

	Matrix* adding_result = addMatrix(mat1,mat2);

	//printing
	printf("Matrix number one:\n");
	printMatrix(mat1);
	printf("Matrix number two:\n");
	printMatrix(mat2);
	printf("Both matrixes added into a new one:\n");
	printMatrix(adding_result);
	//freeing
	free2DArray(arr1,MAT_COL, MAT_ROW);
	free2DArray(arr2, MAT_COL, MAT_ROW);
	freeMatrix(mat1);
	freeMatrix(mat2);
	freeMatrix(adding_result);
	return 1;
}
int** create2DArray(int value,int col, int row) {
	int** arr = (int**)malloc(sizeof(int*) * col);
	for (int i = 0;i < col;i++) {
		arr[i] = (int*)malloc(sizeof(int) * row);
		for (int j = 0;j < row;j++) {
			arr[i][j] = value;
		}
	}
	return arr;
}
void free2DArray(int** arr,int col,int row) {
	for (int i = 0;i < col;i++) {
		free(arr[i]);
	}
	free(arr);
}