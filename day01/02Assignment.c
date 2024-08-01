// Write a program to create an array of n elements using dynamic memory
// allocation. Calculate sum of all the prime elements of the array using
// function and de-allocate the memoryof the array after its use.

#include "stdio.h"
#include "stdlib.h"

int check_prime(int a);
int sum_of_prime(int *p, int n);

int main() {
  int n;
  printf("Enter the size of array: ");
  scanf("%d", &n);

  int *p = (int *)malloc(n * sizeof(int));

  printf("Enter the elements of the array\n");
  for (int i = 0; i < n; i++) {
    printf("%d: ", i);
    scanf("%d", &p[i]);
  }

  int s = sum_of_prime(p, n);
  printf("Sum of the prime numbers are: %d\n", s);

  free(p);
  return 0;
}

int check_prime(int a) {
  if (a == 1)
    return 0;
  else if (a == 2)
    return 1;
  else {
    for (int i = 2; i <= a / 2; i++) {
      if (a % i == 0) return 0;
    }
    return 1;
  }
}

int sum_of_prime(int *p, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (check_prime(p[i]) == 1) {
      sum += p[i];
    }
  }

  return sum;
};