#include <stdio.h>

typedef struct Person
{
  char *name;
  int age;
} person;

/* function declaration */
void birthday(person *p);

void birthday(person *p)
{
  p->age++;
}

int main()
{
  person john;
  john.name = "John";
  john.age = 27;

  printf("%s is %d years old.\n", john.name, john.age);
  birthday(&john);
  printf("Happy birthday! %s is now %d years old.\n", john.name, john.age);

  return 0;
}