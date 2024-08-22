## 1-D Array

### Inserting an elemeent at specific position in a given array

```c
#include "stdio.h"

#define MAX 20

int main() {
  int arr[MAX];
  int n;

  printf("Enter the no of elements: ");
  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }

  for (int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  int elem, pos;
  printf("Enter the element: ");
  scanf("%d", &elem);
  printf("Enter the position: ");
  scanf("%d", &pos);

  for (int i=n-1; i >= pos-1; i--) {
    arr[i] = arr[i+1];
  }
  arr[pos-1] = elem;
  ++n;

  for (int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
```

### Deleting element of an Array
```c
#include "stdio.h"

#define MAX 20

int main() {
  int arr[MAX];
  int n;

  printf("Enter the no of elements: ");
  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }

  for (int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  int pos;
  printf("Enter postion: ");
  scanf("%d", &pos);

  for (int i=pos; i<n-1; i--) {
    arr[i-1] = arr[i];
  }
  --n;

  for (int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
```

### Searching 
```c
#include "stdio.h"

#define MAX 20

int main() {
  int arr[MAX];
  int n;

  printf("Enter the no of elements: ");
  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d", &arr[i]);
  }

  for (int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

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

  for (int i=0; i<n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
````