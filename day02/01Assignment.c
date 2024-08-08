#include "stdio.h"

#define MAX 20

void insert(int arr[], int *n);
void delete_elem(int arr[], int *n);
void search(int arr[], int n);
void traverse(int arr[], int n);

int main() {
  int n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  int arr[MAX];
  printf("Enter the elements of the array\n");
  for (int i = 0; i < n; i++) {
    printf("%d: ", i);
    scanf("%d", &arr[i]);
  }

  int choice, exit;

  do {
    printf("\n***MENU***\n");
    printf("1. insert\n");
    printf("2. delete\n");
    printf("3. linear search\n");
    printf("4. traverse\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1: insert(arr, &n);
        break;
      case 2: delete_elem(arr, &n);
        break;
      case 3: search(arr, n);
        break;
      case 4: traverse(arr, n);
        break;
      default: printf("Invalid choice!\n");
        break;
    }

    printf("Do you want to continue: ");
    scanf("%d", &exit);
  } while (exit == 1);

}

void insert(int arr[], int *n) {
  int elem, pos;
  printf("Enter element: ");
  scanf("%d", &elem);
  printf("Enter position: ");
  scanf("%d", &pos);

  ++(*n);
  for (int i = *n-1; i >= pos; i--) arr[i] = arr[i-1];

  arr[pos-1] = elem;
}

void delete_elem(int arr[], int *n) {
  int pos;
  printf("Enter postion: ");
  scanf("%d", &pos);

  for (int i=pos-1; i < *n-1; i++) arr[i] = arr[i+1];
  --(*n);
}

void search(int arr[], int n) {
  int elem;
  printf("Enter element to search: ");
  scanf("%d", &elem);

  int i;
  for (i=0; i<n; i++) {
    if (arr[i] == elem) {
      printf("%d found on %d index\n", elem, i);
      break;
    }
  }
  if (i == n) {
    printf("%d not found in array\n", elem);
  }
}

void traverse(int arr[], int n) {
  for (int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}