#include <stdio.h>
#include <stdlib.h>

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

int matrix_determinant(int **mainMatrix, int order)
{
  if(order <= 0) {
    printf("Order can't be of order 0 or less...\n");
    return -1;
  }

  // base case
  if (order == 1) return mainMatrix[0][0];

  int det = 0;
  int **subMatrix = init_matrix(order - 1);

  // sign of the determinant 
  int sign = -1;
  
  // selecting the main row-column
  for (int k = 0; k < order; k++)
  {    
    /*** creating the sub-matrix ***/
    int subrow = 0;
    // selecting the sub-row
    for (int mainrow = 1; mainrow < order; mainrow++)
    {
      int subcol = 0;
      // selecting the sub-column
      for(int maincol = 0; maincol < order; maincol++)
      {
        if(maincol == k) continue;
        subMatrix[subrow][subcol] = mainMatrix[mainrow][maincol];
        subcol++;
      }
      subrow++;
    }
    /*** !creating the sub-matrix ***/
  
    // calculating the determinat of the matrix
    sign *= -1;
    det += sign * mainMatrix[0][k] * matrix_determinant(subMatrix, order - 1);
  }

  return det;
}

int main()
{
  int order;
  int daterminant;
  // printf("Enter the order of the matrix: ");
  // scanf("%d", &order);

  // setting the order of the matrix to 3
  order = 3;

  int **mat1 = init_matrix(order);

  // Entering user input values into the matrix
  printf("Enter values in the matrix: ");
  for (int i = 0; i < order; i++)
  {
    for (int j = 0; j < order; j++)
    {
      scanf("%d", &mat1[i][j]);
    }
  }

  // printing the matrix
  print(mat1, order);

  // calculating the determinant of the matrix
  daterminant = matrix_determinant(mat1, order);

  printf("The determinant of the matrix is: %d", daterminant);

  return 0;
}