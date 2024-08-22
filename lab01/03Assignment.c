// Write a program to create a structure to store the information of n number of
// Employees. Employee’s information includes data members: Emp-id, Name,
// Designation, basic_salary, hra%, da%. Display the information of employees
// with gross salary. Use array of structure

#include "stdio.h"

typedef struct {
  char name[20], designation[20];
  int basic_salary, hra, da;
} Employee;

int main() {
  int n;
  printf("Enter the number of employees: ");
  scanf("%d", &n);

  Employee emps[n];

  for (int i=0; i<n; i++) {
    printf("Enter employee %d informations\n", i+1);
    scanf(" %[^\n]s", emps[i].name);
    scanf(" %[^\n]s", emps[i].designation);
    scanf("%d", &emps[i].basic_salary);
    scanf("%d%%", &emps[i].hra);
    scanf("%d%%", &emps[i].da);
  }

  for (int i=0; i<n; i++) {
    printf("Employee %d information\n\n", i+1);
    printf("Name: %s\n", emps[i].name);
    printf("Designation: %s\n", emps[i].designation);
    printf("Basic Salary: %d\n", emps[i].basic_salary);
    printf("HRA %%: %d%%\n", emps[i].hra);
    printf("DA %%: %d%%\n", emps[i].da);
    int gross_salary = emps[i].basic_salary +  emps[i].basic_salary * ((float)(emps[i].hra + emps[i].da) / 100.00);
    printf("Gross Salary: %d\n\n", gross_salary);
  }

  return 0;
}