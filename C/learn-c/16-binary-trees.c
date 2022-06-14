#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int val;
  struct node *left;
  struct node *right;
} node_t;

void insert(node_t *tree, int val);
void print_tree(node_t *current);
void printDFS(node_t *current);

int main()
{
  node_t *test_list = (node_t *)malloc(sizeof(node_t));
  /* set values explicitly, alternative would be calloc() */
  test_list->val = 0;
  test_list->left = NULL;
  test_list->right = NULL;

  insert(test_list, 5);
  insert(test_list, 8);
  insert(test_list, 4);
  insert(test_list, 3);

  printDFS(test_list);
  printf("\n");
}

void insert(node_t *tree, int val)
{
  if (tree->val == 0)
  {
    /* insert on current (empty) position */
    tree->val = val;
  }
  else
  {
    if (val < tree->val)
    {
      /* insert left */
      if (tree->left != NULL)
      {
        insert(tree->left, val);
      }
      else
      {
        tree->left = (node_t *)malloc(sizeof(node_t));
        /* set values explicitly, alternative would be calloc() */
        tree->left->val = val;
        tree->left->left = NULL;
        tree->left->right = NULL;
      }
    }
    else
    {
      if (val >= tree->val)
      {
        /* insert right */
        if (tree->right != NULL)
        {
          insert(tree->right, val);
        }
        else
        {
          tree->right = (node_t *)malloc(sizeof(node_t));
          /* set values explicitly, alternative would be calloc() */
          tree->right->val = val;
          tree->right->left = NULL;
          tree->right->right = NULL;
        }
      }
    }
  }
}

/* depth-first search */
void printDFS(node_t *current)
{
  /* change the code here */
  if (current == NULL)
    return; /* security measure */
  if (current != NULL)
    printf("%d ", current->val);
  if (current->left != NULL)
    printDFS(current->left);
  if (current->right != NULL)
    printDFS(current->right);
}