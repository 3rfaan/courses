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
  printf("source int %d, source double, %.2f, target %c\n", sourceInt, sourceDouble, targetChar);

}
```
