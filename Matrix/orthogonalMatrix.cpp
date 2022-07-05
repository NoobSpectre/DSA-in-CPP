#include <iostream>
using namespace std;

void print(int **mat, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

int **transposeofMatrix(int **mat, int rows, int columns)
{
	int **transposedMatrix = new int *[columns];
	for (int i = 0; i < columns; i++)
	{
		transposedMatrix[i] = new int[rows];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			transposedMatrix[j][i] = mat[i][j];
		}
	}

	return transposedMatrix;
}

int **multiplyMatrices(int **mat1, int **mat2, int rows, int columns)
{
	int **newMat = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		newMat[i] = new int[rows];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			newMat[i][j] = 0;
			for (int k = 0; k < columns; k++)
			{
				newMat[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}

	return newMat;
}

bool isOrthogonal(int **mat, int rows, int columns)
{
	int **transposedMat = transposeofMatrix(mat, rows, columns);

	int **resultantMat = multiplyMatrices(mat, transposedMat, rows, columns);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (i == j && resultantMat[i][j] != 1)
				return false;
			else if (i != j && resultantMat[i][j] != 0)
				return false;
		}
	}

	return true;
}

int main()
{
	cout << "Enter the dimensions(row(s) x column(s)) of the matrix: ";
	int rows, columns;
	cin >> rows >> columns;

	if (rows != columns)
	{
		cout << "Orthogonality can only be checked for square matrices..." << endl;
		return 0;
	}

	int **matrix = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[columns];
	}

	cout << "Enter the elements of the matrix: ";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> matrix[i][j];
		}
	}

	cout << "\nThe given matrix is: " << endl;
	print(matrix, rows, columns);

	if (isOrthogonal(matrix, rows, columns))
		cout << "\nThe given matrix is Orthogonal..." << endl;
	else
		cout << "\nThe given matrix is Non-Orthogonal..." << endl;

	return 0;
}