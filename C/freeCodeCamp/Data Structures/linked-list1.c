// Linked List: Inserting a node at the beginning
#include <stdlib.h>
#include <stdio.h>

void insert(int);
void print();

typedef struct Node
{
  int data;
  struct Node *next;
} node_t;

node_t *head; // global var

int main()
{
  int n, i, x;
  head = NULL; // empty list

  printf("How many numbers?\n");
  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    printf("Enter the number \n");
    scanf("%d", &x);
    insert(x);
    print();
  }
}

void insert(int x)
{
  node_t *temp = (node_t *)malloc(sizeof(node_t));

  temp->data = x;
  temp->next = head;
  head = temp;
}

void print()
{
  node_t *temp = head;

  printf("List is: ");
  while (temp != NULL)
  {
    printf(" %d", temp->data);
    temp = temp->next;
  }
  printf("\n");
}