#include "stdio.h"
#include "stdlib.h"

typedef struct node {
  int data;
  struct node *next;
} Node;

typedef struct {
  Node *front;
} Queue;

Queue* createQueue() {
  Queue *q = (Queue*)malloc(sizeof(Queue));
  q->front = NULL;
  return q;
}

void enqueue(Queue *q, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (q->front == NULL) q->front = newNode;
  else {
    Node *curr = q->front;
    while (curr->next != NULL) curr = curr->next;
    curr->next = newNode;
  }
}

int dequeue(Queue *q) {
  int d;
  if (q->front == NULL) {
    d = -1;
    printf("Queue Underflow!\n");
  } else {
    d = q->front->data;
    Node *temp = q->front;
    q->front = q->front->next;
    free(temp);
  }

  return d;
}

int isEmpty(Queue *q) {
  return q->front == NULL;
}

void displayQueue(Queue *q) {
  Node *curr = q->front;
  while (curr != NULL) {
    printf("%d ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

int main() {
  Queue *q = createQueue();

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
        displayQueue(q);
        break;
      default: 
        break;
    } 
  } while (choice != 5);

  return 0;
}
