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
            mul *= rem;
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

Output will be:

```
$ Please enter a number: 371
371 is an Armstrong number
```

Or:

```
$ Please enter a number: 890
890 is not an Armstrong number
```

## Check If the Number Is A Strong Number

**Problem statement:**

Write a program to check whether a number is a strong number or not.

**What is a strong number?**

**Strong number:** is a number in which the sum of _factorial_ of individual digits of a number is equal to the original number.

**Example:**

$$145=1!+4!+5!=1+24+120=145$$

### Factorial Basics

**Definition:** Factorial of a positive integer $n$, is the number which is obtained by multiplying all positive integers less than or equal to $n$.

$$3!=3\times2\times1=6$$
$$5!=5\times4\times3\times2\times1=120$$

In general,

$$n!=n\times(n-1)\times(n-2)\times...\times3\times2\times1$$

**Step #1** - Calculate the factorial of each digit of a number and add them.

```
q = n, fact = 1, result = 0;

while (q != 0) {
  rem = q % 10;
  for (i = 1; i <= rem; i++) {
    fact = fact * i;
  }
  result = result + fact;
  fact = 1;
  q = q / 10;
}
```

| `q` | `rem` | `fact`                              | `result` |
| --- | ----- | ----------------------------------- | -------- |
| 145 | 5     | $1\times2\times3\times4\times5=120$ | 120      |
| 14  | 4     | $1\times2\times3\times4=24$         | 144      |
| 1   | 1     | $1=1$                               | 145      |

**Step #2** - Check whether the calculated result is equal to the actual number or not.

```
if (result == number)
  printf("%d is a strong number", number);
else
  printf("%d is not a strong number", number);
```

This is the program:

```c
#include <stdio.h>

int main(void) {
    int n, q, rem, fact = 1, i, result = 0;

    printf("Please enter a number: ");
    scanf("%d", &n);

    q = n;
    while (q != 0) {
        rem = q % 10;

        for (i = 1; i <= rem; i++)
            fact *= i;
        result += fact;
        fact = 1;
        q /= 10;
    }
    if (result == n)
        printf("%d is a strong number\n", n);
    else
        printf("%d is not a strong number\n", n);

    return 0;
}
```

## Check If The Number Is Prime Number

**Problem statement:**

Write a program to check whether a number is prime or not?

### Basic Terminology

- **Prime number** - A _number greater than 1_ is called a prime number, if it has only two factors, namely 1 and the number itself.
  - **Example:** `2, 3, 5, 7, 11` ...
- **Composite number** - A _composite number_ is a positive integer which is not prime i.e. which has factors other than 1 and itself.
  - **Example:** `4, 6, 8, 9, 10` ...

**Question:** Is 1 a prime number?

**Solution:** No. It's not a prime number because according to the definition of prime numbers - A prime number is a number which has exactly two divisors, 1 and itself. But 1 has only one divisor i.e. itself. Therefore it is not a prime number.

Another reason - it violates the _fundamental theorem of arithmetic_.

According to this theorem - Every positive integer greater than one can be written _uniquely_ as the product of primes.

**Example:** $9=3\times3$

But we can also write it as:

$$9=3\times3\times1$$
$$9=3\times3\times1\times1$$
$$9=3\times3\times1\times1\times1$$

### The Big Picture

In order to find whether a number is prime or not, we first need to calculate the square root of that number and then we divide that number by numbers less than or equal to the square root of that number. **If it is divisible by any of the number** then we can say that _the number is not a prime number_ else it is a prime number.

**Example:** Suppose we need to find whether 23 is a prime number or not.

**Step 1** - _Take square root of 23_. Which is nearly 4.7958 = 7.

**Step 2** - Divide 23 by numbers greater than 2 and less than or equal to 5. If it is divisible by any of those numbers then it is not prime else it is a prime.

As 23 is not divisible by any of those numbers, therefore 23 is a prime number.

In code it would look like this:

```c
#include <math.h>
#include <stdio.h>

int main(void) {
    int x;
    int i, val1, val2, count = 0;

    printf("Please enter a number (only positive integers): ");
    scanf("%d", &x);

    val1 = ceil(sqrt(x));
    val2 = x;

    for (i = 2; i <= val1; i++)
        if (val2 % i == 0) count = 1;

    if ((count == 0 && val2 != 1) || val2 == 2 || val2 == 3)
        printf("%d is a prime number\n", val2);
    else
        printf("%d is not a prime number\n", val2);

    return 0;
}
```

#### Part 1 - Finding the Square Root

```c
#include <math.h>

int main(void) {
  int x, val1;

  val1 = ceil(sqrt(x));
}
```

##### `sqrt()`

- `sqrt()` means square root.
- Available in _math.h_ library.

**Syntax:** `double sqrt(double x)`

##### `ceil()`

- `ceil()` function returns a smallest integer greater than or equal to `x`.
- Available in _math.h_ library.

**Syntax:** `double ceil(double x)`

#### Part 2 - Check the Divisibility

```c
int val2 = x, count = 0;

for (i = 2; i <= val1; i++)
  if (val2 % i == 0) count = 1;
```

If `val2` is divisible by any of the number less than or equal to the square root of `x`. If it is, then `count` will be set to 1 and we know that `x` is not a prime number.

#### Part 3 - Check Whether a Number is Prime or not

```c
if ((count == 0 && val2 != 1) || val2 == 2 || val2 == 3)
  printf("%d is a prime number\n", val2);
else
  printf("%d is not a prime number\n", val2);
```

If `count` equals 0 and the number is not 1 then we should print that it is not a prime number. If it is 2 or 3 then we print that it is a prime number. These base cases have not been checked by the program before that's why we have to check them here.

## Addition Without `+` Operator

**Problem statement:**

Write a program to add two numbers without using `+` operator.

💡 The _idea_ is to use increment and decrement operators.

```
x = 3, y = 4
```

**Algorithm:**

1. `x++;` `y--;`
2. Repeat step 1 until `y` becomes 0.

| Step | `x` | `y` |
| ---- | --- | --- |
| 1.   | 4   | 3   |
| 2.   | 5   | 2   |
| 3.   | 6   | 1   |
| 4.   | 7   | 0   |

The program in C looks like this:

```c
#include <stdio.h>

int main(void) {
    int x, y;

    printf("Enter the two numbers you want to add: ");
    scanf("%d %d", &x, &y);

    while (y != 0) {
        x++, y--;
    }
    printf("Sum of two values is: %d\n", x);
    return 0;
}
```

⛔️ This program only works with _positive_ integers!

But there is a solution for adding negative integers to the program:

```c
#include <stdio.h>

int main(void) {
    int x, y;
    printf("Enter the two numbers you want to add: ");
    scanf("%d %d", &x, &y);

    if (y > 0)
        while (y != 0)
            x++, y--;
    else if (y < 0)
        while (y != 0)
            x--, y++;
    printf("Sum of two values is: %d\n", x);
    return 0;
}
```

### Half Adder Basics

#### Truth Table

| A   | B   | S   | C   |
| --- | --- | --- | --- |
| 0   | 0   | 0   | 0   |
| 0   | 1   | 1   | 0   |
| 1   | 0   | 1   | 0   |
| 1   | 1   | 0   | 1   |

S = Sum = `A XOR B`

C = Carry = `A AND B`

#### Implementation

```
while (b != 0) {
  sum = a ^ b;
  carry = (a & b) << 1;

  a = sum;
  b = carry;
}
```

#### Example 1

- $a=5$ (`0 1 0 1`)
- $b=10$ (`1 0 1 0`)
- $5+10=15$ **(`1 1 1 1`)**

| `sum`                               | `carry`                         |
| ----------------------------------- | ------------------------------- |
| `0 1 0 1 ^ 1 0 1 0` = **`1 1 1 1`** | `0 1 0 1 & 1 0 1 0` = `0 0 0 0` |

As `b` is equal to 0 after the first iteration, we move out of the `while` loop and print `a` which is **15**.

#### Example 2

- $a=7$ (`0 1 1 1`)
- $b=2$ (`0 0 1 0`)
- $7+2=9$ **(`1 0 0 1`)**

| Iteration | `sum`                               | `carry`                                          |
| --------- | ----------------------------------- | ------------------------------------------------ |
| 1         | `0 1 1 1 ^ 0 0 1 0` = `0 1 0 1`     | `0 1 1 1 & 0 0 1 0` = `0 0 1 0 << 1` = `0 1 0 0` |
| 2         | `0 1 0 1 ^ 0 1 0 0` = `0 0 0 1`     | `0 1 0 1 & 0 1 0 0` = `0 1 0 0 << 1` = `1 0 0 0` |
| 3         | `0 0 0 1 ^ 1 0 0 0` = **`1 0 0 1`** | `0 0 0 1 & 1 0 0 0` = `0 0 0 0`                  |

#### Example 3

- $a=7$ (`0 1 1 1`)
- $b=7$ (`0 1 1 1`)
- $7+7=14$ **(`1 1 1 0`)**

| Iteration | `sum`                               | `carry`                                          |
| --------- | ----------------------------------- | ------------------------------------------------ |
| 1         | `0 1 1 1 ^ 0 1 1 1` = `0 0 0 0`     | `0 1 1 1 & 0 1 1 1` = `0 1 1 1 << 1` = `1 1 1 0` |
| 2         | `0 0 0 0 ^ 1 1 1 0` = **`1 1 1 0`** | `0 0 0 0 & 1 1 1 0` = `0 0 0 0`                  |

#### Final Code

```c
#include <stdio.h>

int main(void) {
    int sum, carry, a, b;

    printf("Enter the two numbers: ");
    scanf("%d %d", &a, &b);

    while (b != 0) {
        sum = a ^ b;
        carry = (a & b) << 1;

        a = sum;
        b = carry;
    }
    printf("Sum of two numbers is: %d\n", sum);
    return 0;
}
```

## Fibonacci Series

**Problem statement:**

Write a program to print _Fibonacci_ series upto $n$ number of terms.

### What is Fibonacci Series?

In Fibonacci series, next term is obtained by taking sum of previous two terms.

| $n$      | 1   | 2   | 3   | 4   | 5   | 6   |
| -------- | --- | --- | --- | --- | --- | --- |
| $fib(n)$ | 0   | 1   | 1   | 2   | 3   | 5   |

Mathematically,

$$fib(n)=fib(n-1)+fib(n-2)$$

Here we represent exactly that in pseudocode:

```
a = 0;
b = 1;

for (i = 1; i <= n; i++) {
  printf("%d ", a);
  result = a + b;
  a = b;
  b = result;
}
```

**Example:**

$a=0$

$b=1$

$n=6$

| Iteration $n$ | Output | `result` | `a` | `b` |
| ------------- | ------ | -------- | --- | --- |
| 1             | 0      | $0+1=1$  | 1   | 1   |
| 2             | 1      | $1+1=2$  | 1   | 2   |
| 3             | 1      | $1+2=3$  | 2   | 3   |
| 4             | 2      | $2+3=5$  | 3   | 5   |
| 5             | 3      | $3+5=8$  | 5   | 8   |
| 6             | 5      | $5+8=13$ | 8   | 13  |

The C program looks like this:

```c
#include <stdio.h>

int main(void) {
    int a, b, result, n, i;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    a = 0, b = 1;
    for (i = 1; i <= n; i++) {
        printf("%d ", a);
        result = a + b;
        a = b;
        b = result;
    }
    putchar('\n');
    return 0;
}
```

## Floyd's Triangle

### Basics

#### What is Floyd's Triangle?

Floyd's Triangle (named after a computer scientist - Robert W. Floyd) is a right-angled triangular array of natural numbers.

It is filled by natural numbers consecutively starting with 1 in the top left corner.

**Example:** A Floyd's triangle with 5 rows:

```
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
```

This is how the code looks in a C program:

```c
#include <stdio.h>

int main(void) {
    int i, j, rows, n = 1;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", n);
            n++;
        }
        putchar('\n');
    }
    return 0;
}
```

## Binary to Decimal Conversion

### Basics

| $2^3$ | $2^2$ | $2^1$ | $2^0$ |
| ----- | ----- | ----- | ----- |
| 1     | 0     | 0     | 1     |

$$2^3\times1+2^2\times0+2^1\times0+2^0\times1=8\times1+1\times1=9$$

This is the C program to convert binary into decimal representation:

```c
#include <stdio.h>

int main(void) {
    int decimal = 0, binary, base = 1, rem, num;

    printf("Enter the binary number: ");
    scanf("%d", &binary);

    num = binary;
    while (binary != 0) {
        rem = binary % 10;
        decimal += rem * base;
        binary /= 10;
        base *= 2;
    }
    printf("Decimal equivalent of binary number %d is: %d\n", num, decimal);
    return 0;
}
```

**Explanation:**

Suppose we have a binary number: `1 0 0 1`.

Going step by step through the program:

| Iteration | `rem`          | `decimal`      | `binary`         | `base`        |
| --------- | -------------- | -------------- | ---------------- | ------------- |
| 1.        | $1001\mod10=1$ | $0+1\times1=1$ | $1001\div10=100$ | $1\times2=2$  |
| 2.        | $100\mod10=0$  | $1+0\times2=1$ | $100\div10=10$   | $2\times2=4$  |
| 3.        | $10\mod10=0$   | $1+0\times4=1$ | $10\div10=1$     | $4\times2=8$  |
| 4.        | $1\mod10=1$    | $1+1\times8=9$ | $1\div10=0$      | $8\times2=16$ |

## Calculating Power of an Integer

### Basics

$$a^b = a\times a\times a\times a...b\ times$$

where $a$ and $b$ are integers.

**Example:**

$$2^3=2\times2\times2$$

$$2^{-3}=\frac1 2\times\frac1 2\times\frac1 2$$

### Implementation

```c
int base, exponent;
int power = 1, expo;

printf("Enter the base: ");
scanf("%d", &base);
printf("Enter the exponent: ");
scanf("%d", &exponent);

expo = exponent;
if (exponent > 0) {
  while (exponent != 0) {
    power *= base;
    exponent--;
  }
  printf("%d to the power of %d is %d\n", base, expo, power);
}
```

For the example value $2^3$ we have the following iterations of the code:

| Iteration | `power`      | `exponent` |
| --------- | ------------ | ---------- |
| 1.        | $1\times2=2$ | $3-1=2$    |
| 2.        | $2\times2=4$ | $2-1=1$    |
| 3.        | $4\times2=8$ | $1-1=0$    |

⛔️ This program works only with positive exponents!

If we wanted to include negative exponents let's add some stuff:

```c
int base, exponent, expo;
double power1 = 1.0;

printf("Enter the base: ");
scanf("%d", &base);
printf("Enter the exponent: ");
scanf("%d", &exponent);

expo = exponent;
if (exponent < 0) {
  while (exponent != 0) {
    power1 *= (1.0 / base);
    exponent++;
  }
  printf("%d to the power of %d is %.10f\n", base, expo, power1);
}
```

Let's calculate $2^{-3}$

| Iteration | `power1`                     | `exponent` |
| --------- | ---------------------------- | ---------- |
| 1.        | $1\times(1.0\div2)=0.5$      | $-3+1=-2$  |
| 2.        | $0.5\times(1.0\div2)=0.25$   | $-2+1=-1$  |
| 3.        | $0.25\times(1.0\div2)=0.125$ | $-1+1=0$   |

So, the output will be:

```
2 to the power of -3 is 0.125
```

Combining the two above programs we can build the full C program:

```c
#include <stdio.h>

int main(void) {
    int base, exponent, expo, power = 1;
    double power1 = 1.0;

    printf("Enter the base: ");
    scanf("%d", &base);
    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    expo = exponent;
    if (exponent > 0) {
        while (exponent != 0) {
            power *= base;
            exponent--;
        }
        printf("%d to the power of %d is %d\n", base, expo, power);
    } else {
        while (exponent != 0) {
            power1 *= (1.0 / base);
            exponent++;
        }
        printf("%d to the power of %d is %.10f\n", base, expo, power1);
    }
    return 0;
}
```

## Check Leap Year

### Basics

#### What is a Leap Year?

A leap year is a year having 366 days.

The extra day is the 29th February.

Leap year arrives after every four years.

**Note:** Every year that is exactly divisible by 4 is a leap year, except the centurial year that is exactly divisible by 100. But these centurial years are leap years if they are exactly divisible by 400.

#### How to Check Whether a Year is a Leap Year or not?

1. If a year is _divisible by 400_ then it is a _leap year_.

- **Example:** 2000 is divisible by 400. Therefore it is a leap year.

2. If a year is _not divisible by 400_ but it is _divisible by 100_ then it is _not a leap year_.

- **Example:** 1900 is divisible by 100 but not by 400. Therefore it is not a leap year.

3. If a year is _not divisible by 400_ and _not divisible by 100_ but it _is divisible by 4_ then it is a leap year.

- **Example:** 2012 is not divisible by 400 and not divisible by 100 but it is divisible by 4. Therefore it is a leap year.

This would be the corresponding C program:

```c
#include <stdio.h>

int main(void) {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0))
        printf("%d is a leap year!\n", year);
    else
        printf("%d is not a leap year!\n", year);

    return 0;
}
```

Output:

```
$ Enter a year: 2000
2000 is a leap year!
```

## Perfect Number

### Basics

#### What is a Perfect Number?

Perfect number is a positive integer that is equal to the sum of all its proper positive divisors excluding the number itself.

**Example:**

6 is a perfect number because the proper positive divisors of 6 are 1, 2 and 3 (excluding 6). The sum of all its positive divisors is 6 i.e. $1+2+3=6$.

### Code

```c
int number;

printf("Enter the number: ");
scanf("%d", &number);

int i, rem, sum = 0;

for (i = 1; i < number; i++) {
  rem = number % i;

  if (rem == 0) {
    sum += i;
  }
}
```

If we had 6 as an input for `number`, let's see the iterations of the program:

| Iteration | `rem`      | `sum`   |
| --------- | ---------- | ------- |
| 1.        | $6\mod1=0$ | $0+1=1$ |
| 2.        | $6\mod2=0$ | $1+2=3$ |
| 3.        | $6\mod3=0$ | $3+3=6$ |

The we check if `sum` is equal to the inputted `number` variable:

```c
if (sum == number)
  printf("%d is a perfect number\n", number);
else
  printf("%d is not a perfect number\n", number);
```

The full C program looks like this:

```c
#include <stdio.h>

int main(void) {
    int number;

    printf("Enter the number: ");
    scanf("%d", &number);

    int i, rem, sum = 0;

    for (i = 1; i < number; i++) {
        rem = number % i;

        if (rem == 0) {
            sum += i;
        }
    }
    if (sum == number)
        printf("%d is a perfect number\n", number);
    else
        printf("%d is not a perfect number\n", number);

    return 0;
}
```

Output:

