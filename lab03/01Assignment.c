#include "stdio.h"

int main() {
  int n;
  printf("Enter the size of the sparse matrix: ");
  scanf("%d", &n);

  int sparseMtx[n][3];

  printf("Enter the sparse matrix in 3-tuple format\n");
  for (int i = 0; i < n; i++) {
    printf("%d: ", i);
    scanf("%d %d %d", &sparseMtx[i][0], &sparseMtx[i][1], &sparseMtx[i][2]);
  }

  int transposeMtx[n][3];
  int k = 0, curr = 0;
  while (k < n) {
    for (int i=0; i<n; i++) {
      if (sparseMtx[i][1] == curr) {
        transposeMtx[k][0] = sparseMtx[i][1];
        transposeMtx[k][1] = sparseMtx[i][0];
        transposeMtx[k++][2] = sparseMtx[i][2];
        ++curr;
      }
    }
  }
  printf("\nTranspose of sparse matrix\n");
  for (int i = 0; i<n; i++) {
    for (int j = 0; j<3; j++) {
      printf("%d ", transposeMtx[i][j]);
    }
    printf("\n");
  }

  return 0;
}