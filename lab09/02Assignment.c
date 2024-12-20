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

int findLargestNode(TreeNode *root) {
  if (root == NULL) return -1;
  if (root->right == NULL) return root->data;
  else return findLargestNode(root->right);
}

int findSmallestNode(TreeNode *root) {
  if (root == NULL) return -1;
  if (root->left == NULL) return root->data;
  else return findSmallestNode(root->left);
}

int heightOfNode(TreeNode *root, int target) {
  if (root == NULL) return 0;

  if (root->data == target) return 0;
  else if (target < root->data) return 1 + heightOfNode(root->left, target);
  else return 1 + heightOfNode(root->right, target);
} 

int noOfLeafNodes(TreeNode *root) {
  if (root == NULL) return 0;
  else if (root->left == NULL && root->right == NULL) return 1;
  else return noOfLeafNodes(root->left) + noOfLeafNodes(root->right); 
}

int main() {
  TreeNode *root = NULL;

  int option;

  printf("\n");
  printf("\tMENU\n");
  printf("1. Insert\n");
  printf("2. Display Largest element\n");
  printf("3. Display smallest element\n");
  printf("4. Height of a node\n");
  printf("5. Number of leaf nodes\n");
  printf("6. Exit\n");

  do {
    printf("Enter option: ");
    scanf("%d", &option);

    int elem;

    switch (option) {
      case 1:
        printf("Enter element: ");
        scanf("%d", &elem);
        root = insertNode(root, elem);
        break;

      case 2:
        printf("Larest element: %d\n", findLargestNode(root));
        break;

      case 3:
        printf("Smallest element: %d\n", findSmallestNode(root));
        break;

      case 4:
        printf("Enter element: ");
        scanf("%d", &elem);
        printf("Height of node %d is %d\n", elem, heightOfNode(root, elem));
        break;

      case 5:
        printf("No of leaf nodes: %d\n", noOfLeafNodes(root));
        break;

      default:
        break;
    }

  } while (option != 6);

  return 0;
}
