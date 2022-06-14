#include <stdio.h>
#include <stdlib.h>

void reverse(struct Node *);

typedef struct Node
{
  int data;
  struct Node *next;
} node_t;

node_t *head;

void reverse(node_t *p)
{
  if (p->next == NULL)
  {
    head = p;
    return;
  }
  reverse(p->next);

  // executes after recursive call
  node_t *q = p->next;
  q->next = p;
  p->next = NULL;
}
