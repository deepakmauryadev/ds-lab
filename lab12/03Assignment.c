#include "stdio.h"

int binarySearch(int arr[], int target, int start, int end) {
  if (start < end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] == target) return 1;
    else if (arr[mid] < target) return binarySearch(arr, target, start, mid);
    else return binarySearch(arr, target, mid+1, end);
  } else return 0;
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

  int target;
  printf("Enter element to search: ");
  scanf("%d", &target);

  if (binarySearch(arr, target, 0, n-1)) printf("Element found!\n");
  else printf("Element not found!\n");

  return 0;
}
