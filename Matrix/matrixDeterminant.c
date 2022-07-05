#include <stdio.h>
#include <stdlib.h>

int **init_matrix(int order)
{
  int **mat = (int *)malloc(order * sizeof(int));
  for (int i = 0; i < order; i++)
  {
    mat[i] = (int *)malloc(order * sizeof(int));
  }

  // Entering user input values in the matrix
  printf("Enter values in the matrix: ");
  for (int i = 0; i < order; i++)
  {
    for (int j = 0; j < order; j++)
    {
      scanf("%d", &mat[i][j]);
    }
  }

  return mat;
}

int matrix_determinant(int **arr, int order)
{
  // base case
  if (order == 1) return **arr;

  int ans = 0;

  for (int i = 0; i < order; i++)
  {
    ans += arr[0][i] * matrix_determinant(&arr[1][(i + 1) % order], order - 1);
  }

  return ans;
}

int main()
{
  int order;
  int daterminant;
  // printf("Enter the order of the matrix: ");
  // sscanf("%d", &order);

  // setting the order of the matrix
  order = 3;

  int **mat1 = init_matrix(order);

  // calculating the determinant of the matrix
  daterminant = matrix_determinant(mat1, order);

  printf("The determinant of the matrix is: %d", daterminant);

  return 0;
}