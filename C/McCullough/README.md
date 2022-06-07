# Advanced C Course by Joe McCullough

I found this amazing course on advanced C by Joe McCullough on YouTube and made some notes for myself. Feel free to share.

## Functions that return pointers

The function `return_me()` takes in an `int` and simply returns it. Then the `main()` function prints it.

```cpp
#include <stdio.h>

int return_me(int);

int main()
{
  int x = 10;
  printf("x: %d\n", x);

  x = return_me(x);
  printf("x: %d\n", x);

  return 0;
}

int return_me(int num)
{
  return num;
}
```

Now we want to transform the `return_me()` function so that it returns a pointer `*pint` which will then again get printed by the `main()` function.

```cpp
#include <stdio.h>

int *return_me(int *);

int main()
{
  int x = 10;
  int *p = &x; // memory address of x

  printf("p: %p\n", p);

  p = return_me(p); // returns a pointer
  printf("p: %p\n", p);

  return 0;
}

int *return_me(int *pint)
{
  return pint;
}
```

We will now write a function `biggest_float()` that checks two `float` pointers and compares them. Then it will `return` the bigger of the two. After that we call the `biggest_float()` function with two pointer parameters of type `float` and assign it to the pointer variable `*b` of type `float`.

```cpp
#include <stdio.h>

float *biggest_float(float *, float *);

int main()
{
  float x = 10.0;
  float y = 20.0;

  printf("y: %p\n", &y);

  float *b = biggest_float(&x, &y);

  printf("b: %p\n", b);

  return 0;
}

float *biggest_float(float *pfloat1, float *pfloat2)
{
  float *biggest;

  if (*pfloat1 > *pfloat2)
  {
    biggest = pfloat1;
  }
  else
  {
    biggest = pfloat2;
  }
  return biggest;
}
```

## The `void` Pointer (Generic Pointer)

A `void` pointer is a pointer of type `void` to which memory addresses of all types can be assigned to.

For example this will throw an error:

```cpp
float y = 20;
int *p = &y;
```

The type of the pointer variable `*p` which is `int` does not match with the type of the variable `y` which is `float`. Therefor we get an error.

This is the difference to a `void` pointer. It can accept any type.

```cpp
int x = 10;
float y = 20;
void *vp;

vp = &x;
vp = &y;
```

This program compiles without problems.

Another example:

```cpp
int x = 10;
int *pint;
void *vp;

vp = &x;
pint = vp;
```

In this demonstration we see a function signature like this:

```cpp
int *return_me(int *);
```

In the following program we replaced the `int` function return type with `void` and it still works exactly the same.

```cpp
#include <stdio.h>

void *return_me(int *);

int main()
{
  int x = 10;
  int *p = &x;

  printf("p: %p\n", p);

  p = return_me(p);
  printf("p: %p\n", p);

  return 0;
}

void *return_me(int *pint)
{
  return pint;
}
```

**To remember**:

- `void` pointer variables cannot be dereferenced!

```cpp
int x = 10;
int *p = &x;

*p = 15;
```

This is perfectly fine. We dereferenced the `*p` pointer variable to a value of 15. But the following code will fail at compile time:

```cpp
int x = 10;
void *vp = &x;

*vp = 15;
```

This would be a workaround:

```cpp
int x = 10;
void *vp = &x;

*(int *)vp = 15;
```

This will work because we casted the void pointer `*vp` to a pointer of type `int`.

Or we could also create a void pointer `*vp` then assign to it the memory address of `x`. After that we can assign the void pointer to a pointer variable of type `int`: `*pint`.

```cpp
int x = 10;
int *pint;
void *vp;

vp = &x;
pint = vp;
```

In this way, we can even dereference a pointer variable:

```cpp
int x = 10;
int *pint;
void *vp;

vp = &x;
pint = vp;
*pint = 20;
```

## `malloc()`

Here is how **NOT** to allocate memory:

```cpp
#include <stdio.h>

int *new_integer(void);

int main()
{
  int *p;
  p = new_integer();

  printf("Value of *p: %d\n", *p);

  return 0;
}

int *new_integer(void)
{
  int x = 10;

  return &x;
}
```

The above program compiles without errors. Yet it's not good practice to write like this. The value of `x` gets outputted as 10 but it might not always stay like this. It was declared locally in the `new_integer()` function and so it depends on the lifetime of this function. **This memory address could be overwritten anytime - we have no control over that!**

