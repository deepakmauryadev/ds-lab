#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
  char data;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
} Stack;

Stack* createStack() {
  Stack *stk = (Stack *)malloc(sizeof(Stack)); 
  stk->head = NULL;
  return stk;
}

int isEmpty(Stack *stk) {
  return stk->head == NULL;
}

void push(Stack *stk, char data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (stk->head == NULL) {
    stk->head = newNode;
  } else {
    newNode->next = stk->head;
    stk->head = newNode;
  }
}

char pop(Stack *stk) {
  Node *temp = stk->head;
  int value = stk->head->data;

  stk->head = stk->head->next;
  free(temp);

  return value;
}

int peek(Stack *stk) {
  return stk->head->data;
}

int getPriority(char symbol) {
  switch (symbol) {
    case '^': return 3; break;
    case '/': return 2; break;
    case '*': return 2; break;
    case '-': return 1; break;
    case '+': return 1; break;
    default: return 0; break;
  }
}

int main() {
  Stack *stk = createStack();

  char infix[50], postfix[50];
  int k=0;

  printf("Enter infix expression: ");
  scanf("%s", infix);

  for (int i=0; infix[i] != '\0'; i++) {
    switch (infix[i]) {
      case '(':
        push(stk, infix[i]);
        break;
      case ')':
        while (peek(stk) != '(') postfix[k++] = pop(stk); // pop until (
        pop(stk); // pop ( from stack
        break;
      default:
        if (getPriority(infix[i]) > 0) {
          while (!isEmpty(stk) && (getPriority(peek(stk)) >= getPriority(infix[i]) || peek(stk) != '('))
            postfix[k++] = pop(stk);
          push(stk, infix[i]);
        } else {
          postfix[k++] = infix[i];
        }
        break;
    }
  }

  while (!isEmpty(stk)) {
    if (peek(stk) == '(') pop(stk);
    else postfix[k++] = pop(stk);
  }
  postfix[k] = '\0';

  printf("Postfix expression: %s\n", postfix);

  return 0;
}
