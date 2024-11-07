#include "stdio.h"
#include "stdlib.h"

typedef struct TreeNode {
  int data;
  struct TreeNode *left, *right;
} TreeNode;

TreeNode* createNode(int data) {
  TreeNode *node = malloc(sizeof(TreeNode));
  node->data = data;
  node->left = node->right = NULL;

  return node;
}

TreeNode* insertNode(TreeNode *root, int data) {
  if (root == NULL) root = createNode(data);

  else if (data <= root->data) 
    root->left = insertNode(root->left, data);
  else if (data > root->data) 
    root->right = insertNode(root->right, data);

  return root;
}

void preOrderTraverse(TreeNode *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
  }
}

void inOrderTraverse(TreeNode *root) {
  if (root != NULL) {
    inOrderTraverse(root->left);
    printf("%d ", root->data);
    inOrderTraverse(root->right);
  }
}

void postOrderTraverse(TreeNode *root) {
  if (root != NULL) {
    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    printf("%d ", root->data);
  }
}

int searchNode(TreeNode *root, int target) {
  if (root == NULL) return 0;
  if (target == root->data) return 1;

  else if (target < root->data) return searchNode(root->left, target);
  else return searchNode(root->right, target);
}

int main() {
  TreeNode *root = NULL;

  int n;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  int d;
  for (int i=0; i<n; i++) {
    printf("node-%d: ", i+1);
    scanf("%d", &d);
    root = insertNode(root, d);
  }

  int option;

  printf("\n");
  printf("\tMENU\n");
  printf("1. Preorder\n");
  printf("2. Postorder\n");
  printf("3. Inorder\n");
  printf("4. Search\n");
  printf("5. Exit\n");

  do {
    printf("Enter option: ");
    scanf("%d", &option);

    int target;

    switch (option) {
      case 1:
        preOrderTraverse(root);
        printf("\n");
        break;

      case 2:
        postOrderTraverse(root);
        printf("\n");
        break;

      case 3:
        inOrderTraverse(root);
        printf("\n");
        break;

      case 4:
        printf("Enter element to search: ");
        scanf("%d", &target);
        printf("Element found: ");
        printf(searchNode(root, target) ? "True" : "False");
        printf("\n");
        break;

      default:
        break;
    }

  } while (option != 5);

  return 0;
}
