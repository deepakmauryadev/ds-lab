#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node * createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->next = NULL;
  newNode->data = data;

  return newNode;
}

void insertAtEnd(Node **head, int data) {
  Node *newNode = createNode(data);
  if (*head == NULL) 
    *head = newNode;
  else {
    Node *curr = *head;
    while (curr->next != NULL) curr = curr->next;
    curr->next = newNode;
  }
}

void insertAtPos(Node **head, int pos, int data) {
  Node *curr = *head;
  Node *newNode = createNode(data);

  int i = 1;
  while (curr != NULL && i < pos-1) {
    curr = curr->next;
    i++;
  }

  newNode->next = curr->next;
  curr->next = newNode;
}

void deleteAtPos(Node **head, int pos) {
  Node *curr = *head, *prev = NULL;

  int i = 1;
  while (curr != NULL && i < pos) {
    prev = curr;
    curr = curr->next;
    i++;
  }
  if (i == 1) *head = (*head)->next;
  else prev->next = curr->next;

  free(curr);
}

void countNodes(Node *head) {
  Node *curr = head;
  int count = 0;
  while (curr != NULL) {
    curr = curr->next;
    count++;
  }
  printf("Number of nodes: %d\n", count);
}

void traverseLL(Node *head) {
  Node *curr = head;
  while (curr != NULL) {
    printf("%d -> ", curr->data);
    curr = curr->next;
  }
  printf("NULL\n");
}

int main() {
  Node *head = NULL;

  int n;
  printf("Enter number of nodes: ");
  scanf("%d", &n);

  // int pointer d for cutting edge efficiency
  int *d = (int *)malloc(sizeof(int));
  for (int i=0; i<n; i++) {
    printf("%d: ", i+1);
    scanf("%d", d);
    insertAtEnd(&head, *d);
  }
  free(d);

  int choice;

  printf("\n\tMENU\n");
  printf("1. Insert a node at a position\n");
  printf("2. Delete a node from specific position\n");
  printf("3. Count nodes\n");
  printf("4. Traverse list\n");
  printf("5. Exit\n");

  do {
    printf("Enter your choice: ");
    scanf("%d", &choice);

    int elem, pos;

    switch (choice) {
      case 1:
        printf("Enter element: ");
        scanf("%d", &elem);
        printf("Enter position: ");
        scanf("%d", &pos);
        printf("\n");
        insertAtPos(&head, pos, elem);
        printf("Element inserted\n");
        break;
      case 2:
        printf("Enter position: ");
        scanf("%d", &pos);
        printf("\n");
        deleteAtPos(&head, pos);
        printf("Element deleted\n");
        break;
      case 3:
        printf("\n");
        countNodes(head);
        break;
      case 4:
        printf("\n");
        traverseLL(head);
        break;
      default:
        break;
    }
  } while (choice != 5);

  return 0;
}
