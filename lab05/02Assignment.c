#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
  int data;
  struct Node *next;
} Node;

void insertAtEnd(Node **head, int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;

  if (*head == NULL) {
    newNode->next = newNode;
    *head = newNode;
  } else {
    Node *curr = *head;
    while (curr->next != *head) curr = curr->next;
    newNode->next = *head;
    curr->next = newNode;
  }
}

void traverseCLL(Node *head) {
  Node *curr = head;
  while (curr->next != head) {
    printf("%d -> ", curr->data);
    curr = curr->next;
  }
  printf("%d\n", curr->data);
}

int main() {
  Node *head = NULL;

  int n;
  printf("Enter number of nodes: ");
  scanf("%d", &n);

  int d;
  for (int i=0; i<n; i++) {
    printf("Node-%d: ", i+1);
    scanf("%d", &d);
    insertAtEnd(&head, d);
  }

  traverseCLL(head);

  return 0;
}
