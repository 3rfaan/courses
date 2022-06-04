# C Codecademy Course

In this Codecademy course I learned the basics of the C language. I included the results for my own reference.

## Hello World

```cpp
#include <stdio.h>

int main() {
  // Output a line
  printf("Hello World!\n")
}

// Output: Hello World!
```

- `#include <stdio.h>`: This line is needed to run the line of code that starts with `printf`.
- `int main(){ }`: This is the starting point of the code. All the code inside the curly braces `{}` runs first.
- `// Output a line`: Comment
- `printf("Hello World!")`: This line of code prints, or outputs, the text “Hello World!” to the console. Printing text to the console is one way for a program to communicate with the user.

## Syntax and Errors

```cpp
#include <stdio.h>

int main() {
  // output a line
  printf("Hello World!\n");
}
```

## Output

```cpp
#include <stdio.h>

int main() {
  // Simple Recipe
  printf("2 Cups: All Purpose Flour");
  printf("1 Cups: Unsalted Butter\t(Room Temperature)");
  printf("\n2/3 Cups: Granulated Sugar");
}
```

## Comments

```cpp
#include <stdio.h>

int main() {
  // First print statement
  printf("Chocolate chip cookies are way better than oatmeal raisin cookies.\n");

  // Second print statement

  /* This is a block comment in C. It reminds me of the comments in JavaScript as they are essentially the same. */
  printf("Learning the C programming language is an exciting adventure!\n");
}
```

## Compiling

```cpp
#include <stdio.h>

int main() {
  // output a line
  printf("Hello World!\n");
}
```

Terminal input:

```bash
gcc script.c -o helloWorld
```

```bash
./helloWorld
```

## Naming Standards

```cpp
#include<stdio.h>

int main() {

  int number;
  int test_value;
  int example;
  float int_float;
  printf("Hello World!\n");

}
```

## Data Types

```cpp
#include <stdio.h>

int main() {

  // Fix the missing data types
  int studentRank;
  float studentFeeTotal;
  char studentGradeLetter;

  // No need to make any changes below here, use these as a hint to how each variable above should be declared
 studentRank = 1;
 studentFeeTotal = 100.56;
 studentGradeLetter = 'A';

 printf("Student's Rank in class: %dst\n", studentRank);
 printf("Student's Total Fees: $%3.2f\n", studentFeeTotal);
 printf("Student's Grade: %c\n", studentGradeLetter);
}
```

## `printf()`

```cpp
int day = 3;
printf("Hello World, today is the %drd!", day);
```

To indicate a variable type you want to replace:

| symbol   | type            |
| -------- | --------------- |
| %d or %i | int             |
| %f       | double or float |
| %c       | char            |

You can also use some reserved symbols within the string to have invoked formatting, here are a few common ones.

| symbol | effect          |
| ------ | --------------- |
| \n     | newline         |
| \r     | carriage return |
| \t     | tab             |

```cpp
#include <stdio.h>

int main() {

 int ageLearnedToRide = 5;


 printf("I was %i years old when I learned to ride a bike.\n", ageLearnedToRide);
 printf("I hope I still remember how to ride.");
}
```

## Initialization

```cpp
#include <stdio.h>

int main() {

  int numOfBooks = 5;
  char favLetter = 'A';
  char favDigit = '7';
  double costOfCandyBar = 1.80;

  printf("Number of books: %d\n", numOfBooks);
  printf("Your Favorite Letter is: %c\n", favLetter);
  printf("Your Favorite Digit is: %c\n", favDigit);
  printf("You expect to pay $%.2f for a candy bar.\n", costOfCandyBar);
}
```

## Float and Double, What's the Difference?

```cpp
#include <stdio.h>

int main() {

// Modify this variable value, start low and increase until something odd appears in the results
  int numOfLoops = 10;

  // Please do not modify anything below this point
  float a = 0.1f;
  float b = 0;
  double x = 0.1;
  double y = 0;

  printf("At the start, our target float b is:%f\n", b);
  printf("At the start, our target double y is:%f\n", y);

// If you were curious about what this code is doing, it is looping through and adding to our variables b and y a set amount of 0.1 on each loop
  for (int i = 0; i < numOfLoops; i++)
  {
    b += a;
    y += x;
  }

  printf("At the end, our target float b is:%f\n", b);
  printf("At the end, our target double y is:%f\n", y);

}
```

## Updating Values

