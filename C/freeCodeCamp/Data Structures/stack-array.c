#include <stdio.h>

#define MAX_SIZE 101

void push(int);
void pop();
int get_top();
void print();

int A[MAX_SIZE]; // array with size of 101 integers
int top = -1;    // empty array

void push(int x)
{
  if (top == MAX_SIZE - 1)
  {
    printf("Error: Stack overflow\n");
    return;
  }

  A[++top] = x;
}

void pop()
{
  if (top == -1)
  {
    printf("Error: No element to pop\n");
    return;
  }
  top--;
}

int get_top()
{
  return A[top];
}

void print()
{
  int i;

  printf("Stack: ");
  for (i = 0; i <= top; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int main()
{
  push(2);
  print();

  push(5);
  print();

  push(10);
  print();

  pop();
  print();

  push(12);
  print();
}