#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
  char data;
  struct Node *left, *right;
} node_t;

// Function Prototypes
void preorder(node_t *);
void inorder(node_t *);
void postorder(node_t *);

// Preorder Binary Tree Traversal
void preorder(node_t *root)
{
  if (root == NULL)
    return;

  printf("%c ", root->data);
  preorder(root->left);
  preorder(root->right);
}

// Inorder Binary Tree Traversal
void inorder(node_t *root)
{
  if (root == NULL)
    return;

  inorder(root->left);
  printf("%c ", root->data);
  inorder(root->right);
}

// Postorder Binary Tree Traversal
void postorder(node_t *root)
{
  if (root == NULL)
    return;

  postorder(root->left);
  postorder(root->right);
  printf("%c ", root->data);
}