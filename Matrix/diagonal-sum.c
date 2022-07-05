#include <stdio.h>
#include <stdlib.h>

enum bool{false, true};

int **init_matrix(int order)
{
  int **mat = (int *)malloc(order * sizeof(int));
  for (int i = 0; i < order; i++)
  {
    mat[i] = (int *)malloc(order * sizeof(int));
  }

  return mat;
}

void print(int** mat, int order)
{
  for (int i = 0; i < order; i++)
  {
    for (int j = 0; j < order; j++)
    {
      printf("%d ", mat[i][j]);
    }
      printf("\n");
  }
}

int diagonalSum(int **mat, int order, enum bool diagonal) {
  int sum = 0;

  if(diagonal) { // left diagonal 
    for (int i = 0; i < order; i++) {
      sum += mat[i][i];
    }
  } else { // right diagonal
    for (int i = 0; i < order; i++) {
      sum += mat[i][order - 1 - i];
    }
  }

  return sum;
}

int main () {
  int order;
  // printf("Enter the order of the matrix: ");
  // scanf("%d", &order);

  // setting the order of the matrix to 3
  order = 3;

  int **matrix = init_matrix(order);

  // Entering user input values into the matrix
  printf("Enter values in the matrix: ");
  for (int i = 0; i < order; i++)
  {
    for (int j = 0; j < order; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
  }

  // printing the matrix
  print(matrix, order);

  int leftDiagonal_sum = diagonalSum(matrix, order, true);
  int rightDiagonal_sum = diagonalSum(matrix, order, false);

  printf("Left diagonal sum: %d, right diagonal sum: %d\n", leftDiagonal_sum, rightDiagonal_sum);

  return 0;
}