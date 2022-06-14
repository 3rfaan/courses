// Linked List: Inserting a node at nth position
#include <stdlib.h>
#include <stdio.h>

void insert(int, int);
void delete (int);
void print();

typedef struct Node
{
  int data;
  struct Node *next;
} node_t;

node_t *head; // global var

void insert(int data, int n)
{
  node_t *temp1 = (node_t *)malloc(sizeof(node_t));
  temp1->data = data;
  temp1->next = NULL;

  if (n == 1)
  {
    temp1->next = head;
    head = temp1;
    return;
  }

  node_t *temp2 = head;

  int i;
  for (i = 0; i < n - 2; i++)
  {
    temp2 = temp2->next;
  }

  temp1->next = temp2->next;
  temp2->next = temp1;
}

void delete (int n)
{
  int i;
  node_t *temp1 = head;

  if (n == 1)
  {
    head = temp1->next;
    free(temp1);
  }

  for (i = 0; i < n - 2; i++)
  {
    temp1 = temp1->next; // temp1 points to (n-1)th node
  }

  node_t *temp2 = temp1->next; // nth node
  temp1->next = temp2->next;   // (n+1)th node
  free(temp2);                 // delete temp2
}

void print()
{
  node_t *temp = head;

  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main()
{
  int n;
  head = NULL; // empty list

  insert(2, 1); // List: 2
  insert(3, 2); // List: 2, 3
  insert(4, 1); // List: 4, 2, 3
  insert(5, 2); // List: 4, 5, 2, 3
  print();

  printf("Enter a position\n");
  scanf("%d", &n);
  delete (n);
  print();
}