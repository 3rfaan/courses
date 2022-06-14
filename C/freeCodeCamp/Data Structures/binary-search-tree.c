#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} node_t;

node_t *get_new_node(int data)
{
  node_t *newNode = (node_t *)malloc(sizeof(node_t));

  newNode->data = data;
  newNode->left = newNode->right = NULL;

  return newNode;
}

node_t *insert(node_t *root, int data)
{
  // empty tree
  if (root == NULL)
  {
    root = get_new_node(data);
  }
  else if (data <= root->data)
  {
    root->left = insert(root->left, data);
  }
  else
  {
    root->right = insert(root->right, data);
  }
  return root;
}

bool search(node_t *root, int data)
{
  if (root == NULL)
  {
    return false;
  }
  else if (root->data == data)
  {
    return true;
  }
  else if (data <= root->data)
  {
    return search(root->left, data);
  }
  else
  {
    return search(root->right, data);
  }
}

int main()
{
  node_t *root = NULL; // pointer to address of root node
  int number;

  root = insert(root, 15);
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 25);
  root = insert(root, 8);
  root = insert(root, 12);

  printf("Enter number to be searched: ");
  scanf("%d", &number);

  if (search(root, number) == true)
  {
    printf("Found!\n");
  }
  else
  {
    printf("Not Found...\n");
  }

  return 0;
}