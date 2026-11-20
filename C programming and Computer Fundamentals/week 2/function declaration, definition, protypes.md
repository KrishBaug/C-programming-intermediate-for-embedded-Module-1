# Functions in C

## What is a function?

A function is a reusable block of code.

```c
return_type function_name(parameters) {
    // code
    return value;
}
```

Example:

```c
int add(int a, int b) {
    return a + b;
}
```

- `int` → return type
- `add` → function name
- `int a, int b` → parameters
- `return a + b;` → sends the result back

## Function declaration

A **function declaration** tells the compiler that a function exists.

```c
int add(int a, int b);
```

It ends with a semicolon `;` and has no body.

A declaration that includes parameter types is called a **function prototype**. [84][86]

## Function definition

A **function definition** contains the actual code.

```c
int add(int a, int b) {
    return a + b;
}
```

It has:

- Function header
- `{ }`
- Actual code inside
- `return` statement, if the function returns a value

A function definition has a return type, name, parameters, and a body inside braces. [85]

## Function prototype

A **function prototype** is written before `main()` so the compiler knows the function name, return type, and parameter types before the function is used.

```c
int add(int a, int b);   // prototype

int main() {
    int result = add(5, 3);
    printf("%d", result);
    return 0;
}

int add(int a, int b) {  // definition
    return a + b;
}
```

A prototype has the same form as the function header but ends with `;` and has no body. [86][89]

## Why use prototypes?

- Lets you define functions after `main()`
- Helps the compiler check correct arguments
- Makes code organized
- Useful when using header files

## Full example

```c
#include <stdio.h>

// Function prototype
int add(int a, int b);

int main() {
    int result = add(10, 20);

    printf("Sum: %d\n", result);

    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;
}
```

Output:

```text
Sum: 30
```

## Function with no return value

Use `void` when the function does not return anything.

```c
void greet() {
    printf("Hello!\n");
}
```

Example:

```c
#include <stdio.h>

void greet();

int main() {
    greet();
    return 0;
}

void greet() {
    printf("Hello!\n");
}
```

## Function with parameters but no return

```c
#include <stdio.h>

void printAge(int age);

int main() {
    printAge(20);
    return 0;
}

void printAge(int age) {
    printf("Age: %d\n", age);
}
```

## Function that returns a value

```c
#include <stdio.h>

int square(int n);

int main() {
    int result = square(5);

    printf("Square: %d\n", result);
    return 0;
}

int square(int n) {
    return n * n;
}
```

Output:

```text
Square: 25
```

## Function with multiple parameters

```c
#include <stdio.h>

int multiply(int a, int b);

int main() {
    printf("%d\n", multiply(4, 5));
    return 0;
}

int multiply(int a, int b) {
    return a * b;
}
```

Output:

```text
20
```

## Function with float return type

```c
#include <stdio.h>

float average(float a, float b);

int main() {
    printf("%.2f\n", average(10.5, 20.5));
    return 0;
}

float average(float a, float b) {
    return (a + b) / 2;
}
```

Output:

```text
15.50
```

## Things to try

### 1. Create a subtraction function

```c
int subtract(int a, int b) {
    return a - b;
}
```

Call it:

```c
printf("%d\n", subtract(10, 4));
```

Expected output:

```text
6
```

### 2. Create a function to check even or odd

```c
#include <stdio.h>

void checkEvenOdd(int n);

int main() {
    checkEvenOdd(7);
    return 0;
}

void checkEvenOdd(int n) {
    if (n % 2 == 0) {
        printf("Even\n");
    } else {
        printf("Odd\n");
    }
}
```

Expected output:

```text
Odd
```

### 3. Create a function to find the maximum of two numbers

```c
#include <stdio.h>

int maximum(int a, int b);

int main() {
    printf("%d\n", maximum(10, 25));
    return 0;
}

int maximum(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
```

Expected output:

```text
25
```

### 4. Create a function to calculate area of a rectangle

```c
#include <stdio.h>

float rectangleArea(float length, float width);

int main() {
    printf("%.2f\n", rectangleArea(5.5, 3.2));
    return 0;
}

float rectangleArea(float length, float width) {
    return length * width;
}
```

Expected output:

```text
17.60
```

### 5. Create a function to print a table

```c
#include <stdio.h>

void printTable(int n);

int main() {
    printTable(5);
    return 0;
}

void printTable(int n) {
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}
```

Expected output:

```text
5 x 1 = 5
5 x 2 = 10
5 x 3 = 15
5 x 4 = 20
5 x 5 = 25
5 x 6 = 30
5 x 7 = 35
5 x 8 = 40
5 x 9 = 45
5 x 10 = 50
```

## Common mistakes

```c
int add(int a, int b);   // correct prototype

int add(int a, int b)    // missing semicolon in prototype
{
    return a + b;
}
```

```c
int add(int a, int b) {
    return a + b;
}
// missing return type in prototype is bad practice
```

```c
void greet() {
    return 10;   // wrong: void function cannot return a value
}
```

## Compile and run

```bash
gcc functions.c -o functions
./functions
```
