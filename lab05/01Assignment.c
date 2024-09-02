#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
} Node;

Node* createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->next = NULL;
  newNode->prev = NULL;
  newNode->data = data;
  return newNode;
}

void insertAtEnd(Node **head, int data) {
  Node *newNode = createNode(data);

  if (*head == NULL) {
    *head = newNode;
  } else {
    Node *curr = *head;
    while (curr->next != NULL) curr = curr->next;
    newNode->prev = curr;
    curr->next = newNode;
  }
}

void insertAtPos(Node **head, int pos, int data) {
  Node *newNode = createNode(data);

  if (pos == 1) {
    newNode->prev = NULL;
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
  } else {
    Node *curr = *head;

    int i = 2;
    while (curr != NULL && i < pos) {
      curr = curr->next;
      ++i;
    }

    newNode->prev = curr;
    newNode->next = curr->next;
    if (curr->next != NULL) curr->next->prev = newNode;
    curr->next = newNode;
  }
}

void deleteAtPos(Node **head, int pos) {
  Node *curr = *head;

  if (pos == 1) {
    (*head)->next->prev = NULL;
    *head = (*head)->next;
  } else {
    int i = 1;
    while (curr != NULL && i < pos) {
      curr = curr->next;
      ++i;
    }
    curr->prev->next = curr->next;
    if (curr->next != NULL) curr->next->prev = curr->prev;
  }

  free(curr);
}

void traverseLL(Node *head) {
  Node *curr = head;
  while (curr != NULL) {
    printf("%d", curr->data);
    curr = curr->next;
    if (curr != NULL) printf(" -> ");
  }
  printf("\n");
}

int main() {
  Node *head = NULL;
  
  int n;
  printf("Enter number of nodes: ");
  scanf("%d", &n);

  printf("Enter the elements\n");
  int d;
  for (int i=0; i<n; i++) {
    printf("%d: ", i+1);
    scanf("%d", &d);
    insertAtEnd(&head, d);
  }

  printf("\n\tMENU\n");
  printf("1. Insert the node at a position\n");
  printf("2. Delete a node from specific position\n");
  printf("3. Traversal\n");
  printf("5. Exit\n");
  int choice;

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
        insertAtPos(&head, pos, elem);
        printf("Element inserted!\n");
        break;

      case 2:
        printf("Enter position: ");
        scanf("%d", &pos);
        deleteAtPos(&head, pos);
        printf("Element deleted!\n");
        break;

      case 3:
        printf("List is: ");
        traverseLL(head);
        break;

      default:
        break;
    }

  } while (choice != 5);

  return 0;
}