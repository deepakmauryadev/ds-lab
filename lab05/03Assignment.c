#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
  int row, col, val;
  struct Node *next;
} Node;

int main() {
  int n, m;
  printf("Enter the size of sparse matrix: ");
  scanf("%d %d", &n, &m);

  int spxMtx[n][m];

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      printf("[%d][%d]: ", i, j);
      scanf("%d", &spxMtx[i][j]);
    }
  }
  
  Node *head = (Node *)malloc(sizeof(Node));
  head->row = n;
  head->col = m;
  head->val = 0;
  head->next = NULL;

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) {
      if (spxMtx[i][j] != 0) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->row = i;
        newNode->col = j;
        newNode->val = spxMtx[i][j];
        newNode->next = NULL;

        Node *curr = head;
        while (curr->next != NULL) curr = curr->next;
        curr->next = newNode;

        ++(head->val);
      }
    }
  }

  Node *curr = head;
  printf("Sparse matrix in 3-tuple format\n");
  while (curr != NULL) {
    printf("%d %d %d\n", curr->row, curr->col, curr->val);
    curr = curr->next;
  }

  return 0;
}
