#include "stdio.h"
#include "stdlib.h"

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void insertionSortAscending(int arr[], int n) {
  for (int i=1; i<n; i++)
    for (int j=i; arr[j] < arr[j-1] && j > 0; j--) 
      swap(&arr[j], &arr[j-1]);
}

void insertionSortDescending(int arr[], int n) {
  for (int i=1; i<n; i++)
    for (int j=i; arr[j] > arr[j-1] && j > 0; j--) 
      swap(&arr[j], &arr[j-1]);
}

int main() {
  int n;
  printf("Enter size of array: ");
  scanf("%d", &n);

  int arr[n];

  int x;
  for (int i=0; i<n; i++) {
    printf("%d: ", i);
    scanf("%d", &x);
    arr[i] = x;
  }

  insertionSortAscending(arr, n);
  printf("Ascending Order: ");
  for (int i=0; i<n; i++) 
    printf("%d ", arr[i]);
  printf("\n");

  insertionSortDescending(arr, n);
  printf("Descending Order: ");
  for (int i=0; i<n; i++) 
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
