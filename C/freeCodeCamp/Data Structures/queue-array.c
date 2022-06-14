#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

int queue[SIZE]; // array with 10 integers

int front = -1; // front of empty queue
int rear = -1;  // rear of empty queue

bool IsEmpty()
{
  if (front == -1 && rear == -1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Enqueue(int x)
{
  if ((rear + 1) % SIZE == front)
  {
    return;
  }
  else if (IsEmpty())
  {
    front = 0;
    rear = 0;

    queue[rear] = x;
  }
  else
  {
    rear = (rear + 1) % SIZE;
    queue[rear] = x;
  }
}

void Dequeue()
{
  if (IsEmpty())
  {
    return;
  }
  else if (front == rear)
  {
    front = -1;
    rear = -1;
  }
  else
  {
    front = (front + 1) % SIZE;
  }
}

void Print()
{
  int i;

  if (IsEmpty())
  {
    printf(" \n Empty Queue\n");
  }
  else
  {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE)
    {
      printf("%d ", queue[i]);
    }
    printf("%d ", queue[i]);
    printf("\n Rear -> %d\n", rear);
  }
}

int Front()
{
  return queue[front];
}

int main()
{
  Enqueue(2);
  Enqueue(5);
  Enqueue(7);
  Dequeue();

  Enqueue(3);
  Enqueue(1);
  Enqueue(9);
  Enqueue(10);
  Enqueue(4);
  Enqueue(6);
  Dequeue();

  Enqueue(2);
  Enqueue(15);
  Dequeue();

  Enqueue(11);
  Enqueue(19);

  Print();

  return 0;
}