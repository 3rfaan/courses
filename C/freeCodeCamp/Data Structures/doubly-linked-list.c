#include <stdio.h>
#include <stdlib.h>

// function declarations
struct Node *get_new_node(int);

void insert_at_head(int);
void insert_at_tail(int);

void print();
void reverse_print();

// node
typedef struct Node
{
  int data;
  struct Node *prev;
  struct Node *next;
} node_t;

node_t *head; // global var - pointer to head node

node_t *get_new_node(int x)
{
  node_t *new_node = (node_t *)malloc(sizeof(node_t)); // pointer to newly allocated node in memory

  new_node->data = x;
  new_node->prev = NULL;
  new_node->next = NULL;

  return new_node;
}

// insert int at beginning of list
void insert_at_head(int x)
{
  node_t *new_node = get_new_node(x); // local variable to insert_at_head()

  if (head == NULL)
  {
    head = new_node;
    return;
  }
  head->prev = new_node;
  new_node->next = head;
  head = new_node;
}

// insert int at end of list
void insert_at_tail(int x)
{
  node_t *temp = head;
  node_t *new_node = get_new_node(x); // local variable to insert_at_tail()

  if (head == NULL)
  {
    head = new_node;
    return;
  }

  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = new_node;
  new_node->prev = temp;
}

void print()
{
  node_t *temp = head;

  printf("Forward: ");
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// print list in reverse order
void reverse_print()
{
  node_t *temp = head;

  if (temp == NULL)
    return; // empty list, exit

  // going to last node
  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  // traversing backwards using prev pointer
  printf("Reverse: ");
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->prev;
  }
  printf("\n");
}

int main()
{
  head = NULL; // empty list

  insert_at_head(2);
  print();
  reverse_print();

  insert_at_head(4);
  print();
  reverse_print();

  insert_at_head(6);
  print();
  reverse_print();

  insert_at_tail(0);
  print();
  reverse_print();
}