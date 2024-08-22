// Sum of all the elements in the array using DMA

#include "stdio.h"
#include "stdlib.h"

int sum_array(int *p, int n);

int main() {
  int n;

  printf("Enter the size of array: ");
  scanf("%d", &n);

  int *p = (int *)malloc(n * sizeof(int));

  printf("Enter elements of the array\n");
  for (int i = 0; i < n; i++) {
    printf("%d: ", i);
    scanf("%d", &p[i]);
  }

  int s = sum_array(p, n);
  printf("Sum of the array is: %d\n", s);

  free(p);
  return 0;
}

int sum_array(int *p, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += p[i];
  }

  return sum;
}