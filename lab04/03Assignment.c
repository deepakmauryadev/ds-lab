#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
  int expo, coff;
  struct Node *next;
} Node;

void insertAtEnd(Node **head, int expo, int coff) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->expo = expo;
  newNode->coff = coff;

  if (*head == NULL) *head = newNode;
  else {
    Node *curr = *head;
    while (curr->next != NULL) curr = curr->next;
    curr->next = newNode;
  }
}

Node* addPolynomial(Node *poly1, Node *poly2) {
  Node *sum = NULL, *p1 = poly1, *p2 = poly2;

  while (p1 != NULL && p2 != NULL) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (p1->expo == p2->expo) {
      newNode->expo = p1->expo;
      newNode->coff = p1->coff + p2->coff;
      p1 = p1->next;
      p2 = p2->next;
    } else if (p1->expo > p2->expo) {
      newNode->expo = p1->expo;
      newNode->coff = p1->coff;
      p1 = p1->next;
    } else {
      newNode->expo = p2->expo;
      newNode->coff = p2->coff;
      p2 = p2->next;
    }
    if (sum == NULL) sum = newNode;
    else sum->next = newNode;

    return sum;
  }
  
}

int main() {
  Node *polynomail1 = NULL, *polynomail2 = NULL;
  int deg1, deg2;

  printf("Polynomial-1\n");
  printf("Enter max power of x: ");
  scanf("%d", &deg1);

  int coff;

  for (int i = deg1; i >= 0; i--) {
    printf("Enter cofficient of x^%d: ", i);
    scanf("%d", &coff);
    insertAtEnd(&polynomail1, i, coff);
  }

  printf("\nPolynomial-2\n");
  printf("Enter max power of x: ");
  scanf("%d", &deg2);

  for (int i = deg2; i >= 0; i--) {
    printf("Enter cofficient of x^%d: ", i);
    scanf("%d", &coff);
    insertAtEnd(&polynomail2, i, coff);
  }

  Node *sum = addPolynomial(polynomail1, polynomail2);

  Node *temp = sum;
  printf("The sum is: ");
  while (temp != NULL) {
    printf("%dx^%d", temp->coff, temp->expo);
    temp = temp->next;
    if (temp != NULL) printf("+");
  }
  printf("\n");
  
  return 0;
}