#include "stdio.h"
#include "stdlib.h"

typedef struct {
  int top, capacity, *arr;
} Stack;

int isFull(Stack *stk) {
  return stk->top == stk->capacity -1;
}

int isEmpty(Stack *stk) {
  return stk->top == -1;
}

Stack* createStack(int size) {
  Stack *stk = (Stack *)malloc(sizeof(Stack));
  stk->top = -1;
  stk->capacity = size;
  stk->arr = (int *)malloc(size * sizeof(int));

  return stk;
}

void push(Stack *stk, int data) {
  if (isFull(stk)) printf("Stack overflow!\n");
  else stk->arr[++(stk->top)] = data;
}

int pop(Stack *stk) {
  if (isEmpty(stk)) {
    printf("Stack underflow!\n");
    return -1;
  } else return stk->arr[(stk->top)--];
}

void displayStack(Stack *stk) {
  if (isEmpty(stk)) printf("Stack empty!\n");
  else {
    for (int i=stk->top; i>=0; i--) printf("%d ", stk->arr[i]);
    printf("\n");
  }
}

int main() {
  Stack *stk = createStack(100);

  printf("\nMAIN MENU\n");
  printf("1. Push\n");
  printf("2. Pop\n");
  printf("3. IsEmpty\n");
  printf("4. IsFull\n");
  printf("5. Display the stack element\n");
  printf("6. Exit\n");

  int choice;

  do {
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int elem;

    switch (choice) {
      case 1:
        printf("Enter element: ");
        scanf("%d", &elem);
        push(stk, elem);
        printf("%d pushed into stack!\n", elem);
        break;
      case 2:
        printf("%d popped from stack!\n", pop(stk));
        break;
      case 3:
        printf("IsEmpty: ");
        printf(isEmpty(stk) ? "True" : "False");
        printf("\n");
        break;
      case 4:
        printf("IsFull: ");
        printf(isFull(stk) ? "True" : "False");
        printf("\n");
        break;
      case 5:
        printf("Stack is: ");
        displayStack(stk);
        break;
      default:
        break;
    }

  } while (choice != 6);

  return 0;
}
