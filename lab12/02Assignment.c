#include "stdio.h"
#include "stdlib.h"

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void maxHeapify(int arr[], int n, int i) {
  int left = (2*i) + 1, right = (2*i) + 2;
  int largest = i;

  if (left < n && arr[left] > arr[largest]) largest = left;
  if (right < n && arr[right] > arr[largest]) largest = right;

  if (largest != i) {
    swap(&arr[largest], &arr[i]);
    maxHeapify(arr, n, largest);
  }
}

void buildMaxHeap(int arr[], int n) {
  for (int i = (n/2)-1; i >= 0; i--) maxHeapify(arr, n, i);
}

void heapSort(int arr[], int n) {
  buildMaxHeap(arr, n);

  for (int k = n-1; k >= 0; k--) {
    swap(&arr[k], &arr[0]);
    maxHeapify(arr, k, 0);
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

  heapSort(arr, n);
  printf("Ascending Order: ");
  for (int i=0; i<n; i++) 
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
