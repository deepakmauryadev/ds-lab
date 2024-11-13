#include "stdio.h"
#include "stdlib.h"

int main() {
  int n;
  printf("Enter number of vertex: ");
  scanf("%d", &n);

  int adjMtx[n+1][n+1];

  char opt;
  for (int i=0; i<=n; i++) {
    for (int j=0; j<=n; j++) {
      if (i == 0 || j == 0 || i == j) adjMtx[i][j] = 0;
      else {
        printf("Vertex %d & %d are adjacent? (y/n): ", i, j);
        scanf(" %c", &opt);
        adjMtx[i][j] = opt == 'y';
      }
    }
  }

  printf("\nVetex\tEdges\n");
  for (int i=1; i<=n; i++) {
    int degree = 0;
    for (int j=1; j<=n; j++) 
      if (adjMtx[i][j]) degree++;

    printf("%d\t%d\n", i, degree);
  }

  return 0;
}