```cpp
#include <stdio.h>

int main() {
  // These variables were created and had a starting value for you, no need to change
  char bookVersionReview = 'A';
  char movieVersionReview = 'B';
  double ticketPrice = 10.25;
  double bookPrice = 19.99;

  // Update the movie review score here
  movieVersionReview = 'C';

  // Update the ticket price here
  ticketPrice = bookPrice;

  // No need to change below here
  printf("The book version has a review score of %c and costs $%.2f\n", bookVersionReview, bookPrice);
  printf("The movie version has a review score of %c and costs $%.2f\n", movieVersionReview, ticketPrice);
}
```

## Constants

```cpp
#include <stdio.h>

int main() {

// Speed of light is 1.86e5 mi/s or 186000 mi/s we will store 1.86 and do the multiplicaiton later.
  const double SPEEDOFLIGHT = 1.86;
  int timeTraveledInSeconds = 30;

  // No need to change below here
  printf("Light would travel %.2f miles in %d seconds\n", SPEEDOFLIGHT * 100000 * timeTraveledInSeconds, timeTraveledInSeconds);

}
```

## Casting Types

The other way to convert a variable from another type is explicitly. You can do this by simply telling the compiler what type you want to set it to. So in our example above we could change the line `a = b` to `a = (int)b`. That way if `b` was something other than 3.0, such as 3.2, we are telling the compiler to make it work, so it would set it to 3.

```cpp
#include <stdio.h>

int main() {

  double testScore = 95.7;
  int displayScore = (int)testScore;

  // No need to change below here
  printf("Great work, you got a %d%% on your test\n", displayScore);

}
```

## Casting Types Continued

A more interesting casting option is converting a `char` to a number type, or the other way around. Just like before, you have to be careful how you set this up. In the back-end, a `char` doesn’t store `'a'`, it stores the value representing that: 97 for lowercase and 65 for uppercase.

```cpp
int targetInt;
char sourceChar = 'a';
targetInt = (int)sourceChar;
```

Now `targetInt` equals 97.

When you cast an int to a `char`, you get the opposite process and the `char` is set to the value at the `int` value. So if you did:

```cpp
int sourceInt = 65;
char targetChar;
targetChar = (char)sourceInt;
```

`targetChar` now equals `'A'`.

---

If `'a'` is 97, what do you suppose we would get if we set an `int` to 99 and cast it to a `char`? Let’s find out. The initial state is set so you need to cast our `sourceInt` to `targetChar`.

Set `targetChar` equal to `sourceInt` and explicitly cast it by using `(char)`.

```cpp
#include <stdio.h>

int main() {

  char targetChar;
  int sourceInt = 99;
  double sourceDouble = 55.67;

  // Cast here
  targetChar = (char)sourceInt;
  targetChar = sourceDouble;

  // No need to change below here
  printf("source int %d, source double %.2f, target %c\n", sourceInt, sourceDouble, targetChar);
}

// Output: source int 99, source double 55.67, target 7
```

## Mathematical Operations

```cpp
#include <stdio.h>

int main() {

  // Variables set for you, do not change here
  int booksSold = 100;
  double bookCost = 9.99;
  double totalSalesValue;

  // Make your changes here
  booksSold += 200;
  totalSalesValue = booksSold * bookCost;
  totalSalesValue /= 2;

  // Output logic, no need to change this
  printf("You sold %d books and your take home was $%.2f\n", booksSold, totalSalesValue);
}

// Output: You sold 300 books and your take home was $1498.50

```

## Modulo

```cpp
#include <stdio.h>

int main() {

  int endingDayOfWeek = 0;
  int daysThatPass = 15;
  int daysInWeek = 7;

  endingDayOfWeek = (0 + daysThatPass)

  printf("You started on the 1st (0) day of the week, went %d days from this, so it is now the %d day of the week\n", daysThatPass, endingDayOfWeek);
}

/* Output:
You started on the 1st (0) day of the week, went 15 days from this, so it is now the 1 day of the week */
```

## Increment and Decrement

```cpp
#include <stdio.h>

int main() {
  int n = 13;
  int m = 10;

  m--;
  n++;

  printf("m = %d\n", m);
  printf("n = %d\n", n);
}
```

## Assignment

```cpp
#include <stdio.h>

int main() {

  int timesServerCrashed = 5;
  double losses = 500.95;

  losses *= timesServerCrashed;
  losses /= 2;

  printf("Total Losses: $%.2f\n", losses);
}
```

## Comparisons

```cpp
#include <stdio.h>

int main() {

  int x = 5;
  int y = 42;

  if (x < y) {
   printf("Congratulations on setting up a comparison correctly!");
  }

}
```

## Logical Operators

```cpp
#include <stdio.h>

int main() {

  int x = 1;
  int y = 27;

  if (!(x == y)) {
    printf("Congratulations on setting up a comparison correctly!");
  } else {
    printf("Please try again!");
  }

}

// Output: Congratulations on setting up a comparison correctly!
```

