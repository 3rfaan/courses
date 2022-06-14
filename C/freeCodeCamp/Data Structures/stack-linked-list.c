#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *link;
} node_t;

node_t *top = NULL; // using top instead of head here for clarification

void push(int x)
{
  node_t *temp = (node_t *)malloc(sizeof(node_t));
  temp->data = x;
  temp->link = top;
  top = temp;
}

void pop()
{
  node_t *temp;

  if (top == NULL)
    return;
  temp = top;
  top = top->link;
  free(temp);
}