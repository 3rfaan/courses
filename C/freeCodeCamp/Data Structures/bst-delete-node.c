#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
  int data;
  struct Node *left, *right;
} node_t;

node_t *findMin(node_t *root)
{
  if (root == NULL)
    return root;

  while (root->left != NULL)
  {
    root = root->left;
  }
  return root;
}

node_t *del(node_t *root, int data)
{
  if (root == NULL)
    return root;
  if (data < root->data)
    root->left = del(root->left, data);
  if (data > root->data)
    root->right = del(root->right, data);
  else // Wohoo... I found you, get ready to be deleted!
  {
    // Case 1: No child
    if (root->left == NULL && root->right == NULL)
    {
      free(root);
      root = NULL;
    }
    // Case 2: One child
    else if (root->left == NULL)
    {
      node_t *temp = root;
      root = root->right;
      free(temp);
    }
    else if (root->right == NULL)
    {
      node_t *temp = root;
      root = root->left;
      free(temp);
    }
    // Case 3: Two children
    else
    {
      node_t *temp = findMin(root->right);
      root->data = temp->data;
      root->right = del(root->right, temp->data);
    }
  }
  return root;
}

int main()
{
  return 0;
}