# Pass by Value in C

## What is pass by value?

Pass by value means the function gets a **copy** of the value.

```c
int x = 10;
change(x);
```

Here, the value `10` is copied into the function parameter.

If the function changes its copy, the original `x` remains unchanged.

## Example

```c
#include <stdio.h>

void change(int n);

int main() {
    int x = 10;

    change(x);

    printf("After function call: %d\n", x);

    return 0;
}

void change(int n) {
    n = n + 100;

    printf("Inside function: %d\n", n);
}
```

### Output

```text
Inside function: 110
After function call: 10
```

### Why?

- `x` has value `10`
- `change(x)` copies `10` into `n`
- `n` becomes `110`
- But `x` is still `10`

## Function parameters are copies

```c
void change(int n) {
    n = n + 100;
}
```

Here, `n` is a local copy of the passed value.

Changing `n` affects only the function, not the original variable.

In C, function arguments are passed by value: the function receives copies of the converted argument values, and assigning to a parameter does not directly affect the caller’s variable. [98]

## Another example

```c
#include <stdio.h>

void addTen(int number);

int main() {
    int num = 5;

    addTen(num);

    printf("num after function: %d\n", num);

    return 0;
}

void addTen(int number) {
    number = number + 10;

    printf("number inside function: %d\n", number);
}
```

### Output

```text
number inside function: 15
num after function: 5
```

## Pass by value with two variables

```c
#include <stdio.h>

void swap(int a, int b);

int main() {
    int x = 5;
    int y = 10;

    swap(x, y);

    printf("x = %d, y = %d\n", x, y);

    return 0;
}

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;

    printf("Inside function: a = %d, b = %d\n", a, b);
}
```

### Output

```text
Inside function: a = 10, b = 5
x = 5, y = 10
```

The values are swapped only inside the function because `a` and `b` are copies.

## Important point

Pass by value does **not** change the original variable.

To actually change the original variable, C uses **pointers**.

```c
void change(int *n) {
    *n = *n + 100;
}
```

This is called **pass by reference using pointers**.

## Things to try

### 1. Double a number

```c
#include <stdio.h>

void doubleValue(int n);

int main() {
    int num = 7;

    doubleValue(num);

    printf("Original number: %d\n", num);

    return 0;
}

void doubleValue(int n) {
    n = n * 2;
    printf("Inside function: %d\n", n);
}
```

Expected output:

```text
Inside function: 14
Original number: 7
```

### 2. Try to reset a number

```c
#include <stdio.h>

void reset(int n);

int main() {
    int score = 100;

    reset(score);

    printf("Score after reset: %d\n", score);

    return 0;
}

void reset(int n) {
    n = 0;
}
```

Expected output:

```text
Score after reset: 100
```

### 3. Swap two numbers using pass by value

```c
#include <stdio.h>

void swap(int a, int b);

int main() {
    int a = 3, b = 8;

    swap(a, b);

    printf("a = %d, b = %d\n", a, b);

    return 0;
}

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
```

Expected output:

```text
a = 3, b = 8
```

The original values do not change.

## Compile and run

```bash
gcc pass_by_value.c -o pass_by_value
./pass_by_value
```
