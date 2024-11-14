#include "stdio.h"
#include "stdlib.h"

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSortAscending(int arr[], int n) {
  for (int i=0; i<n; i++) {
    int minIndex = i;
    for (int j=i; j<n; j++) 
      if (arr[j] < arr[minIndex]) minIndex = j;
    if (minIndex != i) swap(&arr[minIndex], &arr[i]);
  }
}

void selectionSortDescending(int arr[], int n) {
  for (int i=0; i<n; i++) {
    int maxIndex = i;
    for (int j=i; j<n; j++) 
      if (arr[j] > arr[maxIndex]) maxIndex = j;
    if (maxIndex != i) swap(&arr[maxIndex], &arr[i]);
  }
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

  selectionSortAscending(arr, n);
  printf("Ascending Order: ");
  for (int i=0; i<n; i++) 
    printf("%d ", arr[i]);
  printf("\n");

  selectionSortDescending(arr, n);
  printf("Descending Order: ");
  for (int i=0; i<n; i++) 
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