```
$ Enter the number: 28
28 is a perfect number
```

# Introduction to Functions in C

## Basics of Function

**Definition:** Function is basically a set of statements that takes inputs, perform some computation and produces output.

**Syntax:** `return_type func_name(set_of_inputs);`

## Why Functions?

There are two important reasons of why we are using functions:

1. **Reusability** - Once the function is defined, it can be reused over and over again.
2. **Abstraction** - If you are just using the function in your program then you don't have to worry about _how it works inside!_

## Demonstration

```c
#include <stdio.h>

int area_of_rect(int length, int breadth) {
    int area;

    area = length * breadth;
    return area;
}

int main(void) {
    int l = 10, b = 5;
    int area = area_of_rect(l, b);

    printf("%d\n", area);

    l = 50, b = 20;
    area = area_of_rect(l, b);

    printf("%d\n", area);
}
```

Output:

```
50
1000
```

## What is Function Declaration?

As we already know, when we declare a variable, we declare its properties to the compiler.

**Example:** `int var;`

**Properties:**

1. Name of variable: `var`
2. Type of variable: `int`

Similarly, function declaration (also called _function prototype_) means declaring the properties of a function to the compiler.

**Example:** `int fun(int, char);`

**Properties:**

| №   | Properties              | Code   |
| --- | ----------------------- | ------ |
| 1.  | Name of function        | `fun`  |
| 2.  | Return type of function | `int`  |
| 3.  | Number of parameters    | 2      |
| 4.  | Type of parameter 1     | `int`  |
| 5.  | Type of parameter 2     | `char` |

### Important Takeaway

- It is not necessary to put the name of the parameters in function prototype.
  - **Example:** `int fun(int var1, char var2);`

```c
#include <stdio.h>

char fun(void); // function prototype

int main(void) {
  char c = fun();

  printf("character is: %c", c);
  return 0;
}

char fun(void) {
  return 'a';
}
```

#### Is it Always Necessary to Declare the Function before using it?

Not necessary but it is preferred to declare the function before using it.

```c
#include <stdio.h>

char fun(void) {
  return 'a';
}

int main(void) {
  char c = fun();

  printf("character is: %c", c);
  return 0;
}
```

This code will compile, as `fun()` has been defined before the `main()` function.

## Function Definition

### Basics

#### What is Function Definition?

Function definition consists of block of code which is capable of performing some specific task.

**Example:**

```c
int add(int a, int b) {
  int sum;

  sum = a + b;
  return sum;
}
```

### How Function Works?

```c
int add(int, int); // function prototype

int main(void) {
  int m = 20, n = 30, sum;

  sum = add(m, n);
  printf("sum is %d", sum);
  return 0;
}

int add(int a, int b) {
  return (a + b);
}
```

Output: `sum is 50`

### What is the Difference Between an Argument and a Parameter?

**Parameter:** A variable in the declaration and definition of the function.

**Argument:** The actual value of the parameter that gets passed to the function.

📝 **NOTE:** Parameter is also called as **Formal Parameter** and argument is also called as **Actual Parameter**.

## Call By Value & Call By Reference

### Recall

**Actual Parameters:** The parameters passed to a function.

**Formal Parameters:** The parameters received by a function.

### Call By Value

Here values of actual parameters will be copied to formal parameters and these two different parameters store values in different locations.

```c
#include <stdio.h>

int fun(int x, int y) {
  x = 20, y = 10;
}

int main(void) {
  int x = 10, y = 20;

  fun(x, y);
  printf("x = %d, y = %d", x, y);
  return 0;
}
```

Output: `x = 10, y = 20`

The variables `x` and `y` are _local_ to the `fun()` function. So when the execution of the function ends, these two variables are destroyed. So they have no impact on the variables defined and initialized in `main()`.

### Call By Reference

Here both actual and formal parameters refers to same memory location. Therefore, any changes made to the formal parameters will get reflected to actual parameters.

```c
int x = 10, y = 20;

fun(&x, &y);
```

Here we are passing the addresses of variable `x` and `y` instead of the values.

The function will receive the addresses and can manipulate the actual value in memory using pointers:

```c
int fun(int *ptr1, int *ptr2) {
  *ptr1 = 20;
  *ptr2 = 10;
}
```

This would be the whole program:

```c
#include <stdio.h>

int fun(int *ptr1, int *ptr2) {
  *ptr1 = 20;
  *ptr2 = 10;
}

int main(void) {
  int x = 10, y = 20;

  fun(&x, &y); // passing addresses of x and y
  printf("x = %d, y = %d", x, y);
  return 0;
}
```

Output: `x = 20, y = 10`

## Questions on Functions

### Question 1

Consider the function `func()` shown below:

```c
int func(int num) {
  int count = 0;

  while (num) {
    count++;
    num >>=1;
  }
  return count;
}
```

The value returned by `func(435)` is **\_\_\_**.

**Answer**:

`num = 435`

435 is represented as `110110011` in binary.

| Iteration | Operation                      | `count` |
| --------- | ------------------------------ | ------- |
| 1.        | `110110011 >> 1` = `011011001` | 1       |
| 2.        | `011011001 >> 1` = `001101100` | 2       |
| 9.        | `000000001 >> 1` = `000000000` | 9       |

So the answer will be **9** as it takes 9 iterations and `count` gets incremented by 1 each iteration starting at 0.

### Question 2

What is the output of the following C program fragment:

```c
void f1(int a, int b) {
  int c;

  c = a, a = b, b = c;
}

void f2(int *a, int *b) {
  int c;

  c = *a, *a = *b, *b = c;
}

int main(void) {
  int a = 4, b = 5, c = 6;

  f1(a, b);
  f2(&b, &c);
  printf("%d", c - a - b);
  return 0;
}
```

5 - 4 - 6 = -5

After the execution of `f1()` the variables have values as follows:

| `a` | `b` | `c` |
| --- | --- | --- |
| 5   | 4   | 4   |

But these variables will be destroyed.

After the execution of `f2()` the variables have values as follows:

| `a` (`&b`) | `b` (`&c`) | `c` |
| ---------- | ---------- | --- |
| 6          | 5          | 5   |

In the `main()` function, the variables will have the following values after calling `f1()` (no impact) and `f2()`:

| `a` | `b` | `c` |
| --- | --- | --- |
| 4   | 6   | 5   |

So the `printf()` statement will print `c - a - b` which is equivalent to:

$$5-4-6=-5$$

So the output of the C program will be: `-5`

### Question 3

Consider the following C program:

```c
int fun(void) {
  static int num = 16;

  return num--;
}

int main(void) {
  for (fun(); fun(); fun())
    printf("%d ", fun());
  return 0;
}
```

What is the output?

- a) Infinite loop
- b) `13 10 7 4 1`
- **c) `14 11 8 5 2`** ✅
- d) `15 12 8 5 2`

**Answer:**

To understand this problem we look at the value of variable `num` in each iteration:

| for | `fun()` | `fun()` | `fun()` | Output |
| --- | ------- | ------- | ------- | ------ |
| 1.  | 16      | 15      | -       | 14     |
| 2.  | -       | 12      | 13      | 11     |
| 3.  | -       | 9       | 10      | 8      |
| 4.  | -       | 6       | 7       | 5      |
| 5.  | -       | 3       | 4       | 2      |
| 6.  | -       | 0       | 1       | -      |

In a `for` loop, on the first interation the first leftmost statement gets executed, then the condition. After that the increment rightmost statement gets executed and then the condition. Of course on every iteration also the `printf()` statement gets executed.

First iteration:

```
    1.      2.      -
for (fun(); fun(); fun())
```

After the first iteration:

```
    -       2.     1.
for (fun(); fun(); fun())
```

## Static Functions

### Basic

- In C, functions are global by default.
  - This means that if we want to access the function outside from the file where it is declared, we can access it easy.
- Now if we want to restrict this access, then we make our function static by simply putting a keyword `static` in front of the function.

Suppose we have two files, _main.c_ and _file1.c_:

_main.c_

```c
#include <stdio.h>
#include <stdlib.h>

int fun(int, int);

int main(void) {
  int sum = fun(3, 4);

  printf("%d", sum);
  return 0;
}
```

_file1.c_

```c
int fun(int a, int b) {
  int c;

  c = a + b;
  return c;
}
```

If we compiled it this way, it will compile without any problems. The output will be:

```
7
```

If we modified the _file1.c_ file to make `fun()` a static variable the `main()` function cannot access the function `fun()` because as it is static the scope changed so the function is only visible in the file itself, not external.

```c
static int fun(int a, int b) {
  int c;

  c = a + b;
  return c;
}
```

Output: **Error**

### Important Takeaways

- Static functions are restricted to the files where they are declared.
- Reuse of the same function in another file is possible.

# Static and Dynamic Scoping

## Preliminaries

Memory layout of a C program:

| Stack                    |
| ------------------------ |
| Heap                     |
| Uninitialized data (bss) |
| Initialized data         |
| Text/Code segment        |

- Stack is a container (or memory segment) which holds some data.
- Data is retrieved in _Last In First Out_ (LIFO) fashion.
- Two operations: _push_ and _pop_.

If we had for example this C program:

```c
int main(void) {
  fun1();
  return 0;
}

void fun1(void) {
  fun2();
}

void fun2(void) {
  fun3();
}

void fun3(void) {
  return;
}
```

The stack looks like this:

| Stack    |
| -------- |
| `fun3()` |
| `fun2()` |
| `fun1()` |
| `main()` |

So `fun3()` will return and removed from the stack. Then `fun2()`, then `fun1()` until control goes back to the `main()` function. When `main()` finishes executing, the stack is empty and this indicates that all functions of the program finished their executions.

But not the real functions are stored in the stack, but the **Activation Record**.

**Activation Record** - is a portion of a stack which generally is composed of:

1. Locals of the callee
2. Return address to the caller
3. Parameters of the callee

**Example:**

```c
int main(void) {
  int a = 10;

  a = fun1(a);
  printf("%d", a);
}

int fun1(int a) {
  int b = 5;

  b = b + a;
  return b;
}
```

Output: `15`

| Stack                          |
| ------------------------------ |
| `b = 5`, `some addr`, `a = 10` |
| `a = 10`                       |

After execution of `fun1()`, the activation record of this functions gets popped from the stack and control returns to `main()`, where `a` will be assigned a value of 15 which was returned by `fun1()`.

| Stack      |
| ---------- |
| `printf()` |
| `a = 15`   |

After the `printf()` function, there is nothing left in `main()` to be executed, so `main()` returns 0 and exits and the program is done.

## Why Scoping?

Scoping is necessary if you want to reuse variable names.

**Example:**

```c
int fun1(void) {
  int a = 10;
}

int fun2(void) {
  int a = 40;
}
```

## What is Static Scoping?

**In static scoping (or lexical scoping),** definition of a variable is resolved by searching its containing block or function. If that fails, then searching the outer containing block and so on.

```c
int a = 10, b = 20;

int fun(void) {
  int a = 5;

  {
    int c;

    c = b / a;
    printf("%d", c);
  }
}
```

Output: `4`

### Static Scoping Example

```c
int fun1(int);
int fun2(int);

int a = 5;

int main(void) {
  int a = 10;

  a = fun1(a);
  printf("%d", a);
}

int fun1(int b) {
  b = b + 10;
  b = fun2(b);
  return b;
}

int fun2(int b) {
  int c;

  c = a + b;
  return c;
}
```

Output: `25`

| Initialized Data Segment |
| ------------------------ |
| Global var: `a = 5`      |

| Stack (Call Stack)       |
| ------------------------ |
| fun2: `b = 20`, `c = 25` |
| fun1: `b = 20`           |
| main: `a = 10`           |

| Stack (Call Stack) |
| ------------------ |
| fun1: `b = 25`     |
| main: `a = 10`     |

| Stack (Call Stack) |
| ------------------ |
| main: `a = 25`     |

| Stack (Call Stack) |
| ------------------ |
| -                  |

## What is Dynamic Scoping?

**In dynamic scoping,** definition of a variable is resolved by searching its containing block and if not found, then searching its calling function and if still not found then the function which called that calling function will be searched and so on.

### Dynamic Scoping Example

```c
int fun1(int);
int fun2(int);

int a = 5;

int main(void) {
  int a = 10;

  a = fun1(a);
  printf("%d", a);
}

int fun1(int b) {
  b = b + 10;
  b = fun2(b);
  return b;
}

int fun2(int b) {
  int c;

  c = a + b;
  return c;
}
```

Output: `30`

| Initialized Data Segment |
| ------------------------ |
| Global var: `a = 5`      |

| Stack (Call Stack)       |
| ------------------------ |
| fun2: `b = 20`, `c = 30` |
| fun1: `b = 20`           |
| main: `a = 10`           |

| Stack (Call Stack) |
| ------------------ |
| fun1: `b = 30`     |
| main: `a = 10`     |

| Stack (Call Stack) |
| ------------------ |
| main: `a = 30`     |

| Stack (Call Stack) |
| ------------------ |
| -                  |

## Homework Problem

What will be the output of the following program snippet:

```c
int a, b; // a = 0, b = 0

void print(void) {
  printf("%d %d", a, b);
}

int fun1(void) {
  int a, c;

  a = 0, b = 1, c = 2;
  return c;
}

void fun2(void) {
  int b;

  a = 3, b = 4;
  print();
}

int main(void) {
  a = fun1();
  fun2();
  return 0;
}
```

With static scoping

- a) `2 4`
- **b) `3 1`** ✅
- c) `2 5`
- d) `3 4`

With dynamic scoping

- a) `2 4`
- b) `3 1`
- c) `2 5`
- **d) `3 4`** ✅

**Answer:**

In static scoping, definition of a variable is resolved by searching its containing block or function. If that fails, then searching the outer containing block and so on.

Let's go through the program and observe the variables:

| Function    | `a` (only global!) | `b` (only global!)                                      |
| ----------- | ------------------ | ------------------------------------------------------- |
| Global vars | 0                  | 0                                                       |
| `main()`    | `a = fun1()`       | 0                                                       |
| `fun1()`    | 0                  | 1                                                       |
| `main()`    | `a = fun1()` = 2   | 1                                                       |
| `fun2()`    | 3                  | 1 (`b` in `fun2()` is local, global var doesn't change) |
| `print()`   | 3                  | 1                                                       |

For dynamic scoping we have to also consider the local variables of the functions:

| Function    | `a`              | `b` |
| ----------- | ---------------- | --- |
| Global vars | 0                | 0   |
| `main()`    | `a = fun1()`     | 0   |
| `fun1()`    | 0                | 1   |
| `main()`    | `a = fun1()` = 2 | 1   |
| `fun2()`    | 3                | 4   |
| `print()`   | 3                | 4   |

So for static scoping the output will be `3 1` while for dynamic scoping the output will be `3 4`.

## Important Takeaways

1. In most of the programming languages, **static scoping** is follwed instead of dynamic scoping.
2. Languages, including Algol, Pascal, C, Haskell, Scheme etc. are **statically scoped**.
3. Some languages, including SNOBOL, APL, Lisp etc. are **dynamically scoped**.
4. As C follows **static scoping** therefore it is not possible to see programmatically, how dynamic scoping works in C.

💡 Perl is a programming language which supports both static as well as dynamic scoping.

This is an example for dynamic scoping in Perl:

```perl
$x = 50;

sub fun2 {
  return $x;
}

sub fun1 {
  local $x = 10;  # makes var visible up the call stack too
  my $y = fun2(); # makes var visible only where declared
  return $y;
}

print fun1();
```

Output: `10`

And this is for static scoping:

```perl
$x = 50;

sub fun2 {
  return $x;
}

sub fun1 {
  my $x = 10;     # makes var visible up the call stack too
  my $y = fun2(); # makes var visible only where declared
  return $y;
}

print fun1();
```

Output: `50`

This would be the corresponding C program in - of course - static scoping:

```c
int x = 50;

int fun2(void) {
  return x;
}

int fun1(void) {
  int x = 10;
  int y = fun2();

  return y;
}

int main(void) {
  printf("%d", fun1());
}
```

Output: `50`

## Question 1

Consider the program below in a hypothetical programming language which allows global variables and a choice of static or dynamic scoping.

```
int i;

program main() {
  i = 10;
  call f();
}

procedure f() {
  int i = 20;
  call g();
}

procedure g() {
  print i;
}
```

Let `x` be the value printed under static scoping and `y` be the value printed under dynamic scoping. Then, `x` and `y` are

- a) `x = 10, y = 10`
- b) `x = 20, y = 10`
- **c) `x = 10, y = 20`** ✅
- d) `x = 20, y = 20`

**Answer:**

As in `main()` the assignment `i = 10` does not declare a new variable, so the global variable `i` gets assigned with 10. In `f()` a new (local) variable is declared and assigned a value of 20. So when `g()` is called if we had static scoping then `i` would print 10 because the variable `i` in function `f()` is not considered as it is local. If we had dynamic scoping then `g()` will consider the local variable `i` in function `f()`.

## Question 2

What will be the output of the following pseudocode when parameters are passed by reference and dynamic scoping is assumed?

```
a = 3;

void n(x) {
  x = x * a;
  print(x);
}

void m(y) {
  a = 1;
  a = y - a;
  n(a);
  print(a);
}

void main() {
  m(a);
}
```

- a) `6 2`
- b) `6 6`
- c) `4 2`
- **d) `4 4`** ✅

**Answer:**

We have a global variable `a` with a value of 3. We pass the address of `a` (`&a`) to function `m()`. In `m()` we have a local variable `a` with a value of 1. The local variable `a` will contain 2 after the expression `y - a` (3 - 1).

We pass the local variable `a` with a value of 2 by reference (`&a`) to `n()`. Because we assume dynamic scoping, `a` in function `n()` will take the value of 2 also because `m()` is the caller. As we passed the value of local variable `a` by reference, `a` in `print` of function `m()` will also be 4. So the output will be `4 4`.

# Recursion

## Outline

- Definition of recursion
- Program to demonstrate recursion
- Homework problem

## Definition

**Recursion** is a process in which a function calls itself directly or indirectly.

**Example:**

```
int fun() {
  ...
  fun();
}
```

## Program to Demonstrate Recursion

```c
int fun(int n) {
  if (n == 1)
    return 1;
  else
    return 1 + fun(n - 1);
}

int main(void) {
  int n = 3;
  printf("%d", fun(n));
  return 0;
}
```

Output: `3`

| Stack           |
| --------------- |
| fun(1): `n = 1` |
| fun(2): `n = 2` |
| fun(3): `n = 3` |
| main(): `n = 3` |

## Homework Problem

What is the output of the following C program:

```c
#include <stdio.h>

int fun(int n) {
  if (n == 0)
    return 1;
  else
    return 7 + fun(n - 2);
}

int main(void) {
  printf("%d", fun(4));
  return 0;
}
```

