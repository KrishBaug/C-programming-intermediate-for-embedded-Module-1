# Pointer Fundamentals

## What is a pointer?

A pointer stores the address of another variable.

```c
int x = 10;
int *p = &x;
```

Here:

- `x` is an integer variable
- `p` is a pointer
- `p` stores the address of `x`

## Declare a pointer

```c
data_type *pointer_name;
```

Examples:

```c
int *p;
float *f;
char *c;
```

## Address-of operator: &

`&` gives the memory address of a variable.

```c
int x = 10;
int *p = &x;
```

- `&x` means “address of x”
- `p` now points to `x`

The `&` operator is called the address-of operator; `&x` gives the address where `x` is stored. [167][166]

## Dereference operator: *

`*` gives the value stored at the address pointed to by a pointer.

```c
printf("%d", *p);
```

This prints:

```text
10
```

The `*` operator is called the dereference operator; it follows the pointer and accesses the value it points to. [165][169]

## Full example

```c
#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x;

    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", &x);
    printf("Value stored in p: %p\n", p);
    printf("Value pointed by p: %d\n", *p);

    return 0;
}
```

### Sample output

```text
Value of x: 10
Address of x: 0x7ffee4b2c8ac
Value stored in p: 0x7ffee4b2c8ac
Value pointed by p: 10
```

Addresses can be different on every run.

## Change original value using pointer

```c
#include <stdio.h>

int main() {
    int x = 10;
    int *p = &x;

    *p = 50;  // changes x

    printf("x = %d\n", x);

    return 0;
}
```

Output:

```text
x = 50
```

`*p = 50;` means: “Go to the address stored in `p` and put `50` there.”

## Pointer and pass by value

Normally, a function receives a copy of a value:

```c
void change(int n) {
    n = 100;
}
```

The original value does not change.

Using a pointer, the function can change the original value:

```c
#include <stdio.h>

void change(int *n) {
    *n = 100;
}

int main() {
    int x = 10;

    change(&x);

    printf("x = %d\n", x);

    return 0;
}
```

Output:

```text
x = 100
```

## Important symbols

| Symbol | Name | Meaning | Example |
|---|---|---|---|
| `&` | Address-of | Gives address of a variable | `&x` |
| `*` | Dereference | Gives value at an address | `*p` |
| `*` in declaration | Pointer declaration | Creates a pointer | `int *p;` |

## Pointer declaration vs dereference

```c
int *p;       // declaration: p is a pointer
*p = 10;      // dereference: change value at address
```

## NULL pointer

A pointer that does not point to any valid variable is called a `NULL` pointer.

```c
int *p = NULL;
```

Do not dereference a NULL pointer:

```c
int *p = NULL;
printf("%d", *p);  // wrong / unsafe
```

## Things to try

### 1. Print address and value

```c
#include <stdio.h>

int main() {
    int a = 25;
    int *p = &a;

    printf("Value: %d\n", a);
    printf("Address: %p\n", &a);
    printf("Pointer value: %p\n", p);
    printf("Dereferenced value: %d\n", *p);

    return 0;
}
```

### 2. Change value using pointer

```c
#include <stdio.h>

int main() {
    int num = 5;
    int *ptr = &num;

    *ptr = 99;

    printf("num = %d\n", num);

    return 0;
}
```

Expected output:

```text
num = 99
```

### 3. Swap two numbers using pointers

```c
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;

    swap(&x, &y);

    printf("x = %d, y = %d\n", x, y);

    return 0;
}
```

Expected output:

```text
x = 10, y = 5
```

## Compile and run

```bash
gcc pointers.c -o pointers
./pointers
```
