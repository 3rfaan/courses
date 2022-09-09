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

```
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

## Range of 4-bit Data

**4-bit data**:

Minimum value = 0 (0000)

Maximum value = 15 (1111)

**Range of 4-bit data**: 0 (0000) to 15 (1111)

Formula is:

$$2^n-1$$

## Range of Integer

### 2 Bytes

If an integer in a system is 2 bytes (16 bits) then applying the above formula will result in:

**Unsigned range**: 0 to 65535 $(2^{16}-1)$

**Signed range**: -32768 to 32767

**2's complement range**: $-(2^{n-1})$ to $(2^{n-1}-1)$

### 4 Bytes

If the machine support 4 bytes (32 bits) then we have the following ranges:

**Unsigned range**: 0 to 4294967295 (by applying: $2^{32}-1$)

**Signed range**: -2147483648 to 2147483647

**2's complement range**: $-(2^{n-1})$ to $(2^{n-1}-1)$

## `long` and `short`

If integer is 4 bytes, `short int` may be 2 bytes.

```c
printf("%d", sizeof(short int)); // Output: 2
```

If integer is 4 bytes, `long int` may be 8 bytes.

```c
printf("%d", sizeof(long int)); // Output: 8
```

What is _always_ guaranteed:

$$sizeof(short) <= sizeof(int) <= sizeof(long)$$

**Note**: By default, a variable declares as `int var_name` is a `signed` integer variable, while `unsigned int var_name` allows only positive values.

### Examples

#### Signed Integer

```c
#include <stdio.h>
#include <limits.h>

int main(void) {
  int var1 = INT_MIN;
  int var2 = INT_MAX;

  printf("Range of signed integer is from: %d to %d", var1, var2);
  return 0;
}
```

The output will be:

```
Range of signed integer is from: -2147483648 to 2147483647
```

The header file `limits.h` consists of some symbolic constants that are useful in determining the minimum as well as the maximum values of any data type according to the system.

#### Unsigned Integer

```c
#include <stdio.h>
#include <limits.h>

int main(void) {
  unsigned int var1 = 0;
  unsigned int var2 = UINT_MAX;

  printf("Range of unsigned integer is from: %u to %u", var1, var2);
  return 0;
}
```

The output will be:

```
Range of unsigned integer is from 0 to 4294967295
```

This will show the range of an `unsigned` integer.

#### Short Signed Integer

```c
#include <stdio.h>
#include <limits.h>

int main(void) {
  short int var1 = SHRT_MIN;
  short int var2 = SHRT_MAX;

  printf("Range of short signed integer is from: %d to %d", var1, var2);
  return 0;
}
```

The output will be:

```
Range of short signed integer is from -32768 to 32767
```

#### Short Unsigned Integer

```c
#include <stdio.h>
#include <limits.h>

int main(void) {
  unsigned short int var1 = 0;
  unsigned short int var2 = USHRT_MAX;

  printf("Range of short unsigned integer is from: %u to %u", var1, var2);
  return 0;
}
```

The output will be:

```
Range of short unsigned integer is from 0 to 65535
```

For `long` integers use in `printf()` the placeholder `%ld` and for `unsigned long` integers `%lu`.

### `long long` Integers

| Type            | Size    |
| --------------- | ------- |
| `long int`      | 4 bytes |
| `long long int` | 8 bytes |

The maximum limit is 8 bytes!

## Summary

1. `sizeof(short) <= sizeof(int) <= sizeof(long)`
2. Writing `signed int var_name` is equivalent to `int var_name`
3. `%d` is used to print `signed int`
4. `%u` is used to print `unsigned int`
5. `%ld` is used to print `long int` which is equivalent to `signed long int`
6. `%lu` is used to print `unsigned long int`
7. `%lld` is used to print `long long int`
8. `%llu` is used to print `unsigned long long int`

# Exceeding the Valid Range of Data Types

## Outline

1. Exceeding the unsigned range
2. Exceeding the signed range

## Example

The number **4294967295** is the maximum value for assigning to a `unsigned int` variable.

```c
#include <stdio.h>

int main(void) {
  unsigned int var = 4294967295;

  printf("%u", var);
  return 0;
}
```

The output will be:

```
4294967295
```

If we add 1 to the value of var the output will be **0**.

## 3-bit Unsigned Range

| $2^2$ | $2^1$ | $2^0$ | 3-bit |
| ----- | ----- | ----- | ----- |
| 0     | 0     | 0     | **0** |
| 0     | 0     | 1     | **1** |
| 0     | 1     | 0     | **2** |
| 0     | 1     | 1     | **3** |
| 1     | 0     | 0     | **4** |
| 1     | 0     | 1     | **5** |
| 1     | 1     | 0     | **6** |
| 1     | 1     | 1     | **7** |

If we wanted to represent the number **8**, the binary would be `1 0 0 0` but in a 3-bit range the 1 in `1 0 0 0` would not be considered which leaves the binary representation of `0 0 0` which equals **0**.
The same logic applies to **9** `1 0 0 1` -> `0 0 1` = **1** and every other following number.

The formula in the case of 3-bit representation is:

$$\mod 2^3$$

- 1 % 8 = 1
- 2 % 8 = 2
- 3 % 8 = 3
- ...
- 8 % 8 = 0
- 9 % 8 = 1

For 32-bit unsigned data

$$\mod 2^{32}$$

For n-bit unsigned data

$$\mod 2^n$$

## Signed-Unsigned Range Representation

In a 32-bit architecture the unsigned range is from **0** to **4294967295**.
If we exceed **4294967295** we start back at **0**.

In signed range of 32-bit it is from **-2147483648** to **2147483647**. So if we exceed **2147483647** we start again at **-2147483648**.

# Fundamental Data Types - Character

## Outline

1. Brief overview on character data type
2. Size of characters
3. Range of characters
4. Difference between signed and unsigned characters

## Overview

Binary representation of characters in the word **"HELLO!"**:

| Character | Binary     |
| --------- | ---------- |
| H         | `01001000` |
| E         | `01100101` |
| L         | `01101100` |
| L         | `01101100` |
| O         | `01101111` |
| !         | `00100001` |

The computer uses internally **ASCII** to encode characters from a decimal number which is represented in binary.

Here is how we declare and define a character variable:

```c
char var_name = 'A';
```

A character has to be surrounded by single quotes (`'`) and a `char` variable can only hold one character representing one byte.

We can also assign integer values to a `char` variable:

```c
#include <stdio.h>

int main(void) {
  char var = 65;

  printf("%c", var);
  return 0;
}
```

This will output:

```
A
```

Note that we use `%c` in the `printf()` function for characters.

## Size and Range of Character

**Size**: 1 byte = 8 bits

| U/S      | Range       |
| -------- | ----------- |
| Unsigned | 0 to 255    |
| Signed   | -128 to 127 |

## Signed vs Unsigned

In **2's complement** the most significant byte (on the far left) represents a negative value if the type is `signed`.

| №    | $-2^7$ | $2^6$ | $2^5$ | $2^4$ | $2^3$ | $2^2$ | $2^1$ | $2^0$ |
| ---- | ------ | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| -126 | 1      | 0     | 0     | 0     | 0     | 0     | 1     | 0     |
| -127 | 1      | 0     | 0     | 0     | 0     | 0     | 0     | 1     |
| -128 | 1      | 0     | 0     | 0     | 0     | 0     | 0     | 0     |

| №   | $2^7$ | $2^6$ | $2^5$ | $2^4$ | $2^3$ | $2^2$ | $2^1$ | $2^0$ |
| --- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 128 | 1     | 0     | 0     | 0     | 0     | 0     | 0     | 0     |
| 129 | 1     | 0     | 0     | 0     | 0     | 0     | 0     | 1     |
| 130 | 1     | 0     | 0     | 0     | 0     | 0     | 1     | 0     |

To represent the range of a character in binary:

| №   | $-2^7$ | $2^6$ | $2^5$ | $2^4$ | $2^3$ | $2^2$ | $2^1$ | $2^0$ |
| --- | ------ | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| -1  | 1      | 1     | 1     | 1     | 1     | 1     | 1     | 1     |

| №   | $2^7$ | $2^6$ | $2^5$ | $2^4$ | $2^3$ | $2^2$ | $2^1$ | $2^0$ |
| --- | ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| 255 | 1     | 1     | 1     | 1     | 1     | 1     | 1     | 1     |

```c
#include <stdio.h>

int main(void) {
  char var = 129;

  printf("%c", var);
  return 0;
}
```

The output will be:

```
ü
```

If we changed the value of `var` to be **-127** the output will be the same: `ü` because the binary representation of **-127** and **129** is exactly the same: `1000 0001`.

