# Data Structures

## What Is Data?

📖 **Dictionary Definition:**

> The _quantities_, _characters_ or _symbols_ on which operations are performed by a computer, which may be stored and transmitted in the form of electrical signals and recorded on magnetic, optical or mechanical recording media.

**Example:** `c = a + b`

## When Does Data Become Information?

- Data: `TEERPSAJ SI EMAN YM` (Collection of _characters_)
- Information: `MY NAME IS JASPREET`

If data is arranged in a systematic way then it gets a structure and become meaningful.

> This meaningful or processes data is called _Information_.

It's not difficult to understand that the data needs to be managed in such a way so that it can produce some meaningful Information.

To provide an appropriate way to structure the data, we need to know about **data structures**.

## What Is A Data Structure?

A data structure is the systematic way to organize data so that it can be used efficiently.

**Example:** Arrays

Instead of creating _multiple variables_ of the same type, why not create an array to store all the values.

_Storing strings_ is equivalent of storing a sequence of characters. This requires an array.

## Some Real-Life Examples

### Example 1

**Did you know?** Stack data structure is used in implementing redo and undo feature.

### Example 2

Which data structure is used to store an image as a bitmap? **Arrays**.

**Bitmap** images are stored as a series of tiny dots called pixels.

Here, each pixel is actually a small square that is assigned a color and then arranged in a pattern to form an image.

### Example 3

Storing the _friendship information_ on a social networking site. **Graph** is used for this kind of information.

## Data Types Vs Abstract Data Types

### What Is A Data Type?

Two important things about data types:

1. Defines a certain _domain_ of values.
2. Defines _operations_ allowed on those values.

**Example:**

`int` type:

- Takes only integer values.
- Operations: Addition, subtraction, multiplication, bitwise operations etc.

`float` type:

- Takes only floating point values.
- Operations: Addition, subtraction, multiplication, division etc. (Bitwise and `%` operations are not allowed!)

### User Defined Data Types

In contrast to primitve data types, there is a concept of user defined data types.

The operations and values of user defined data types are not specified in the language itself but is specified by the user.

**Example:** `struct`, `union`, `enum`

By using structures, we are defining our own type by combining other data types.

```c
struct poing {
  int x;
  int y;
};
```

### Abstract Data Types (ADT)

ADTs are like user defined data types which define operations on values using functions without specifying what is there inside the function and how the operations are performed.

**Example:** Stack ADT

A stack consists of elements of same type arranged in a sequential order.

**Operations:**

- `initialize()` - Initializing it to be empty
- `push()` - Insert an element into the stack
- `pop()` - Delete an element from the stack
- `is_empty()` - Checks if the stack is empty
- `is_full()` - Checks if the stack is full

Think of ADT as a _black box_ which hides the inner structure and design of the data type from the user.

> There are multiple ways to implement an ADT.

**Example:**

A stack ADT can be implemented using arrays or linked lists.

### Why ADT?

The program which uses data structures is called a _client_ program. It has access to the ADT i.e. the interface.

The program which implements the data structure is known as the _implementation_.

**Advantage:** Let's say if someone wants to use the stack in the program, then he can simply use `push()` and `pop()` operations without knowing its implementation.

Also, if in the future the implementation of stack is changed from array to linked list, then the client program will work in the same way without being affected.

👉🏼**Conclusion:** ADT provides _abstraction_.