## Order of Operations

Looking at the table below, the operations with priority 1 will be performed first. Then priority 2, 3, and so on will be processed. For operators of the same level of priority, they operations occur from left to right.

| Priority | Symbol                   |
| -------- | ------------------------ |
| 1        | ++                       |
| 1        | --                       |
| 1        | ()                       |
| 2        | !                        |
| 2        | (typecast)               |
| 3        | \*                       |
| 3        | /                        |
| 3        | %                        |
| 4        | +                        |
| 4        | -                        |
| 5        | <, <=                    |
| 5        | >, >=                    |
| 6        | ==, !=                   |
| 7        | &&                       |
| 8        | \|\|                     |
| 9        | all assignment operators |

```cpp
#include <stdio.h>

int main() {

  int x;
  int y;

  x = (2 + 3) * 5;
  y = 2 / (4 + 6);

  printf("x is: %d\n", x);
  printf("y is: %d\n", y);

}
```

## Coin Flip Demo

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Create a number that’s 0 or 1
  srand (time(NULL));
  int coin = rand() % 2;

  // If number is 0: Heads
  // If it is not 0: Tails
  if (coin == 0) {
    printf("Heads\n");
  } else {
    printf("Tails\n");
  }

}
```

## `if` statement

```cpp
#include <stdio.h>

int main() {

  int grade1 = 90;
  int grade2 = 59;

  if (grade1 > 60) {
    printf("Pass\n");
  }

  if (grade2 < 60) {
    printf("Fail");
  }

}
```

## Working with Operators

```cpp
#include <stdio.h>

int main() {

  int a = 10;
  int b = -5;

  if (a > 0 || b > 0) {
    printf("Positive\n");
  }

  if (a > 0 && !(b > 0)) {
    printf("Positive too");
  }

}

/* Output:
Positive
Positive too */
```

## `else` Clause

```cpp
#include <stdio.h>

int main() {

  int grade1 = 59;
  int grade2 = 90;

  if (grade1 > 60) {
    printf("Pass\n");
  } else {
    printf("Fail\n");
  }

  if (grade2 > 60) {
    printf("Pass\n");
  } else {
    printf("Fail\n");
  }

}
```

## `else if`

```cpp
#include <stdio.h>

int main() {

  double ph = 7;

  // Start the if, else if, else here:
  if (ph > 7) {
    printf("Basic\n");
  } else if (ph < 7) {
    printf("Acidic\n");
  } else {
    printf("Neutral\n");
  }

}
```

## `switch` Statement

```cpp
#include <stdio.h>

int main() {

  int number = 7;

  switch(number) {
    case 1:
      printf("Bulbasaur\n");
      break;
    case 2:
      printf("Ivysaur\n");
      break;
    case 3:
      printf("Venusaur\n");
      break;
    case 4:
      printf("Charmander\n");
      break;
    case 5:
      printf("Charmeleon\n");
      break;
    case 6:
      printf("Charizard\n");
      break;
    case 7:
      printf("Squirtle\n");
      break;
    case 8:
      printf("Wartortle\n");
      break;
    case 9:
      printf("Blastoise\n");
      break;
    default:
      printf("Unknown\n");
      break;
  }
}
```

## Ternary Operators

```cpp
#include <stdio.h>

int main() {

  int a = 10;
  int b = 5;
  int min;

  // Print out the smaller number with return
  min = a < b ? a : b;
  printf("%d\n", min);

  // Print out the smaller number without return
  a < b ? printf("%d\n", a) : printf("%d\n", b);
}

// Output: 5 5
```

## Optional Assesment

**Optional**: Little Mac is an interplanetary space boxer, who is trying to win championship belts for various weight categories on other planets within the solar system.

Write a **space.c** program that helps him keep track of his target weight by: It should ask him what his earth weight is. Ask him to enter a number for the planet he wants to fight on. It should then compute his weight on the destination planet.

Compile and execute:

```bash
gcc space.c
./a.out
```

Here is the table of conversion:

| \#  | Planet  | Relative Gravity |
| --- | ------- | ---------------- |
| 1   | Mercury | 0.38             |
| 2   | Venus   | 0.91             |
| 3   | Mars    | 0.38             |
| 4   | Jupiter | 2.34             |
| 5   | Saturn  | 1.06             |
| 6   | Uranus  | 0.92             |
| 7   | Neptune | 1.19             |

To compute his weight on the planet he is fighting on, multiply his earth weight and the relative gravity of that planet.

Try using both `if`, `else if`, `else` and a `switch` statement!

One possible answer:

```cpp
#include <stdio.h>

