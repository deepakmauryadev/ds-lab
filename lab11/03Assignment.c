#include "stdio.h"
#include "stdlib.h"

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partision(int arr[], int start, int end) {
  int pivot = arr[start];
  int i=start, j=end;

  while (i < j) {
    while (arr[i] <= pivot && i <= end-1) i++;
    while (arr[j] > pivot && j >= start+1) j--;

    if (i < j) swap(&arr[i], &arr[j]);
  }
  swap(&arr[start], &arr[j]);
  return j;
}

void quickSort(int arr[], int start, int end) {
  if (start < end) {
    int p = partision(arr, start, end);

    quickSort(arr, start, p-1);
    quickSort(arr, p+1, end);
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

  quickSort(arr, 0, n-1);
  printf("Ascending Order: ");
  for (int i=0; i<n; i++) 
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
