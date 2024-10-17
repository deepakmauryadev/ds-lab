#include "stdio.h"
#include "stdlib.h"

typedef struct node {
  int data, priority;
  struct node *next;
} Node;

typedef struct {
  Node *front;
} PQueue;

Node *createNode(int data, int priority) {
  Node *newNode = malloc(sizeof(Node));
  newNode->next = NULL;
  newNode->data = data;
  newNode->priority = priority;

  return newNode;
} 

PQueue* createPQueue() {
  PQueue *q = malloc(sizeof(PQueue));
  q->front = NULL;

  return q;
}

void enqueue(PQueue *q, int data, int priority) {
  Node *newNode = createNode(data, priority);

  if (q->front == NULL) q->front = newNode;
  else {
    Node *curr = q->front, *prev = NULL;
    while (curr != NULL && curr->priority < priority) {
      prev = curr;
      curr = curr->next;
    };
    
    if (curr == q->front) {
      newNode->next = q->front;
      q->front = newNode;
    } else {
      newNode->next = curr;
      prev->next = newNode;
    }
  }
}

int dequeue(PQueue *q) {
  int d;
  if (q->front == NULL) printf("Queue Underflow!\n");
  else {
    Node *temp = q->front;
    d = q->front->data;
    q->front = q->front->next;
    free(temp);
  }

  return d;
}

void displayPQueue(PQueue *q) {
  Node *curr = q->front;

  printf("Data\tPriority\n");
  while (curr != NULL) {
    printf("%d\t%d\n", curr->priority, curr->data);
    curr = curr->next;
  }
  printf("\n");
}

int main() {
  PQueue *q = createPQueue();

  printf("\t\tMENU\n");
  printf("1. Enqueue\n");
  printf("2. Dequeue\n");
  printf("3. Traverse\n");
  printf("4. Exit\n");

  int choice;
  do {
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int elem, prior;

    switch (choice) {
      case 1: 
        printf("Enter element: ");
        scanf("%d", &elem);
        printf("Enter priority: ");
        scanf("%d", &prior);
        enqueue(q, elem, prior);
        break;
      case 2:
        printf("%d deleted!\n", dequeue(q));
        break;
      case 3:
        displayPQueue(q);
        break;
      default: 
        break;
    } 
  } while (choice != 4);

  return 0;
}
