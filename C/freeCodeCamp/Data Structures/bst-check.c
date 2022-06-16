#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct Node
{
  int data;
  struct Node *left, *right;
};
typedef struct Node node_t;

bool isSubtreeLesser(node_t *root, int value)
{
  if (root == NULL)
    return true;
  if (root->data <= value && isSubtreeLesser(root->left, value) && isSubtreeLesser(root->right, value))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isSubtreeGreater(node_t *root, int value)
{
  if (root == NULL)
    return true;
  if (root->data > value && isSubtreeGreater(root->left, value) && isSubtreeGreater(root->right, value))
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Check if a tree is a binary search tree
bool isBstUtil(node_t *root, int minVal, int maxVal)
{
  if (root == NULL)
    return true;

  // return true if BST, false otherwise
  if (root->data < minVal && root->data > maxVal && isBstUtil(root->left, minVal, root->data) && isBstUtil(root->right, root->data, maxVal))
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isBinarySearchTree(node_t *root)
{
  return isBstUtil(root, INT_MIN, INT_MAX);
}

int main()
{
  node_t *root = NULL;

  if (isBinarySearchTree(root))
  {
    printf("This is a binary search tree!");
  }
  else
  {
    printf("This is NOT a binary search tree");
  }
  return 0;
}