## Summary

1. Size of character = 1 bytes
2. Signed character range: -128 to 127
3. Unsigned character range: 0 to 255
4. Negative values won't buy you any additional powers
5. In traditional ASCII table, each character requires 7 bits
6. In extended ASCII table, each character utilize 8 bits

# Fundamental Data Types - Float, Double & Long Double

## Outline

1. `float`, `double`, `long double` - size and difference between them
2. Brief introduction to fixed and floating point
3. Coding examples

## Float, Double and Long Double

Used for representing fractional numbers.

E.g. **3.14**, **0.678**, **-3276.789**, **0.0000009999**, etc.

The size of these data types totally depends from system to system.

| Type          | Bytes | Bits | Representation                           |
| ------------- | ----- | ---- | ---------------------------------------- |
| `float`       | 4     | 32   | IEEE 754 Single Precision Floating Point |
| `double`      | 8     | 64   | IEEE 754 Double Precision Floating Point |
| `long double` | 12    | 96   | Extended Precision Floating Point        |

## Overview on Fixed and Floating Point

### Fixed Point Representation

Example:

| Sign | Integer | .   | Fraction | Fraction |
| ---- | ------- | --- | -------- | -------- |
| -    | 9       | .   | 9        | 9        |

Minimum value = **-9.99**<br/>
Maximum value = **+9.99**

The positions are fixed meaning if we want to represent a number like -7.9765 then in fixed point representation it would be -7.97 and .0065 gets truncated and removed, reducing the precision.

### Floating Point Representation

Example:

| Sign | Exponent | Exponent | Mantissa -> |
| ---- | -------- | -------- | ----------- |
| -    | +        | 9        | 9           |

Formula:

$$(0.M)\times Base^{Exponent}$$

Minimum value = -(0.9) \* 10<sup>+9</sup><br/>
Maximum value = +(0.9) \* 10<sup>+9</sup>

## Why Three Different Data Types?

> No more words. Let the code speak it out.

```c
#include <stdio.h>

int main(void) {
  float var1 = 3.1415926535897932;
  double var2 = 3.1415926535897932;
  long double var3 = 3.141592653589793213456;

  printf("%d\n", sizeof(float));
  printf("%d\n", sizeof(double));
  printf("%d\n", sizeof(long double));

  printf("%.16f\n", var1);
  printf("%.16f\n", var2);
  printf("%.21Lf\n", var3);
}
```

The output will be:

```
4
8
12
3.1415927410125732
3.1415926535897931
3.141592653589793213359
```

The statement `%.16f` determines that there will be 16 places after the comma when printing the float.

For `double` the actual format specified is `%lf`, but some compilers also accept `%f`, as in the example `%.16f`.

For `long double` it is important to use a capital L in the `printf()` parameter: `%Lf`.

`float` has 23 mantissa bits + 1 hidden bit, which is **7** decimal digits of precision:

$$log(2^{24})\div log(10) = 7.22$$

`double` has 52 mantissa bits + 1 hidden bit, which is **15** decimal digits of precision:

$$log(2^{53})\div log(10) = 15.95$$

```c
#include <stdio.h>

int main(void) {
  int var = 4/9;
  printf("%d\n", var);

  float var1 = 4/9;
  printf("%.2f\n", var1);

  float var2 = 4.0/9.0;
  printf("%.2f\n", var2);
}
```

The output will be:

```
0
0.00
0.44
```

The first output of **0** is, because we divide two integers (4 and 9) and define the type of `var` as `int`. So everything after the comma will be truncated.

The second output of **0.00** is, because we divide again two integers (4 and 9) which results in 0. But this time we defined the type of `var1` as `float`. So the result will be printed as `%.2f` which equals to **0.00**.

The third output is our desired result. As we divided two floats (4.0 and 9.0) and stored it in `var2` which is of type `float`.

# Important Questions Set 1

## Q1: What is the output of the following C program fragment?

```c
#include <stdio.h>

int main(void) {
  printf("%d", printf("%s", "Hello World!"));
  return 0;
}
```

- `%s` is used to print "string of characters".
- `printf()` not only prints the content on the screen. It also **returns the number of characters that it successfully prints on the screen.**

**Answer:**

```
Hello World!12
```

## Q2: What is the output of the following C program fragment?

```c
int main(void) {
  printf("%10s", "Hello");
  return 0;
}
```

**Answer:**

```
     Hello
```

By setting `%10s`, we define the width of the string to be printed. So we defined here a string that is 10 characters long. As the word _Hello_ is only 5 characters long, the rest of the 10 characters (5 characters) will get added on the beginning.

## Q3: What is the output of the following C program fragment?

```c
int main(void) {
  char c = 255;

  c = c + 10;
  printf("%d", c);
  return 0;
}
```

- a) 265
- b) Some character according to ASCII table
- c) 7
- **d) 9** ✅

## Q4: Which of the following statement(s) is/are correct corresponding to the definition of integer?

1. `signed int i`
2. `signed i`
3. `unsigned i`
4. `long i`
5. `long int i`
6. `long long i`

- a) Only 1 and 5 are correct
- b) Only 1 is correct
- **c) All are correct** ✅
- d) Only 4, 5, 6 are correct

## Q5: What does the following program fragment print?

```c
int main(void) {
  unsigned i = 1;
  int j = -4;

  printf("%u", i+j);
  return 0;
}
```

- a) Garbage
- b) -3
- **c) Integer value depends from machine to machine** ✅
- d) None of the above

**Answer:**

-3 in 2's complement representation:

- **Step 1**: Take 1's complement of 3
  - 3 = 00000000 00000000 00000000 00000011
  - 1's complement of 3 = 11111111 11111111 11111111 11111100
- **Step 2**: Add 1 bit to the result

  - 11111111 11111111 11111111 11111101 = **4294967293** (on my computer)

If we would use `%d` as a `printf()` statement, the result would have been **-3**.

# Scope of Variables - Local vs Global

## Outline

1. Defining scope of a variable
2. Local variable
3. Global variable

## Defining Scope

> Scope = Lifetime

The area under which a variable is applicable or _alive_.

**Strict definition:** A block or a region where a variable is _declared, defined and used_ and when a block or a region ends, the variable is automatically _destroyed_.

```c
#include <stdio.h>

int main(void) {
  int var = 34;

  printf("%d", var);
  return 0;
}

int fun(void) {
  printf("%d", var);
}
```

Scope of `var` is within the `main()` function only. Therefore called **local** to `main()` function.

Trying to access variable `var` outside `main()` function will result in an error:

```
error: 'var' undeclared (first use in this function)
```

## Basic Principle of Scoping

```c
{
  ... // Outer block
  {
    ... // Internal block
  }
}
```

Contents of outer block upto the beginning of internal block are visible to the **internal block**.

Contents of **internal block** are not visible to outer block.

```c
{
  ... // Block 1
}
{
  ... // Block 2
}
```

Contents of block 1 are not visible to any block outside of this block.<br/>
Contents of block 2 are not visible to any block outside of this block.

```c
#include <stdio.h>

int main(void) {
  int var = 3;
  int var = 4;

  printf("%d\n", var);
  printf("%d", var);
  return 0;
}
```

This program will produce an error because we defined `var` two times, which is not allowed:

```
error: redefinition of 'var'
```

---

```c
#include <stdio.h>

int main(void) {
  int var = 3;
  {
    int var = 4;
    printf("%d\n", var);
  }
  printf("%d", var);
  return 0;
}
```

There is **no error** in this code because `var` is declared in `main()` and in a seperate block internal to `main()`.

The output will be:

```
4
3
```

---

```c
#include <stdio.h>

int var = 10; // global variable

int main(void) {
  int var = 3;

  printf("%d\n", var);  // Output: 3
  fun();                // Output: 10
  return 0;
}

int fun(void) {
  printf("%d", var);
}
```

`var` is outside of all functions. Therefore called a **global** variable. So it is available to all functions in a program.

# Variable Modifiers

## Auto & Extern

### What is Auto Modifier?

**Auto** means **Automatic**.

Variables declared insisde a scope by default are automatic variables.

Syntax: `auto int var_name`

These two declarations of `var` are equal:

```c
#include <stdio.h>

int main(void) {
  int var;
  return 0;
}
```

```c
#include <stdio.h>

int main(void) {
  auto int var;
  return 0;
}
```

### Take Aways

1. If you won't initialize auto variable, by default it will be initialized with some garbage (random) value
2. On the other hand, **global variables** by default are initialized to 0

### What is Extern Modifier?

