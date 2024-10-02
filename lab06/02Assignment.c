#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
} Stack;

Stack* createStack() {
  Stack *stk = (Stack *)malloc(sizeof(Stack)); 
  stk->head = NULL;
  return stk;
}

int isEmpty(Stack *stk) {
  return stk->head == NULL;
}

void push(Stack *stk, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (stk->head == NULL) stk->head = newNode;
  else {
    newNode->next = stk->head;
    stk->head = newNode;
  }
}

int pop(Stack *stk) {
  if (isEmpty(stk)) {
    printf("Stack empty!\n");
    return -1;
  } else {
    Node *temp = stk->head;
    int value = stk->head->data;

    stk->head = stk->head->next;
    free(temp);

    return value;
  }
}

void displayStack(Stack *stk) {
  Node *curr = stk->head;
  while (curr != NULL) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

int main() {
  Stack *stk = createStack();

  printf("\nMAIN MENU\n");
  printf("1. Push\n");
  printf("2. Pop\n");
  printf("3. IsEmpty\n");
  printf("4. Display the stack element\n");
  printf("5. Exit\n");

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
        printf("Stack is: ");
        displayStack(stk);
        break;
      default:
        break;
    }

  } while (choice != 5);

  return 0;
}
