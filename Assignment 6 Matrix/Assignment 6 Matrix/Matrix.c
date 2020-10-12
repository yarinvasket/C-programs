#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
Matrix* newMatrix(int col, int row) {
	Matrix* mat = (Matrix*)calloc(1, sizeof(Matrix));
	mat->matrix = (int**)malloc((col) * sizeof(int*));
	mat->row_size = row;
	mat->col_size = col;
	for (int i = 0; i < col; i++) {
		mat->matrix[i] = (int*)malloc(row * sizeof(int));
		for (int j = 0;j < mat->row_size;j++) {
			*(*(mat->matrix + i) + j) = 0;
		}
	}
	return mat;
}
void printMatrix (Matrix* matrix) {
	for (int i =0;i < matrix->col_size;i++) {
		for (int j = 0;j < matrix->row_size;j++) {
			printf("%d ",*(*(matrix->matrix + i) + j));
		}
		printf("\n");
	}
}
void copy2DArrayToMatrix(Matrix* mat, int** twoDArray, int col_size, int row_size) {
	if (col_size != mat->col_size || row_size != mat->row_size) { 
		printf("The given 2d array size has to be same size as the Matrix\n");
		return; 
	}
	for (int i = 0;i < mat->col_size;i++) {
		for (int j = 0;j < mat->row_size;j++) {
			*(*(mat->matrix + i) + j)=*(*(twoDArray+i)+j);
		}
	}
}
Matrix* addMatrix(Matrix* mat1, Matrix* mat2) {
	if (mat1->col_size != mat2->col_size || mat1->row_size != mat2->row_size) {
		printf("Can not add two matrix with different dimensions\n");
		return NULL;
	}
	Matrix* out = newMatrix(mat1->col_size, mat1->row_size);
	for (int i = 0;i < out->col_size;i++) {
		for (int j = 0;j < out->row_size;j++) {
			*(*(out->matrix + i) + j) = *(*(mat1->matrix + i) + j) + *(*(mat2->matrix + i) + j);
		}
	}
	return out;
}
Matrix* multiplyMatrix(Matrix* mat1, Matrix* mat2) {
	if (mat1->col_size != mat2->row_size) {
		printf("Matrix 1 columns must be equal to matrix 2 rows\n");
		return NULL;
	}
	Matrix* out = newMatrix(mat2->col_size, mat1->row_size);
	for (int i = 0; i < out->col_size; i++) {
		for (int j = 0; j < out->row_size; j++) {
			int sum = 0;
			for (int k = 0; k < mat1->col_size; k++) {
				sum += mat1->matrix[k][j] * mat2->matrix[i][k];
			}
			out->matrix[i][j] = sum;
		}
	}
	return out;
}
void freeMatrix(Matrix* mat) {
	for (int i = 0; i < mat->col_size; i++) {
		free(mat->matrix[i]);
	}
	free(mat->matrix);
	free(mat);
}