int main() {

  double weight;
  int x;

  printf("Please enter your current earth weight: ");
  scanf("%lf", &weight);

  printf("\nI have information for the following planets:\n\n");
  printf("\t1. Mercury\t2. Venus\t3. Mars\t4. Jupiter\n");
  printf("\t5. Saturn\t6. Uranus\t7. Neptune\n\n");

  printf("Which planet are you visiting? ");
  scanf("%d", &x);

  switch (x) {
    case 1:
      weight *= 0.38;
      break;
    case 2:
      weight *= 0.91;
      break;
    case 3:
      weight *= 0.38;
      break;
    case 4:
      weight *= 2.34;
      break;
    case 5:
      weight *= 1.06;
      break;
    case 6:
      weight *= 0.92;
      break;
    case 7:
      weight *= 1.19;
      break;
    }

  printf("\nYour weight: %lf\n", weight);

}
```

## Interacting with a Loop

```cpp
#include <stdio.h>

int main() {
  int pin = 0;
  int tries = 0;

  printf("BANK OF CODECADEMY:\n");
  printf("Enter your PIN: ");
  scanf("%d", &pin);

  tries++;

  while (pin != 1234 && tries < 3) {
    printf("Enter your PIN: ");
    scanf("%d", &pin);
    tries++;
  }

  if (pin == 1234) {
    printf("PIN accepted!\n");
    printf("You now have access.\n");
  }
}
```

## Guess the Number

```cpp
#include <stdio.h>

int main() {

  int guess;
  int tries = 0;

  printf("I’m thinking of a number in the range 1-10.\n");
  printf("Try to guess it: ");
  scanf("%d", &guess);

  // Write a while loop here:
  while (guess != 8 && tries < 50) {
    printf("Wrong guess, try again: ");
    scanf("%d", &guess);
    tries++;
  }

  if (guess == 8) {
    printf("You got it!\n");
  }

}
```

## `while` Loop

```cpp
#include <stdio.h>

int main() {

  int i = 9;
  int square = 0;

  // Write a while loop here:
  while (i >= 0) {
    printf("%d\t%d\n", i, i * i);
    i--;
  }

}
```

## `do-while` Loop

```cpp
#include <stdio.h>

int main() {

  int i = 0;

  do {
    printf("%d\n", i);
    i++;
  } while (i < 10);
}
```

## `for` Loop

```cpp
int main() {

  // Write your loop here
  for (int i = 99; i >= 0; i--) {
    printf("%d bottles of pop on the wall.\n", i);
    printf("Take one down and pass it around.\n");
    printf("%d bottles of pop on the wall.", i - 1);
    i--;
  }

}
```

## Breaking Out

```cpp
#include <stdio.h>

int main() {

  int number1 = 1;
  int numbers_entered1 = 0;
  int number2 = 1;
  int numbers_entered2 = 0;

  while (numbers_entered1 < 10) {

    printf("Loop 1 - Please enter a number: ");
    scanf("%d", &number1);

    // Figure out how to break out here!
    if (number1 <= 0) {
      break;
    }

    numbers_entered1++;
  }

  while (number2 > 0 && numbers_entered2 < 10) {

    printf("Loop 2 - Please enter a number: ");
    scanf("%d", &number2);

    numbers_entered2++;
  }

  printf("Good job! You’ve broken out!\n");

}
```

## Continuing

```cpp
#include <stdio.h>

int main() {

  for (int i = 0; i < 10; i++) {
    // Figure out how to skip the print of 5 here
    if (i == 5) {
      continue;
    }

    printf("%d\n", i);
  }

}
```

## Creating and Initializing Arrays

```cpp
#include<stdio.h>

int main() {

  // Checkpoint 1 code goes here.
  double q[5];

  // Checkpoint 2 code goes here.
  int evens[] = {2, 4, 6, 8, 10};

}
```

## Array Access and Element Modification

```cpp
#include<stdio.h>

int main() {

  int evens[] = {2, 4, 6, 8, 10, 12};
  int odds[] = {1, 4, 5, 7, 10, 11}; // Don't modify this line.

  printf("%i\n", evens[5]); // Checkpoint 1. Fix this error.

  // Code for checkpoint 2 goes here.
  printf("%i\n", evens[2]);

  // Code for checkpoint 3 goes here.
  odds[1] = 3;
  odds[4] = 9;

}
```

## Looping Through Arrays

```cpp
#include<stdio.h>

