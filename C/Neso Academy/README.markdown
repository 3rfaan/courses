# Introduction

These are my notes on the **C Programming & Data Structures** course from **Neso Academy** which consists of 300+ videos concentrating on the C Programming Language and the most widely used Data Structures and Algorithms. _You can use these notes for your studies and share them among other students_.

## Reasons for programming in C

- Portability
- Easier to write than Assembly
- Less lines of code

# Features & The First C Program

## Features of C

- Procedural programming
- Middle level language (between high level and low level languages)
  - Direct access to memory through pointers
  - Bit manipulation using bitwise operators
  - Writing assembly code within C code
- Popular choice for system level apps
- Wide variety of built in functions, standard libraries and header files

## The First C Program

```c
// This program will print the output Neso Academy on the console windows

#include <stdio.h>
int main(void) {
  printf("Neso Academy");
  return 0;
}
```

### `#include <stdio.h>`

**Preprocessor:** Replaces text (starting with #) with the actual content.

- Replaces before the compilation begins
- Output of preprocessing is expanded source code

**`stdio.h`**: Standard input output file

- Header file
- Contains declarations (prototypes) of functions like `printf()`, `scanf()`, etc..

### Syntax of a Function

| Keyword     | Description                           |
| ----------- | ------------------------------------- |
| **int**     | Return type                           |
| **main**    | Name of the function                  |
| **void**    | Parameter type                        |
| **{ ... }** | Set of statements inside curly braces |

### Why Different Files?

**Header files**: Declaration of functions<br/>
**C Standard Library**: Actual definitions of functions

The _Linker_ which maps down the prototypes mentioned by the preprocessor to the actual code written in the standard library.

# Introduction to Variables

Variables are simply names that point to some memory locations.

## Declaration & Definition

Before using a variable, we have to _declare_ it.

**Declaration**: Announcing the properties of variable to the compiler.

**Properties**:

1. Size of the variable
2. Name of the variable

**Definition**: Allocating memory to a variable

Most of the time declaration and definition will be done at the same time.

### Example of Declaring a Variable

```c
int var;
```

| int | **Data type**: How much space a variable is going to occupy in memory. |
| --- | ---------------------------------------------------------------------- |
| var | **Name of variable**                                                   |

Semicolon `;` must be added at the end of the declaration!

## Initialization

If a value is assigned at the time of declaration, this is called **Initialization**:

```c
int var = 3;
```

A variable can vary over time and its value can be changed.

## Example

```c
#include <stdio.h>

int main() {
  int var = 3;
  var = 4;
  printf("%d", var);
  return 0;
}
```

Here we reassigned `var` of value 3 to a value of 4, then printed it using the standard library function `printf()`.

We can also assign a variable to the value of another value:

```c
#include <stdio.h>

int var1 = 3;
int var2;
var2 = var1;
printf("%d", var2);
return 0;
```

We assigned the value of `var1` (3) to the variable `var2`. This program prints out 3 to the console.

We can declare variables on a single line:

```c
int var1, var2, var3;
var1 = var2 = var3 = 4;
```

# Variable Naming Conventions

**Rule #1**: Don't start variable name with digit.

**Rule #2**: Begining with underscore is valid but not recommended.

**Rule #3**: C language is case sensitive. Uppercase are different from lowercase letters.

**Rule #4**: Special characters (@, #, %, ^, &, \*, ...) not allowed in the name of variable.

**Rule #5**: Blanks or white spaces not allowed.

**Rule #6**: Don't use keywords to name your variables.

- Cannot use `if`, `else`, `for`, `while`, `switch`, `int`, `float`, `long`, `double`, etc...

# Basic Output Function

## Recall these Code Snippets

```c
printf("Neso Academy"); // From Lecture 2
```

```c
printf("%d", var); // From Lecture 4
```

```c
printf("%d %d", var1, var2);
```

`%d` is a placeholder for variable.
"_d_" means decimal.

If there are more `%d` placeholders than arguments for `%d`, the program will throw an error.

```c
#include <stdio.h>

int main(void) {
  int two = 2, three = 3, six = 6;
  int result = (two + three) * six / three;

  printf("Arithmetic expression: (%d + %d) * %d / %d ", two, three, six, three);
  printf("and the result is: %d", result);

  return 0;
}
```

The program outputs:

```bash
Arithmetic expression: (2 + 3) * 6 / 3 and the result is: 10
```

# Fundamental Data Types - Integer

## Size of Integer

The size of an integer depends on the machine. It can either be 2 bytes (16 bits) or 4 bytes (32 bits).

## `sizeof` Operator

We can find out the size of an integer programmatically:

```c
printf("%d", sizeof(int));
```

**Note:** `sizeof` is a unary operator and not a function!

## Range

Range is the upper and lower limit of some set of data.

For example: {0,1,2,3,4} is **Range: 0 to 4**.

## Prerequisites

**Decimal Number System**: Human understandable number system. Also called as _base10_ number system.

Range: 0 to 9

For example the number **568** in the _base10_ system:

| 5      | 6      | 8      |
| ------ | ------ | ------ |
| $10^2$ | $10^1$ | $10^0$ |

This translates as:

$$10^2\times5+10^1\times6+10^0\times8=500+60+8=568$$

**Binary Number System**: Machine understandable number system. Also called as _base2_ number system.

Range: 0 to 1

For example the number **12** (1100) in the _base2_ system:

| 1     | 1     | 0     | 0     |
| ----- | ----- | ----- | ----- |
| $2^3$ | $2^2$ | $2^1$ | $2^0$ |

This can be written as:

$$2^3\times1+2^2\times1+2^1\times0+2^0\times0=8+4+0+0=12$$

## Range of 4-bit Data?

**4-bit data**:

Minimum value = 0 (0000)<br/>
Maximum value = 15 (1111)

**Range of 4-bit data**: 0 (0000) to 15 (1111)

Formula is:

$$2^n-1$$

## Range of Integer

If an integer in a system is 2 bytes (16 bits) then applying the above formula will result in:

**Unsigned range**: 0 to 65535 (2^16 - 1)

**Signed range**: -32768 to 32767<br/>
**2's complement range**:
$-(2^{n-1})$ to $(2^{n-1}-1)$

If the machine support 4 bytes (32 bits) then we have the following ranges:

**Unsigned range**: $0$ to $4294967295$ (by applying: $2^n-1$)

**Signed range**: $-2147483648$ to $2147483647$