- a) `4`
- b) `7`
- **c) `15`** ✅
- d) `12`

`fun(4)` -> `return 7 + fun(2)` -> `return 7 + fun(0)` -> `return 1`

Output: `15`

## How to Write Recursive Functions

### Idea

1. Divide the problem into smaller sub-problems.
2. Specify the base condition to stop the recursion.

**Problem:** Calculate the factorial of a number.

**Factorial of 5:**

$$5\times4\times3\times2\times1=120$$

### Basic Structure

```
Fact() {
  if () { }     <---- Base case

  else { }      <---- Recursive procedure
}
```

1. Divide the problem into smaller sub-problems

Calculate `Fact(4)`

- `Fact(1)` = $1$
- `Fact(2)` = $2\times1=2\times{Fact(1)}$
- `Fact(3)` = $3\times2\times1=3\times{Fact(2)}$
- `Fact(4)` = $4\times3\times2\times1=4\times{Fact(3)}$

`Fact(n)` = $n\times{Fact(n-1)}$

or in code:

```
Fact(int n) {
  if () {

  } else {
    return n * Fact(n - 1);
  }
}
```

2. Specify the base condition to stop the recursion.

Base condition is the one which doesn't require to call the same function again and it helps in stopping the recursion.

We take `Fact(1) = 1` as our base case:

```Fact(int n) {
  if (n == 1) {
    return 1;
  } else {
    return n * Fact(n - 1);
  }
}
```

And this would be a real C program, rather than pseudocode:

```c
#include <stdio.h>

int fact(int n) {
    if (n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main(void) {
    int n;

    printf("Enter the number: ");
    scanf("%d", &n);
    printf("Factorial of a number %d is: %d\n", n, fact(n));
}
```

## Types of Recursion

1. Direct recursion
2. Indirect recursion
3. Tail recursion
4. Non-tail recursion

### Direct Recursion

A function is called direct recursive if it calls the same function again.

**Structure of direct recursion:**

```
fun() {
  // some code

  fun();

  // some code
}
```

### Indirect Recursion

A function (say `fun`) is called indirect recursive if it calls another function (say `fun2`) and then `fun2` calls `fun` directly or indirectly.

```
fun() {
  // some code
  fun2();
  // some code
}

fun2() {
  // some code
  fun();
  // some code
}
```

#### Program to Understand Indirect Recursion

WAP to print numbers from 1 to 10 in such a way that when number is _odd_, add 1 and when number is _even_, subtract 1.

Output: `2 1 4 3 6 5 8 7 10 9`

This is the C program:

```c
#include <stdio.h>

void odd(void);
void even(void);

int n = 1;

void odd(void) {
  if (n <= 10) {
    printf("%d ", n + 1);
    n++;
    even();
  }
  return;
}

void even(void) {
  if (n <= 10) {
    printf("%d ", n - 1);
    n++;
    odd();
  }
  return;
}

int main(void) {
  odd();
  return 0;
}
```

The call stack would look like this:

- `Act` - Activation record
- `o` - odd()
- `e` - even()

| Stack (Call Stack) |
| ------------------ |
| odd(): `Act o`     |
| even(): `Act e`    |
| odd(): `Act o`     |
| even(): `Act e`    |
| odd(): `Act o`     |
| main(): `Act m`    |

When reaching 11, the condition fails and the stack gets popped until the stack is empty.

### Tail Recursion

A recursive function is said to be _tail recursive_ if the recursive call is the last thing done by the function. There is no need to keep record of the previous state.

```c
void fun(int n) {
  if (n == 0)
    return;
  else
    printf("%d ", n);
  return fun(n - 1);
}

int main(void) {
  fun(3);
  return 0;
}
```

Output: `3 2 1`

| Stack (Call Stack) |
| ------------------ |
| fun(0): `return;`  |
| fun(1): `Act f1`   |
| fun(2): `Act f2`   |
| fun(3): `Act f3`   |
| main(): `Act m`    |

### Non-Tail Recursion

A recursive function is said to be _non-tail recursive_ if the recursive call is not the last thing done by the function. After returning back, there is something left to evaluate.

```c
void fun(int n) {
  if (n == 0)
    return;
  fun(n - 1);
  printf("%d ", n);
}

int main(void) {
  fun(3);
  return 0;
}
```

Output: `1 2 3`

| Stack (Call Stack) |
| ------------------ |
| fun(0): `return;`  |
| fun(1): `Act f1`   |
| fun(2): `Act f2`   |
| fun(3): `Act f3`   |
| main(): `Act m`    |

Another example for a non-tail recursion:

```c
int fun(int n) {
  if (n == 1)
    return 0;
  else
    return 1 + fun(n / 2);
}

int main(void) {
  printf("%d", fun(8));
  return 0;
}
```

Output: `3`

| Stack (Call Stack) |
| ------------------ |
| fun(1): `return;`  |
| fun(2): `Act f2`   |
| fun(4): `Act f4`   |
| fun(8): `Act f8`   |
| main(): `Act m`    |

`fun(8)` => `return 1 + fun(8)` => `return 1 + fun(4)` => `return 1 + fun(2)` => `return 0`

#### Homework Problem

Identify whether the following programs are tail recursive or non-tail recursive.

**Program 1:**

```c
void fun2(int n) {
  if (n == 0) return;

  fun2(n / 2);
  printf("%d", n % 2);
}
```

**Program 2:**

```c
void fun2(int n) {
  if (n <= 0) return;

  printf("%d ", n);
  fun2(2 * n);
  printf("%d ", n);
}
```

**Answer:** Both programs are non-tail recursions.

## Advantage and Disadvantage of Recursion

### Advantage

- Every recursive program can be modeled into an iterative program but recursive programs are more elegant and requires relatively less lines of code.

**Example:** Program to calculate factorial of a number can be written in both iterative as well as recursive way as follows:

**Iterative:**

```c
int fact(int n) {
  int res = 1;

  while (n != 0) {
    res *= n;
    n--;
  }
  return res;
}

int main(void) {
  printf("%d", fact(5));
  return 0;
}
```

**Recursive:**

```c
int fact(int n) {
  if (n == 1)
    return 1;
  else
    return n * fact(n - 1);
}

int main(void) {
  printf("%d", fact(5));
  return 0;
}
```

### Disadvantage

- Recursive programs require more space than iterative programs.

Stack of iterative program of `fact()` above:

| Stack             |
| ----------------- |
| fact(5): `Act f5` |
| main(): `Act m`   |

Stack of recursive program of `fact()` above:

| Stack              |
| ------------------ |
| fact(1): `return;` |
| fact(2): `Act 2`   |
| fact(3): `Act 3`   |
| fact(4): `Act 4`   |
| fact(5): `Act 5`   |
| main(): `Act m`    |

## Question 1

Consider the follwing recursive C function:

```c
void get(int n) {
  if (n < 1) return;
  get(n - 1);
  get(n - 3);
  printf("%d", n);
}
```

If `get(6)` function is being called in `main()` then how many times will the `get()` function be invoked before returning to the `main()`?

- a) 15
- **b) 25** ✅
- c) 35
- d) 45

## Question 2

Determine how many number of times the star will be printed on the screen:

```c
void fun1(int n) {
  int i = 0;

  if (n > 1)
    fun1(n - 1);
  for (i = 0; i < n; i++)
    printf(" * ");
}
```

- a) n
- **b) n \* (n + 1) / 2** ✅
- c) n \* n
- d) None of the above

**Answer:**

If `n = 3` then we have the following function calls:

| Stack     |
| --------- |
| `fun1(3)` |
| `fun1(2)` |
| `fun1(1)` |

| Call      | Loop                      | Output                       |
| --------- | ------------------------- | ---------------------------- |
| `fun1(1)` | `for (i = 0; i < 1; i++)` | Star will be printed 1 time  |
| `fun1(2)` | `for (i = 0; i < 2; i++)` | Star will be printed 2 times |
| `fun1(3)` | `for (i = 0; i < 2; i++)` | Star will be printed 3 times |

So for `n = 2` star will be printed $1+2=3$ times and for `n = 3` star will be printed $1+2+3=6$ times.

So we could say for `n = 4` star will be printed $1+2+3+4=10$ times.

So for `n = k` star will be printed:

$$1+2+3+4+...+k=k\times(k+1)\div2$$

## Question 3

Consider the C function given below:

```c
int f(int j) {
  static int i = 50;
  int k;

  if (i == j) {
    printf("something");
    k = f(i);
    return 0;
  } else {
    return 0;
  }
}
```

Which one of the following is true?

- a) The function returns 0 for all values of j.
- b) The function prints the string "something" for all values of j.
- c) The function returns 0 when j = 50.
- **d) The function will exhaust the runtime stack or run into an infinite loop when j = 50.** ✅

**Answer:** If `j = 50` then the function go into an infinite loop as `i` retains the value 50 and `f()` calls itself with the function call `f(50)`.

## Question 4

Consider the following C function:

```c
int fun(int n) {
  int x = 1, k;

  if (n == 1) return x;
  for (k = 1; k < n; ++k)
    x = x + fun(k) * fun(n - k);
  return x;
}
```

The return value of `fun(5)` is:

- a) 0
- b) 26
- **c) 51** ✅
- d) 71

**Answer:**

`fun(5)`

= `1 + fun(1) * fun(4) + fun(2) * fun(3) + fun(3) * fun(2) + fun(4) * fun(1)`

= `1 + 2(fun(1) * fun(4) + fun(2) * fun(3))`

**= `1 + 2(fun(4) + fun(2) * fun(3))`**

`fun(2)` = `1 + fun(1) * fun(1)` = $1+1=2$

`fun(3)` = `1 + fun(1) * fun(2) + fun(2) * fun(1)`= $1+2+2=5$

`fun(4)` = `1 + fun(1) * fun(3) + fun(2) * fun(2) + fun(3) * fun(1)` = $1+5+4+5=15$

`fun(5)` = $1+2\times(15+2\times5)=51$

## Question 5

What will be the output of the following C program?

```c
void count(int n) {
  static int d = 1;

  printf("%d ", n);
  printf("%d ", d);
  d++;

  if (n > 1)
    count(n - 1);
  printf("%d ", d);
}

int main(void) {
  count(3);
  return 0;
}
```

- **a) `3 1 2 2 1 3 4 4 4`** ✅
- b) `3 1 2 1 1 1 2 2 2`
- c) `3 1 2 2 1 3 4`
- d) `3 1 2 1 1 1 2`

**Answer:**

| Stack              |
| ------------------ |
| count(1): `Act c1` |
| count(2): `Act c2` |
| count(3): `Act c3` |
| main(): `Act m`    |

# Rapid Fire Quiz 2

## Instructions

1. All questions are multiple choice questions.
2. There are 10 questions in this rapid fire quiz.
3. You have been provided 10 seconds to answer each question except the last question. You have been provided 15 seconds to answer the last question.
4. All questions carry one mark for correct answer and zero marks for incorrect answer. There is no negative marking.
5. Whatever we learned so far is now being tested in this quiz.
6. Please not down the scores you gain this quiz for self evaluation.
7. All questions are compulsory to attempt.

## Q1: Which of the following statements is true about static functions in C?

- a) Static functions are global functions
- **b) Static functions are restricted to the files where they are declared** ✅
- c) There is no concept like static functions in C
- d) None of the above

## Q2: State true or false. In C, is it mandatory to declare a function before use?

- a) True
- **b) False** ✅

## Q3: Which keyword is used to come out of a loop only for that iteration?

- a) `break`
- **b) `continue`** ✅
- c) `return`
- d) None of the above

## Q4: Which of the following ways to write a function prototype is correct?

1. `int fun(int var1, int var2)`
2. `int fun(int, int)`
3. `fun(int, int)`

- a) Only 1
- b) Only 2 and 3
- **c) Only 1 and 2** ✅
- d) All 1, 2 and 3

## Q5: Is this statement correct?

> C supports dynamic scoping

- a) Yes
- **b) No** ✅

## Q6: In C, parameters are always

- **a) Passed by value** ✅
- b) Passed by reference
- c) Both
- d) None of the above

## Q7: In C, what is the meaning of the following function prototype with empty parameter list?

```c
void fun();
```

- a) Function can only be called without any parameter.
- **b) Function can be called with any number of parameters of any type.** ✅
- c) Function can be called with any number of integer parameters.
- d) Function can be called with one integer parameter.

## Q8: Assuming int size is 4 bytes. What is going to happen when the following program runs?

```c
#include <stdio.h>

int main(void) {
  printf("Hi!\n");
  main();
  return 0;
}
```

- a) We can't use `main()` inside `main()`
- b) `Hi!` will be printed 2147483647 times i.e. $2^{31}-1$
- **c) `Hi!` would be printed until stack overflow happens for this program** ✅
- d) `Hi!` would be printed only once because when `main()` is used inside `main()`, it's ignored by compiler at run time.

## Q9: In the context of `break` and `continue` statements in C, pick the best statement.

- a) `break` and `continue` can be used in `for`, `while`, do-while loop body and `switch` body.
- **b) `break` and `continue` can be used in `for`, `while`, do-while loop body. But only `break` can be used in `switch` body.** ✅
- c) `break` and `continue` can be used in `for`, `while` and do-while loop body. Besides, `continue` and `break` can be used in `switch` and if-else body.
- d) None of the above

## Q10: Determine the output of the following C program?

```c
int main(void) {
  int i = 9;

  for (; i;) {
    printf("Hmmm...");
    i--;
  }
}
```

- a) `Hmmm...` will be printed 10 times
- **b) `Hmmm...` will be printed 9 times** ✅
- c) Compiler error
- d) None of the above

# Arrays

## Outline

1. Definition of array
2. Understanding the definition of array
3. Introduction to one-dimensional array

## Definition of Array

An array is a data structure containing a number of data values (all of which are of the same type).

### What is Data Structure?

Data structure is a format for _organizing_ and _storing data_.

Also, each data structure is designed to organize data to suit a specific purpose.

**Example:** Array is a data structure which you can visualize as follows:

|     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |

Imagine an array as a large chunk of memory divided into a smaller block of memory and each block is capable of storing a data value of some type.

This array consists of 10 data values:

| 5   | 6   | 10  | 13  | 56  | 76  | 1   | 2   | 4   | 8   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |

This array consists of only 5 data values:

| 5   | 6   | 10  | 13  | 56  |
| --- | --- | --- | --- | --- |

All elements have to be of the same type. Here we have an array containing elements of type `char`:

| 'a' | 'b' | 'c' | 'd' | 'e' |
| --- | --- | --- | --- | --- |

### One-Dimensional Array

The simplest form of array one can image is one-dimensional array.

| 5   | 6   | 10  | 13  | 56  | 76  | 1   | 2   | 4   | 8   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |

## Declaration of Array

### Outline

1. How to declare and define one-dimensional array?
2. How to access the array elements?
3. How to initialize one-dimensional array?

### Declaration and Definition of 1D Array

**Sytnax:** `type arr_name[no. of elements]`

**Example:** `int arr[5]`

Compiler will allocate a coniguous block of memory of size = `5 * sizeof(int)`.

The length of an array can be specified by any _integer_ constant expression.

- `int arr[5];`
- `int arr[5 + 5];`
- `int arr[5 * 3];`
- `int a;`, `int arr[a = 21 / 3];`

#### Best Practice

Specifying the length of an array using _macro_ is considered to be an excellent practice:

```c
#define N 10

int arr[N];
```

### Accessing Elements From 1D Array

To access an array element, just write: `array_name[index]`

Accessing the first element of an array: `arr[0]`

Accessing the second element of an array: `arr[1]`

### Initializing 1D Array

**Method 1:**

```c
int arr[5] = { 1, 2, 5, 67, 32 };
```

**Method 2:**

```c
int arr[] = { 1, 2, 5, 67, 32 };
```

**Method 3:**

```c
int arr[5];

arr[0] = 1;
arr[1] = 2;
arr[2] = 5;
arr[3] = 67;
arr[4] = 32;
```

**Method 4:**

```c
int arr[5];

for (i = 0; i < 5; i++)
  scanf("%d", &arr[i]);
```

**Question:** What if number of elements are lesser than the length specified?

```c
int arr[10] = { 45, 6, 2, 78, 5, 6 };
```

**Answer:** The remaining locations of the array are filled by value 0.

```c
int arr[10] = { 45, 6, 2, 78, 5, 6, 0, 0, 0, 0 };
```

#### A Small Tip

To initialize an array with zero values, instead of writing this:

```c
int arr[10];

for (i = 0; i < 10; i++)
  arr[i] = 0;
```

We can write like this:

```c
int arr[10] = { 0 };
```

But why not `int arr[10] = {};`?

You must have to specify at least 1 element. It cannot be completly empty. Also it's illegal to add more elements than the length of an array.

#### Summary

- If the number of elements are lesser than the length of the array then the rest of the locations are automatically filled by value 0.
- Easy way to initialize an array with all zeros is given by: `int arr[10] = { 0 };`

⛔️ At the time of initialization, never leave these flower brackets `{}` empty and also never exceed the limit of number of elements specified by the length of an array.

#### Designated Initialization

Sometimes we want something like this:

```c
int arr[10] = { 1, 0, 0, 0, 0, 2, 3, 0, 0, 0 };
```

We want:

- 1 in position 0
- 2 in position 5
- 3 in position 6

We could achieve that in this way:

```c
int arr[10] = { [0] = 1, [5] = 2, [6] = 3 };
```

This way of initialization is called _designated initialization_. And each number in the square brackets is said to be a _designator_.

##### Advantages

1. No need to bother about the entries containing zeros.
2. No need to bother about the order at all:

```c
// These are the same
int a[15] = { [0] = 1, [5] = 2 };
int a[15] = { [5] = 2, [0] = 1 };
```

##### Be Careful!

If the length of an array is $n$, then each designator must be between 0 and $n-1$.

##### What If I Won't Mention The Length?

- Designator could be any non-negative integer.
- Compiler will deduce the length of the array from the largest designator in the list.

```c
int a[] = { [5] = 90, [20] = 4, [1] = 45, [49] = 78 };
```

Because of the designator `[49] = 78`, maximum length of this array would be 50.

Also, we can mix both the traditional way and designated initialization:

```c
int a[] = { 1, 7, 5, [5] = 90, 6, [8] = 4 };
// is equivalent
int a[] = { 1, 7, 5, 0, 0, 90, 6, 0, 4 };
```

But, if there is a clash, then designated initializer will win.

```c
int a[] = { 1, 2, 3, [2] = 4, [6] = 45 };
// is equivalent
int a[] = { 1, 2, 4, 0, 0, 0, 45 };
```

## Question 1

Write a program to print the following numbers in reverse order:

| 34  | 56  | 54  | 32  | 67  | 89  | 90  | 32  | 21  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |

Assume that all these numbers are stored in an array.

