#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
  int data;
  struct Node *next;
} node_t;

node_t *front = NULL; // points to head of list
node_t *rear = NULL;  // points to tail of list

void enQueue(int x)
{
  node_t *temp = (node_t *)malloc(sizeof(node_t));

  temp->data = x;
  temp->next = NULL;

  if (front == NULL && rear == NULL)
  {
    front = rear = temp;
    return;
  }
  rear->next = temp;
  rear = temp;
}

void deQueue()
{
  node_t *temp = front;

  if (front == NULL)
    return;
  if (front == rear)
  {
    front = rear = NULL;
  }
  else
  {
    front = front->next;
  }
  free(temp);
}

void printQueue()
{
  node_t *temp = front;

  printf("\n Front -> %d", front->data);
  printf("\n Items -> ");
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n Rear -> %d", rear->data);
}

int main()
{
  enQueue(2);
  enQueue(4);
  enQueue(6);
  deQueue();

  enQueue(8);
  enQueue(10);
  enQueue(20);
  deQueue();

  printQueue();

  return 0;
}