int main() {
  int arr[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 20, 22, 26, 28, 29};
  int arr2[100];

  // Code for Checkpoint 1 goes here
  for (int i = 0; i < 20; i++) {
    printf("%d\n", arr[i]);
  }

  // Code for Checkpoint 2 goes here
  for (int i = 0; i < 100; i++) {
    arr2[i] = i + 4;
  }

}
```

## Length of Array Using `sizeof()`

```cpp
#include<stdio.h>

int main() {
  double arr[] = {1.0, 8, 2.27, 16.2, 2, 3.14, 12.6, 1.62, 6.54, 9, 11};
  int len;

  // Checkpoint 1 code goes here.
  len = sizeof(arr) / sizeof(double);

  printf("%i\n", len);

  // Checkpoint 2 code goes here.
  for (int i = 0; i < len; i++) {
    printf("%f\n", arr[i]);
  }

}
```

## Multidimensional Arrays

```cpp
#include<stdio.h>

int main() {

  // Checkpoint 1 code goes here.
  int arr[9][9];

  // Checkpoint 2 code goes here.
  int matrix[][3] = {{2, 9, 11}, {3, 1, 4}, {8, 3, 1}};

}
```

## Element Access in Multidimensional Arrays

To prevent the hardcoding of dimensions in a loop, the `sizeof()` function is used as follows:

rowDimension = sizeof(matrix)/sizeof(matrix[0]);
columnDimension = sizeof(matrix[0])/sizeof(dataType);
Let’s use these identities to write the `for` loop from the previous exercise:

```cpp
int mat[3][3] = {{12, 8, 2}, {17, 19, 5}, {6, 11, 2}};

int rowDimension = sizeof(mat)/sizeof(mat[0]);
int columnDimension = sizeof(mat[0])/sizeof(int);

for(int i = 0; i < rowDimension; i++){
  for(int j = 0; j < columnDimension; j++){
    int num = mat[i][j];
    printf("%i\n", num);
  }
}
```

---

```cpp
#include<stdio.h>

int main() {
  int matrix[][4] = {{14, 10, 6, 4}, {3, 7, 18, 11}, {13, 9, 5, 17}, {19, 12, 2, 1}};
  int sum = 0;

  // Checkpoint 1 code goes here.
  printf("%i\n", matrix[3][1]);

  // Checkpoint 2 code goes here.
  for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); i++) {
    for (int j = 0; j < sizeof(matrix[0]) / sizeof(int); j++) {
      sum += matrix[i][j];
    }
  }

}
```

## Creating and Initializing Strings

```cpp
#include<stdio.h>

int main() {
 // Checkpoint 1 code goes here
 char comp[] = {'C', 'o', 'm', 'p', 'u', 't', 'e', 'r', '\0'};

 // Checkpoint 2 code goes here
 char compCode[] = "Computer Code";

 // Checkpoint 3 code goes here
 printf("%s\n%s\n", comp, compCode);

}
```

## Character Access and Modification

```cpp
#include <stdio.h>

int main() {
  char p[] = "procezzor";

  // Checkpoint 1 code goes here
  printf("%c\n", p[2]);

  // Checkpoint 2 code goes here
  p[5] = 's';
  p[6] = 's';

  printf("%s", p);
}
```

## Looping Through Strings

```cpp
#include<stdio.h>
#include<string.h>

int main() {
  char s[] = "When the zombies arrive, quickly fax Judge Pat Alphabet";
  char p[] = "poolloop";

  // Checkpoint 1 code goes here
  for (int i = 0; i < strlen(s); i++) {
    s[i] = '*';
  }

  printf("%s\n", s);

  // Checkpoint 2 code goes here
  for (int i = 0; i < strlen(p) / 2; i++) {
    p[i] = '#';
  }

  printf("%s", p);

}
```

## Concatenating Strings

```cpp
#include<stdio.h>
#include<string.h>

int main() {

  char s1[] = "London";
  char s2[] = " Bridge";

  char n[] = "New";
  char y[] = " York";
  char c[] = " City";

  // Code for checkpoint 1 goes here
  strcat(s1, s2);
  printf("%s\n", s1);

  // Code for checkpoint 2 goes here
  strcat(n, y);
  strcat(n, c);
  printf("%s\n", n);

}
```

## Copying Strings

```cpp
#include<stdio.h>
#include<string.h>