**Answer:**

```c
int a[9] = { 34, 56, 54, 32, 67, 89, 90, 32, 21 };
int i;

// Original order
for (i = 0; i < 9; i++) {
  printf("%d ", a[i]);
}
printf("\n");

// Reverse order
for (i = 8; i >= 0; i--) {
  printf("%d ", a[i]);
}
printf("\n");
```

## Question 2

Write a program to check whether any of the digits in a number appears more than once:

**Example:**
Input: 67827<br/>
Output: `Yes`

**Part 1**

```c
int seen[10] = { 0 };
```

We initialize an array `seen` filled with zero values. The indexes (0 - 9) represent the digits in a number. In anumber, we iterate over every digit and increment the specific digit if it has been seen on the right index. 23 would increment the value at index 2 and index 3. If an index has a value higher than 2 we stop the program and return `Yes`.

**Part 2:**

```c
while (N > 0) {
  rem = N % 10;

  if (seen[rem] == 1) break;
  seen[rem] = 1;
  N = N / 10;
}
```

Here we take the last digit of a number in each iteration and check if this digit has been seen yet. If it has been seen we `break` from the loop, else we put the value zero in the index. Then get the next digit.

**Part 3:**

Two cases:

- When `N > 0` and `break`
- When `N == 0`

```c
if (N > 0)
  printf("Yes");
else
  printf("No");
```

This would be the final C program:

```c
#include <stdio.h>

int main(void) {
    int seen[10] = {0};  // Part 1
    int N;

    printf("Enter the number: ");
    scanf("%d", &N);

    int rem;
    while (N > 0) {  // Part 2
        rem = N % 10;

        if (seen[rem] == 1) break;
        seen[rem] = 1;
        N /= 10;
    }

    if (N > 0)  // Part 3
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
```

## Count Array Element Using `sizeof()` Operator

**Syntax:** `sizeof(name_of_arr) / sizeof(name_of_arr[0])`

### `sizeof(name_of_arr)`

```c
int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
```

There are total 10 integers.

Assume that each integer requires 4 bytes.

`sizeof(a)` = $4\times10$ = 40 bytes

### `sizeof(name_of_arr[0])`

```c
int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
```

`sizeof(a[0])` = 4 bytes

So the final calculation is: $40/4=10$. So the array has 10 elements in it which makes its length 10.

## Multi-Dimensional Arrays

### Definition And Syntax

Multi-dimensional arrays can be defined as an _array of arrays_.

General form of declaring $n$-dimensional array is as follows:

```
type name_of_array[size1][size2]...[sizeN];
```

**Example:**

```c
int a[3][4];    // Two dimensional array
int a[3][4][6]; // Three dimensional array
```

### Size Calculation

Size of multi-dimensional array can be calculated by multiplying the size of all the dimensions.

**Example:**

size of `a[10][20]` = $10\times20=200$ = $200\times4=800$ bytes<br/>
size of `a[4][10][20]` = $4\times10\times20=800$ = $800\times4=3200$ bytes

Assuming size of integer is 4 bytes.

### Syntax

The basic form of declaring two dimensional array is:

```
type name_of_array[x][y];
```

where `x` and `y` are representing the size of arrays

_Recall that_ a multidimensional array is an array of arrays.

How to declare a 1D array? `int arr[5];`

How to declare a 2D array? `int arr[4][5];`

```c
int arr[4][5];
```

`[4]` - number of rows

`[5]` - number of columns

size of `arr[4][5]` = $4\times5=20$ elements = $20\times4=80$ bytes

### How to Initialize 2D Array?

**Method 1:**

```c
int a[2][3] = {1, 2, 3, 4, 5, 6};
```

| I     | 0   | 1   | 2   |
| ----- | --- | --- | --- |
| **0** | 1   | 2   | 3   |
| **1** | 4   | 5   | 6   |

**I:** Index

**Method 2:**

```c
int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
```

### How To Access 2D Array Elements?

Using row index and column index.

**Example:**

We can access element stored in 1st row and 2nd column of below array

| I     | 0   | 1   | 2   |
| ----- | --- | --- | --- |
| **0** | 1   | 2   | 3   |
| **1** | 4   | 5   | 6   |

using: `a[0][1]` = 2

### How To Print 2D Array Elements?

1D array elements can be printed using single `for` loop:

```c
int a[5] = {1, 2, 3, 4, 5};

for (i = 0; i < 5; i++)
  printf("%d ", a[i]);
```

2D array elements can be printed using two nested `for` loops:

```c
int a[2][3] = {{1, 2, 3}, {4, 5, 6}};

for (i = 0; i < 2; i++) {
  for (j = 0; j < 3; j++) {
    printf("%d ", a[i][j]);
  }
}
```

Output: `1 2 3 4 5 6`

### Three Dimensional Array

```c
int arr[2][3][3];
```

#### Initializing 3D Array

**Method 1:**

```c
int a[2][2][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
```

**Method 2:**

```c
int a[2][2][3] = {
  {{1, 2, 3}, {4, 5, 6}},
  {{7, 8, 9}, {10, 11, 12}}
};
```

| I     | 0   | 1   | 2   |
| ----- | --- | --- | --- |
| **0** | 1   | 2   | 3   |
| **1** | 4   | 5   | 6   |

$2\times3$

| I     | 0   | 1   | 2   |
| ----- | --- | --- | --- |
| **0** | 7   | 8   | 9   |
| **1** | 10  | 11  | 12  |

$2\times3$

#### Printing 3D Array

```c
int a[2][2][3] = {
  {{1, 2, 3}, {4, 5, 6}},
  {{7, 8, 9}, {10, 11, 12}}
};

for (i = 0; i < 2; i++) {
  for (j = 0; j < 2; j++) {
    for (k = 0; k < 3; k++) {
      printf("%d ", a[i][j][k]);
    }
  }
}
```

Output:

```
1 2 3 4 5 6 7 8 9 10 11 12
```

### Question 1

Write a program that reads a 5x5 array of integers and then prints the row sum and the column sum:

| Row               | Integers         |
| ----------------- | ---------------- |
| Enter row 1:      | `8 3 9 0 10`     |
| Enter row 2:      | `3 5 17 1 1`     |
| Enter row 3:      | `2 8 6 23 1`     |
| Enter row 4:      | `15 7 3 2 9`     |
| Enter row 5:      | `6 14 2 6 0`     |
|                   |                  |
| **Row total:**    | `30 27 40 36 28` |
| **Column total:** | `34 37 37 32 21` |

```c
int main(void) {
  int a[5][5] = {
    {8, 3, 9, 0, 10},
    {3, 5, 17, 1, 1},
    {2, 8, 6, 23, 1},
    {15, 7, 3, 2, 9},
    {6, 14, 2, 6, 0}
  };

  int i, j;
  int sum = 0;

  // Row sum
  printf("Row total: ");

  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5; j++) {
      sum += a[i][j];
    }
    printf("%d", sum);
    sum = 0;
  }

  // Column sum
  printf("\nColumn total: ");
  for (j = 0; j < 5; j++) {
    for (i = 0; i < 5; i++) {
      sum += a[i][j];
    }
    printf("%d", sum);
    sum = 0;
  }
  putchar('\n');
  return 0;
}
```

### Matrix Multiplication

#### Basics Of Matrix Multiplication

| 1     | 2     | 3     |
| ----- | ----- | ----- |
| **1** | **2** | **1** |
| **3** | **1** | **2** |

$3\times3$

| 1     | 2     | 3     |
| ----- | ----- | ----- |
| **1** | **2** | **1** |
| **3** | **1** | **2** |

$3\times3$

Firstly, we multiply first row of the first matrix with first column of the second matrix:

$$1\times1+1\times2+3\times3=12$$

Then we take the first row of first matrix with the second column of second matrix:

$$1\times2+2\times2+3\times1=9$$

Then we take the first row of first matrix with the third column of second matrix:

$$1\times3+2\times1+3\times2=11$$

When we continue with this pattern, we get the following end result:

| 12     | 9      | 11     |
| ------ | ------ | ------ |
| **6**  | **7**  | **7**  |
| **10** | **10** | **14** |

$3\times3$

#### Important Point

👉🏼 In order to multiply two matrices, # columns of 1st matrix = # of rows of 2nd matrix.

It is mandatory to have no. of columns of 1st matrix to be equal to no. of rows of 2nd matrix.

👉🏼 Also, size of the resultant matrix depends on # of rows of 1st matrix and # of columns of 2nd matrix.

#### Program For Matrix Multiplication

We want something like this:

```
$ Enter the rows and columns of matrix a: 3 3
$ Enter the elements of matrix a:

1 2 3
1 2 1
3 1 2

$ Enter the rows and columns of matrix b: 3 3
$ Enter the elements of matrix b:

1 2 3
1 2 1
3 1 2

Resultant matrix:

12 9 11
6 7 7
10 10 14
```

**Part 1:**

```
$ Enter the rows and columns of matrix a: 3 3
```

This is the C program fragment:

```c
int a[MAX][MAX];
int arows, acolumns;

printf("Enter the rows and columns of the matrix a: ");
scanf("%d %d", &arows, &acolumns);
```

**Part 2:**

```c
printf("Enter the elements of matrix a:\n");

for (i = 0; i < arows; i++) {
  for (j = 0; j < acolumns; j++) {
    scanf("%d", &a[i][j]);
  }
}
```

**Part 3:**

This is the most important part.

```c
int product[MAX][MAX];
int sum = 0;

for (i = 0; i < arows; i++) {
  for (j = 0; j < bcolumns; j++) {
    for (k = 0; k < brows; k++) {
      sum += a[i][k] * b[k][j];
    }
    product[i][j] = sum;
    sum = 0;
  }
}
```

This would be the full C program:

```c
#include <stdio.h>
#define MAX 50

int main(void) {
    int a[MAX][MAX], b[MAX][MAX], product[MAX][MAX];
    int arows, acolumns, brows, bcolumns;
    int i, j, k;
    int sum = 0;

    printf("Enter the rows and columns of the matrix a: ");
    scanf("%d %d", &arows, &acolumns);

    printf("Enter the elements of matrix a:\n");
    for (i = 0; i < arows; i++) {
        for (j = 0; j < acolumns; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the rows and columns of the matrix b: ");
    scanf("%d %d", &brows, &bcolumns);

    if (brows != acolumns)
        printf("Sorry! We cannot multiply the matrices a and b");
    else {
        printf("Enter the elements of matrix b:\n");
        for (i = 0; i < brows; i++) {
            for (j = 0; j < bcolumns; j++) {
                scanf("%d", &b[i][j]);
            }
        }
    }
    putchar('\n');

    // Calculating resultant matrix
    for (i = 0; i < arows; i++) {
        for (j = 0; j < bcolumns; j++) {
            for (k = 0; k < brows; k++) {
                sum += a[i][k] * b[k][j];
            }
            product[i][j] = sum;
            sum = 0;
        }
    }

    // Printing array elements
    printf("Resultant matrix\n");
    for (i = 0; i < arows; i++) {
        for (j = 0; j < bcolumns; j++) {
            printf("%2d ", product[i][j]);
        }
        putchar('\n');
    }
}
```

## Constant Arrays In C

Either one-dimensional or multi-dimensional arrays can be made constant by starting the declaration with the keyword `const`.

**Example:**

```c
const int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
a[1] = 45;
```

This will produce an error, because this array is read-only!

### Advantage

It assures us that the program will not modify the array which may contain some valuable information.

It also helps the compiler to catch errors by informing that there is no intention to modify this array.

## Variable Length Arrays In C

We can modify our old program to reverse a series of numbers so the array stores a variable length:

```c
#include <stdio.h>

int main(void) {
    int n;

    printf("Enter the number of elements you want to reverse: \n");
    scanf("%d", &n);

    int a[n];
    int i;

    printf("Enter all the %d elements: \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Elements in reverse order are: \n");
    for (i = n - 1; i >= 0; i--)
        printf("%d ", a[i]);
    putchar('\n');
    return 0;
}
```

### Advantages

- At the time of execution, we can decide the length of the array.
- No need to choose the fix length while writing the code.
- Even arbitrary expressions are possible:
  - `int a[3 * i + 5];`
  - `int a[k / 7 + 2];`
  - `int a[i + j];`

### Points To Be Noted

1. Variable length arrays _cannot have static storage duration_.
2. Variable length arrays do not have an initializer.

# Pointers

- Pointer is a special variable that is capable of storing some address.
- It points to a memory location where the first byte is stored.

## Declaring & Initializing Pointers

General syntax for declaring pointer variables:

```
type *pointer_name
```

Here the data type refers to the type of the value that the pointer will point to.

**Example:**

```c
int *ptr;   // Points to integer value
char *ptr;  // Point to character value
float *ptr; // Points to float value
```

### Need Of Address Of Operator

- Simlpy declaring a pointer is not enough.
- It is important to _initialize pointer_ before use.
- One way to initialize a pointer is to _assign address of some variable_.

```c
int x = 5;    // Address 1000
int *ptr;     // Address 2000

ptr = &x;     // ptr points to address of x (1000)
```

We can also write all these lines on a single line:

```c
int x = 5, *ptr = &x;
```

## Value Of Operator In Pointers

_Value of_ operator/indirection operator/dereference operator is an operator that is used to access the value stored at the location pointed to by the pointer.

When we have this line:

```c
int x = 5, *ptr = &x;
```

We can access the value to which the pointer points to by adding a star (`*`) in front of the pointer name.

```c
printf("%d", *ptr);
```

Output: `5`

We can also change the value of the object pointed by the pointer.

**Example:**

```c
int x = 10;
int *ptr = &x;

*ptr = 4;
printf("%d", *ptr);
```

Output: `4`

Now the variable `x` stores the value 4.

### A Word Of Caution

⛔️ Never apply the indirection operator to the uninitialized pointer.

**Example:**

```c
int *ptr;
printf("%d", *ptr);
```

Output: _Error_

⛔️ Assigning value to an uninitialized pointer is dangerous.

```c
int *ptr;
*ptr = 1;
```

Output: _Segmentation Fault (SIGSEGV)_

Segmentation fault is caused by a program trying to _read_ or _write_ an illegal memory location.

## Pointer Assignment

```c
int i = 10; // Memory address: 1000
int *p, *q;

p = &i;     // p stores memory address of i: 1000
q = p;      // q stores memory address of i: 1000
printf("%d %d", *p, *q);
```

Output: `10 10`

```c
int i = 10, j = 20;
int *p, *q;

p = &i;
q = &j;
*q = *p;
```

Output: `10 10`

### Homework Problem

Predict the output of the following C program:

```c
int i = 1;
int *p = &i, *q;

q = p;
*q = 5;
printf("%d", *p);
```

Output: `5`

**Answer:**

`i` is initialized to a value of 1. Then we store the address of `i` into the pointer `*p`. Then we store this address in the pointer `*q`. So all of these variables have the same memory address. Next we assign `*q` a value of 5 through dereferencing. So the value 5 is stored in this memory location making all other variables store the same value which is 5.

## Application Of Pointers

### Idea

Pseudocode:

```
int a[] = {23, 45, 6, 98};

int min, max;
min = max = a[0];

for i = 1 to 3:
  1. if a[i] < min then
      min = a[i]
  2. if a[i] > max then
      max = a[i]
```

In a C program the code would look like this:

```c
#include <stdio.h>

void min_max(int arr[], int len, int *min, int *max) {
    *min = *max = arr[0];
    int i;

    for (i = 1; i < len; i++) {
        if (arr[i] > *max) *max = arr[i];
        if (arr[i] < *min) *min = arr[i];
    }
}

int main(void) {
    int a[] = {23, 4, 21, 98, 987, 45, 32, 10, 123, 986, 50, 3, 4, 5};
    int min, max;
    int len = sizeof(a) / sizeof(a[0]);

    min_max(a, len, &min, &max);
    printf("Minimum value in the array is: %d\n", min);
    printf("Maximum value in the array is: %d\n", max);
    return 0;
}
```

Output:

```
Minimum value in the array is: 3
Maximum value in the array is: 987
```

## Returning Pointers

This is a program to find the middle of an array:

```c
int main(void) {
  int a[] = {1, 2, 3, 4, 5};
  int n = sizeof(a)/sizeof(a[0]);
  int *mid = find_mid(a, n);

  printf("%d", *mid);
  return 0;
}
```

This is the function `find_mid()`:

```c
int *find_mid(int a[], int n) {
  return &a[n / 2];
}
```

Output: `3`

### Word Of Caution

Never every try to return the address of an _automatic (local) variable_.

**Example:**

```c
int *fun(void) {
  int i = 10;
  return &i;
}

int main(void) {
  int *p = fun();

  printf("%d", *p);
  return 0;
}
```

⛔️ Warning: Functino returns address of local variable.

This code **won't compile!**

## Important Questions

### Question 1: Consider the following two statements

```c
int *p = &i;
p = &i;
```

First statement is the declaration and second is simple assignment statement. Why isn't in second statement, `p` preceded by `*` symbol?

**Solution:** In C, `*` symbol has different meanings depending on the context in which it's used.

At the time of declaration, `*` symbol is not acting as an indirection operator. `*` symbol in the first statement tells the compiler that `p` is a pointer to an integer.

But if we write `*p = &i` then it is wrong, because here `*` symbol indicates the indirection operator and we cannot assign the address to some integer value.

Therefore, in the second statement, there is no need of `*` symbol in front of `p`. It simply means we are assigning the address to a pointer.

### Question 2: What is the output of the following program?

```c
void fun(const int *p) {
  *p = 0;
}

int main(void) {
  const int i = 10;

  fun(&i);
  return 0;
}
```

Output: _Error: Assignment of read-only location \*p_

### Question 3: How to print the address of a variable?

**Solution:** Use `%p` as a format specifier in `printf()` function.

```c
int main(void) {
  int i = 10;
  int *p = &i;

  printf("The address of variable i is %p", p);
  return 0;
}
```

Output:

```
The address of variable i is 0x16d76f3f8
```

### Question 4: If `i` is a variable and `p` points to `i`, which of the following expressions are aliases of `i`?

- **a) `*p`** ✅
- b) `*&p`
- c) `&p`
- d) `*i`
- **e) `*&i`** ✅

**Example:**

```c
int i = 10;
int *p = &i;
```

Suppose we have for `i` a value of 10 in memory address _1000_ and for `p` a value of _1000_ in memory address _2000_.

- a) `*p` = `*(1000)` = 10
- b) `*&p` = `*(&p)` = `*(2000)`
- c) `&p` = 2000
- d) `*i` = `*(10)` doesn't make sense
- e) `*&i` = `*(&i)` = `*(1000)` = 10

## Pointer Arithmetic - Addition

We want the pointer `*p` to point to the first element of the array `a`. What would be the code?

```c
p = &a[0];
```

