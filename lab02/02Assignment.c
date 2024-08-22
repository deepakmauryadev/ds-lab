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

  printf("i. Number of non zero elements: %d\n", noOfNonZero);

  printf("\nii. Upper Triangular Matrix\n");
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<n; j++) {
      if (i < j) {
        printf("%d ", matrix[i][j]);
      }
    }
    printf("\n");
  }
  
  printf("\niii. Elements just above the diagonal\n");
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<n; j++) {
      if (i == j+1 || i == j-1) {
        printf("%d ", matrix[i][j]);
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  return 0;
}