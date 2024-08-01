//  Write a program to read two numbers and compare the numbers using function
//  call by address.

#include "stdio.h"

void compare(int *a, int *b);

int main() {
  int a, b;
  printf("Enter two numbers: ");
  scanf("%d %d", &a, &b);

  compare(&a, &b);

  return 0;
}

void compare(int *a, int *b) {
  if (*a == *b)
    printf("Both numbers are same\n");
  else if (*a > *b)
    printf("%d is greater than %d\n", *a, *b);
  else
    printf("%d is smaller than %d\n", *a, *b);
}