What happens if we add some integer to the pointer?

```c
p = p + 1;
```

means moving the pointer 3 positions in forward direction. So `p` will store the address of the 4th element (index 3) in the array.

So in general, if `p` point to `a[i]`, then

`p = p + j` = `&a[i + j]`

or in our example:

`p = p + 3` = `&a[0 + 3]`

So, **what happened?**

When we add to a pointer, we move the pointer to the next memory location.
For an array of integers, an integer will take 4 bytes of memory (depends on system). So if we add 3 to pointer `p`, we move forward 12 bytes to the next memory location.

### Homework Problem

Let's say we have a pointer `p` and an array `a`. Initially, `p` contains the address of 3rd element of array i.e. `p = &a[2];`.

What will be the index of the array after this operation: `p = p + 2`?

**Answer:** Initially, `p` has the address of `a[2]`, so when we add 2 to `p` we shift 2 positions towards right from the inital address, so `p = &a[4]`.

## Pointer Arithmetic - Subtraction

If we had `p = &a[3]` and we apply the operation `p = p - 3` then we will have `p` will have the address of `a[0]`.

Initially, if `p` point to `a[i]`, then

`p = p - j` = `&a[i - j]`

or, if `p` points to `a[3]`, then

`p = p - 3` = `&a[3 - 3]` = `&a[0]`

### Subtracting One Pointer From Another Pointer

Result is distance between the two pointers.

If `p` points to the second element of the array (`a[2]`) and `q` points to the sixth element (`a[6]`), then we have to subtract the two pointers:

`q - p = 4`

### Undefined Behaviours

Performing arithmetic on pointers which are not pointing to array element leads to undefined behaviour.

```c
int main(void) {
  int i = 10;
  int *p = &i;

  printf("%d", *(p + 3));
  return 0;
}
```

Output: _Different outputs everytime_

If two pointers are pointing to different array then performing subtraction between them leads to undefined behaviour.

```c
int main(void) {
  int a[] = {1, 2, 3, 4};
  int b[] = {10, 20, 30, 40};
  int *p = &a[0];
  int *q = &b[3];

  printf("%d", q - p);
  return 0;
}
```

Output: _Different outputs everytime_

## Pointer Arithmetic - Increment & Decrement

### Post Increment

```c
int main(void) {
  int a[] = {5, 16, 7, 89, 45, 32, 23, 10};
  int *p = &a[0];

  printf("%d ", *(p++));
  printf("%d", *p);
  return 0;
}
```

Output: `5 16`

### Pre Increment

```c
int main(void) {
  int a[] = {5, 16, 7, 89, 45, 32, 23, 10};
  int *p = &a[0];

  printf("%d", *(++p));
  return 0;
}
```

Output: `16`

### Pre & Post Decrement

```c
int main(void) {
  int a[] = {5, 16, 7, 89, 45, 32, 23, 10};
  int *p = &a[2];

  printf("%d ", *(--p));
  printf("%d", *(p--));
  return 0;
}
```

Output: `16 16`

## Pointer Arithmetic - Comparing Pointers

- Use relational operators (`<`, `>`, `<=`, `>=`) and equality operators (`==`, `!=`) to compare pointers.
- Only possible when both pointers point to same array.
- Output depends upon the relative positions of both pointers.

**Example:**

```c
int main(void) {
  int a[] = {1, 2, 3, 4, 5, 6};
  int *p = &a[3];
  int *q = &a[5];

  printf("%d\n", p <= q);   // Output: 1
  printf("%d\n", p >= q);   // Output: 0

  q = &a[3];
  printf("%d", p == q);     // Output: 1
  return 0;
}
```

### Homework Problem

What is the output of the following C program?

```c
int main(void) {
  int a[] = {5, 16, 7, 89, 45, 32, 23, 10};
  int *p = &a[1], *q = &a[5];

  printf("%d ", *(p + 3));
  printf("%d ", *(q - 3));
  printf("%d ", q - p);
  printf("%d ", q < p);
  printf("%d ", *p < *q);
  return 0;
}
```

- a) `45 7 4 1 1`
- b) `45 4 7 1 1`
- c) `44 7 4 1 0`
- **d) `45 7 4 0 1`** ✅

**Answer:**

Initially, `*p` points to 16 and `*q` points to 32.

The following are the various `printf()` statements:

1. `*(p + 3)` = `*(&a[1 + 3])` = `*(&a[4])` = 45
2. `*(q - 3)` = `*(&a[5 - 3])` = `*(&a[2])` = 7
3. `q - p` = $1020-1004\div4=4$
4. `q < p` = 1020 < 1004 = 0 (`false`)
5. `*p < *q` = 16 < 32 = 1 (`true`)

## Program - Calculate Sum Of Elements Of Array Using Pointers

```c
int main(void) {
  int a[] = {11, 22, 36, 5, 2};
  int sum = 0, *p;

  for (p = &a[0]; p <= &a[4]; p++)
    sum += *p;

  printf("Sum is %d\n", sum);
  return 0;
}
```

Output: `Sum is 76`

## Using Array Name As Pointer

💡 **Fact:** Name of an array can be used as a pointer to the _first element_ of an array.

**Example:**

```c
int main(void) {
  int a[5];

  *a = 10;
  printf("%d", a[0]);
  return 0;
}
```

Output: `10`

Supposing the first element of array `a` has a memory address of 1000:

`*a = 10` = `*(1000) = 10`

Let's do some pointer arithmetic:

```c
int main(void) {
  int a[5];

  *(a + 1) = 20;
  printf("%d", a[1]);
  return 0;
}
```

Output: `20`

`*(a + 1) = 20` = `*(1000 + 1 * 4) = 20` = `*(1004) = 20`

So it is clear that

`*(a + i) = a[i]`

Now we can rewrite the program where we calculated the sum of an array:

```c
int main(void) {
  int a[] = {11, 22, 36, 5, 2};
  int sum = 0, *p;

  for (p = a; p <= a + 4; p++)
    sum += *p;

  printf("Sum is %d", sum);
  return 0;
}
```

Output: `Sum is 76`

⛔️ **Be careful:** It is true that we can use array names as pointers, but assigning a new address to them is not possible!

```c
int main(void) {
  int a[] = {11, 22, 36, 5, 2};

  printf("%p", a++);
  return 0;
}
```

This will output an error because `a++` means `a = a + 1` so we are trying to assign address 1004 to array `a` which is not possible!

Recall that name of the array indicates the base address of the array i.e. 1000. We cannot change this.

Obviously, we can write something like this:

```c
int main(void) {
  int a[] = {11, 22, 36, 5, 2};

  printf("%p", a + 1);
  return 0;
}
```

Here we are not trying to assign some new address to `a`. We are simply accessing the address of the second element of the array.

**Alternative:**

```c
int main(void) {
  int a[] = {11, 22, 36, 5, 2};
  int *p = a;

  printf("%d", *(++p));
  return 0;
}
```

Output: `22`

We can assign the first element of the array to the pointer `*p` and then increment the pointer and dereference it to print the value. This is allowed.

## Program - Reverse A Series Of Numbers Using Pointers

```c
#include <stdio.h>
#define N 5

int main(void) {
    int a[N], *p;

    printf("Enter %d elements in the array: ", N);
    for (p = a; p <= a + N - 1; p++)
        scanf("%d", p);

    printf("Elements in reverse order:\n");
    for (p = a + N - 1; p >= a; p--)
        printf("%d ", *p);
    putchar('\n');

    return 0;
}
```

Output:

```
$ Enter 5 elements in the array: 10 20 30 40 50
Elements in reverse order:
50 40 30 20 10
```

## Passing Array Name As An Argument To A Function

```c
int add(int b[], int len) {
  int sum = 0, i;

  for (i = 0; i < len; i++)
    sum += b[i];
  return sum;
}

int main(void) {
  int a[] = {1, 2, 3, 4};
  int len = sizeof(a)/sizeof(a[0]);

  printf("%d", add(a, len));
  return 0;
}
```

Output: `10`

Note that we are _not_ passing the whole array in `add(a, len)`. We are just passing the base address of the array.

An array name is always treated as a pointer. You can also write `*b` instead of `b[]`.

## Using Pointers With 2D Arrays

### Difference Betweent Row Major And Column Major Order

**Row major order:** Elements are stored row by row.

**Column major order:** Elements are stored column by column.

👉🏼 C stores multidimensional arrays in row major order.

```c
for (i = 0; i < row; i++)
  for (j = 0; j < col; j++)
    printf("%d ", a[i][j]);
```

| 1     | 2     | 3    | 4    |
| ----- | ----- | ---- | ---- |
| Row 0 | Row 0 | Row1 | Row1 |

| a      | c0  | c1  |
| ------ | --- | --- |
| **r0** | 1   | 2   |
| **r1** | 3   | 4   |

- row = 2
- col = 2

Using pointers:

```c
for (p = &a[0][0]; p <= &a[row - 1][col - 1]; p++)
  printf("%d ", *p);
```

Output: `1 2 3 4`

| 1         | 2         | 3         | 4         |
| --------- | --------- | --------- | --------- |
| `a[0][0]` | `a[0][1]` | `a[1][0]` | `a[1][1]` |
| Row 0     | Row 0     | Row 1     | Row 1     |

- row = 2
- col = 2

## Address Arithmetic in Mutlidimensional Arrays

### 1D Array

| a              | 1    | 2    | 3    | 4    |
| -------------- | ---- | ---- | ---- | ---- |
| Memory address | 1000 | 1004 | 1008 | 1012 |

`int a[4];` means array of 4 integers. So `a` is a pointer to the first element of the array.

- `a` => 1000
- `*a` => 1

### 2D Array

| a              | 1    | 2    | 3    | 4    |
| -------------- | ---- | ---- | ---- | ---- |
| Memory address | 1000 | 1004 | 1008 | 1012 |
| Row            | 1    | 1    | 2    | 2    |

`int a[2][2];`

Here `a` is a pointer to the first 1D array.

- `a` => 1000 (pointer to 1st 1D array)
- `a + 1` => 1008 (pointer to 2nd 1D array)
- `*a` => \*(pointer to 1st 1D array) => address to first element of first 1D array
  - `*a` = `*(a + 0)` = `a[0]` = `&a[0][0]`
- `**a` => `*(*a)` => `*(*(a + 0))` => `*(&a[0][0])` => `a[0][0]` => 1
- `*(a + 1)` => \*(pointer to 2nd 1D array) => pointer to 1st element of 2nd 1D array
- `**(a + 1)` => \*\*(pointer to 2nd 1D array) => \*(pointer to 1st element of 2nd 1D array) => 3
- `*(a + 1) + 1` => pointer to 1st element of 2nd 1D array + 1 => pointer to the 2nd element of 2nd 1D array
- `*(*(a + 1) + 1)` => \*pointer to 2nd element of 2nd 1D array => 4 => `a[1][1]`

### 3D Array

| a              | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    |
| -------------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| Memory address | 1000 | 1004 | 1008 | 1012 | 1016 | 1020 | 1024 | 1028 |
| 2D array       | 1st  | 1st  | 1st  | 1st  | 2nd  | 2nd  | 2nd  | 2nd  |

`int a[2][2][2];`

- `a`: Pointer to the first 2D array
- `[2]`: Two 2D arrays
- `[2]`: Each of which contains two 1D arrays
- `[2]`: Each of which contains two elements

---

- `a` => pointer to 1st 2D array = 1000
- `a + 1` => pointer to 2nd 2D array = 1016
- `*(a + 1)` => pointer to 1st 1D array of 2nd 2D array => 1016
- `*(*(a + 1))` => pointer to 1st element of 1st 1D array of 2nd 2D array
- `**(*(a + 1))` => 5 => `a[1][0][0]`

We want to access 2nd element of the above array.

1. `a`: Pointer to 1st 2D array
2. `*a`: Pointer to 1st 1D array of 1st 2D array
3. `**a`: Pointer to 1st element of 1st 1D array of 1st 2D array
4. `**a + 1`: Pointer to 2nd element of 1st 1D array of 1st 2D array
5. `*(**a + 1)`: 2nd element of 1st 1D array of 1st 2D array

### Homework Problem

| a              | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    |
| -------------- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| Memory address | 1000 | 1004 | 1008 | 1012 | 1016 | 1020 | 1024 | 1028 |
| 2D array       | 1st  | 1st  | 1st  | 1st  | 2nd  | 2nd  | 2nd  | 2nd  |

How to access the second last element of the above array using pointer arithmetic?

1. `a + 1`: Pointer to 2nd 2D array
2. `*(a + 1) + 1`: Pointer to 2nd 1D array of 2nd 2D array
3. `*(*(a + 1) + 1)`: Pointer to 1st element of 2nd 1D array of 2nd 2D array
4. `**(*(a + 1) + 1))`: 1st element of 2nd 1D array of 2nd 2D array => 7

## Pointers GATE Question 1

Consider the following declaration of two dimensional array in C:

```c
char a[100][100];
```

Assuming that the main memory is byte addressable and that the array is stored starting from the memory address 0, the address of `a[40][50]` is:

- a) 4040
- **b) 4050** ✅
- c) 5040
- d) 5050

**Answer:**

`a[100][100]` means we have 100 1D arrays, each containing 100 elements (100 rows & 100 columns). We want the address `&a[40][50]`. We can find this by this formula:

Formula: `&a[i][j]` = $BA+[(i-lb_1)\times NC+(j-lb_2)]\times c$

- $BA$ = Base address of whole 2D array
- $NC$ = Number of columns
- $c$ = Size of data type of elements stored in array (in bytes)
- $lb_1$ = Lower bound of rows
- $ub_1$ = Upper bound of rows
- $lb_2$ = Lower bound of columns
- $ub_2$ = Upper bound of columns

In our example, we have the following data:

- $BA=0$
- $NC=100$
- $c=$ 1 bytes
- `a[0...99][0...99]`

So if we fill the formula with the above data we get:

`&a[40][50]` = $0+[(40-0)\times100+(50-0)]\times1=4000+50=4050$

So the address is **4050**.

To understand the formula, we can look at this example:

We have an array `int a[5][5];`. We have to find `&a[2][2]`.

Let's assume that `a[2] = b`. So we can write `&b[2]`. Then we can transform it to `&*(b + 2)`, which is `&*(*(a + 2) + 2)`.

`a` is a pointer to the first 1D array. We add 2 to it `*(a + 2)`. We assume integer size is 4 bytes and memory address of first element is 1000. We move 2 rows down the 2D array which consists of 5 elements per row and each element is 4 bytes. So we have `*(1000 + 2 * 5 * 4)` = `*(1000 + 40)` = `*(1040)` = `1040`. We are now in the first element of the second row in the 2D array. Now we add 2 to move forward 2 elements in the 1D array: `*(1040 + 2)` = `*(1040 + 2 * 4)` = `*(1048)`.

So now we have `&*(1048)` and the `&` and `*` cancel each other. So we have **1048** which is the address of `&a[2][2]`.

## Pointers GATE Question 2

What is the output of the following C code? Assume that address of `x` is 2000 (in decimal) and an integer requires 4 bytes of memory.

```c
#include <stdio.h>

int main(void) {
    unsigned int x[4][3] = {{1, 2, 3}, {4, 5, 6},
                            {7, 8, 9}, {10, 11, 12}};
    printf("%u, %u, %u", x + 3, *(x + 3), *(x + 2) + 3);
}
```

- **a) 2036, 2036, 2036** ✅
- b) 2012, 4, 2204
- c) 2036, 10, 10
- d) 2012, 4, 6

**Answer:**

This is how the array would look like in memory:

| x   | 1    | 2    | 3    | 4    | 5    | 6    | 7    | 8    | 9    | 10   | 11   | 12   |
| --- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| MA  | 2000 | 2004 | 2008 | 2012 | 2016 | 2020 | 2024 | 2028 | 2032 | 2036 | 2040 | 2044 |
| AN  | 1    | 1    | 1    | 2    | 2    | 2    | 3    | 3    | 3    | 4    | 4    | 4    |

`x` = Pointer to the first 1D array

- `x + 3` = $2000+3\times12=2036$ = Pointer to 4th 1D array
- `*(x + 3)` = Pointer to first element of 4th 1D array: **2036**
- `*(x + 2) + 3`
  - `x` = Pointer to first 1D array
  - `x + 2` = Pointer to the 3rd 1D array
  - `*(x + 2)` = 2024 = Pointer to first element of 3rd 1D array
  - `\*(x + 2) + 3 = $2024+3\times4=2036$

## Pointer Pointing To An Entire Array

```c
#include <stdio.h>

int main(void) {
    int a[5] = {1, 2, 3, 4, 5};
    int *p = a;

    printf("%d", *p);
    return 0;
}
```

Output: `1`

Let's suppose we make a little change in the code:

```c
#include <stdio.h>

int main(void) {
    int a[5] = {1, 2, 3, 4, 5};
    int (*p)[5] = &a;

    printf("%p", p);
    return 0;
}
```

`(*p)`: A pointer to five integer elements.

### Why Passing `&a`?

**Example:** 2D array `b`:

| 1    | 2    | 3    | 4    |
| ---- | ---- | ---- | ---- |
| 1000 | 1004 | 1008 | 1012 |
| 1000 | 1000 | 1008 | 1008 |

- `*b` = Pointer to 1st element of 1st 1D array
- `&*b` = b = Pointer to 1st 1D array

Because `a` points to the first element of the array we need to go outside to point to the _whole_ 1D array, not just the first element of it.

Let's now try to print the first element of array `a`:

```c
int (*p)[5] = &a;
printf("%d", **p);
```

Output: `1`

### Question Pointer Pointing To Entire Array

What is the output of the following program:

```c
#include <stdio.h>

int main(void) {
    int a[][3] = {1, 2, 3, 4, 5, 6};
    int (*ptr)[3] = a;

    printf("%d %d ", (*ptr)[1], (*ptr)[2]);
    ++ptr;
    printf("%d %d ", (*ptr)[1], (*ptr)[2]);

    return 0;
}
```

- **a) `2 3 5 6`** ✅
- b) `2 3 4 5`
- c) `4 5 0 0`
- d) None of the above

**Answer:**

We have an array `a` with 3 columns. So the number of rows must be 2. `a` gets assigned to pointer `*ptr` pointing to an 1D array with 3 integer elements. We pass to `*ptr` the address of the first 1D array. Then we print `(*ptr)[1]` and `(*ptr)[2]`.

`ptr` is a pointer to the first 1D array while `*ptr` is a pointer to the first element of the first 1D array. And `(*ptr)[1]` is equal to `*((*ptr) + 1)`. `(*ptr) + 1` gives pointer to second element of first 1D array. `*((*ptr) + 1)` gives the second element. So `*((*ptr) + 2)` gives the third element. So far, the output will be `2 3`.

Then `ptr` is incremented (`++ptr`). So `ptr` now points to the second 1D array. Then we repeat the above process and we will have `5 6` as an ouput. Putting everything together we will have an ouput of `2 3 5 6`.

## Pointers GATE Question 3

What is the output of the following C program:

```c
void f(int *p, int *q) {
    p = q;
    *p = 2;
}

