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

```bash
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

```bash
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

```bash
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

```bash
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

```bash
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

```bash
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

```bash
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

```bash
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

```bash
0
0.00
0.44
```

The first output of **0** is, because we divide two integers (4 and 9) and define the type of `var` as `int`. So everything after the comma will be truncated.

The second output of **0.00** is, because we divide again two integers (4 and 9) which results in 0. But this time we defined the type of `var1` as `float`. So the result will be printed as `%.2f` which equals to **0.00**.

The third output is our desired result. As we divided two floats (4.0 and 9.0) and stored it in `var2` which is of type `float`.
