// WAP to perform transpose of a given sparse matrix in 3-tuple format

#include "stdio.h"

int main() {
  int nz;
  printf("Enter the size of the sparse matrix: ");
  scanf("%d", &nz);

  int spxMtx[nz][3];

  printf("Enter the sparse matrix in 3-tuple format\n");
  for (int i = 0; i < nz; i++) {
    printf("%d: ", i);
    scanf("%d %d %d", &spxMtx[i][0], &spxMtx[i][1], &spxMtx[i][2]);
  }

  int trpsMtx[nz][3];
  int k = 0, curr = 0;

  while (k < nz) {
    for (int i=0; i<nz; i++) {
      if (spxMtx[i][1] == curr) {
        trpsMtx[k][0] = spxMtx[i][1];
        trpsMtx[k][1] = spxMtx[i][0];
        trpsMtx[k++][2] = spxMtx[i][2];
      }
    }
    ++curr;
  }

  printf("\nTranspose of sparse matrix\n");
  for (int i = 0; i<nz; i++) {
    for (int j = 0; j<3; j++) {
      printf("%d ", trpsMtx[i][j]);
    }
    printf("\n");
  }

  return 0;
}