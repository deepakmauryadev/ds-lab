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
  printf("List is: ");
  while (curr != NULL) {
    printf("%d", curr->data);
    curr = curr->next;
    if (curr != NULL) printf(" -> ");
  }
  printf("\n");
}

void searchNode(Node *head, int key) {
  Node *curr = head;
  int i = 1;
  while (curr != NULL) {
    if (curr->data == key) {
      printf("%d found at node-%d\n", key, i);
      return;
    }
    curr = curr->next;
    i++;
  }
  printf("%d not found in the list\n", key);
}

void sortLL(Node **head) {
  Node *curr1 = *head;

  while (curr1 != NULL) {
    Node *curr2 = curr1->next;

    while (curr2 != NULL) {
      if (curr2->data < curr1->data) {
        int temp = curr1->data;
        curr1->data = curr2->data;
        curr2->data = temp;
      }

      curr2 = curr2->next;
    }
    curr1 = curr1->next;
  }
}

// void sortLLByNode(Node **head) {
//   Node *curr1 = *head, *prev1 = NULL, *next1 = NULL;

//   while (curr1->next != NULL) {
//     Node *curr2 = curr1->next, *prev2 = curr1, *next2 = NULL;
//     next1 = curr1->next;

//     while (curr2->next != NULL) {
//       next2 = curr2->next;

//       if (curr2->data < curr1->data) {
//         if (prev1 != NULL) prev1->next = curr2;

//         if (prev1 == curr2) curr2->next = curr1;
//         else curr2->next = next1;

//         if (prev1 != curr2) prev2->next = curr1;

//         curr1->next = next2;

//         if (curr1 == *head) *head = curr2;
//       }

//       prev2 = curr2;
//       curr2 = next2;
//     }

//     prev1 = curr1;
//     curr1 = next1;
//   }
  
// }

void reverseLL(Node **head) {
  Node *curr = *head, *prev = NULL, *next = NULL;

  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;

    prev = curr;
    curr = next;
  }
  *head = prev;
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
  printf("5. Search\n");
  printf("6. Sort\n");
  printf("7. Reverse\n");
  printf("8. Exit\n");

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
        countNodes(head);
        break;
      case 4:
        traverseLL(head);
        break;
      case 5:
        printf("Enter key to search: ");
        scanf("%d", &elem);
        searchNode(head, elem);
        break;
      case 6:
        sortLL(&head);
        printf("List sorted!\n");
        break;
      case 7:
        reverseLL(&head);
        printf("List reversed!\n");
        break;
      default:
        break;
    }
  } while (choice != 8);

  return 0;
}