| Variable          | Description                | Meaning                                                                                                                   |
| ----------------- | -------------------------- | ------------------------------------------------------------------------------------------------------------------------- |
| `int var;`        | Declaration and Definition | Declaring type of `var` to be integer<br/>Definition means telling the compiler to allocate memory for the variable `var` |
| `extern int var;` | Declaration                | Only declaring type of `var` to be integer. No memory gets allocated.                                                     |

- `extern` is short name for external
- Used when a particular file needs to access a variable from another file

### Example

_main.c_

```c
#include <stdio.h>

extern int a;

int main(void) {
  printf("%d\n", a);
  return 0;
}
```

_other.c_

```c
int a = 5;
```

We can now compile the two files and give the program the name _test-program_:

```
gcc main.c other.c -o test-program
```

The output will be:

```
5
```

### Take Aways

1. When we write `extern type var_name;` no memory is allocated. Only property of variable is announced.
2. Multiple declarations of an extern variable is allowed within the same file. This is not the case with automatic variables.
3. Extern variable says to compiler _"go outside from my scope and you will find the definition of the variable that I declared"_.
4. Compiler believes that whatever the extern variable said is true and produces no error. Linker throws an error when it finds no such variable exists.
5. When an extern variable is _initialized_, then memory for this variable is allocated and it will be considered _defined_.

## Register

### What is Register Modifier?

Syntax: `register type var_name`

```c
#include <stdio.h>

int main(void) {
  register int var;
  return 0;
}
```

**The register keyword hints the compiler to store a variable in register memory.**

This is done because access time reduces greatly for most frequently referred variables.

This is the choice of compiler whether it puts the given variable in register or not.

Usually compiler themselves do the necessary optimizations.

## Static

To understand static variables we look at this program:

_main.c_

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int value;

  value = increment();
  value = increment();
  value = increment();

  printf("%d", value);
  return 0;
}
```

_add.c_

```c
int increment() {
  int count = 0;

  count = count + 1;
  return count;
}
```

We would expect the value **3**, but this is the actual output:

```
1
```

This is because everytime we call the function `increment()`, the variable `count` will be set back to **0** and the function will add **1** to `count`, which will always result in **1** being returned.

If we modify the code of file _add.c_, we can get the expected output:

```c
int count; // global variable, gets initialized to 0

int increment() {
  count = count + 1;
  return count;
}
```

The output will be as expected:

```
3
```

The value 3 is returned because the global variable `count` doesn't get destroyed after the functions lifecycle because it is _global_, outside any functions.

The disadvantage of using a global variable here is that the global variable is visible to all other files of the program. Sometimes we want a variable to be visible only to a file that is specific to that variable, so it can't be modified by other files.

To achieve this, we use the `static` keyword:

_add.c_

```c
static int count;

int increment() {
  count = count + 1;
  return count;
}
```

Now the variable `count` can be used by all functions INSIDE the file _add.c_ only, not by other files.

We can also declare `count` as a static variable local to the function `increment()` to retain its value even after finishing the function's life cycle:

```c
int increment() {
  static int count; // initialized with 0

  count = count + 1;
  return count;
}
```

Normally, uninitialized _local variables_ are automatically initialized with garbage values and _global variables_ are initialized with **0**. Now _local STATIC variables_ are also initialized with **0**.

Another important point to note is that we can initialize a static variable **only** with a constant value. For example:

````c
int increment() {
  static int count = 3;

  count = count + 1;
  return count;
}

The output would be:

```
6
````

But this would not be possible as the variable `var` is not constant:

```c
int increment() {
  int var = 3;
  static int count = var;

  count = count + 1;
  return count;
}
```

This will throw an error!

### Take Aways

1. Static variable remains in memory even if it is declared within a block on the other hand automatic variable is destroyed after the completion of the function in which it was declared.
2. Static variable if declared outside the scope of any function will act like a global variable but only within the file in which it is declared.
3. You can only assign a constant literal (or value) to a static variable.

# Constants in C

## What is a Constant?

As the name suggests - something that never changes

**Once defined, it cannot be modified later in the code.**

## Defining Constants

Using `#define` or using `const`.

### Using `#define`

**Syntax:** `#define NAME value` (Also called _Macro_)

Job of preprocessor (_not compiler_) to replace `NAME` with `value`.

```c
#include <stdio.h>
#define PI 3.14159

int main(void) {
  printf("%.5f", PI);
  return 0;
}
```

Output:

```
3.14159
```

#### Take Aways

1. Please don't add _semicolon_ at the end.
2. Choosing capital letters for `NAME` is good practice.
3. Whatever is inside double quotes won't get replaced.
4. We can use macros like functions. E. g. `#define add(x, y) x+y`
5. We can write multiple lines using `\`.
6. First expansion then evaluation.
7. Some predefined macros like `__DATE__`, `__TIME__` can print current date and time.

### Using `const`

**Syntax:** `const type var_name`

```c
#include <stdio.h>

int main(void) {
  const int var = 67;
  var = 57;

  printf("%d", var);
  return 0;
}
```

This will result in an error, as we cannot reassign the variable `var` to 57 as it is a constant.

# Important Questions Set 2

## Q1: What is the output of the following C program?

```c
int main(void) {
  int var = 052;

  printf("%d", var);
  return 0;
}
```

- a) 52
- b) 56
- **c) 42** ✅
- d) Compiler error

**Answer:**

When we place a zero (0) in front of any value, then that value is threated as an **octal value**, not a decimal value!

| $8^1$ | $8^0$ |
| ----- | ----- |
| 5     | 2     |

$$5\times8+2\times1=40+2=42$$

So 52 in octal representation is 42 in decimal representation.

If we used `printf("%o", var);`, then the result would have been **52**, as we printed out an octal value, not a decimal one.

## Q2: What is the output of the following C program?

```c
#include <stdio.h>

#define STRING "%s\n"
#define NESO "Welcome to Neso Academy!"

int main(void) {
  printf(STRING, NESO);
  return 0;
}
```

- a) Compiler error
- b) "Welcome to Neso Academy!"
- c) Garbage value
- **d) Welcome to Neso Academy!** ✅

# Basic Input Function - `scanf()`

## What is `scanf()` ?

Stands for **scan f**ormatted string

Accept character, string and numeric data from the user using standard input - _keyboard_.

`scanf()` also uses _format specifiers_ like `printf()`.

**For example:**

- `%d` to accept input of type integer.
- `%c` to accept input of type character.
- `%s` to accept a string

and so on...

## Example

```c
int var;

scanf("%d", &var);
```

### Why `&`?

While scanning the input, `scanf()` needs to store that input data somewhere.

To store this input data, `scanf()` needs to know the memory location of a variable.

`&` is also called as **address-of** operator.

> `&var` = Address of `var`

```c
#include <stdio.h>

int main(void) {
  int a, b;

  printf("Enter the first number\n");
  scanf("%d", &a);

  printf("Enter the second number\n");
  scanf("%d", &b);

  printf("%d + %d = %d", a, b, a + b);
  return 0;
}
```

The output will be:

```
$ Enter the first number
> 7
$ Enter the second number
> 7
$ 7 + 7 = 14
```

# Important Questions Set 3

## Q1: What is the output of the following C program fragment?

```c
#include <stdio.h>

int main(void) {
  int var = 0x43FF;

  printf("%x", var);
  return 0;
}
```

**Answer:**

```
43ff
```

The hexdecimal value will be printed directly as we use the specifier `%x` as an argument for `printf()`.

**Note:** 0x and 0X are the same and can be used interchangeably.

If we wanted the output to use uppercase letters we set the format specifier `%X` instead of `%x`:

```
43FF
```

## Q2: What is the output of the following C program fragment?

```c
#include <stdio.h>

static int i;
static int i = 27;
static int i;

