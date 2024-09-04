// WAP to perform addition of two given sparse matrix in 3-tuple format

#include "stdio.h"

int main() {
  int nz1, nz2;
  printf("Enter size of sparse matrix 1: ");
  scanf("%d", &nz1);

  int spxMtx1[nz1][3];

  printf("Enter sparse matrix 1 in 3-tuple format\n");
  for (int i = 0; i < nz1; i++) {
    printf("%d: ", i);
    scanf("%d %d %d", &spxMtx1[i][0], &spxMtx1[i][1], &spxMtx1[i][2]);
  }

  printf("Enter size of sparse matrix 2: ");
  scanf("%d", &nz2);

  int spxMtx2[nz2][3];

  printf("\nEnter sparse matrix 2 in 3-tuple format\n");
  for (int i = 0; i < nz2; i++) {
    printf("%d: ", i);
    scanf("%d %d %d", &spxMtx2[i][0], &spxMtx2[i][1], &spxMtx2[i][2]);
  }

  int sumMtx[nz1 + nz2][3];
  int i1 = 0, i2 = 0, k = 0;

  while (i1 < nz1 && i2 < nz2) {
    if (spxMtx1[i1][0] == spxMtx2[i2][0]) {
      if (spxMtx1[i1][1] == spxMtx2[i2][1]) {
        sumMtx[k][0] = spxMtx1[i1][0];
        sumMtx[k][1] = spxMtx1[i1][1];
        sumMtx[k++][2] = spxMtx1[i1++][2] + spxMtx2[i2++][2];
      } else if (spxMtx1[i1][1] < spxMtx2[i2][1]) {
        sumMtx[k][0] = spxMtx1[i1][0];
        sumMtx[k][1] = spxMtx1[i1][1];
        sumMtx[k++][2] = spxMtx1[i1++][2];
      } else if (spxMtx1[i1][1] > spxMtx2[i2][1]) {
        sumMtx[k][0] = spxMtx2[i2][0];
        sumMtx[k][1] = spxMtx2[i2][1];
        sumMtx[k++][2] = spxMtx2[i2++][2];
      }
    } else if (spxMtx1[i1][0] < spxMtx2[i2][0]) {
      sumMtx[k][0] = spxMtx1[i1][0];
      sumMtx[k][1] = spxMtx1[i1][1];
      sumMtx[k++][2] = spxMtx1[i1++][2];
    } else if (spxMtx1[i1][0] > spxMtx2[i2][0]) {
      sumMtx[k][0] = spxMtx2[i2][0];
      sumMtx[k][1] = spxMtx2[i2][1];
      sumMtx[k++][2] = spxMtx2[i2++][2];
    }
  }

  printf("\nResultant matrix in 3-tuple format\n");
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", sumMtx[i][j]);
    }
    printf("\n");
  }

  return 0;
}