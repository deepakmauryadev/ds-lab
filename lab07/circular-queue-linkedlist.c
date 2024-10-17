#include "stdio.h"
#include "stdlib.h"

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef struct {
  Node *front;
} CQueue;

CQueue* createCQueue() {
  CQueue *q = (CQueue*)malloc(sizeof(CQueue));
  q->front = NULL;
  return q;
}

void enqueue(CQueue *q, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = newNode;

  if (q->front == NULL) q->front = newNode;
  else {
    Node *curr = q->front;
    while (curr->next != q->front) curr = curr->next;
    newNode->next = q->front;
    curr->next = newNode;
  }
}

int dequeue(CQueue *q) {
  int d;
  if (q->front == NULL) printf("Queue Underflow!\n");
  else {
    d = q->front->data;
    Node *temp = q->front, *curr = q->front;
    while (curr->next != q->front) curr = curr->next;
    curr->next = q->front->next;
    q->front = q->front->next;
    free(temp);
  }

  return d;
}

int isEmpty(CQueue *q) {
  return q->front == NULL;
}

void displayCQueue(CQueue *q) {
  Node *curr = q->front;
  while (curr->next != q->front) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("%d\n", curr->data);
}

int main() {
  CQueue *q = createCQueue();

  printf("\t\tMENU\n");
  printf("1. Enqueue\n");
  printf("2. Dequeue\n");
  printf("3. isEmpty\n");
  printf("4. Traverse\n");
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
        enqueue(q, elem);
        break;
      case 2:
        printf("%d deleted!\n", dequeue(q));
        break;
      case 3:
        printf("isEmpty: ");
        printf(isEmpty(q) ? "True" : "False");
        printf("\n");
        break;
      case 4:
        displayCQueue(q);
        break;
      default: 
        break;
    } 
  } while (choice != 5);

  return 0;
}
