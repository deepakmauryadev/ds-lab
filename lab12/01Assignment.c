#include "stdio.h"

void merge(int arr[], int start, int mid, int end) {
  int n1 = mid - start + 1;
  int n2 = end - mid;

  int leftArr[n1], rightArr[n2];

  for (int i=0; i<n1; i++) leftArr[i] = arr[start + i];
  for (int i=0; i<n2; i++) rightArr[i] = arr[mid + 1 + i];

  int i1 = 0, i2 = 0, k = start;

  while (i1 < n1 && i2 < n2) {
    if (leftArr[i1] <= rightArr[i2]) arr[k++] = leftArr[i1++];
    else arr[k++] = rightArr[i2++];
  }

  while (i1 < n1) arr[k++] = leftArr[i1++];
  while (i2 < n1) arr[k++] = leftArr[i2++];
}

void mergeSort(int arr[], int start, int end) {
  if (start < end) {
    int mid = start + (end - start) / 2;  

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, start, mid, end);
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

  mergeSort(arr, 0, n-1);
  printf("Ascending Order: ");
  for (int i=0; i<n; i++) 
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
