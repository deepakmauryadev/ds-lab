#include "stdio.h"

typedef struct {
  int emp_id;
  char emp_name[20];
} Employee;

int main() {
  int n;
  printf("Enter the number of employees: ");
  scanf("%d", &n);

  Employee e[n];

  for (int i=0; i<n; i++) {
    printf("Enter the details of employee %d\n", i+1);

    printf("Employee ID: ");
    scanf("%d", &e[i].emp_id);
    printf("Employee Name: ");
    scanf(" %[^\n]s", e[i].emp_name);
  }

  for (int i=0; i<n; i++) {
    printf("Details of employee %d\n", i+1);
    printf("Employee ID: %d\n", e[i].emp_id);
    printf("Employee Name: %s\n", e[i].emp_name);
  }
}