int main(void) {
  static int i;

  printf("%d", i);
  return 0;
}
```

- a) 27
- **b) 0** ✅
- c) No output
- d) None of the above

### Memory Layout of a C Program

Two memory segments:

- Text/code segment
- Data sagment
  - Initialized
    - Read only
    - Read write
  - Uninitialized (bss - Block started by symbol)
  - Stack
  - Heap

| Segment            | Description                                                                     |
| ------------------ | ------------------------------------------------------------------------------- |
| Text/code segment  | Contains machine code of the compiled program                                   |
| Initialized data   | Global, extern, static (both local and global), const global variables          |
| Uninitialized data | Uninitialized global, static (both local and global), constant global variables |

The answer is **0** because the local variable `static int i;` gets prefered over the global variable `static int i;`. As it is uninitialized it gets the value 0 automatically as it is a static variable.

# Introduction to Operators in C

Operators are the foundation of any programming language.

| Operation             | Operator               |
| --------------------- | ---------------------- |
| $15\times10$          | _Arithmetic operator_. |
| $3000 >= 5000$        | _Relational operator_. |
| `if (chair && table)` | _Logical operator_     |

## Types of Operators in C

| Name of Operators             | Operators                                                          |
| ----------------------------- | ------------------------------------------------------------------ |
| Arithmetic operators          | `+`, `-`, `*`, `/`, `%`                                            |
| Increment/Decrement operators | `++`, `--`                                                         |
| Relational operators          | `==`, `!=`, `<=`, `>=`, `<`, `>`                                   |
| Logical operators             | `&&`, `\|\|`, `!`                                                  |
| Bitwise operators             | `&`, `^`, `\|`, `~`, `>>`, `<<`                                    |
| Assignment operators          | `=`, `+=`, `-=`, `*=`, `/=`, `%=`, `<<=`, `>>=`, `&=`, `^=`, `\|=` |
| Other operators               | `?:`, `&`, `*`, `sizeof()`, `,`                                    |

### Arithmetic Operators

| Operator | Operation      |
| -------- | -------------- |
| `+`      | Addition       |
| `-`      | Subtraction    |
| `*`      | Multiplication |
| `/`      | Division       |
| `%`      | Modulus        |

All are _binary operators_ which means **two operands** are required to perform operation.

**Example:** $A+B$

```c
#include <stdio.h>

int main(void) {
  int a, b;

  printf("Enter the first number\n");
  scanf("%d", &a);
  printf("Enter the second number\n");
  scanf("%d", &b);

  printf("a / b = %d\n", a/b);
  printf("a %% b = %d", a%b);
  return 0;
}
```

The output will be:

```
$ Enter the first number
> 9
$ Enter the second number
> 3
$ a / b = 3
$ a % b = 0
```

#### Operator Precedence and Associativity

| Precedence | Operators     | Associativity |
| ---------- | ------------- | ------------- |
| Highest    | `*`, `/`, `%` | Left to right |
| Lowest     | `+`, `-`      | Left to right |

**Note:** Associativity is used only when two or more operators are of same precedence.

**Example:** `+`, `-`

_Same precedence_ therefore we _use associativity_.

#### Example

```c
#include <stdio.h>

int main(void) {
  int a = 2, b = 3, c = 4, d = 5;

  printf("a * b / c = %d\n", a*b/c);
  printf("a + b - c = %d\n", a+b-c);
  printf("a + b * d - c %% a = %d", a+b*d-c%a);
  return 0;
}
```

The output will be:

```
$ a * b / c = 1
$ a + b - c = 1
$ a + b * d - c % a = 17
```

The last operation will be evaluated as follows:

$$a+b\times d-c\mod a = a+(b\times d)-(c\mod a) = a+(3\times5)-(4\mod2)$$

So:

$$2+15-0=17$$

## Increment and Decrement Operators in C

### What are Increment and Decrement Operators?

- **Increment operator** is used to increment the value of a variable by one. Similarly, **decrement operator** is used to decrement the value of a variable by one.
- Both are unary operators.
  - because they are applied on single operand.
    - `a++;` ✅
    - `a ++ a;` ❌

**Increment**

```c
int a = 5;
a++;
```

`a` is now 6.

**Decrement**

```c
int a = 5;
a--;
```

`a` is now 4

`a++;` is the same as `a = a + 1;`

`a--;` is the same as `a = a - 1;`

### Pre- and Post Increment/Decrement

| Pre-increment operator | Post-increment operator |
| ---------------------- | ----------------------- |
| `++a;`                 | `a++;`                  |

| Pre-decrement operator | Post-decrement operator |
| ---------------------- | ----------------------- |
| `--a;`                 | `a--;`                  |

You cannot use **rvalue** before or after increment/decrement operator.

- `(a + b)++;` ❌
- `++(a + b);` ❌

**lvalue (left value):** Simply means an object that has an identifiable location in memory (i.e. having an address).

- In any assignment statement _lvalue_ must have the capability to hold the data.
- _lvalue_ **must be a variable** because they have the capability to store the data.
- _lvalue_ cannot be a function, expression (like `a+b`) or a constant (like 3, 4, etc.).

**rvalue (right value):** Simply means an objec that has no identifiable location in memory.

- Anything which is capable of returning a constant expression or value.
- Expressions like `a + b` will return some constant value.

`a++;` is the same as `a = a + 1;`

So `(a+b)++;` is equal to: `(a+b) = (a+b) + 1;` which is completly wrong!

**Question:** What is the difference between pre-increment and post-increment operator OR pre-decrement and post-decrement operator?

**Pre -** means first increment/decrement, then assign it to another variable.

**Post -** means first assign it to another variable, then increment/decrement.

If we suppose that variable `int a = 5;` and we have the following statements:

- `x = ++a;`, then `x` is equal to **6**, as the increment happens before the assignment.
- `x = a++;`, then `x` is equal to **5**, as the assignment happens before the increment.

### Questions

#### Q1: What is the output of the following C program fragment?

```c
#include <stdio.h>

int main(void) {
  int a = 4, b = 3;

  printf("%d", a+++b);
  return 0;
}
```

##### Token Generation

- Lexical analysis is the first phase in the compilation process.
- Lexical analyzer (scanner) scans the whole source program and when it finds the meaningful sequence of characters (lexemes) then it converts it into a token.
- **Token:** Lexemes mapped into token-name and attribute-value.
  - **Example:** int -> <keywoard, int>
- It always matches the longest character sequence.

The tokens of the statement `a+++b` will be the following:

| a   | ++  | +   | b   |
| --- | --- | --- | --- |

Or: `a++ + b`

Now we can review an important topic:

**Post increment/decrement in context of equation:** First use the value in the equation and then increment the value.

**Pre increment/decrement in context of equation:** First increment the value and then use it in the equation after completion of the equation.

When `a = 4` and `b = 3` then the operation would be:

`4 + 3` which equals **7**. So **7** will be the ouput of the program.

#### Q2: What is the output of the following C program fragment?

```c
#include <stdio.h>

int main(void) {
  int a = 4, b = 3;

  printf("%d", a + ++b);
  return 0;
}
```

The tokens of `a + ++b` will be:

| a   | +   | ++  | b   |
| --- | --- | --- | --- |

If `a = 4` and `b = 3` then we must increment the value of `b` first and then complete the equation, making `b` equals 4.

`4 + 4` which equals **8**, so **8** will be the output.

#### Q3: What is the output of the following C program fragment?

```c
#include <stdio.h>

int main(void) {
  int a = 4, b = 3;

  printf("%d", a+++++b);
  return 0;
}
```

- a) 7
- b) 8
- c) 9
- **d) Error** ✅

## Relational Operators in C

| Operator | Description              |
| -------- | ------------------------ |
| `==`     | Equal to                 |
| `!=`     | Not equal to             |
| `<=`     | Less than or equal to    |
| `>=`     | Greater than or equal to |
| `<`      | Less than                |
| `>`      | Greater than             |

**Used for comparing values.**

- All relational operators will return either `true` or `false`.
  - `4 == 5` is equivalent to _is 4 equal to 5?_ - Answer: `false`
  - `4 != 5` is equivalent to _is 4 not equal to 5?_ - Answer: `true`

```c
int a = 300, b = 2090;

if (b >= a) {
  printf("Bingo! You are in");
} else {
  printf("OOPS! You are out");
}
```

Output:

```
Bingo! You are in
```

## Logical Operators in C

| Operator | Description |
| -------- | ----------- |
| `&&`     | AND         |
| `\|\|`   | OR          |
| `!`      | NOT         |

- `&&` and `||` are used to combine two conditions.
  - `&&` returns `true` when _all_ conditions under consideration are true and returns `false` when any one or more than one condition is false.
  - `||` returns `true` when _one or more than one_ condition under consideration is true and returns `false` when all conditions are false.
- `!` operator is used to complement the condition under consideration.
  - `!` returns `true` when condition is **false** and returns `false` when condition is **true**.

### Concept of Short Circuit in Logical Operators

**Short circuit in case of `&&`:** Simply means if there is a condition anywhere in the expression that returns `false`, then the rest of the conditions after that will not be evaluated.

```c
#include <stdio.h>

int main(void) {
  int a = 5, b = 3;
  int incr;

  incr = (a < b) && (b++);
  printf("%d\n", incr);
  printf("%d", b);
  return 0;
}
```

- `false` = 0
- `true` = 1

As `(a < b)` is `false`, therefore `(b++)` will not be evaluated.

The output will be:

```
0
3
```

---

```c
#include <stdio.h>

