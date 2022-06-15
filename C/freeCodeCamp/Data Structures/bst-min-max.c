#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} node_t;

/* Function Signatures */

// Iterative search functions
int findMinIt(struct Node *);
int findMaxIt(struct Node *);

// Recursive search functions
int findMinRe(struct Node *);
int findMaxRe(struct Node *);

int findMinIt(node_t *root)
{
  if (root == NULL)
  {
    printf("Error: Tree is empty\n");
    return -1;
  }

  while (root->left != NULL)
  {
    root = root->left;
  }
  return root->data;
}

int findMaxIt(node_t *root)
{
  if (root == NULL)
  {
    printf("Error: Tree is empty\n");
    return -1;
  }

  while (root->right != NULL)
  {
    root = root->right;
  }
  return root->data;
}

int findMinRe(node_t *root)
{
  if (root == NULL)
  {
    printf("Error: Tree is empty\n");
    return -1;
  }
  else if (root->left == NULL)
  {
    return root->data;
  }
  // search in left subtree
  return findMinRe(root->left);
}

int findMaxRe(node_t *root)
{
  if (root == NULL)
  {
    printf("Error: Tree is empty\n");
    return -1;
  }
  else if (root->right == NULL)
  {
    return root->data;
  }
  // search in right subtree
  return findMaxRe(root->right);
}

int main()
{
  return 0;
}