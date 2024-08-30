#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
  int expo, coeff;
  struct Node *next;
} Node;

void insertAtEnd(Node **head, int expo, int coeff) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->expo = expo;
  newNode->coeff = coeff;
  newNode->next = NULL;

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
    newNode->next = NULL;
    
    if (p1->expo == p2->expo) {
      newNode->expo = p1->expo;
      newNode->coeff = p1->coeff + p2->coeff;
      p1 = p1->next;
      p2 = p2->next;
    } else if (p1->expo > p2->expo) {
      newNode->expo = p1->expo;
      newNode->coeff = p1->coeff;
      p1 = p1->next;
    } else if (p2->expo > p1->expo) {
      newNode->expo = p2->expo;
      newNode->coeff = p2->coeff;
      p2 = p2->next;
    }
    if (sum == NULL) sum = newNode;
    else {
      Node *temp = sum;
      while (temp->next != NULL) temp = temp->next;
      temp->next = newNode;
    }
  }

  return sum;
}

void displayPoly(Node *head) {
  Node *curr = head;
  while (curr != NULL) {
    printf("%dx^%d", curr->coeff, curr->expo);
    curr = curr->next;
    if (curr != NULL) printf("+");
  }
  printf("\n");
}

int main() {
  Node *poly1 = NULL, *poly2 = NULL;
  int deg1, deg2;

  printf("Polynomial-1\n");
  printf("Enter max power of x: ");
  scanf("%d", &deg1);

  int coff;

  for (int i = deg1; i >= 0; i--) {
    printf("Enter cofficient of x^%d: ", i);
    scanf("%d", &coff);
    insertAtEnd(&poly1, i, coff);
  }

  printf("\nPolynomial-2\n");
  printf("Enter max power of x: ");
  scanf("%d", &deg2);

  for (int i = deg2; i >= 0; i--) {
    printf("Enter cofficient of x^%d: ", i);
    scanf("%d", &coff);
    insertAtEnd(&poly2, i, coff);
  }

  Node *sum = addPolynomial(poly1, poly2);
  printf("The sum is: ");
  displayPoly(sum);

  return 0;
}