int main() {

  char src[] = "banana";
  char dst[7];

  char pan[] = "How vexingly quick daft zebras jump!";
  int len = strlen(pan) + 1; // Checkpoint 2
  char dst2[len];

  // Code for checkpoint 1 goes here
  strcpy(dst, src);
  printf("%s\n", dst);

  // Code for checkpoint 3 goes here
  strcpy(dst2, pan);
  printf("%s", dst2);

}
```

## Memory in C

For a program to execute, it must use some of the computer’s resources such as CPU, RAM, IO, or other hardware. Deciding how and at what capacity to use these resources is the job of the underlying operating system. One of the most important of these resources is memory, more specifically: the temporary memory used for program execution which is called random access memory (RAM). When a program executes, the operating system reserves a section of the computer’s physical RAM to be used exclusively by the program. The fundamental unit of this memory is a byte. As you learned previously, all variables are simply a collection of some number of bytes: an `int` is four bytes, a `double` is eight bytes, and so on. The allocated section of RAM is simply a block of however many bytes the program needs (if available, of course).

As you can see, in this block of memory to the right, every byte has an associated address numbered using the [hexadecimal numbering system](https://en.wikipedia.org/wiki/Hexadecimal). For example, a byte of memory could be located at address 0x200 and the immediate byte next to it is located at address 0x201.

Every programming language has a different policy regarding the direct access and manipulation of a byte in memory; some allow it, some do not. C is one of the languages that allow such operations through the use of a pointer, and we will see how in this lesson.

At first glance, pointers may appear to be an overcomplicated way to work with variables, and for such simple examples meant to illustrate basic principles, this is true. However, the real value of pointers becomes apparent in more complex applications, such as working with data structures or embedded systems (think robots and microchips). Examples of these are well beyond the scope of this introductory tutorial. For now, just familiarize yourself with these ideas such that you may recall them when you need to!

## Pointers

In C, a byte of memory can be accessed using a pointer. A pointer containing the address of a variable is said to “point” to that variable.

Recall that when you declare a variable, a contiguous block of bytes is reserved in memory. A pointer to a variable is the address of the first of these bytes. A pointer can be created for every type of variable: be it primitive (for example `int`, `char`, or `double`), a custom data type created using a `struct` (we’ll cover those in a later lesson), or even another pointer. The syntax of a pointer is the following:

> _dataType\* nameOfPointer_;

or

> _dataType \*nameOfPointer_;

For example, to declare a pointer variable (called `ptr`) that points to an `int`, you would write:

```cpp
int* ptr; // Pointer to an int
int *ptr; // Same as above but different style.
```

In this case, `ptr` stores the address of the first byte of a block of memory containing an `int`. To print this address to the screen, `printf()` is used like so:

```cpp
int x; // Create an int variable
int* ptr = &x; // Pointer to that int (we'll dive into what "&" means in the coming exercises)
printf("%p", ptr); // %p needed to instruct printf() that ptr is of type pointer
```

This will output a hexadecimal integer that represents the address in memory that is storing a variable of type `int`. This number will be different every time the program is executed.

If we had another pointer named `ptr2` that doesn’t point to a declared variable, printing it will result in (`nil`) rather than a hexadecimal address:

```cpp
int* ptr2;
printf("%p", ptr2); // Prints: (nil)
```

---

```cpp
#include<stdio.h>

int main() {

  // Checkpoint 1 code goes here.
  double dblVar;

  // Checkpoint 2 code goes here.
  double *dblPtr = &dblVar;

  // Checkpoint 3 code goes here.
  printf("%p", dblPtr);

}

// Outputs: 0x7ffcf00236e8 (Address in memory)
```

## The Reference Operator

Since pointers are used to store the memory address of a variable, we need to obtain this address first. This is done by using the reference operator (&). The syntax for this is:

> &variableName;

Consider the following piece of code:

```cpp
int x = 9;
printf("%p", &x);
```

This will output to the screen the memory address of the variable `x`. To assign an address to a pointer, the following syntax is used:

> pointer = &variableName;

Consider the following example:

```cpp
int x = 727; // Declare variable x
int* ptr = &x; // Declare a pointer to an int variable and assign to it the address of variable x
printf("%p\n", &x); // Print the address of x
printf("%p\n", ptr); // Print the address pointed to by ptr
```

The code above declares an integer variable `x` and an `int` pointer variable `ptr`. The pointer is then assigned the memory of the variable `x`. The last two `printf()` statements print this address; both lines will output the same hexadecimal number as they both refer to the same address in memory.

The address a pointer contains is not constant. A pointer may be reassigned to a new address so long as type consistency is maintained (e.g., `int` pointer points to a variable of type `int`). Consider this example:

```cpp
int* ptr; // Declare pointer to an integer type

int x = 3; // Declare variable x
ptr = &x; // Assigns memory address of variable x to the pointer
printf("%p\n", ptr); // Prints address of variable x

int y = 14; // Declare variable y
ptr = &y; // Reassigns the pointer to the memory address of variable y
printf("%p\n", ptr); // Prints address of variable y
```

---

```cpp
#include<stdio.h>