int main(void) {
  int a = 5, b = 3;
  int incr;

  incr = (a > b) && (b++);
  printf("%d\n", incr);
  printf("%d", b);
  return 0;
}
```

As `(a > b)` is `true` and `(b++)` returns a value greater than 0, `incr` is `true` which will be printed as **1**. Also, `(b++)` is evaluated, so `b` will be incremented.

```
1
4
```

**Short circuit in case of `||`:** Simply means if there is a condition anywhere in the expression that returns `true`, then the rest of the conditions after that will not be evaluated.

```c
#include <stdio.h>

int main(void) {
  int a = 5, b = 3;
  int incr;

  incr = (a > b) || (b++);
  printf("%d\n", incr);
  printf("%d", b);
  return 0;
}
```

As `(a > b)` returns `true`, the second part of the `||` (OR) operand `(b++)` will not be evaluated.

So the output will be:

```
1
3
```

## Bitwise Operators in C

### Outline

- Introducing bitwise operators.
- Bitwise OR, AND, NOT
- Difference between bitwise and logical operators.

### Introduction to Bitwise Operators

As the name suggests - **it does bitwise manipulation**.

| Operator | Description |
| -------- | ----------- |
| `&`      | AND         |
| `\|`     | OR          |
| `^`      | XOR         |
| `~`      | NOT         |
| `<<`     | Left shift  |
| `>>`     | Right shift |

#### Bitwise AND (`&`) Operator

- It takes two bits at a time and performs AND operation.
- AND (`&`) is a binary operator. It takes two numbers and performs bitwise AND.
- Result of AND is 1 when both bits are 1.

**Example:** `7 & 4`

7 -> `0 1 1 1`

4 -> `0 1 0 0`

`0 1 1 1 & 0 1 0 0 = 0 1 0 0`

So: `7 & 4 = 4`

##### Truth Table

| A   | B   | A & B |
| --- | --- | ----- |
| 0   | 0   | 0     |
| 0   | 1   | 0     |
| 1   | 0   | 0     |
| 1   | 1   | 1     |

#### Bitwise OR (`|`) Operator

- It takes two bits at a time and performs OR operation.
- OR (`|`) is a binary operator. It takes two numbers and performs bitwise OR.
- Result of OR is 0 when both bits are 0.

**Example:** `7 | 4`

7 -> `0 1 1 1`

4 -> `0 1 0 0`

`0 1 1 1 | 0 1 0 0 = 0 1 1 1`

So: `7 | 4 = 7`

##### Truth Table

| A   | B   | A \| B |
| --- | --- | ------ |
| 0   | 0   | 0      |
| 0   | 1   | 1      |
| 1   | 0   | 1      |
| 1   | 1   | 1      |

#### Bitwise NOT (`~`) Operator

- NOT is a unary operator.
- Its job is to complement each bit one by one.
- Result of NOT is 0 when bit is 1 and 1 when bit is 0.

**Example:** `~7`

7 -> `0 1 1 1`

`~0 1 1 1 = 1 0 0 0`

So: `~7 = 8`

##### Truth Table

| A   | ~A  |
| --- | --- |
| 0   | 1   |
| 1   | 0   |

### Difference between Bitwise and Logical Operators

```c
#include <stdio.h>

int main(void) {
  char x = 1, y = 2; // x = 1 (0000 0001), y = 2 (0000 0010)

  if (x & y)  // 1 & 2 = 0 (0000 0000)
    printf("Result of x & y is 1");
  if (x && y) // 1 && 2 = TRUE && TRUE = TRUE = 1
    printf("Result of x && y is 1");

  return 0;
}
```

Only the second `if` statement will get satisfied, because `x & y` will evaluate to 0, thus will not be printed. But `x && y` will evaluate to 1 so it will get printed:

```
Result of x && y is 1
```

### Left Shift Operator

| First operand               | `<<` | Second operand                                 |
| --------------------------- | ---- | ---------------------------------------------- |
| Whose bits get left shifted |      | Decides the number of places to shift the bits |

#### Important Points

1. When bits are shifted left then trailing positions are filled with zeros.
2. Left shifting is equivalent to **multiplication** by $2^{rightOperand}$.

##### How Left Shift Works?

Let's suppose we have a variable with a value of 3, `int var = 3;`. We will do a left shift by 1 position, `var << 1`.

In binary, 3 is `0000 0011`. So we have to left shift all digits by one and replace trailing positions with 0:

`0000 0110`

and this is the binary representation of the number **6**.

This could also be solved mathematically by using above formula:

$$2^{rightOperand}$$

or in this case:

$$3\times2^1=6$$

If we wanted to left shift by 4 positions, `var << 4`, then we would use the following equation:

$$3\times2^4=48$$

### Right Shift Operator

| First operand                | `>>` | Second operand                             |
| ---------------------------- | ---- | ------------------------------------------ |
| Whose bits get right shifted |      | Decides number of places to shift the bits |

#### Important Points

1. When bits are shifted right then leading positions are filled with zeros.
2. Right shifting is equivalent to **division** by $2^{rightOperand}$.

##### How Right Shift Works?

Again we have a variable with the value of 3: `int var = 3;`. We want to right shift the bits by one: `var >> 1`.

In binary, 3 is `0000 0011`. So we right shift all digits by one and replace leading positions with 0:

`0000 0001`

and this is the binary representation of the number **1**.

In mathematical terms:

$$3\div2^1=1$$

If we had `var = 32` and `var >> 4` then:

$$32\div2^4=2$$

## Assignment Operators in C

### Outline

- Introduction to assignment operators.
- Shorthand assignment operators.
- Homework problem.

### Assignment Operator

Values to a variable can be assigned using **assignment operator**.

Requires two values - _lvalue_ and _rvalue_.

This operator copies _rvalue_ to _lvalue_:

| `var`  | `=`                | `5;`   |
| ------ | ------------------ | ------ |
| lvalue | Assigment operator | rvalue |

### Shorthand Assignment Operators

| Operator | Description                          |
| -------- | ------------------------------------ |
| `+=`     | First addition then assignment       |
| `-=`     | First substraction then assignment   |
| `*=`     | First multiplication then assignment |
| `/=`     | First division then assignment       |

Assignment operator is having **least precedence** except the comma operator.

**Example:** `a += 1` is equivalent to `a = a + 1`

Similar concept for other shorthand assignment operators as well.

| Operator | Description                               |
| -------- | ----------------------------------------- |
| `%=`     | First modulus then assignment             |
| `<<=`    | First bitwise left shift then assignment  |
| `>>=`    | First bitwise right shift then assignment |
| `&=`     | First bitwise AND then assignment         |
| `\|=`    | First bitwise OR then assignment          |
| `^=`     | First bitwise XOR then assignment         |

### Homework Problem

What is the output of the following program segment?

```c
#include <stdio.h>

int main(void) {
  char a = 7;

  a ^= 5;
  printf("%d", printf("%d", a += 3));
  return 0;
}
```

- a) 5
- b) 6
- **c) 51** ✅
- d) 15

**Answer:**

7 -> `0000 0111`

5 -> `0000 0101`

a = 7 ^ 5 = `0000 0111 ^ 0000 0101` = `0000 0010` = 2

a = 2 + 3 = 5 (inner `printf()`)

Outer `printf()` will print **1** as the inner one printed only one character. So the output will be:

```
51
```

## Conditional Operator in C

### Outline

- Introduction to conditional operator.
- Quick facts.
- Homework problem.

### Introduction to Conditional Operator

**Look and feel:** `? :`

Instead of writing this:

```c
char result;
int marks;

if (marks > 33) {
  result = 'p';
} else {
  result = 'f';
}
```

We can compress it into one line:

```c
char result;
int marks;

result = (marks > 33) ? 'p' : 'f';
```

Let's take it apart:

`(marks > 33)` is a boolean expression, therefore it will return either `true` or `false`.

`(marks > 33) ? 'p' : 'f'` is a conditional expression, which is after all an expression, therefore it is an _rvalue_ and **result** is _lvalue_.

### Quick Facts Checklist

- Conditional operator is the only **ternary operator** available in the list of operators in C language.
- As in `expression1 ? expression2 : expression3`, `expression1` is the boolean expression. If we simply write 0 instead of some boolean expression then that simply means `false` and therefore `expression3` will get evaluated.
  - **Example:** `result = 0 ? 2 : 1`, `result` will be 1.

### Homework Problem

What is the output of the following C program fragment?

```c
#include <stdio.h>

