#include "stdio.h"

int main() {
  int n1, n2;
  printf("Enter size of sparse matrix 1: ");
  scanf("%d", &n1);

  int sparseMtx1[n1][3];

  printf("Enter sparse matrix 1 in 3-tuple format\n");
  for (int i = 0; i<n1; i++) {
    printf("%d: ", i);
    scanf("%d %d %d", &sparseMtx1[i][0], &sparseMtx1[i][1], &sparseMtx1[i][2]);
  }

  printf("Enter size of sparse matrix 2: ");
  scanf("%d", &n2);

  int sparseMtx2[n2][3];

  printf("\nEnter sparse matrix 2 in 3-tuple format\n");
  for (int i = 0; i<n2; i++) {
    printf("%d: ", i);
    scanf("%d %d %d", &sparseMtx2[i][0], &sparseMtx2[i][1], &sparseMtx2[i][2]);
  }

  int resultantMtx[n1+n2][3];
  int i1=0, i2=0, k=0;

  while (i1 < n1 && i2 < n2) {
    // error here
    if (
      sparseMtx2[i2][0] < sparseMtx1[i1][0] || 
      sparseMtx2[i2][0] == sparseMtx1[i1][0] && sparseMtx2[i2][1] < sparseMtx1[i1][1]
    ) {
      resultantMtx[k][0] = sparseMtx2[i2][0];
      resultantMtx[k][1] = sparseMtx2[i2][1];
      resultantMtx[k++][1] = sparseMtx2[i2][2];
      ++i2;
    } else if (
      sparseMtx1[i1] < sparseMtx2[i2] ||
      sparseMtx1[i1][0] == sparseMtx2[i2][0] && sparseMtx1[i1][1] < sparseMtx2[i2][1]
    ) {
      resultantMtx[k][0] = sparseMtx1[i1][0];
      resultantMtx[k][1] = sparseMtx1[i1][1];
      resultantMtx[k++][1] = sparseMtx1[i1][2];
      ++i1;
    } else if (sparseMtx1[i1][0] == sparseMtx2[i2][0] && sparseMtx1[i1][1] == sparseMtx2[i2][1]) {
      resultantMtx[k][0] = sparseMtx1[i1][0];
      resultantMtx[k][1] = sparseMtx1[i1][1];
      resultantMtx[k++][1] = sparseMtx1[i1][2] + sparseMtx2[i2][2];
      ++i1;
      ++i2;
    }
  }

  printf("\nResultant matrix in 3-tuple format\n");
  for (int i = 0; i<k; i++) {
    for (int j = 0; j<3; j++) {
      printf("%d ", resultantMtx[i][j]);
    }
    printf("\n");
  }

  return 0;
}