int main() {

  double g = 9.81;
  double pi = 3.14;

  // Checkpoint 1 code goes here.
  double *dblPtr = &g;

  // Checkpoint 2 code goes here.
  printf("%p\n", dblPtr);

  // Checkpoint 3 code goes here.
  dblPtr = &pi;

}
```

## The Dereference Operator

If we have a pointer that is assigned the memory address of a variable, eventually we will need to access the data that it contains so we can use or manipulate it. The data contained in the memory address pointed to by a pointer can be accessed using the dereference operator (\*). The syntax is as follows:

> _\*pointerName;_

Once a pointer is dereferenced, we can use its contents as we would a regular variable. It is important not to confuse this operator with the multiplication operator as they are represented by the same symbol!

Here is a full example:

```cpp
int x = 4;
int* ptr = &x; // ptr stores the memory address of variable x

int y = *ptr; // Declare variable y and assign to it the data stored in memory pointed to by ptr, which is the value of variable x

printf("%i", y);
```

The code above illustrates how to obtain the data stored in the address pointed to by `ptr` by dereferencing it. Since `ptr` stores the address of variable `x`, the value obtained by dereferencing `ptr` is the value of `x`. If the value of a dereferenced pointer is changed, the value of the corresponding variable will change in the same way:

```cpp
int x = 4;
int *ptr = &x;

*ptr = 200; // The data in the memory address pointed to by ptr now contains the value 200

printf("%i", x); // This will output 200
```

---

```cpp
#include<stdio.h>

int main() {

  int k = 2000;
  int* ptr = &k;

  // Checkpoint 1 code goes here.
  printf("%i\n", *ptr);

  // Checkpoint 2 code goes here.
  *ptr = 961;

  printf("%i\n", k); // Notice how this variable changed value after Checkpoint 2!

}
```

## Pointer Arithmetic

Remember that a pointer is a special type of integer variable. This implies that basic arithmetic operations can be done on pointers. In this exercise, we will explore this idea.

The only arithmetic operations allowed for pointers are addition and subtraction. Conceptually, adding to (or subtracting from) a pointer means the pointer will point to some new address. Multiplication is not allowed because the address of a byte of memory is usually a large number; therefore, multiplying an address may yield an even larger number, possibly representing an address outside the bounds of the available memory space. Division is not allowed as it potentially allows a pointer to illogically point to an address with a non-integer index.

The addition operation for a pointer is only valid when adding an integer to a pointer; you cannot add two or more pointers together! The syntax is traditional addition illustrated by the following example (**here, `n` represents an integer**):

```cpp
pointer += n;
```

The important thing to note here is that adding `n` to a pointer does not increment the address to point to a value n bytes away. It moves the pointer by `n` \* (size of the data type in bytes). For example, if a pointer to an `int`, the size of which is four bytes, initially contains address 100 (we will use a decimal address for simplicity), and three is added to the pointer, the pointer will now point to address 112.

Let’s take a look at how this works:

```cpp
int main() {
  int* ptr;
  ptr += 3; // Increment pointer by three blocks.
}
```

This code increments the pointer `ptr` to store the address that is three `int` sizes away. Incrementing by one can be done in the following ways:

```ccp
pointer++;
pointer += 1; // Same outcome with different syntax
```

Subtracting from a pointer behaves in the same way with the address being decremented instead of incremented.

Pointers are very powerful and allow greater control over a program. But with great power comes great responsibility! Working with pointer arithmetic can be dangerous if used carelessly. If an attempt is made to increment (or decrement) a pointer beyond the bounds of the memory space of a program, a crash will occur. Pointers are so dangerous, that many high-level languages (such as Java) will not even allow such operations. Be careful!

---

```cpp
#include<stdio.h>

int main() {
  double* ptr1;

  // Code for Checkpoint 1 goes here:
  ptr1 += 5;

  // Code for Checkpoint 2 goes here:
  ptr1 -= 4;

}
```

## Pointers & Arrays

In the lesson on arrays, you learned that an array is a contiguous block of memory reserved for many variables of the same type. Because of this structured organization, a pointer is well suited to work with this data type. If we have an integer array, we can use pointers and pointer arithmetic to iterate through the array to access or manipulate its values. This might seem like an overcomplicated way to work with arrays, but there are some advanced applications in which working with an array through a pointer is necessary.

Consider an array of integers `arr`. Since arrays are contiguous blocks of memory, if we have a pointer to the first element, we can use pointer arithmetic to access the rest of the array. Keep in mind that while this is a valid way to work with arrays, it is unsafe. Accessing memory outside of the bounds of the array will not cause a program crash, but will silently corrupt data stored in those addresses. In the case of a read operation, it will return a random value.

With caution in mind, let’s see how we can carefully access and manipulate elements in an array using pointers. The following code prints all of the elements of an array:

```cpp
int arr[10] = {2, 4, 7, 1, 10, 3, 11, 6, 20, 5};
int* ptr = &arr[0]; // Pointer to the first element