int i = 0, j = 1;

int main(void) {
    f(&i, &j);
    printf("%d %d\n", i, j);
    return 0;
}
```

- a) `2 2`
- b) `2 1`
- c) `0 1`
- **d) `0 2`** ✅

**Answer:**

We have two variables `i` (address 1000) with a value of 0 and `j` (address 2000) with a value of 1. Then we assign the address of `q` (`j`: 2000) to `p` (`i`: 2000). Now `p` and `q` point to the same memory location (2000). When we now change the value of `*p` to 2, we change it for both the pointers `*p` and `*q` as they are pointing to the exact same location. Then we print the values of `i` and `j`. `i` has the address 1000, on which we didn't modify the value, so it is still 0. And `j` has the address 2000, which now holds a value of 2. So the output is `0 2`.

## Pointers GATE Question 4

What is the value printed by the following C program:

```c
#include <stdio.h>

int f(int *a, int n) {
    if (n <= 0)
      return 0;
    else if (*a % 2 == 0)
      return *a + f(a + 1, n - 1);
    else
      return *a - f(a + 1, n - 1);
}

int main(void) {
    int a[] = {12, 7, 13, 4, 11, 6};

    printf("%d", f(a, 6));
    getchar();
    return 0;
}
```

- a) `-9`
- b) `5`
- **c) `15`** ✅
- d) `19`

**Answer:**

Every C program starts executing from `main()`. We have an array `a` with 6 integer elements and we call the function `f()` with the arguments `a` and 6. `a` is passing a pointer to the first element of the array `a`. It is equal to passing `&a[0]`.

We then have a recursion inside `f()`:

`f(&a[0], 6)` -> `12 + f(&a[1], 5)` -> `7 - f(&a[2], 4)` -> `13 - f(&a[3], 3)` -> `4 + f(&a[4], 2)` -> `11 - f(&a[5], 1)` -> `6 + f(&a[6], 0)` -> `return 0`

## Pointers GATE Question 5

What is printed by the following C program:

```c
int f(int x, int *py, int **ppz) {
    int y, z;

    **ppz += 1;
    z = **ppz;

    *py += 2;
    y = *py;
    x += 3;

    return x + y + z;
}

void main(void) {
    int c, *b, **a;

    c = 4, b = &c, a = &b;
    printf("%d", f(c, b, a));
}
```

- a) `18`
- **b) `19`** ✅
- c) `21`
- d) `22`

**Answer:**

|         | c    | b    | a    |
| ------- | ---- | ---- | ---- |
| Value   | 7    | 1000 | 2000 |
| Address | 1000 | 2000 | 3000 |

|         | x    | py   | ppz  |
| ------- | ---- | ---- | ---- |
| Value   | 7    | 1000 | 2000 |
| Address | 4000 | 5000 | 6000 |

| y    | z    |
| ---- | ---- |
| 7    | 5    |
| 7000 | 8000 |

$$x+y+z=7+7+5=19$$

## Pointers GATE Question 6

Which one of the choices given below would be printed when the following program is executed?

```c
void swap(int *x, int *y) {
    static int *temp;

    temp = x;
    x = y;
    y = temp;
}

void printab(void) {
    static int i, a = -3, b = -6;

    i = 0;
    while (i <= 4) {
      if ((i++) % 2 == 1) continue;
      a = a + i;
      b = b + i;
    }
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
}

int main(void) {
    printab();
    printab();
    return 0;
}
```

- a) `a = 0, b = 3` `a = 0, b = 3`
- b) `a = 3, b = 0` `a = 12, b = 9`
- c) `a = 3, b = 6` `a = 3, b = 6`
- **d) `a = 6, b = 3` `a = 15, b = 12`** ✅

**Answer:**

Static:

| `i`  | `a`  | `b`  |
| ---- | ---- | ---- |
| 0    | -3   | -6   |
| 1000 | 2000 | 3000 |

Iterations

| `i` | `a` | `b` |
| --- | --- | --- |
| 1   | -2  | -5  |
| 2   | -2  | -5  |
| 3   | 1   | -2  |
| 4   | 1   | -2  |
| 5   | 6   | 3   |

The `swap()` function doesn't really do anything except swapping addresses of `x` and `y` which has no effect on the values `a` and `b`.

So the output after the first `printab()` call will be `a = 6, b = 3`.

As `a` and `b` are _static_ variables, they retain their values. So we start this time with these values:

| `i`  | `a`  | `b`  |
| ---- | ---- | ---- |
| 0    | 6    | 3    |
| 1000 | 2000 | 3000 |

| `i` | `a` | `b` |
| --- | --- | --- |
| 1   | 7   | 4   |
| 2   | 7   | 4   |
| 3   | 10  | 7   |
| 4   | 10  | 7   |
| 5   | 15  | 12  |

So the output after the second `printab()` call will be `a = 15, b = 12`.

## Pointers GATE Question 7

A C program is given below:

```c
#include <stdio.h>

int main(void) {
    int i, j;
    char a[2][3] = {{'a', 'b', 'c'}, {'d', 'e', 'f'}};
    char b[3][2];
    char *p = *b;

    for (i = 0; i < 2; i++) {
      for (j = 0; j < 3; j++) {
        *(p + 2 * j + i) = a[i][j];
      }
    }
}
```

What should be the contents of the array `b` at the end of the program?

- a) `a b` `c d` `e f`
- **b) `a d` `b e` `c f`** ✅
- c) `a c` `e b` `d f`
- d) `a e` `d c` `b f`

**Answer:**

Array `a` would look something like this:

| `'a'` | `'b'` | `'c'` | `'d'` | `'e'` | `'f'` |
| ----- | ----- | ----- | ----- | ----- | ----- |
| 3000  | 3001  | 3002  | 3003  | 3004  | 3005  |

Pointer `*p` points to the first element in the first 1D array of array `b`,
that's what `*b` means. Now we just have to iterate through the loops and add
the values of `i` and `j` to `p` which means we traverse through the array. For
example `(p + 1)` is the second element of the first 1D array and so on. This
is what the array looks in the end:

| `'a'` | `'b'` | `'c'` | `'d'` | `'e'` | `'f'` |
| ----- | ----- | ----- | ----- | ----- | ----- |
| 4000  | 4001  | 4002  | 4003  | 4004  | 4005  |

# String Literals

## Definition

**String literal (or string constant)** is a sequence of characters enclosed
within double quotes.

**Example:** `"Hello everyone"`, `"Hallo zusammen"`, `"Hola a todos"`

**`%s` is a placeholder**

```c
int main(void) {
    printf("%s", "Hello everyone");
    return 0;
}
```

Double quotes are important! We cannot use single quotes for string literals like in other languages.

## Continuing String Literals

### Splicing

```c
printf("%s", "You have to dream before your dreams can come true.\
--A.P.J. Abdul Kalam");
```

This is called "splicing". We just added an `\` after the first secntence. The same can be achieved like this:

```c
printf("%s", "You have to dream before your dreams can come true. "
"--A.P.J. Abdul Kalam")
```

The output of the above programs is:

```
You have to dream before your dreams can come true.      --A.P.J. Abdul Kalam
You have to dream before your dreams can come true. --A.P.J. Abdul Kalam
```

As we can see in the first string literal where we used splicing there are additional spaces while in the second the text is formatted like we intended.

## Storing String Literals

```c
printf("Earth");
```

`"Earth"` is a string literal.

First argument to `printf()` and `scanf()` functions is always a string literal.

**But what are we actually passing to `printf()`/`scanf()`?**

String literals are stored as an array of characters in memory.

| E   | a   | r   | t   | h   | \0  |
| --- | --- | --- | --- | --- | --- |

Total 6 bytes of read-only memory is allocated to the above string literal.

⛔️ `'\0'` character must not be confused with the character `'0'`. Both have different ASCII codes. `'\0'` (null character) has the code 0 while `'0'` has the code 48.

In C, compiler treats a string literal as a pointer to the first character.

**So to the `printf()` or `scanf()` functions we are passing a pointer to the first character of a string literal.**

Both `printf()` and `scanf()` functions expects a character pointer (`char *`) as an argument.

```c
printf("Earth");
```

Passing "Earth" here is equivalent to passing the pointer to character `'E'`.

## Operations On String Literals

### Assigning String Literal To A Pointer

```c
char *ptr = "Hello World";
```

**Recall:** Writing string literal is equivalent to writing the pointer to the first character of the string literal.

`ptr` contains the address of the first character of the string literal.

As writing "Hello" is equivalent to writing the pointer to the first character. Therefore, we can subscript it to get some character of the string literal.

`"Hello"[1]` is equivalent to pointer to `'H'[1]`.

| H    | e    | l    | l    | o    | \0   |
| ---- | ---- | ---- | ---- | ---- | ---- |
| 1000 | 1001 | 1002 | 1003 | 1004 | 1005 |

Pointer to `'H'[1]` = \*(pointer to `'H'` + 1)

Pointer to `'H'[1]` = `*(1000 + 1)` = `*(1001)` = `'e'`

Similarly,

- `"Hello"[0]` => `'H'`
- `"Hello"[1]` => `'e'`
- `"Hello"[2]` => `'l'`
- `"Hello"[3]` => `'l'`
- `"Hello"[4]` => `'o'`

👉 String literals cannot be modified. It causes undefined behaviour.

```c
char *ptr = "Hello";

*ptr = 'M'; // ⛔️ Not allowed!
```

String literals are also known as string constants. They have been allocated a read only memory. So we cannot alter them.

But character pointer itself has been allocated read-write memory. So the same pointer can point to some other string literal.

## String Literal Versus Character Constant

String literal and character constant are not the same.

`"H"` $\neq$ `'H'`

- The string literal is represented by a pointer to a character `'H'`.
- The character constant is represented by an integer (ASCII code: 72).

So:

`printf("\n")` $\neq$ `printf('\n')`

`printf()` expects a pointer to a character, not an integer. So the second `printf()` will output an error!

## Declaring & Initializing A String Variable

A string variable is a one dimensional array of characters that is capable of holding a string at a time.

**Example:** `char s[6];`

**Note:** Always make the array one character longer than the string. If length of the string is 5 characters long then don't forget to make extra room for the _null_ character.

Failing to do the same may cause unpredictable results when program is executed as some C libraries assume the strings are _null_ terminated.

### Initializing A String Variable

**Example:** `char s[6] = "Hello";`

| H   | e   | l   | l   | o   | \0  |
| --- | --- | --- | --- | --- | --- |

Although it seems like `"Hello"` in the above example is a string literal but it is not.

When a string is assigned to a character array, then this character array is treated like other types of arrays.

```c
char s[6] = "Hello";

char s[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
```

**Recall:** We cannot modify a string literal. The following code will produce an error message:

```c
char *ptr = "Hello";

*ptr = 'M';
```

But we can modify a char array:

```c
char s[6] = "Hello";

s[0] = 'M';
```

### Short Length Initializer

```c
char s[7] = "Hello";
```

If the char array holds less character than we initialized, then the rest of the empty places will get filled up by _null_ terminators:

| H   | e   | l   | l   | o   | \0  | \0  |
| --- | --- | --- | --- | --- | --- | --- |

### Long Length Initializer

```c
char s[4] = "Hello";
```

| H   | e   | l   | l   |
| --- | --- | --- | --- |

The rest of the part is truncated. We will also get a warning and we should
always prevent this case at any cost.

### Equal Length Initializer

```c
char s[5] = "Hello";
```

| H   | e   | l   | l   | o   |
| --- | --- | --- | --- | --- |

There is no room for `\0` and we have an undefined behaviour.

### Omitting The Length

```c
char s[] = "Hello";
```

Automatically, the compiler sets aside 6 characters for `s` which is enough to store the string `"Hello"` with the _null_ character.

| H   | e   | l   | l   | o   | \0  |
| --- | --- | --- | --- | --- | --- |

## Writing Strings

### Writing Strings Using `printf()`

```c
char *ptr = "Hello world";

printf("%s", ptr);
```

Output: `Hello world`

`"%.ns"` is used to print just a part of the string where `n` is the number of characters to be displayed on the screen.

```c
char *ptr = "Hello world";

printf("%.5s", ptr);
```

Output: `Hello`

`"%m.ns"` is used to print just a part of the string where `n` is the number of characters to be displayed and `m` denotes the size of the field within which the string will be displayed.

```c
char *ptr = "Hello world";

printf("%.5s", ptr);
printf("%6.5s", ptr);
```

Output:

```
Hello
 Hello
```

|     | H   | e   | l   | l   | o   |
| --- | --- | --- | --- | --- | --- |

Field of length `m` = 60

### Writing Strings Using `puts()`

`puts()` is a function declared in `<stdio.h>` library and is used to write strings to the output screen.

Also, `puts()` function automatically writes a _newline character_ after writing the string to the output screen.

```c
char *s = "Hello";

puts(s);
puts(s);
```

Output:

```
Hello
Hello
```

## Reading Strings

### Reading Strings Using `scanf()`

Using `scanf()` we can read a string into a string variable (character array).

```c
char a[10];

printf("Enter the string:\n");
scanf("%s", a);
printf("%s", a);
```

Like any array name, `a` is treated as a pointer to the first element of the array. Therefore, there is no need to put `&`.

Output:

```
$ Enter the string:
$ You are most welcome
You
```

Why does it output only `You`? `scanf()` doesn't store the white space characters in the string variable.

It only reads characters other than white spaces and store them in the specified character array until it encounters a white space character.

When white space is seen by `scanf()`, it stops and hence, only `You` is stored in the specified character array.

### Reading Strings Using `gets()`

In order to read an entire line of input, `gets()` function can be used.

```c
char a[10];

printf("Enter the string:\n");
gets(a);
printf("%s", a);
```

Input: `You are most welcome`

⛔️ The program may crash after the input!

This is because the inputted string is longer than the specified length of character array `a`.

Both, `gets()` and `scanf()` functions have no way to detect when the character array is full.

Both of them never check the maximum limit of input characters. Hence, they may cause undefined behaviour and probably lead to buffer overflow error which eventually causes the program to crash.

Although `scanf()` has a way to set the limit for the number of characters to be stored in the character array.

By using `%ns`, where `n` indicates the number of characters allowed to store in the character array.

```c
char a[10];

printf("Enter the string:\n");
scanf("9s", a);
printf("%s", a);
```

Output:

```
$ Enter the string:
$ Youaremostwelcome
Youaremos
```

But unfortunately, `gets()` is still _unsafe_.

It will try to write the characters beyond the memory allocated to the character array which is _unsafe_ because it will simply overwrite the memory beyond the memory allocated to the character array.

Hence, it is advisable to _not_ use the `gets()` function.

## Designing Input Function Using `getchar()`

As `scanf()` and `gets()` functions are risky to use. Hence, _it is advisable to design our own input function._

We want our input function to have the following functionalities:

1. It must continue to read the string even after seeing white space characters.
2. It must stop reading the string after seeing the newline character.
3. It must discard extra characters.
4. It must return the number of characters it stores in the character array.

```c
#include <stdio.h>

int input(char str[], int n) {
  int ch, i = 0;

  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
  }
  str[i] = '\0';
  return i;
}

int main(void) {
  char str[100];
  int n = input(str, 5);

  printf("%d %s", n, str);
  return 0;
}
```

Output:

```
$ Hello, How are you?
5 Hello
```

`getchar()` is used to read one character at a time from the user input. It returns an integer equivalent to the ASCII code of the character. This is the reason why we have `int ch` in place of `char ch`.

## `putchar()` In C99

**Prototype:** `int putchar(int ch)`

`putchar()` accepts an integer argument (which represents a character it wants to display) and returns an integer representing the character written on the screen.

💡 Always remember that character is internally represented in binary form only. It doesn't make any difference if you write `int ch` instead of `char ch`.

**Example:**

```c
#include <stdio.h>

int main(void) {
  int ch;

  for (ch = 'A'; ch <= 'Z'; ch++)
    putchar(ch);
  return 0;
}
```

Output: `ABCDEFGHIJKLMNOPQRSTUVWXYZ`

## Problem 1

Identify which of the following calls work properly and give the reason for the same.

- a) `printf("%c", '\n');` ✅
- b) `printf("%c", "\n");`
- c) `putchar('\n');` ✅
- d) `putchar("\n");`
- e) `puts('\n');`
- f) `puts("\n");` ✅
- g) `printf("%s", '\n');`
- h) `printf("%s", "\n");` ✅

## C String Library

### Introcution To C String Library

There are some operations which we can perform on strings.

**Example:** Copy strings, concatenate strings, select substrings and so on.

`<string.h>` library contains all the required functions for performing string operations.

So we just have to include this header file:

```c
#include <string.h>
```

and we are good to go!

### `strcpy()` - String Copy

**Prototype:** `char* strcpy(char* destination, const char* source)`

`strcpy()` is used to copy a string pointed by source (including _NULL_ character) to the destination (character array).

**Example:**

```c
#include <stdio.h>
#include <string.h>

int main(void) {
  char str1[10] = "Hello";
  char str2[10];

  printf("%s\n", strcpy(str2, str1));
  printf("%s", str2);
  return 0;
}
```

Output:

```
Hello
Hello
```

`strcpy()` returns the pointer to the first character of the string which is copied in the destination. Hence if we use `%s`, then whole string will be printed on the screen.

We can also chain together a series of `strcpy()` calls:

```c
#include <stdio.h>
#include <string.h>

int main(void) {
  char str1[10] = "Hello";
  char str2[10];
  char str3[10];

  strcpy(str3, strcpy(str2, str1));
  printf("%s %s", str2, str3);
  return 0;
}
```

Output:

```
Hello
Hello
```

In the call to `strcp(str1, str2)` there is no way the `strcpy()` will check whether the string pointed by `str2` will fit in `str1`.

If the length of the string pointed by `str2` is greater than the length of the character array `str1` then it will be an undefined behaviour.

To avoid this we can call the `strncpy()` function.

`strncpy(destination, source, sizeof(destination));`

**Example:**

```c
#include <stdio.h>
#include <string.h>

int main(void) {
  char str1[6] = "Hello";
  char str2[4];

  strncpy(str2, str1, sizeof(str2));
  printf("%s", str2);
  return 0;
}
```

Output: `Hell`

`strncpy()` will leave the string in `str2` (destination) without a terminating _NULL_ character, if the size of `str1` (source) is equal to or greater than the size of `str2` (destination).

**Example:**

```c
#include <stdio.h>
#include <string.h>

