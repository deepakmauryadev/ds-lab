// WAP to represent the polynomial of single variable using 1-D array and
// perform the addition of two polynomial

#include "stdio.h"

typedef struct {
  int coeff, expo;
} Polynomial;

int main() {
  int n;
  printf("Enter maximum degree of x: ");
  scanf("%d", &n);

  Polynomial p1[n+1], p2[n+1], sum[n+1];

  printf("Enter polynomail-1\n");
  for (int i=0; i<n+1; i++) {
    printf("coeff of x^%d: ", i);
    scanf("%d", &p1[i].coeff);
    p1[i].expo = i;
  }

  printf("Enter polynomail-2\n");
  for (int i=0; i<n+1; i++) {
    printf("coeff of x^%d: ", i);
    scanf("%d", &p2[i].coeff);
    p2[i].expo = i;
  }

  for (int i=0; i<n+1; i++) {
    sum[i].expo = i;
    sum[i].coeff = p1[i].coeff + p2[i].coeff;
  }

  printf("Resultant polynomail: ");
  for (int i=0; i<n+1; i++) {
    printf("%dx^%d", sum[i].coeff, sum[i].expo);
    if (i != n) printf("+");
  }
  printf("\n");

  return 0;
}