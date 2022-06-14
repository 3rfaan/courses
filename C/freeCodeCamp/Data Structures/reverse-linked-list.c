#include <stdlib.h>
#include <stdio.h>

struct Node *reverse(struct Node *);
struct Node *insert(struct Node *, int);
void print(struct Node *);

typedef struct Node
{
  int data;
  struct Node *next;
} node_t;

node_t *reverse(node_t *head)
{
  node_t *current, *prev, *next;
  current = head;
  prev = NULL;

  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
  return head;
}

node_t *insert(node_t *head, int data)
{
  node_t *temp = (node_t *)malloc(sizeof(node_t));
  temp->data = data;
  temp->next = NULL;

  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    node_t *temp1 = head;

    while (temp1->next != NULL)
    {
      temp1 = temp1->next;
    }
    temp1->next = temp;
  }
  return head;
}

void print(node_t *head)
{
  while (head != NULL)
  {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main()
{
  node_t *head = NULL;

  head = insert(head, 2);
  head = insert(head, 4);
  head = insert(head, 6);
  head = insert(head, 8);
  print(head);
  head = reverse(head);
  print(head);
}