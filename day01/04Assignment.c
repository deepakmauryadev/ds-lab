// Write a menu driven program to create a structure to represent complex number
// and perform the following operation using function

#include "stdio.h"

typedef struct {
  int a, b;
} Complex;

Complex add_complex(Complex x, Complex y);
Complex multiply_complex(Complex x, Complex y);

int main() {
  Complex n1, n2;
  printf("Enter complex number 1: ");
  scanf("%d %d", &n1.a, &n1.b);
  printf("Enter complex number 2: ");
  scanf("%d %d", &n2.a, &n2.b);

  int choice;
  printf("MENU\n");
  printf("1. Addition\n");
  printf("2. Multiplication\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  if (choice == 1) {
    Complex sum = add_complex(n1, n2);
    printf("Sum is %d+%di\n", sum.a, sum.b);
  } else if (choice == 2) {
    Complex mul = multiply_complex(n1, n2);
    printf("Product is %d+%di\n", mul.a, mul.b);
  }

  return 0;
}

Complex add_complex(Complex x, Complex y) {
  Complex sum;
  sum.a = x.a + y.a;
  sum.b = x.b + y.b;
  return sum;
};

Complex multiply_complex(Complex x, Complex y) {
  Complex product;
  product.a = x.a * y.a - x.b * y.b;
  product.b = x.a * y.b + x.b * y.a;
  return product;
}