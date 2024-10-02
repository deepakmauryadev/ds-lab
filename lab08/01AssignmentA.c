#include "stdio.h"
#include "stdlib.h"

typedef struct {
  int front, rear, size, *arr;
} Queue;

Queue* createQueue(int size) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->front = q->rear = -1;
  q->size = size;
  q->arr = (int *)malloc(size * sizeof(int));
  return q;
}

void enqueue(Queue *q, int data) {
  if (q->rear >= q->size-1) printf("Queue Overflow!\n");
  else if (q->rear == -1 && q->front == -1) {
    q->front = q->rear = 0;
    q->arr[q->rear] = data;
  } else q->arr[++(q->rear)] = data;
}

int dequeueFront(Queue *q) {
  int d;
  if (q->front == -1 && q->rear == -1) {
    d = -1;
    printf("Queue Underflow!\n");
  } else if (q->front == q->rear) {
    d = q->arr[q->rear];
    q->front = q->rear = -1;
  } else d = q->arr[(q->front)++];
  
  return d;
}

int dequeueRear(Queue *q) {
  int d;
  if (q->front == -1 && q->rear == -1) printf("Queue Underflow!\n");
  else if (q->front == q->rear) {
    d = q->arr[q->rear];
    q->front = q->rear = -1;
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
  printf("1. Insert at right\n");
  printf("2. Delete from left\n");
  printf("3. Delete from right.\n");
  printf("4. Display\n");
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
        printf("%d deleted!\n", dequeueFront(q));
        break;
      case 3:
        printf("%d deleted!\n", dequeueRear(q));
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
