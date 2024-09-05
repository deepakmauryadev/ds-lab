// WAP to represent a given sparse matrix in 3-tuple format using 2-D array

#include "stdio.h"

int main() {
  int n;
  printf("Enter size of the square matrix: ");
  scanf("%d", &n);
  
  int matrix[n][n];
  printf("Enter the elements of the matrix\n");
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<n; j++) {
      printf("[%d][%d]: ", i, j);
      scanf("%d", &matrix[i][j]);
    }
  }

  int noOfNonZero = 0;
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<n; j++) {
      if (matrix[i][j] != 0) ++noOfNonZero;
    }
  }

  int spxMtx[noOfNonZero][3];
  int k=0;
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<n; j++) {
      if (matrix[i][j] != 0) {
        spxMtx[k][0] = i;
        spxMtx[k][1] = j;
        spxMtx[k++][2] = matrix[i][j];
      }
    }
  }

  printf("\nSparse matrix in 3-tuple form\n");
  for (int i = 0; i<noOfNonZero; i++) {
    for (int j = 0; j<3; j++) {
      printf("%d ", spxMtx[i][j]);
    }
    printf("\n");
  }

  return 0;
}