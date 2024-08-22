#include "stdio.h"

struct student {
  int rollno;
  char name[20];
  float m1, m2, m3, tm;
};

void display_info(struct student s[], int n);

int main() {
  int n;
  printf("Enter the number of students: ");
  scanf("%d", &n);

  struct student s[n];

  for (int i = 0; i < n; i++) {
    printf("Enter details for student %d: ", i + 1);
    scanf("%d %s %f %f %f", &s[i].rollno, s[i].name, &s[i].m1, &s[i].m2, &s[i].m3);
    s[i].tm = s[i].m1 + s[i].m2 + s[i].m3;
  }

  display_info(s, n);

  return 0;
}

void display_info(struct student s[], int n) {
  for (int i = 0; i < n; i++) {
    printf("Student %d info\n", i + 1);
    printf("Roll no: %d\n", s[i].rollno);
    printf("Name: %s\n", s[i].name);
    printf("M1: %f\n", s[i].m1);
    printf("M2: %f\n", s[i].m2);
    printf("M3: %f\n", s[i].m3);
    printf("Total Marks: %f\n\n", s[i].tm);
  }
}