int main(void) {
  int var = 75;
  int var2 = 56;
  int num;

  num = sizeof(var) ? (var2 > 23 ? ((var == 75) ? 'A' : 0) : 0) : 0;

  printf("%d", num);
  return 0;
}
```

**Answer:**

1. The first condition `sizeof(var)` returns how many bytes a data type can hold (for integer either 2 or 4 bytes), so it evaluates to true as every number except 0 is evaluated to be true.

2. The next condition `(var2 > 23)` will evaluate to be true as `var2` is 56 and therefore bigger than 23.

3. Because so far everything evaluated to be true the last condition is being checked: `(var == 75)`. As `var` is indeed 75, also the last condition is true and therefore the expression assigns `'A'` to the variable `num` of type integer.

As we specified a data specifier of `%d` (int) in `printf()` and `num` is of type `int`, we need to convert the ASCII character `'A'` to its equilavent decimal value, which is 65.

So the output will be:

```
65
```

## Comma Operator in C

### Comma (`,`) Operator

1. Comma operator can be used as a "separator".

```c
int a = 3;
int b = 4;
int c = 8;
```

is equivalent to:

```c
int a = 3, b = 4, c = 8;
```

2. Comma operator can be used as an "operator".

```c
int a = (3, 4, 8);

printf("%d", a);
```

Output: `8`

**Comma operator** returns the _rightmost_ operand in the expression and it simply evaluates _the rest of the operands_ and finally reject them.

```c
int var = (printf("%s\n", "HELLO"), 5);

printf("%d", var);
```

The output will be:

```
HELLO!
5
```

This is because 5 will get assigned to `var` as it is the rightmost operand, but the `printf()` expression will be evaluated too, before the value 5 will be returned to `var`.

3. Comma operator is having **least precedence** among all the operators available in C language.

```c
int a;

a = 3, 4, 8;
printf("%d", a);
```

We would think that 8 is returned to `a`, but this is wrong. Because _assignment operator_ (`=`) has higher precedence than _comma operator_. The above code would look like this if we added brackets:

```c
int a;

(a = 3), 4, 8;
printf("%d", a);
```

The output will be:

```
3
```

---

```c
int a = 3, 4, 8;

printf("%d", a);
```

When we initialize `a` with comma operator then here comma is behaving like a _seperator_.

Comma operator acts like a separator within function calls and definitions, variable declarations and enum declarations.

So `int a = 3, 4, 8;` is equivalent to `int a = 3; int 4; int 8;` which will throw an error as we can not start variable names with digits.

```c
int a;

a = (3, 4, 8);
printf("%d", a);
```

_Bracket_ has the highest precedence than any other operator.

Or we could also write:

```c
int a = (3, 4, 8);
printf("%d", a);
```

The output will be:

```
8
```

### Homework Problem

What is the output of the following C program fragment?

```c
#include <stdio.h>

int main(void) {
  int var;
  int num;

  num = (var = 15, var + 35);
  printf("%d", num);
  return 0;
}
```

- a) 15
- **b) 50** ✅
- c) No output
- d) Error

**Answer:**

The answer is 50 because `var = 15` will get evaluated, then rejected as the rightmost operand will be assigned to `num` which will be `15 + 35` which is 50. Then `num` gets printed.

## Precedence and Associativity of Operators

### Precedence of Operators

Precedence of operators come into picture when in an expression we need to decide which operator will be evaluated first. **Operator with higher precedence will be evaluated first**.

**Example:** `2 + 3 * 5` = `2 + (3 * 5)` = **17**

❕ Precedence of multiplication is greater than addition.

### Associativity of Operators

Associativity of operators come into picture when **precedence of operators are same** and we need to decide which operator will be evaluated first.

**Example:** `10 / 2 * 5` -> Left to right: `(10 / 2) * 5` = **25**

> Associativity can be either:
>
> 1. Left to right
> 2. Right to left

### Precedence and Associativity Table

| Category             | Operators                                                          | Associativity |
| -------------------- | ------------------------------------------------------------------ | ------------- |
| Parenthesis/brackets | `()`, `[]`, `->`, `.`, `++`, `--`                                  | Left to right |
| Unary                | `!`, `~`, `++`, `--`, `+`, `-`, `*`, `&`, `(type)`, `sizeof()`     | Right to left |
| Multiplicative       | `*`, `/`, `%`                                                      | Left to right |
| Additive             | `+`, `-`                                                           | Left to right |
| Bitwise Shift        | `<<`, `>>`                                                         | Left to right |
| Relational           | `<`, `<=`, `>`, `>=`                                               | Left to right |
| Equality             | `==`, `!=`                                                         | Left to right |
| Bitwise AND          | `&`                                                                | Left to right |
| Bitwise XOR          | `^`                                                                | Left to right |
| Bitwise OR           | `\|`                                                               | Left to right |
| Logical AND          | `&&`                                                               | Left to right |
| Logical OR           | `\|\|`                                                             | Left to right |
| Conditional          | `? :`                                                              | Right to left |
| Assignment           | `=`, `+=`, `-=`, `*=`, `/=`, `%=`, `&=`, `^=`, `\|=`, `<<=`, `>>=` | Right to left |
| Comma                | `,`                                                                | Left to right |

#### `()` - Parenthesis in Function Calls

**Example:** `int var =fun();` -> `int var =(fun());`

`=` operator is having less precedence as compared to `()`, therefore `()` belongs to `fun` and `fun` will be treated as a function.

If suppose `=` operator is having greated precedence then `fun` will belong to `=` operator and therefore it will be treated as a variable.

`int (var =fun)();`

#### Member Access Operators (`->`, `.`)

They are used to **access members of structures**. We will talk about structures later in this course.

#### Postfix Increment/Decrement (`++`, `--`)

**Precedence** of postfix increment/decrement operator is _greater_ than prefix increment/decrement operator.

**Associativity** of postfix is also different from prefix. Associativity of **postfix** operators is from _left to right_ and that of **prefix** operators is from _right to left_.

### Important Facts

- Associativity can only help if there are two or more operators of same precedence and not when there is just one operator.
- Operators with same precedence have same associativity as well.

```c
int main(void) {
  int a;

  a = fun1() + fun2();
  printf("%d", a);
  return 0;
}

int fun1(void) {
  printf("Neso");
  return 1;
}

int fun2(void) {
  printf("Academy");
  return 1;
}
```

Which function is called first? `fun1()` or `fun2()`?

It is not defined whether `fun1()` will be called first or whether `fun2()` will be called. **Behaviour is undefined and output is compiler dependent.**

📝 **NOTE:** Here associativity will not come into picture as we have just one operator and which function will be called first is undefined. Associativity will only work when we have more than one operator of same precedence.

So the output will be either:

```
NesoAcademy2
```

or

```
AcademyNeso2
```

The **2** at the end gets printed because both functions, `fun1()` and `fun2()` return a value of 1. So 2 gets assigned to `a` which will then get printed after the two functions got called.

### Homework Problem

What is the output of the following C program fragment?

```c
#include <stdio.h>

int main(void) {
  int a = 10, b = 20, c = 30, d = 40;

  if (a <= b == d > c) {
    printf("TRUE");
  } else {
    printf("FALSE");
  }
  return 0;
}
```

- **a) TRUE** ✅
- b) FALSE

**Answer:**

In the expression `(a <= b == d > c)`, `<=` and `>` have the same precedence and their associativity is from left to right. So `a<= b` returns 1 (for `true`), and `d > c` also returns 1 leading to `1 == 1` which again returns 1 for `true` which then evaluated the `printf()` statement printing `TRUE`.

## Operators in C - Solved Problem 1

What is the output of the following C program fragment? Assume size of integer to be 4 bytes.

```c
#include <stdio.h>

int main(void) {
  int i = 5;
  int var = sizeof(i++);

  printf("%d %d", i, var);
  return 0;
}
```

- **a) `5 4`** ✅
- b) `6 4`
- c) `5 8`
- d) Compiler error

**Answer:**

C standard is the language specification which is adopted by all C compilers across the globe.

According to C99 standard:

> The sizeof operator yields the size (in bytes) of its operand, which may be an expression or a parenthesized name of a type. _The size is determined from the type of the operand_. If the type of the operand is a **variable length array type, then the operand is evaluated;** otherwise, **the operand is not evaluated** and the result is an integer constant.

Therefore, `i++` inside of `sizeof()` is not evaluated.

## Operators in C - Solved Problem 2

What is the output of the following C program fragment?

```c
int a = 1;
int b = 1;
int c = ++a || b++;
int d = b-- && --a;

