# C Programming Tutorial for Beginners

## Introduction

### Hello World!

```cpp
#include <stdio.h>

int main()
{
  printf("Hello world!\n");
  return 0;
}
```

```bash
gcc helloWorld.c -o helloWorld
```

### Constants

Variable that can't be modified.

```cpp
const int FAV_NUM = 7;
```

## Getting User Input

```cpp
int age;

printf("Enter your age: ");
scanf("%d", &age);
printf("You are %d years old.\n", age);
```

### String Input

When using `scanf()` you set the second parameter directly not with pointers!

```cpp
char name[20];

printf("Enter your name: ");
scanf("%s", name); // <- name is not a pointer!
printf("Your name is %s\n", name);
```

### `fgets()`

Import `fgets()`:

```cpp
#include <stdio.h>
```

```cpp
char name[20];
printf("Enter your name: ");
fgets(name)
printf("Your name is %s", name);
```

Using `fgets()` with parameters:

```cpp
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char name[20];

  printf("Enter your name: ");

  // Variable to store input in, amount of characters, standard input
  fgets(name, 20, stdin);
  printf("Your name is %s", name);
}
```

## Arrays

Initiate an array with type `int`:

```cpp
int luckyNumbers[] = {4, 8, 15, 16, 23, 42};
```

_or_

```cpp
int luckyNumbers[10];

luckyNumbers[0] = 4;
luckyNumbers[1] = 8;
// etc.
```

## Functions

Declare function of return type `void` and prints `hi!`:

```cpp
void sayHi()
{
  printf("hi!\n");
}
```

This won't print anything. We have to call it in `main()`:

```cpp
int main()
{
  sayHi();

  return 0;
}
```

### Function with parameters

```cpp
void sayHi(char name[], int age)
{
  printf("Hello %s, you are %d\n", name, age);
}
```

Then calling it like this in the `main()` function:

```cpp
sayHi("Mike", 40);
```

## Return Statements

Writing a function that will return a `double` value:

```cpp
double cube(double num)
{
  double result = num * num * num;
  return result;
}
```

### Prototype

Use a prototype to declare a function signature at the beginning of the code so that you can call from `main()` any function even if it's declared after the `main()` function.

```cpp
#include <stdio.h>
#include <stdlib.h>

double cube(double num);

int main()
{
  printf("Answer: %f\n", cube(3.0));
  return 0;
}

// The cube() function follows the main() function
double cube(double num)
{
  double result = num * num * num;
  return result;
}

// Output: 27.000000
```

## Conditions

### `if`, `else`, `else if`

```cpp
int max(int num1, int num2, int num3)
{
  int result;

  if (num1 >= num2 && num1 >= 3)
  {
    result = num1;
  }
  else if (num2 >= num1 && num2 >= num3)
  {
    result = num2;
  }
  else
  {
    result = num3;
  }

  return result;
}
```

### `switch` Statements

```cpp
char grade = 'A';

switch (grade)
{
  case 'A':
    printf("You did great! ");
    break;
  case 'B':
    printf("You did alright! ");
    break;
  case 'C':
    printf("You did poorly");
    break;
  case 'D':
    printf("You did very bad");
    break;
  case 'F':
    printf("You failed!");
    break;
  default:
    printf("Invalid Grade");
}
```

## Structs

A data structure where we can store groups of data types.

```cpp
struct Student
{
  char name[50];
  char major[50];
  int age;
  double gpa;
};
```

Create instance `student1` of `struct`:

```cpp
int main()
{
  struct Student student1;

  student1.age = 22;
  student1.gpa = 3.2;
  strcpy(student1.name, "Jim");
  strcpy(student1.major, "Business");

  printf("%f", student1.gpa);
}
```

And another instance `student2`:

```cpp
int main()
{
  struct Student student2;

  student2.age = 20;
  student2.gpa = 2.5;
  strcpy(student2.name, "Pam");
  strcpy(student2.major, "Art");

  printf("%f", student2.name);
}
```

## Loops

### `while` Loop

```cpp
int index = 1;

while(index <= 5)
{
  printf("%d\n", index);
  index++;
}
```

### `do while` Loop

```cpp
int index = 6;

do
{
  printf("%d\n", index);
  index++;
} while (index <= 5);

// Output: 6
```

### `for` Loop

```cpp
for (int i = 1; i <= 5; i++)
{
  printf("%d\n", i);
}
```

Use a `for` loop to loop through all elements inside an array:

```cpp
int luckyNumbers[] = {4, 8, 15, 16, 23, 42};
int arrsize = sizeof(luckyNumbers) / sizeof(int);

for (int i = 0; i < arrsize; i++)
{
  printf("%d\n", luckyNumbers[i]);
}
```

## 2D Arrays & Nested Loops

Array where elements in the array are also an array.

```cpp
int nums[3][2] = {
  {1, 2}, {3, 4}, {5, 6}
};
```

The `nums` array has 3 elements (arrays in it) which each have a length of 2.

### Accessing Elements

```cpp
printf("%d\n", nums[1][1]);

// Output: 4
```

### Nested `for` Loop

```cpp
int i, j;

for (i = 0; i < 3; i++)
{
  for (j = 0; j < 2; j++)
  {
    printf("%d,", nums[i][j]);
  }
  printf("\n");
}
```

## Memory Address

Variables are stored in memory so every variable has a specific address in memory or RAM.

```cpp
int age = 30;

printf("%p", &age);

// Output: 0060FF00
```

## Pointers

A pointer _points_ to the memory address of a variable.

```cpp
int age = 30;
int *pAge = &age;

double gpa = 3.4;
double *pGpa = &gpa;

char grade = 'A';
char *pGrade = &grade;
```

The pointer variable `*pAge` stores the memory address of the variable `age`.

### Dereferencing Pointers

When we dereference a pointer we go to that specific memory address and get the value stored on that address.

```cpp
int age = 30;
int pAge = &age;

printf("%p", pAge); // Output: memory address
printf("%d", *pAge); // Output: 30
```

The last `printf()` statement outputs the dereferenced pointer so we get the value stored on the address the pointer is _pointing_ to.

## Writing Files

We can change, modifiy and create new files in C.

To _create_ a new file or _override_ an existing one:

```cpp
  FILE *fpointer = fopen("employees.txt", "w");

  fprintf(fpointer, "Jim, Salesman\nPam, Receptionist\nOscar, Accounting");

  fclose(fpointer);
```

To _append_ to an existing file:

```cpp
FILE *fpointer = fopen("employees.txt", "a");

fprintf(fpointer, "\nKelly, Customer Service");
fclose(fpointer);
```

## Reading Files

```cpp
char line[255];

FILE *fpointer = fopen("employees.txt", "r");

fgets(line, 255, fpointer);
printf("%s", line);

// Output: Jim, Salesman (1st line of employees.txt)

```

Reads file line by line and prints the specific line.
