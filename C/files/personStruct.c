#include <stdio.h>

int main(void)
{
  struct Person
  {
    char firstName[25];
    // Write your code below
    char lastName[40];
    int age;
  };

  // Write your code below
  struct Person person1 = {"Ada", "Lovelace", 28};
  struct Person person2 = {"Marie", "Curie", 44};

  printf("Person 1 is %s %s and is %d years old.\n", person1.firstName, person1.lastName, person1.age);
  printf("Person 2 is %s %s and is %d years old.\n", person2.firstName, person2.lastName, person2.age);
}
