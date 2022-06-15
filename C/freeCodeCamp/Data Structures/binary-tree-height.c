#include <stdlib.h>
#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};

int find_height(struct Node *root)
{
  if (root == NULL)
    return -1;

  return MAX(find_height(root->left), find_height(root->right)) + 1;
}

int main()
{
  return 0;
}