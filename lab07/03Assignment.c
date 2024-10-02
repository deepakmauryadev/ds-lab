#include "stdio.h"
#include "stdlib.h"

typedef struct {
  int front, rear, size, *arr;
} Queue;

Queue* createQueue(int size) {
  Queue *q = (Queue*)malloc(sizeof(Queue));
  q->front = q->rear = -1;
  q->size = size;
  q->arr = (int*)malloc(size * sizeof(int));

  return q;
}

int isEmpty(Queue *q) {
  return q->front == -1 && q->rear == -1;
}

int isFull(Queue *q) {
  return ((q->rear - q->front + q->size) % q->size) + 1 == q->size;
}

void enqueue(Queue *q, int data) {
  if (isFull(q)) printf("Queue Overflow!\n");
  else { 
    if (q->front == -1 && q->rear == -1) q->front = q->rear = 0;
    else if (q->rear == q->size-1 && q->front > 0) q->rear = 0;
    else q->rear++;

    q->arr[q->rear] = data;
  }
}

int dequeue(Queue *q) {
  int d;
  if (isEmpty(q)) printf("Queue Underflow!\n");
  else {
    d = q->arr[q->front];
    if (q->rear == q->front) q->front = q->rear = -1;
    else q->front = (q->front + 1) % q->size;
  }

  return d;
}

void displayQueue(Queue *q) {
  int i=q->front;
  while (1) {
    printf("%d ", q->arr[i]);
    if (i == q->rear) break;
    else i = (i+1) % q->size;
  }
  printf("\n");
}

int main() {
  int n;
  printf("Enter the size of queue: ");
  scanf("%d", &n);

  Queue *q = createQueue(n);

  printf("\t\tMENU\n");
  printf("1. Enqueue\n");
  printf("2. Dequeue\n");
  printf("3. isEmpty\n");
  printf("4. isFull\n");
  printf("5. Traverse\n");
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
        printf("isFull: ");
        printf(isFull(q) ? "True" : "False");
        printf("\n");
        break;
      case 5:
        displayQueue(q);
        break;
      default: 
        break;
    } 
  } while (choice != 6);

  return 0;
}