So we use `malloc()` to allocate memory and free it manually so we have full control over how memory gets allocated.

### Definition of `malloc()`

```cpp
void* malloc (size_t size);
```

> This function returns a pointer to a newly allocated block size bytes long, or a null pointer if the block could not be allocated.

We write the above program again but this time using `malloc()`:

```cpp
#include <stdio.h>
#include <stdlib.h>

int *new_integer(void);

int main()
{
  int *p;
  p = new_integer();
  *p = 15;

  printf("Value of *p: %d\n", *p);

  free(p);

  return 0;
}

int *new_integer(void)
{
  // int *p = malloc(sizeof(int));
  int *p = malloc(sizeof *p);
  return p;
}
```

## Pointers

A pointer is essentialy a memory address.

Let's look at the variable `x` and it's value 10. This value is stored as an `int` in memory. So free memory space is allocated to store this value.

```cpp
int x = 10;
```

To find out _where_ this variable is stored we can write:

```cpp
&x
```

This should return the memory address of where the variable `x` is stored.

But what if we wanted to store the output of `&x` and assign it to a variable? That's where pointers come into play.

```cpp
int *pointer = &x;
```

When we want to assign a memory address to a variable we have to use a pointer. A pointer is essentially a "data type" (in quotes!), to which memory addresses are assigned.

So here, the pointer variable `*pointer` hold a memory address in which a value of type `int` is stored.

Also possible:

```cpp
int *pointer;
pointer = &x;
```

The pointer variable `*pointer` holds the memory address of the variable `x`.

### Dereference

Now we have a pointer variable `*pointer` which _points_ to the memory address of variable `x`. What if we wanted to retrieve the value stored on this address?

We have to _dereference_ the pointer variable like so:

```cpp
*pointer
```

Dereferencing gets the value stored on the memory address the pointer refers to.

In a program all of the above parts would look like this:

```cpp
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x = 10;
  int *pointer;

  pointer = &x;

  printf("The value of x: %d\n", *pointer);
  printf("The address of x: %p\n", pointer);

  return 0;
}

/* Output:
The value of x: 10
The address of x: 0x16d60f488 */
```

If we dereference the address of a variable we get the address of that variable:

```cpp
*(&x) == x; // true
```

This outputs the value of variable `x`.

### Assign to Pointer Variable

We can assign new values to pointer variables by using the dereferenced pointer variable and assign it to a new value:

```cpp
int x = 10;
int *pointer = &x;

*pointer = 20;
```

We assigned to the `*pointer` variable a new value of 20. Now when we dereference `*pointer` we get the new value of 20.

**Note also: The value of `x` also becomes 20!**

This is because the `*pointer` variable just _points_ to the memory address of `x`. So when we change the value of `*pointer` we also change the value of `x`.

## Changing Function Argument Variables

When we have a variable `x` and the value of 10:

```cpp
int x = 10;
```

Now we want to change this value through a function `change_value()`:

```cpp
void change_value(int x)
{
  x = 15;
}
```

When we call this function in the `main()` function we expect that the value of `x` changes to 15.

```cpp
int main()
{
  int x = 10;
  printf("The value of x is: %d\n", x);
  change_value(x);
  printf("The value of x is: %d\n", x);

  return 0;
}
```

But the output is not as expected. We get two times the same value of 10.

Why is that? Let's check this by printing out the value of `x` inside the `main()` function and inside our `change_value()` function:

```cpp
#include <stdio.h>
#include <stdlib.h>

void change_value(int);

int main()
{
  int x = 10;

  printf("The address of x outside of fn: %p\n", &x);
  change_value(x);

  return 0;
}

void change_value(int x)
{
  x = 15;
  printf("The address of x inside of fn: %p\n", &x);
}

/*
Output:
The address of x outside of fn: 0x16f5bb478
The address of x inside of fn: 0x16f5bb44c
*/
```

As we can see the memory address of `x` inside our `change_value()` function is not the same as the address of `x` in the `main()` function. This is because functions create a copy of variables in different memory addresses.

---

So how can we pass the value of `x` to the function `change_value()` and then modify it? Through dereferencing!

Instead of passing the value of `x` this time we pass the _memory address_ of `x` and then use pointer dereferencing to assign a new value to the exact same memory address where our variable `x` is stored:

