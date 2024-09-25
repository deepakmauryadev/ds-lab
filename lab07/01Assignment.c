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

void enqueue(Queue *q, int data) {
  if (q->rear == q->size-1) printf("Queue Overflow!");
  else { 
    if (q->front == -1) q->front = 0;
    q->arr[++(q->rear)] = data;
  }
}

int dequeue(Queue *q) {
  int d;
  if (q->front == -1 && q->rear == -1) {
    d = -1;
    printf("Queue Underflow!");
  } else if (q->rear == q->front) {
    q->front = -1;
    d = q->arr[(q->rear)--];
  } else d = q->arr[(q->rear)--];

  return d;
}

int isEmpty(Queue *q) {
  return q->front == -1 && q->rear == -1;
}

int isFull(Queue *q) {
  return q->rear == q->size-1;
}

void displayQueue(Queue *q) {
  for (int i=q->front; i<=q->rear; i++) printf("%d ", q->arr[i]);
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

    switch (choice) {
      case 1: break;
      default: break;
    } 
  } while (choice != 6);

  return 0;
}
