#pragma once
#include <stdlib.h>
#include <stdio.h>
typedef struct Matrix {
	int** matrix;
	int col_size;
	int row_size;
}Matrix;
Matrix* newMatrix(int col, int row);
void printMatrix(Matrix* matrix);
void copy2DArrayToMatrix(Matrix* mat, int** TwoDArray, int col_size, int row_size);
Matrix* addMatrix(Matrix* mat1, Matrix* mat2);
Matrix* multiplyMatrix(Matrix* mat1, Matrix* mat2);
void freeMatrix(Matrix* mat);