```cpp
#include <stdio.h>
#include <stdlib.h>

void change_value(int *);

int main()
{
  int x = 10;

  printf("The value of x: %d\n", x);
  change_value(&x);
  printf("The value of x after calling fn: %d\n", x);

  return 0;
}

void change_value(int *pointer)
{
  *pointer = 15; // *p = 15 -> *(&x) = 15 -> x = 15
}

/* Output:
The value of x: 10
The value of x after calling fn: 15
*/
```

As you can see, this is exactly what we wanted and expected.

## `argc` and `argv`

In our `main()` function we can pass arguments to it:

```cpp
int main(int argc, char *argv[]) {}
```

`argc` here stands for the count of arguments received by the `main()` function. The minimum is always 1 because when we run our program in the terminal

```bash
./add
```

Then this is regarded as the first argument.

So if we'd execute our program and pass it arguments like this:

```bash
./add arg1 arg2 arg3
```

Here the `argc` value would be 3.

To access these arguments in our program we can loop through them:

```cpp
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int i;

  printf("argc = %d\n", argc);
  printf("Let's see what is in argv[]\n");

  for (i = 0; i < argc; i++)
  {
    printf("argv[%d] = %s\n", i, argv[i]);
  }
}
```

Let's compile and run this program:

```bash
gcc mainArgs.c -o outputs/mainArgs
outputs/mainArgs test test2 test3
```

This will give us the following output:

```bash
argc = 4
Let's see what is in argv[]
argv[0] = outputs/mainArgs
argv[1] = test
argv[2] = test2
argv[3] = test3
```

## `typedef`

With `typedef` we can define an abbreviation for data types.

For the data type `unsigned long long` we could give a shortcut so we don't have to write out this long type all the time:

```cpp
typedef unsigned long long UINT64;
```

Now we can use this everywhere we'd normally use type `unsigned long long`:

```cpp
int main()
{
  UINT64 l = 14;
  printf("%llu\n", l);

  return 0;
}
```

### `typedef` on Structs

We can also define our Structs with the `typedef` keyword.

Let's assume we have this `struct`:

```cpp
struct Point {
  double x, y;
};
```

When we call an instance of `Point` we have to write the `struct` keyword every time like this:

```cpp
int main() {
  struct Point p;

  p.x = 0.24;
  p.y = 0.78;
  printf("%lf %lf\n" p.x, p.y);
}
```

We could use `typedef` to make life easier:

```cpp
typedef struct Point Point
```

We now gave our `struct` with the name `Point` a shortcut of `Point`. So now we can instantiate our `struct` like this:

```cpp
Point p;
p.x = 0.24;
p.y = 0.78;
```

Or this works also and saves some space:

```cpp
typedef struct Point {
  double x, y;
} Point;
```

There is also a library which takes care of `int` shortcuts:

```cpp
#include <stdint.h>

uint64_t l = 14;
```

## Multi-dimensional Arrays

If we have an array of words like the following:

```cpp
char array_of_words[] = "One\0Two\0Three";

printf("%s\n", array_of_words);

// Output: One
```

The output will be the string `One` because the `printf()` function exits at the _null termination character_ `\0`.

Now we can create a pointer to the memory address of the first element of `array_of_words[]`:

```cpp
char *pointer = array_of_words;

printf("%s\n", pointer);

// Output: One
```

Exactly the same output because the pointer just points to the memory address of our `array_of_words[]`.

If we wanted to print out the second word `Two` we have to move the pointer:

```cpp
printf("%s\n", (pointer + 4));

// Output: Two
```

Now we start printing at the memory address of `array_of_words[]` plus 4 bytes and exit at the null termination character after the word `Two`.

---

Let's now assume we wanted to print only a specific `char` of the array. We have to change the `printf()` function to print out a `char` instead of a `string`. Then we dereference the pointer to get the value.

```cpp
printf("%c\n", *(pointer + 8));

// Output: T
```

We successfully printed out the `char` **T** of the word `Three`.

Now let's print the `char` **r** in the word `Three`:

```cpp
printf("%c\n", *(pointer + 8 + 2));

// Output: r
```

We can also access elements using the array indexing syntax like this:

```cpp
char array_of_words[] = "One\0Two\0Three";

printf("%c\n", array_of_words[0]);

// Output: O
```

So these two syntaxes are alike and produce the same result:

```cpp
array_of_words[0]

*(array_of_words + 0)
```