printf("%d %d %d %d", d, c, b, a);
```

- a) `1 1 1 1`
- b) `0 1 0 0`
- c) `1 0 0 1`
- d) **`1 1 0 1`** ✅

**Answer:**

`a = 1` `b = 1`

`c = 2 || b++` - As the first operand is `true`, the second will not be evaluated, leaving the value of `b = 1` and `c = 1`. `a = 2` because it got incremented.

`d = 1 && 1` - This will evaluate to `true` or 1. So `d = 1`. `b` get post incremented and will be `b = 0`. `a` has been post incremented so `a = 1`.

# Rapid Fire Quiz 1

## Instructions

1. All questions are multiple choice questions.
2. There are **10 questions** in this rapid fire quiz.
3. You have been provided **10 seconds** to answer each question except the last question. You have been provided **15 seconds** to answer the last question.
4. All questions carry **one mark** for correct answer and **zero marks** for incorrect answer. There is no negative marking.
5. Whatever we learned so far is now being tested in this quiz.
6. Please not down the scores you gain this quiz for self evaluation.
7. All questions are compulsory to attempt.

## Q1: Sizeof operator returns size in?

- a) Bits
- **b) Bytes** ✅
- c) Kilobytes
- d) Megabytes

## Q2: Which of the following is the correct inline declaration of variable?

- a) `int a; b; c;`
- b) `int a, int b, int c;`
- **c) `int a, b, c;`** ✅

## Q3: What does printf function return?

- a) Size of integer
- b) Size of character
- **c) Number of characters printed on the screen** ✅
- d) Size of variable

## Q4: ASCII decimal range of characters from A...Z is?

- **a) 65 - 90** ✅
- b) 97 - 122
- c) 100 - 127
- d) 1 - 28

## Q5: Size of integer?

- a) 32 bytes
- b) 8 bytes
- c) 16 bytes
- **d) Depends from machine to machine** ✅

## Q6: Consider the following variable declarations and definitions in C?

1. `int 39 = 1;`
2. `int var_39 = 2;`
3. `int_ = 3;`

Which of the following is correct?

- a) Both 1 and 2 are valid.
- b) Only 2 is valid.
- **c) Both 2 and 3 are valid.** ✅
- d) None of the above.

## Q7: Consider the following lines.

`int var;`
`extern int var;`

Which of the following is correct?

- a) Both statements only declare variables and not define them.
- b) Both statements declare and define variables.
- c) Statement 1 declares a variable and statement 2 defines a variable.
- **d) Statement 1 declares and defines a variable and statement 2 just declares a variable.** ✅

## Q8: Predict the output.

```c
#include <stdio.h>

int var = 5;

int main(void) {
  int var = var;
  printf("%d", var);
}
```

- a) 5
- b) Compiler error
- **c) Garbage value** ✅
- d) None of the above

## Q9: Predict the output.

```c
#include <stdio.h>

int main(void) {
  {
    int var = 10;
  }
  {
    printf("%d", var);
  }
}
```

- a) 10
- **b) Compiler error** ✅
- c) Garbage value
- d) None of the above

## Q10: Predict the output.

```c
#include <stdio.h>

int main(void) {
  unsigned int var = 10;

  printf("%d", ~var);
}
```

- a) 10
- b) -10
- **c) -11** ✅
- d) -5

# Conditionals

## If - Else

```c
if (button is clicked) {
  Applications page will get opened;
} else {
  Stay at home page;
}
```

### Nested If

```c
if (button is clicked) {
  Applications page will get opened;

  if (icon is clicked) {
    Play store will get opened;
  }
} else {
  Stay at home page;
}
```

### Else If

```c
if (button is clicked) {
  Applications page will get opened;
} else if (chrome is clicked) {
  Google Chrome will get opened;
}
```

#### Is It Necessary to Put the Else Part?

The answer to this question is NO and YES!

**Example 1:**

```c
int n = 4;

if (n != 4)
  printf("n is not 4");
```

No output.

**Example 2:**

```c
int n = 4;

if (n != 4)
  printf("n is not 4");
else
  printf("n is 4");
```

Output: `n is 4`

#### Why Curly Braces?

**Example 1:**

```c
int n = 5;

if (n == 4)
printf("n is 4");
n++;
printf("%d", n);
```

Output: `6`

**Example 2:**

```c
int n = 5;
if (n == 4) {
  printf("n is 4");
  n++;
}
printf("%d", n);
```

Output: `5`

If we want to include more than one statement in the condition we have to use curly braces.

## Switch

### What is Switch?

`switch` is a great replacement to long else if constructs.

```c
int x = 2;

if (x == 1)
  printf("x is 1");
else if (x == 2)
  printf("x is 2");
else if (x == 3)
  printf("x is 3");
else
  printf("x is a number other than 1, 2 and 3");
```

This looks very verbose. Here is a replacement:

```c
int x = 2;

switch(x) {
  case 1:
    printf("x is 1");
    break;
  case 2:
    printf("x is 2");
    break;
  case 3:
    printf("x is 3");
    break;
  default:
    printf("x is a number other than 1, 2 and 3");
    break;
}
```

### Facts Related to Switch

1. You are not allowed to add duplicate cases.
2. Only those expressions are allowed in switch which results in an integral constant value.
3. Float value is not allowed as a constant value in _case label_. Only integer constants/constant expressions are allowed in case label.
4. **Variable expressions are not allowed in case labels.** Although macros are allowed.
5. Default can be placed anywhere inside switch. It will still get evaluated if no match is found.

# Loops

## For and While Loops

### While Loop

**Syntax:**

```c
while (expression) {
  statement1;
  statement2;
  .
  .
  .
}
```

**Example:**

```c
int i = 3;

while (i > 0) {
  printf("%d\n", i);
  i--;
}
```

Output will be:

```
3
2
1
```

### For Loop

**Syntax:**

```c
for (initialization; condition; increment/decrement) {
  statements;
}
```

**Example:**

```c
int i;

for (i = 3; i > 0; i--) {
  printf("%d\n", i);
}
```

This program will have the exact same output as the program above using a `while` loop.

## Do-While Loop

### Difference Between While Loop and Do-While Loop

`while`:

```c
int i = 0;

while (i > 0) {
  printf("%d", i);
  i--;
}
```

Output: No output

`do-while`:

```c
int i = 0;

do {
  printf("%d", i);
  i--;
} while (i > 0);
```

Output: `0`

### When Should I Prefer Do-While Over While?

Wrtie a program which allows user to enter an integer until he enters a value zero.

`while`:

```c
int n;

printf("Enter an integer\n");
scanf("%d", &n);

while (n != 0) {
  printf("Enter an integer\n");
  scanf("%d", &n);
}
printf("You are out of the loop");
```

`do-while`:

```c
int n;

do {
  printf("Enter an integer\n");
  scanf("%d", &n);
} while (n != 0);

printf("You are out of the loop");
```

Whenever we require to execute the body of the loop at least once, we should use `do-while` loops.

## Loop Control Statements

### Break

Used to terminate from the loop.

**Example:** WAP to allow user to enter integers until he enters a negative number or a zero.

```c
#include <stdio.h>

int main(void) {
  int n;

  printf("Enter a number\n");
  scanf("%d", &n);

  while (n != 0) {
    if (n < 0) break;
    printf("Enter a number\n");
    scanf("%d", &n);
  }
}
```

### Continue

Similar to `break` but instead of terminating from the loop it forces to execute the next iteration of the loop.

**Example:** WAP to print all odd numbers from 1 to 20.

```c
#include <stdio.h>

int main(void) {
  int i, n = 2;

  for (i = 1; i <= 20; i++) {
    if (i == n) {
      n += 2;
      continue;
    }
    printf("%d ", i);
  }
}
```

The output will be:

```
1 3 5 7 9 11 13 15 17 19
```

## Loops - Question 1

How many times will "Hello, World" be printed in the below program?

```c
#include <stdio.h>

int main(void) {
  int i = 1024;

  for (; i; i >>= 1)
    printf("Hello, World");
  return 0;
}
```

- a) 10
- **b) 11** ✅
- c) Infinite
- d) Compile time error

**Answer:**

1024 = `0100 0000 0000`

`i >>= 1` is equivalent to `i = i >> 1`, so we right shift the bits by one and we get:

`0010 0000 0000` = 512

This will get repeated until `i` is equal to 0.

`0001 0000 0000` = 256

`0000 1000 0000` = 128

`0000 0100 0000` = 64

until:

`0000 0000 0001` = 1

Then the loop terminates because the condition is false as `i` is equal to 0 (`0000 0000 0000`).

## Conditionals and Loops - Question 2

What is the output of the following C program fragment?

```c
#include <stdio.h>