for(int i = 0; i < 10; i++){
  printf("%i\n", *ptr); // Dereference the pointer and print the value
  ptr++; // Increment the pointer to point to the next int in the array
}
```

The following code illustrates how to change the values of an array using pointers by changing all the elements in an array to three:

```cpp
int arr[10] = {2, 4, 7, 1, 10, 3, 11, 6, 20, 5};
int* ptr = &arr[0]; // Pointer to the first element

for(int i = 0; i < 10; i++){
  *ptr = 3; // Dereference the pointer and assign the value at the ptr address to three
  ptr++; // Increment the pointer to point to the next int in the array
}

for(int i = 0; i < 10; i++){
  printf("%i",arr[i]);
}
```

The output of the code above will be a string of 10 threes. These techniques are also applicable to strings since they are arrays too. **It cannot be stressed enough: be very careful when working with pointers!**

---

```cpp
#include<stdio.h>
#include<string.h>

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  char s[] = "Farmer Jack realized that big yellow quilts were expensive!!";

  // Code for Checkpoint 1 goes here.
  int *ptr = &arr[sizeof(arr) / sizeof(int) - 1];

  // Code for Checkpoint 2 goes here.
  for (int i = sizeof(arr) / sizeof(int); i > 0 ; i--) {
    printf("%d\n", *ptr);
    ptr--;
  }

  // Code for Checkpoint 3 goes here.
  char *ptr2 = &s[0];

  // Code for Checkpoint 4 goes here.
  for (int i = 0; i < strlen(s); i++) {
    *ptr2 = '#';
    ptr2++;
  }

  printf("%s\n", s);
}
```

## Memory Management

| Function  | Use Case                                                                                                      |
| --------- | ------------------------------------------------------------------------------------------------------------- |
| malloc()  | Use this function to reserve as many bytes as you want on the heap                                            |
| calloc()  | Use this function to reserve memory for some number of ints, doubles, or any other data type.                 |
| realloc() | Use this function to expand or contract a block of reserved memory (reserved by either malloc() or calloc()). |
| free()    | Use this function to release previously allocated memory.                                                     |

## Calling a Function

```cpp
#include <stdio.h>

int main(int num1, int num2) {
  // Write your code below
  printf("My favorite numbers: %d, %d\n", num1, num2);

}
```

## Library Functions

C gives us access to many useful libraries that include many different functions for you to use. In order to have access to these functions you need to include header files like `<stdio.h>` and `<stdlib.h>`.

You have already used `printf()` to output text to the console and learned about `abs()` to find the absolute value of an integer. Here are a few more functions we might use in your programs:

- `ceil()`: takes any number as an argument, rounds it up to the nearest integer, and returns the integer.
- `log()`: takes an integer as an argument and returns the natural logarithm of the given number.
- `toupper()`: takes a `char` as an argument and returns the uppercase of any alphabetic character.
- `isupper()`: takes a `char` as an argument and returns `1` if the character is an uppercase letter, `0` otherwise.

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));

  // Write your code below
  int randomNumber = rand() % 20 + 1;
  printf("%i", randomNumber);

}
```

The `srand()` function is used to set the seed for the random number generator. The seed initializes the random generation and should be a number that changes over time. The `time()` function is used as the `srand()` argument to ensure that the seed is a different number every time the code is run. When passed the argument `NULL`, the `time()` function will return the number of seconds passed since the date, January 1, 1970.

## Defining Functions

```cpp
#include <stdio.h>

// Write your code below
void printMyFavoriteAnimal(void) {
  printf("My favorite animal is a tiger\n");
}

int main(void) {
  printMyFavoriteAnimal();
}
```

## Function Return Values

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Modiy the code below
int getRandom1000() {
  int random1000 = rand() % 1000 + 1;

  return random1000;
}

int main(void) {
  srand(time(NULL));

  // Modify the code below
  int randomNumber = getRandom1000();
  printf("My random number is: %d", randomNumber);
}
```

## Function Parameters

```cpp
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Modify the code below
int getRandomNumber(int maxNumber) {
  int randomNumber = rand() % maxNumber + 1;
  return randomNumber;
}

int main(void) {
  srand(time(NULL));
  // Modify the code below
  int randomNumber = getRandomNumber(100);
  printf("My random number is: %d", randomNumber);
}
```
