#include "stdio.h"

int main() {
  int n;
  printf("Enter size of the square matrix: ");
  scanf("%d", &n);
  
  int matrix[n][n];
  printf("Enter the elements of the matrix\n");
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<n; j++) {
      printf("matrix[%d][%d]: ", i, j);
      scanf("%d", &matrix[i][j]);
    }
  }

  int noOfNonZero = 0;
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<n; j++) {
      if (matrix[i][j] != 0) ++noOfNonZero;
    }
  }

  int sparseMtx[noOfNonZero][3];
  int k=0;
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<n; j++) {
      if (matrix[i][j] != 0) {
        sparseMtx[k][0] = i;
        sparseMtx[k][1] = j;
        sparseMtx[k++][2] = matrix[i][j];
      }
    }
  }

  printf("\nSparse matrix in 3-tuple form\n");
  for (int i = 0; i<noOfNonZero; i++) {
    for (int j = 0; j<3; j++) {
      printf("%d ", sparseMtx[i][j]);
    }
    printf("\n");
  }

  return 0;
}