int main(void) {
  char str1[6] = "Hello";
  char str2[6];

  strncpy(str2, str1, sizeof(str2));
  str2[sizeof(str2) - 1] = '\0';
  printf("%s", str2);
  return 0;
}
```

Output: `Hello`

### `strlen()` - String Length

**Prototype:** `size_t strlen(const char* str);`

`size_t` is an unsigned integer type of at least 16 bits.

`strlen()` function is used to determine the length of the given string.

To the `strlen()` function, we should pass the pointer to the first character of the string whose length we want to determine.

**Note:** It doesn't count the _NULL_ character.

**Example:**

```c
#include <stdio.h>
#include <string.h>

int main(void) {
  char *str = "Hello world";
  printf("%d", strlen(str));
  return 0;
}
```

Output: `11`

It calculates the length of the string and not the length of the array.

### `strcat()` & `strncat()` - String Concatenation

**Prototype:** `char* strcat(char* str1, const char* str2);`

`strcat()` function _appends_ the content of string `str2` at the end of string `str1`. It _returns_ the pointer to the resulting string `str1`.

**Example:**

```c
#include <stdio.h>
#include <string.h>

int main(void) {
  char str1[100], str2[100];

  strcpy(str1, "Welcome to ");
  strcpy(str2, "our Academy");
  strcat(str1, str2);

  printf("%s", str1);
  return 0;
}
```

Output: `Welcome to our Academy`

⛔️ **Caution:** An undefined behaviour can be observed if size of `str1` isn't long enough to accomodate the additional characters of `str2`.

`strncat()` is the _safer version_ of `strcat()`.

It appends the limited number of characters specified by the third argument passed to it.

📝 **Note:** `strncat()` automatically adds the _NULL_ character at the end of the resultant string.

```c
#include <stdio.h>
#include <string.h>

int main(void) {
  char str1[5], str2[100];

  strcpy(str1, "He");
  strcpy(str2, "llo!");
  strncat(str1, str2, sizeof(str1) - strlen(str1) - 1);
  printf("%s", str1);
  return 0;
}
```

Output: `Hell`

### `strcmp()` - String Comparison

**Prototype:** `int strcmp(const char* s1, const char* s2);`

- Compares two strings `s1` and `s2`
- Returns value
  - Less than 0 if `s1 < s2`
  - Greater than 0 if `s1 > s2`
  - Equal to 0 if `s1 == s2`

👉🏼**Attention!**

In ASCII character set:

- All uppercase letters are less than all the lowercase letters (Uppercase letters have ASCII codes between 65 and 90 and lowercase letters have ASCII codes between 97 and 122).
- Digits are less than letters (0-9 digits have ASCII codes between 48 and 57).
- Spaces are less than all printing characters (Space character has the value of 32 in ASCII set).

`strcmp()` considers `s1 < s2` if either one of the following conditions is satisfied:

- When the first i characters in `s1` and `2` are same and (i+1)st character of `s1` is less than that of `s2`.

```c
#include <stdio.h>
#include <string.h>

int main(void) {
  char *s1 = "abcd";
  char *s2 = "abce";

  if (strcmp(s1, s2) < 0)
    printf("s1 is less than s2");
  else
    printf("s1 is greater than or equal to s2");
  return 0;
}
```

Output: `s1 is less than s2`

- All characters of `s1` match `s2` but `s1` is shorter than `s2`.

```c
#include <stdio.h>
#include <string.h>

int main(void) {
  char *s1 = "abc";
  char *s2 = "abcd";

  if (strcmp(s1, s2) < 0)
    printf("s1 is less than s2");
  else
    printf("s1 is greater than or equal to s2");
  return 0;
}
```

Output: `s1 is less than s2`

## Array Of Strings

### 2D Array

```c
char fruits[][12] = {"2 Oranges", "2 Apples", "3 Bananas", "1 Pineapple"};
```

This array could be represented like this:

| 2   |     | O   | r   | a   | n   | g   | e   | s   | \0  | \0  | \0  |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 2   |     | A   | p   | p   | l   | e   | s   | \0  | \0  | \0  | \0  |
| 3   |     | B   | a   | n   | a   | n   | a   | s   | \0  | \0  | \0  |
| 1   |     | P   | i   | n   | e   | a   | p   | p   | l   | e   | \0  |

Here a lot of memory is wasted because of the _NULL_ characters. But we have an alternative.

### Array Of Pointers

```c
char *fruits[] = {"2 Oranges", "2 Apples", "3 Bananas", "1 Pineapple"};
```

### Homework Problem

What is the output of the following C program:

```c
#include <stdio.h>
#include <string.h>

int main(void) {
  char *fruits[] = {"2 Oranges", "2 Apples", "3 Bananas", "1 Pineapple"};

  if (strcmp(fruits[1], fruits[2]) < 0)
    printf("%s are lesser than %s", fruits[1], fruits[2]);
  else if (strcmp(fruits[1], fruits[2]) > 0)
    printf("%s are greater than %s", fruits[1], fruits[2]);
  return 0;
}
```

Output: `2 Apples are lesser than 3 Bananas`

## Problem 2

Consider the following C program segment:

```c
char p[20];
char *s = "string";
int length = strlen(s);   // 6
int i;

for (i = 0; i <length; i++)
  p[i] = s[length - i];
printf("%s", p);
```

The output of the program is:

- a) `gnirts`
- b) `string`
- c) `gnirt`
- **d) No output is printed** ✅

**Answer:**

`printf()` function will print everything before the _null_ character and will not see anything after the _null_ character. Therefore, **nothing will be printed on the screen.**

## Problem 3

What does the following fragment of C program print?

```c
char c[] = "GATE2011";
char *p = c;

printf("%s", p + p[3] - p[1]);
```

- a) `GATE2011`
- b) `E2011`
- **c) `2011`** ✅
- d) `011`

**Answer:**

We have a character array `c` containing `GATE2011` and a pointer `*p` that stores the address of the first element in the character array. Then in the `printf()` statement we have the first address, which we suppose is 1000, then `p[3]` which can be written as `*(1000 + 3)` containing the letter `E` and then `p[1]` (`*(1000 + 1)`) which contains the letter `A`.

Always remember that character is internally represented as integer only. So `E` is represented as 69 and `A` as 65. So we have `printf("%s", 1000 + 69 - 65)`. So we print the address of 1004. Address 1004 contains the value `2`. So the `printf()` functions prints the string starting from 2 and continues until the _null_ character. So 2011 will be printed on the screen.

## Problem 4

Consider the following function written in the C programming language. The output of the below function on input `ABCD EFGH` is

```c
void foo(char *a) {
  if (*a && *a != ' ') {
    foo(a + 1);
    putchar(*a);
  }
}
```

- a) `ABCD EFGH`
- b) `ABCD`
- c) `HGFE DCBA`
- **d) `DCBA`** ✅

**Answer:**

We pass the input `ABCD EFGH` to character pointer `*a`. So `a` holds the address of the first element in the passed character array. The `if` condition means if a character pointed by pointer `a` is neither a _NULL_ character nor a blank character then continue, else stop. `*a` is dereferencing the value of the address stored in `a`, so `A`. Then recursion is happening and calling `foo()` incrementing `a` to address 1001.

`foo(1000)` -> `foo(1001)` -> `foo(1002)` -> `foo(1003)` -> `foo(1004)`

We don't have any `return` statement. So we just go back until we reach `foo(1000)` in the stack. On each step, `printf()` will print the current element value in the character array.

## Problem 5

Consider the following C program:

```c
void fun1(char *s1, char *s2) {
  char *tmp;

  tmp = s1;
  s1 = s2;
  s2 = tmp;
}

void fun2(char **s1, char **s2) {
  char *tmp;

  tmp = *s1;
  *s1 = *s2;
  *s2 = tmp;
}

int main(void) {
  char *str1 = "Hi", *str2 = "Bye";

  fun1(str1, str2);
  printf("%s %s", str1, str2);

  fun2(&str1, &str2);
  printf("%s %s", str1, str2);

  return 0;
}
```

- **a) `Hi Bye Bye Hi`** ✅
- b) `Hi Bye Hi Bye`
- c) `Bye Hi Hi Bye`
- d) `Bye Hi Bye Hi`

**Answer:**

We start in the `main()` function. We pass the addresses of first element in `str1` and `str2` to the `fun1()` function. The `fun1()` function switches the addresses of `s1` and `s2` which are _local_ to it. So there is no change of `str1` and `str2` in the `main()` function. So the first `printf()` statement prints `Hi Bye`.

In the second case we pass the addresses of character pointers `str1` and `str2`. In `fun2()` we have double pointers. So `**s1` holds the address of the pointer `str1` which points to a character and `**s2` of `str2`. We are dereferencing `s1` and put the value of it, which is the address to the first character in the `str1` array, into `temp`. Then we assign the value of `s2`, which is the address that points to the first character in `str2` to `s1` which then holds the address of the first character of `str2`. Then we assign `s2` to the pointer `tmp` which holds the address of the first character in string `str1`. So the addresses get switched. In the end `str1` points to the first character of `str2` and `s2` points to the first character of `str1`.

## Problem 6

Determine the output of the following program:

```c
#include <stdio.h>
#include <string.h>

int main(void) {
  char *c = "GATECSIT2017";
  char *p = c;

  printf("%d", (int)strlen(c + 2[p] - 6[p] - 1));
  return 0;
}
```

- a) `1`
- **b) `2`** ✅
- c) `4`
- d) `6`

**Answer:**

We have two pointers, `*c` and `*p` pointing to the first character in the characters array (G). Then we have the `strlen()` statement, which can also be written as:

```c
(int)strlen(1000 + *(2 + 1000) - *(6 + 1000) - 1)
```

If we do the maths we have:

```c
(int)strlen(1000 + *(1002) - *(1006) - 1)
```

In the character array we can look up the different addresses and the value they hold as it is dereferenced.

```c
(int)strlen(1000 + T - I - 1)
```

We can now do a simple trick. As we know `I` is before `T` so we can think of `I` as being 1 and then count the letters until `T`, so `T` will be 12:

```c
(int)strlen(1000 + 12 - 1 - 1)

(int)strlen(1010)
```

So `strlen()` will count the characters starting at address 1010 until the _null_ character but not including _null_ character.

`strlen()` returns a `size_t` type data. Therefore, `(int)` will convert the `size_t` type to `int` type. This is called type casting.

So we will have 2 as the output.

# Function Pointers

Function pointers are like normal pointers but they have the capability to point to a function.

**Example:**

How to declare a pointer to an array?

```c
int main(void) {
  int *ptr[10];   // ⛔ WRONG

  return 0;
}
```

Always remember the _precedence of operators._ Precedence of `[]` is higher than `*`.

So `ptr` is an array of 10 pointers pointing to integers.

The right method to declare a pointer to an array is as follows:

```c
int main(void) {
  int (*ptr)[10];

  return 0;
}
```

Now, `ptr` is a pointer which is pointing to an array of 10 integers.

**Example:**

Now the question arises: _How to delcare a pointer to a function?_

We want a pointer to the following function:

```c
int add(int a, int b) {
  return a + b;
}
```

We can declare a pointer like this. Here `ptr` is a pointer pointing to a function that contains 2 integers arguments and returns an integer.

```c
int main(void) {
  int (*ptr)(int, int);
}
```

**Example:** Assigning the address of a function to a function pointer.

```c
int main(void) {
  int (*ptr)(int, int) = &add;
}
```

OR

```c
int main(void) {
  int (*ptr)(int, int);

  ptr = &add;
}
```

**Example:** Using the function pointer.

```c
int main(void) {
  int result;
  int (*ptr)(int, int) = &add;

  result = *ptr(10, 20);
  printf("%d", result);
}
```

Because a function name represents also the initial address of that function. So we can instead of writing `&add` just passing `add` to the function pointer. If we do it this way, there is no need to dereference `ptr`:

```c
int add(int a, int b) {
  return a + b;
}

int main(void) {
  int result;
  int (*ptr)(int, int) = add;

  result = ptr(10, 20);
  printf("%d", result);
}
```

## Application Of Function Pointers

Suppose we want to call a function named `func()` at a certain point in time in our code:

```c
int func(int a, int b) {
  return a + b;
}

int main(void) {
  printf("%d", func(2, 5));

  return 0;
}
```

There is nothing that has to be decided at runtime.

Let's say we want to design a _calculator_ which has the capability to perform addition, subtraction, multiplication and division.

Here, the user will decide which operation he wants to perform.

Suppose we have decided to create separate functions for these operations.

Now we want the user to decide which function has to be called at runtime. _One way is to use if/switch case expressions._

```c
#include <stdio.h>

float sum(float a, float b) { return (a + b); }
float sub(float a, float b) { return (a - b); }
float mult(float a, float b) { return (a * b); }
float divi(float a, float b) { return (a / b); }

int main(void) {
  int choice;
  float a, b, result;

  printf("Enter your choice: 0 for sum, 1 for sub, 2 for mult, 3 for div:\n");
  scanf("%d", &choice);

  printf("Enter the two numbers:\n");
  scanf("%f %f", &a, &b);

  switch (choice) {
  case 0:
    result = sum(a, b);
    break;
  case 1:
    result = sub(a, b);
    break;
  case 2:
    result = mult(a, b);
    break;
  case 3:
    result = divi(a, b);
    break;
  }
  printf("%f", result);
  return 0;
}
```

A better way in this case would be to declare a function pointer and let it decide at runtime which function will get executed:

```c
#include <stdio.h>

#define OPS 4

float sum(float a, float b) { return (a + b); }
float sub(float a, float b) { return (a - b); }
float mult(float a, float b) { return (a * b); }
float divi(float a, float b) { return (a / b); }

int main(void) {
  float (*funptr[OPS])(float, float) = {sum, sub, mult, divi};
  int choice;
  float a, b;

  printf("Enter your choice: 0 for sum, 1 for sub, 2 for mult, 3 for div:\n");
  scanf("%d", &choice);

  printf("Enter the two numbers:\n");
  scanf("%f %f", &a, &b);

  printf("%f", funptr[choice](a, b));
  return 0;
}
```

# Structures

**Problem:** I have a garage. I want to store all the information about the cars which are available in my garage.

🚗 **Car 1 specifications**

| Title              | Description     |
| ------------------ | --------------- |
| Engine             | DDis 190 Engine |
| Fuel type          | Petrol          |
| Fuel tank capacity | 37              |
| Seating capacity   | 5               |
| City mileage       | 19.74 kmpl      |

We could declare variables for each specification of `car1`:

```c
char *car1Engine = "DDis 190 Engine";
char *car1fuelType = "Petrol";
int car1fuelCap = 37;
int car1seatingCap = 5;
float car1CityMileage = 19.74;
```

🚕 **Car 2 specifications**

| Title              | Description           |
| ------------------ | --------------------- |
| Engine             | 1.2 L Kappa Dual VTVT |
| Fuel type          | Diesel                |
| Fuel tank capacity | 35                    |
| Seating capacity   | 5                     |
| City mileage       | 22.54 kmpl            |

```c
char *car2Engine = "1.2 L Kappa Dual VTVT";
char *car2fuelType = "Diesel";
int car2fuelCap = 35;
int car2seatingCap = 5;
float car2CityMileage = 22.54;
```

This is a very bad approach if we had more cars. It's time and memory intensive.

_Array is also not a good option_ - Array has the capability to store more than one element but they all must be of the _same type_. Our requirement is to store data of different types.

## Definition

A _structure_ is a user defined data type that can be used to group elements of different types into a single type.

For the above car (`car1` & `car2`) we can define a structure like this:

```c
struct {
  char *engine;
  char *fuel_type;
  int fuel_tank_cap;
  int seating_cap;
  float city_mileage;
} car1, car2;
```

**Example:**

```c
struct {
  char *engine;
} car1, car2;

int main(void) {
  car1.engine = "DDis 190 Engine";
  car2.engine = "1.2 L Kappa Dual VTVT";

  printf("%s\n", car1.engine);
  printf("%s", car2.engine);
  return 0;
}
```

Output:

```
DDis 190 Engine
1.2 L Kappa Dual VTVT
```

## Structure Tags

Structure tag is used to identify a particular kind of structure.

```c
struct employee {   // Structure tag
  char *name;
  int age;
  int salary;
};

int manager(void) {
  struct employee manager;
}

int main(void) {
  struct employee emp1;
  struct employee emp2;
}
```

Another example:

```c
struct car {        // Structure tag
  char engine[50];
  char fuel_type[10];
  int fuel_tank_cap;
  int seating_cap;
  float city_mileage;
};

int main(void) {
  struct car c1;
}
```

We can also create a struct variable with the structure tag:

```c
struct car {        // Structure tag
  char engine[50];
  char fuel_type[10];
  int fuel_tank_cap;
  int seating_cap;
  float city_mileage;
}, c1;              // Declared variable c1 here
```

## Structure Types

**Syntax:** `typedef existing_data_type new_data_type`

`typedef` gives freedom to the user by allowing them to create their own types.

**Example:**

```c
#include <stdio.h>

typedef int INTEGER;

int main(void) {
  INTEGER var = 100;

  printf("%d", var);
  return 0;
}
```

### Using `typedef` In Structures

#### Structure Declaration

```c
struct car {
  char engine[50];
  char fuel_type[10];
  int fuel_tank_cap;
  int seating_cap;
  float city_mileage;
}, c1;
```

#### Separate Declaration

```c
struct car {
  char engine[50];
  char fuel_type[10];
  int fuel_tank_cap;
  int seating_cap;
  float city_mileage;
};

int main(void) {
  struct car c1;
}
```

Instead of writing `struct car` everytime when initiating an instance of `car`, we can use a `typedef` for the type `car`.

```c
typedef struct car {
  char engine[50];
  char fuel_type[10];
  int fuel_tank_cap;
  int seating_cap;
  float city_mileage;
} car;

int main(void) {
  car c1;
}
```

## Initializing & Accessing Structure Members

⛔️ The following is **NOT** allowed:

```c
struct abc {
  int p = 23;
  int q = 34;
};
```

We have to do the following:

```c
struct abc {
  int p;
  int q;
};

int main(void) {
  struct abc x = {23, 34};
}
```

**Example:**

```c
struct car {
  char engine[50];
  char fuel_type[10];
  int fuel_tank_cap;
  int seating_cap;
  float city_mileage;
};

int main(void) {
  struct car c1 = {"DDis 190 Enginge", "Diesel", 37, 5, 19.74};
  struct car c2 = {"Kappa", "Petrol", 22, 8, 14.5};
}
```

### Accessing Members Of Structures

We can access members of the structure using dot (`.`) operator.

```c
struct car {
  int fuel_tank_cap;
} c1, c2;