int main(void) {
  int i;

  for (i = 0; i < 20; i++) {
    switch (i) {
      case 0: i += 5;
      case 1: i += 2;
      case 5: i += 5;
      default: i += 4;
    }
    printf("%d ", i);
  }
  return 0;
}
```

- a) `5 10 15 20`
- b) `7 12 17 22`
- c) Compiler error
- **d) `16 21`** ✅

**Answer:**

Because there is no `break` keywod after the cases, all cases will be evaluated. So in the first run `i` (0) gets incremented by 5, 2, 5 and 4 which is 16. Then in the second loop `i` gets incremented by one and then by 4 as 16 does not match any cases so the `default` case gets evaluated.

## Conditionals and Loops - Question 3

How many times will "Neso" be printed on the screen?

```c
int i = -5;

while (i <= 5) {
  if (i >= 0)
    break;
  else {
    i++;
    continue;
  }
  printf("Neso");
}
```

- a) 10 times
- b) 5 times
- c) Infinite times
- **d) 0 times** ✅

**Answer:**

The value of `i` will get incremented until it reaches a value of 0. On each increment, the loop gets continued, meaning the `printf()` will not evaluate. If `i` reaches 0 then the loop will be terminated.

## Homework Problem

What is the output of the following C program fragment?

```c
#include <stdio.h>

int main(void) {
  int i = 0;

  for (printf("one\n"); i < 3 && printf(""); i++) {
    printf("Hi!\n");
  }
  return 0;
}
```

Output: `one`

The initial `printf()` statement prints "one" to the console and returns 3. Then the condition returns `false` as the second `printf()` function returns 0 which is `false`. As there is a `&&` (conditional AND operator) the whole condition returns 0 so the inner `printf()` will never get evaluated.

## Conditionals and Loops - Question 4

What is the output of the following C program fragment? Assuming size of unsigned int is 4 bytes.

```c
#include <stdio.h>

int main(void) {
  unsigned int i = 500;

  while (i++ != 0);
  printf("%d", i);
  return 0;
}
```

- a) Infinite loop
- b) 0
- **c) 1** ✅
- d) Compiler error

**Answer:**

Range of `unsigned int` (4 bytes) -> 0 to 4294967295

When `i` reached 4294967295, then because of `i++`, it comes back again to 0.

As `0 != 0` is `false` therefore we come outside of the `while` loop.

After we come out of the loop, `i` will contain 1 because of post increment operator. Therefore, **1** will be printed to the screen.

## Conditionals and Loops - Question 5

What is the output of the following C program fragment?

```c
#include <stdio.h>

int main(void) {
  int x = 3;

  if (x == 2); x = 0;
  if (x == 3) x++;
  else x += 2;

  printf("x = %d", x);
  return 0;
}
```

- a) x = 4
- **b) x = 2** ✅
- c) Compiler error
- d) x = 0

**Answer:** Because after `if (x == 2);` there is a semicolon so `x = 0;` will be executed in any case. So x is 0 and the `else` will be executed which increments `x` by 2. So the output will be `x = 2`.

# Special Programs in C

## Pyramid of Stars

### Prequisite: Matrices

Code for filling a matrix of 2 x 2 with stars (`*`) where `i` represents the rows and `j` represents the columns.

```c
for (i = 1; i <= 2; i++) {
  for (j = 1; j <= 2; j++) {
    printf("*");
  }
}
```

For a matrix of 4 x 4 we use the following code:

```c
for (i = 1; i <= 4; i++) {
  for (j = 1; j <= 4; j++) {
    printf("*");
  }
}
```

For a pyramid of 4 x 7 like this:

| -     | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
| ----- | --- | --- | --- | --- | --- | --- | --- |
| **1** |     |     |     | \*  |     |     |     |
| **2** |     |     | \*  | \*  | \*  |     |     |
| **3** |     | \*  | \*  | \*  | \*  | \*  |     |
| **4** | \*  | \*  | \*  | \*  | \*  | \*  | \*  |

The relations of rows to columns is as follows:

| Rows   | Columns    |
| ------ | ---------- |
| 3 rows | 5 columns  |
| 4 rows | 7 columns  |
| 5 rows | 9 columns  |
| 6 rows | 11 columns |

So: If $n$ is no. of rows then $2n - 1$ will be no. of columns.

```c
for (i = 1; i <= n; i++) {
  for (j = 1; j <= 2 * n - 1; j++) {

  }
}
```

To print the stars and blanks in the right order, we use the following logic:

```c
if (j >= n - (i - 1) && j <= n + (i - 1)) {
  printf("*");
} else {
  printf(" ");
}
```

Combining all things together this will be the final program:

```c
#include <stdio.h>

int main(void) {
    int n, i, j;

    printf("How many rows do you wish in your pyramid?\n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= 2 * n - 1; j++) {
            if (j >= n - (i - 1) && j <= n + (i - 1))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
```

Output will be:

```
$ How many rows do you wish in your pyramid?
> 10

         *
        ***
       *****
      *******
     *********
    ***********
   *************
  ***************
 *****************
*******************
```

## Palindromes

### Basics

**What is a palindrome?**

A number or a word or a phrase if read backwards gives the same number or a word or a phrase as it is being read forwards.

**Example:** 1221, racecar, 24542 etc.

**Idea:**

Make last number first number, second last number the second number and so on...

That means you need to reverse the number and if the reversed number is equal to the actual number then we can say that the number is a palindrome.

**What happens when we divide the number by 10?**

$456\div10$ -> Remainder = 6, quotient = 45

```
result = 0;
number = 2332
q = number

remainder = q % 10
result = result * 10 + remainder
q = q / 10
```

In C the program would look like this:

```c
#include <stdio.h>

int main(void) {
    int n, result = 0, q, rem;

    printf("Please enter a number: ");
    scanf("%d", &n);

    q = n;
    while (q != 0) {
        rem = q % 10;
        result = result * 10 + rem;
        q /= 10;
    }

    if (result == n)
        printf("It's a palindrome!\n");
    else
        printf("No! It's not a palindrome.\n");
    return 0;
}
```

The output would be:

```
$ Please enter a number: 2332
It's a palindrome!
```

## Check If The Number Is Armstrong Number

Write a program to check whether a number is an Armstrong number or not?

**Armstrong number:** An Armstrong number of _order n_ is a number in which each digit when multiplied by itself _n number of times_ and finally added together, results in the same number.

**Example:**

371 is a 3 digit number. Therefore, its order is 3.

Now here, each digit is multiplied by _itself 3 times_ and finally added together and results in our original number i.e.

$$3\times3\times3+7\times7\times7+1\times1\times1=27+343+1=371$$

How to write a program which checks whether a number is an Armstrong number or not?

**Step #1** - First find out, how many digits are there in your number.

```
count = 0;
while (q != 0) {
  q = q / 10;
  count++;
}
```

| Step | Operation      | Count |
| ---- | -------------- | ----- |
| 1.   | $371\div10=37$ | 1     |
| 2.   | $37\div10=3$   | 2     |
| 3.   | $3\div10=0$    | 3     |

**Step #2** - Multiply each digit $n$ times (in our example, $n = 3$) and add them together.

```
cnt = count, result = 0;

while (q != 0) {
  rem = q % 10;

  while (cnt != 0) {
    mul = mul * rem;
    cnt--;
  }
  result = result + mul;
  cnt = count;
  q = q / 10;
  mul = 1;
}
```

| Step | `rem`         | `mul`                 | `result`     |
| ---- | ------------- | --------------------- | ------------ |
| 1.   | $371\mod10=1$ | 1                     | 1            |
| 2.   | $37\mod10=7$  | $7\times7\times7=343$ | $1+343=344$  |
| 3.   | $3\mod10=3$   | $3\times3\times3=27$  | $344+27=371$ |

**Step #3** - Check whether the calculated result is equal to the actual number or not.

```
if (result == number)
  printf("%d is an Armstrong number", number);
else
  printf("%d is not an Armstrong number", number);
```

Combining all of the above steps, we get the final program:

```c
#include <stdio.h>

int main(void) {
    int number, count = 0, result = 0, mul = 1, cnt, rem;

    printf("Please enter a number: ");
    scanf("%d", &number);

    int q = number;
    while (q != 0) {
        q /= 10;
        count++;
    }
    cnt = count;
    q = number;

    while (q != 0) {
        rem = q % 10;
        while (cnt != 0) {
            mul = mul * rem;
            cnt--;
        }
        result += mul;
        cnt = count;
        q /= 10;
        mul = 1;
    }
    if (result == number)
        printf("%d is an Armstrong number\n", number);
    else
        printf("%d is not an Armstrong number\n", number);
    return 0;
}
```