int main(void) {
  c1.fuel_tank_cap = 45;
  c2.fuel_tank_cap = 30;

  printf("%d %d", c1.fuel_tank_cap, c2.fuel_tank_cap);
  return 0;
}
```

Output: `45, 30`

## Designated Initialization

Designated initialization allows structure members to be initialized in any order.

```c
struct abc {
  int x;
  int y;
  int z;
};

int main(void) {
  struct abc a = {.y = 20, .x = 10, .z = 30};

  printf("%d %d %d", a.x, a.y, a.z);
  return 0;
}
```

Output: `10 20 30`

## Declaring An Array Of Structure

Instead of delcaring multiple variables, we can also declare an array of structure in which each element of the array will represent a structure variable.

```c
#include <stdio.h>

struct car {
  int fuel_tank_cap;
  int seating_cap;
  float city_mileage;
};

int main(void) {
  struct car c[2];
  int i;

  for (i = 0; i < 2; i++) {
    printf("Enter the car %d fuel tank capacity: ", i + 1);
    scanf("%d", &c[i].fuel_tank_cap);

    printf("Enter the car %d seating capacity ", i + 1);
    scanf("%d", &c[i].seating_cap);

    printf("Enter the car %d city mileage ", i + 1);
    scanf("%f", &c[i].city_mileage);
  }
  putchar('\n');

  for (i = 0; i < 2; i++) {
    printf("\nCar %d details: \n", i + 1);
    printf("Fuel tank capacity: %d\n", c[i].fuel_tank_cap);
    printf("Seating capacity: %d\n", c[i].seating_cap);
    printf("City mileage: %f\n", c[i].city_mileage);
  }
  return 0;
}
```

## Pointer To Structure Variable

**Program:**

```c
struct abc {
  int x;
  int y;
};

int main(void) {
  struct abc a = {0, 1};
  struct abc *ptr = &a;

  printf("%d %d", ptr->x, ptr->y);
  return 0;
}
```

Output: `0 1`

`ptr` is a pointer to some variable of type `struct abc`.

`ptr->x` is equivalent to `(*ptr).x`.

## Structure Padding

When an object of some structure type is declared then some contiguous block of memory will be allocated to structure members.

**Example:**

```c
struct abc {
  char a;
  char b;
  int c;
} var;
```

What is the size of `struct abc`?

### Calculating The Size Of The Structure

Let the size of `int` is 4 bytes and size of `char` is 1 byte.

Naturally, we'd assume the following:

```c
struct abc {
  char a;   // 1 byte
  char b;   // 1 byte
  int c;    // 4 bytes
} var;      // = 6 bytes
```

But this assumption is **WRONG**!

There is a concept called _structure padding_.

The processor doesn't read 1 byte at a time from memory. It reads 1 word at a time.

If we have a 32 bit processor then it means it can access 4 bytes at a time which means word size is 4 bytes.

If we have a 64 bit processor then it means it can access 8 bytes at a time which means word size is 8 bytes.

In a 32 bit architecture system the structure `abc` will be allocated as follows:

|     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- |
| a   | b   | c   | c   | c   | c   |     |     |
| 1   | 1   | 1   | 1   | 2   | 2   | 2   | 2   |

In one CPU cycle (1), `char a`, `char b` and 2 bytes of `int c` can be accessed. There is no problem with `char a` and `char b` but...

...whenever we want the value stored in variable `c`, 2 cycles are required to access the contents of variable `c`. In the first cycle, 1st 2 bytes can be accessed and in the 2nd cycle the last 2 bytes. It's an unncecessary wastage of CPU cycles.

We can save the number of cycles by using the concept called _padding_.

|     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- |
| a   | b   |     |     | c   | c   | c   | c   |
| 1   | 1   | 1   | 1   | 2   | 2   | 2   | 2   |

So the total size of the struct `abc` in this case is:

| Struct member | Size        |
| ------------- | ----------- |
| `char a`      | 1 byte      |
| `char b`      | 1 byte      |
| Empty spaces  | 2 bytes     |
| `int c`       | 4 bytes     |
| **Total**     | **8 bytes** |

So:

```c
struct abc {
  char a;
  char b;
  int c;
};

int main(void) {
  struct abc var;

  printf("%d", sizeof(var));
}
```

Output: `8`

What happens if we changed the order of members?

```c
struct abc {
  char a;
  int b;
  char c;
};

int main(void) {
  struct abc var;

  printf("%d", sizeof(var));
}
```

Output: `12`

In a 32 bit architecture:

|     |     |     |     |     |     |     |     |     |     |     |     |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| a   |     |     |     | b   | b   | b   | b   | c   |     |     |     |
| 1   | 1   | 1   | 1   | 2   | 2   | 2   | 2   | 3   | 3   | 3   | 3   |

Total size: 4 bytes + 4 bytes + 4 bytes = 12 bytes (3 words accessed)

## Structure Packing

Because of structure padding, size of the structure becomes more than the size of the actual structure. Due to this some memory will get wasted.

We can avoid the wastage of memory by simply writing `#pragma pack(1)`.

`#pragma` is a special purpose directive used to turn on or off certain features.

```c
#pragma pack(1)

struct abc {
  char a;
  int b;
  char c;
} var;

int main(void) {
  printf("%d", sizeof(var));
  return 0;
}
```

Output: `6`

## Problem 1

Predict the output of the following C program:

```c
#include <stdio.h>

struct Point {
  int x, y, z;
};

int main(void) {
  struct Point p1 = {.y = 0, .z = 1, .x = 2};

  printf("%d %d %d", p1.x, p1.y, p1.z);
  return 0;
}
```

- **a) `2 0 1`** ✅
- b) Compiler Error
- c) `0 1 2`
- d) `2 1 0`

## Problem 2

Consider the following C program:

```c
#include <stdio.h>

struct Ournode {
  char x, y, z;
};

int main(void) {
  struct Ournode p = {'1', '0', 'a' + 2};
  struct Ournode *q = &p;

  printf("%c %c", *((char*)q + 1), *((char*)q + 2));
  return 0;
}
```

- **a) `0, c`** ✅
- b) `0, a + 2`
- c) `'0', 'a + 2'`
- d) `'0', 'c'`

**Answer:**

We have a struct `Ournode` that has three variables of type `char`. Then we initialize the struct variable `p` with the values of type `char` `'1'`, `'0'`, `'c'`. `'c'` because adding 2 to `'a'` (ASCII: 97) will be 99 which is the ASCII code of the character `'c'`.

Members are stored in a contiguous block of memory. So we can assume:

| `'1'` | `'0'` | `'c'` |
| ----- | ----- | ----- |
| 1000  | 1001  | 1002  |

We then have a pointer `q` which points to the struct variable `p` of type `Ournode`. So `q` contains the address 1000. Here, `p` contains the address of the whole structure, not the address of the first element of the structure, even though they are the same (1000).

Then through `printf()` we print two characters. `q` was the pointer to the whole structure. Now, after type casting, it is a pointer to a character. `q` in fact is now pointing to the first element. As we add 1 to the address, `q` points to the second element, which is address 1001 (`'0'`). The second argument to `printf()` works the same, except we are adding 2, pointing now to 1002 (`'c'`). Both are dereferenced so `printf()` prints the characters `0, c`.

## Problem 3

The following C declarations

```c
struct node {
  int i;
  float j;
};

struct node *s[10];
```

define `s` to be:

- **a) An array, each element of which is a pointer to a structure of type `node`.** ✅
- b) A structure of 2 fields, each field being a pointer to an array of 10 elements.
- c) A structure of 3 fields: An integer, a float and an array of 10 elements.
- d) An array, each element of which is a structure of type node.

**Answer:**

As square brackets have precedence over the star operator `*`, we know that `s` is an array. As there is an `*`, we know that it is a pointer to type `struct node`. So `s` is an array which holds pointers to `struct node` type in each of its elements.

# Unions

Union is a user defined data type but unlike structures, union members share the same memory location.

**Example:**

```c
struct abc {
  int a;
  char b;
};
```

- Address of `a` = 6295624
- Address of `b` = 6295628

```c
union abc {
  int a;
  char b;
};
```

- Address of `a` = 6295616
- Address of `b` = 6295616

## Fact

In union, members will share the same memory location. If we make changes in one member then it will be reflected to other members as well.

**Example:**

```c
union abc {
  int a;
  char b;
} var;

int main(void) {
  var.a = 65;

  printf("a = %d\n", var.a);
  printf("b = %c\n", var.b);
  return 0;
}
```

Output:

```
a = 65
b = A
```

### Deciding The Size Of Union

Size of the union is taken according to the size of the largest member of the union.

**Example:**

```c
union abc {
  int a;
  char b;
  double c;
  float d;
};

int main(void) {
  printf("%ld", sizeof(union abc));
  return 0;
}
```

Output: `8`

Sizes depend on the machine. Let's assume the following sizes:

| Type     | Size    |
| -------- | ------- |
| `int`    | 4 bytes |
| `char`   | 1 byte  |
| `double` | 8 bytes |
| `float`  | 4 bytes |

### Accessing Members Using Pointers

We can access members of union through pointers using the arrow syntax (`->`) operator.

```c
union abc {
  int a;
  char b;
};

int main(void) {
  union abc var;
  var.a = 90;

  union abc *p = &var;
  printf("%d %c", p->a, p->b);
  return 0;
}
```

Output: `90 Z`

ASCII code of `'Z'` is 90 so when we print `p->b` we print `Z`.

## Problem 1

Consider the following C declaration:

```c
struct {
  short s[5];
  union {
    float y;
    long z;
  } u;
} t;
```

Assume that objects of type `short`, `float` and `long` occupy 2 bytes, 4 bytes and 8 bytes respectively. The memory requirement for variable `t`, ignoring alignment considerations, is

- a) 22 bytes
- b) 14 bytes
- **c) 18 bytes** ✅
- d) 10 bytes

**Answer:**

In the structure we have an array of 5 elements of type `short`. Each element occupies 2 bytes so we have 10 bytes in total.

As for the `union`, we know that memory allocated to the union is equal to the memory needed for the largest member of it. As the `z` member of type `long` is the largest member in the union (8 bytes), we have 18 bytes in total. So size of variable `t` will be 18 bytes.

## Application Of Unions

A store sells two kinds of items:

- 📙 Books
- 👕 Shirts

Store owners want to keep records of the above mentioned items along with the relevant information.

- **Books:** Title, author, number of pages, price
- **Shirts:** Color, size, design, price

Initially, they decided to create a structure like below:

```c
struct store {
  double price;
  char *title;
  char *author;
  int num_pages;
  int color;
  int size;
  char *design;
};
```

This structure is perfectly usable but only price is a common property in both the items and the rest are individual.

We access the members of `struct store`:

```c
int main(void) {
  struct store book;

  book.title = "The Alchemist";
  book.author = "Paulo Coelho";
  book.num_pages = 197;
  book.price = 23; // in dollars
  return 0;
}
```

The `book` variable doesn't possesses `int color`, `int size` and `char *design`. Therefore it's a wastage of memory.

### Printing Size Of Structure

Note that structure padding is not considered.

```c
int main(void) {
  struct store book;

  printf("%ld bytes", sizeof(book));
  return 0;
}
```

Output: `44 bytes`

Why is size 44 bytes?

```c
struct store {
  double price;   // 8 bytes
  char *title;    // 8 bytes
  char *author;   // 8 bytes
  int num_pages;  // 4 bytes
  int color;      // 4 bytes
  int size;       // 4 bytes
  char *design;   // 8 bytes
};                // Total: 44 bytes
```

We can save lot of space if we start using unsions.

```c
#include <stdio.h>

#pragma pack(1)
struct store {
  double price;       // 8 bytes
  union {
    struct {
      char *title;    // 8 bytes
      char *author;   // 8 bytes
      int num_pages;  // 4 bytes
    } book;           // Total: 20 bytes

    struct {
      int color;      // 4 bytes
      int size;       // 4 bytes
      char *design;   // 8 bytes
    } shirt;          // Total: 16 bytes
  } item;             // Total: max(20, 16) = 20 bytes
};                    // Total: price + item = 8 + 20 = 28 bytes

int main(void) {
  struct store s;

  s.item.book.title = "The Alchemist";
  s.item.book.author = "Paulo Coelho";
  s.item.book.num_pages = 197;

  printf("%s\n", s.item.book.title);
  printf("%ld", sizeof(s));
  return 0;
}
```

Output:

```
The Alchemist
28
```

## Application of Unions - Part 2

How good is that if we have an array containing mixed type data?

```c
typedef union {
  int a;
  char b;
  double c;
} data;

int main(void) {
  data arr[10];

  arr[0].a = 10;
  arr[1].b = 'a';
  arr[2].c = 10.178;
  // and so on
  return 0;
}
```

Here we are successfully creating an array containing mixed type data.

Why not structures?

Assuming,

- `sizeof(int)` = 4 bytes
- `sizeof(char)` = 1 bytes
- `sizeof(double)` = 8 bytes

```c
typedef union {
  int a;
  char b;
  double c;
} data;       // size = 8 bytes
```

```c
typedef struct {
  int a;
  char b;
  double c;
} data;       // size = 13 bytes
```

So for `data arr[10]` using unions the size will be 80 bytes while `data arr[10]` using structures will be 130 bytes.

# Enumerations

An enumerated type is a user defined type which is used to assign names to _integral constants_ because names are easier to handle in program.

```c
enum Bool {False, True};

int main(void) {
  enum Bool var;

  var = True;
  printf("%d", var);
  return 0;
}
```

Output: `1`

`False` and `True` are the names to _integral constants_.

If we do not assign values to enum names then automatically compiler will assign values to them starting from 0.

**But** we can also use `#define` to assign names to integral constants. Then why do we even need enumerations?

## Need Of Enumerations

Two important reasons:

1. Enums can be declared in the local scope.
2. Enum names are automatically initialized by the compiler.

**Reason #1:** Enums can be declared in the local scope.

```c
int main(void) {
  enum Bool {False, True} var;

  var = True;
  printf("%d", var);
  return 0;
}
```

This enum is not visible outside the `main()` function.

**Reason #2:** Enum names are automatically initialized by the compiler.

```c
int main(void) {
  enum Bool {False, True} var;

  var = True;
  printf("%d", var);
  return 0;
}
```

`False` is initialized to 0 and `True` to 1.

## Some Important Facts

**Fact #1:** Two or more names can have the same value.

```c
int main(void) {
  enum point {x = 0, y = 0, z = 0};

  printf("%d %d %d", x, y, z);
  return 0;
}
```

Output: `0 0 0`

**Fact #2:** We can assign values in any order. All unassigned names will get value as value of previous name +1.

```c
int main(void) {
  enum point {y = 2, x = 34, t, z = 0};

  printf("%d %d %d", x, y, z, t);
  return 0;
}
```

Output: `34 2 0 35`

**Fact #3:** Only integral values are allowed.

```c
int main(void) {
  enum point {x = 34, y = 2.5, z = 0};

  printf("%d %d %d", x, y, z);
  return 0;
}
```

This would output an error, as we assigned `y` to a float value.

**Fact #4:** All enum constant must be unique in their scope.

```c
int main(void) {
  enum point1 {x = 34, y = 2, z = 0};
  enum point2 {x = 4, p = 25, q = 1};

  printf("%d %d %d %d %d", x, y, z, p, q);
  return 0;
}
```

This would also ouput an error, as we are redeclaring enumerator `x`.

# Calculating Area Of Rectangle

**Question:** The following structures are designed to store information about objects on a graphics screen:

```c
struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };
```

A point structure stores the `x` and `y` coordinates of a point on the screen. A rectangle structure stores the coordinates of the upper left and lower right corners of the rectangle.

Write a function that accepts rectangle structure `r` as an argument and computes the area of `r`.

**Formula for calculating an area:**
$$A=l\times b$$

- Length = `lower_right_x` - `upper_left_x`
- Breadth = `upper_left_y` - `lower_right_y`

```c
#include <stdio.h>

struct point {
  int x;
  int y;
};

struct rectangle {
  struct point upper_left;
  struct point lower_right;
};

int area(struct rectangle r) {
  int length, breadth;

  length = r.lower_right.x - r.upper_left.x;
  breadth = r.upper_left.y - r.lower_right.y;

  return length * breadth;
}

int main(void) {
  struct rectangle r;

  printf("Enter the upper left coordinates of the rectangle: \n");
  scanf("%d %d", &r.upper_left.x, &r.upper_left.y);

  printf("Enter the lower right coordinates of the rectangle: \n");
  scanf("%d %d", &r.lower_right.x, &r.lower_right.y);

  printf("Area of the rectangle: %d", area(r));
  return 0;
}
```

# Problems On Structures & Unions

**Question 1:** Suppose that `s` is the following structure:

```c
struct {
  double a;
  union {
    char b[4];
    double c;
    int d;
  } e;
  char f[4];
} s;
```

If `char` values occupy 1 byte, `int` values occupy 4 bytes and `double` values occupy 8 bytes, how much space will a C compiler allocate for `s`? _(Assume that the compiler leaves no "holes" between members - no padding.)_

| Member      | Size    |
| ----------- | ------- |
| `double a`  | 8 bytes |
| `char b[4]` | 4 bytes |
| `double c`  | 8 bytes |
| `int d`     | 4 bytes |
| `char f[4]` | 4 bytes |

The size of a union is equal to the size of the member which possesses the maximum size. As `double c` is the biggest member, so size of the unin is 8 bytes. So we have:

$$8+8+4=20$$

The size of struct `s` is **20 bytes** in total, padding not considered.

**Question 2:** Suppose that `u` is the following union:

```c
union {
  double a;
  struct {
    char b[4];
    double c;
    int d;
  } e;
  char f[4];
} u;
```

If `char` values occupy 1 byte, `int` values occupy 4 bytes and `double` values occupy 8 bytes, how much space will a C compiler allocate for `u`? _(Assume that the compiler leaves no "holes" between members - no padding.)_

| Member      | Size     |
| ----------- | -------- |
| `double a`  | 8 bytes  |
| `struct e`  | 16 bytes |
| `char f[4]` | 4 bytes  |

In this case, we have a union and we know that size of a union is equal to the size of its biggest member. The biggest member in this union is the `struct e`, which has a size of 16 bytes. So the total size of this union is **16 bytes**.

```c
#include <stdio.h>

#pragma pack(1)

struct {
  double a; // 8 bytes
  union {
    char b[4]; // 4 bytes
    double c;  // 8 bytes
    int d;     // 4 bytes
  } e;         // 8 bytes
  char f[4];   // 4 bytes
} s;           // 20 bytes

union {
  double a; // 8 bytes
  struct {
    char b[4]; // 4 bytes
    double c;  // 8 bytes
    int d;     // 4 bytes
  } e;         // 16 bytes
  char f[4];   // 4 bytes
} u;           // 16 bytes

int main(void) {
  printf("%ld %ld", sizeof(s), sizeof(u));
  return 0;
}
```

Output: `20 16`
