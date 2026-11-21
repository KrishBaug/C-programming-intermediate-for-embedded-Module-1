# Pointer Arithmetic, Arrays & Function Parameters

## Pointer arithmetic

A pointer stores an address. You can add or subtract an integer from it.

```c
int *p;
p = p + 1;
```

For an `int *`, `p + 1` moves to the next `int`, not necessarily the next byte.

If `int` is 4 bytes:

```text
p       -> address 1000
p + 1   -> address 1004
p + 2   -> address 1008
```

Pointer arithmetic advances a pointer by the size of the type it points to. [177][181]

## Example

```c
#include <stdio.h>

int main() {
    int numbers = {10, 20, 30, 40, 50};
    int *p = numbers;

    printf("%d\n", *p);       // 10
    printf("%d\n", *(p + 1)); // 20
    printf("%d\n", *(p + 2)); // 30

    return 0;
}
```

## Pointer increment and decrement

```c
p++;  // move to next element
p--;  // move to previous element
```

Example:

```c
#include <stdio.h>

int main() {
    int numbers = {1, 2, 3};
    int *p = numbers;

    printf("%d\n", *p);  // 1

    p++;
    printf("%d\n", *p);  // 2

    p++;
    printf("%d\n", *p);  // 3

    return 0;
}
```

## Arrays and pointers

An array name usually acts like the address of its first element.

```c
int numbers = {10, 20, 30, 40, 50};
int *p = numbers;
```

Here:

```c
numbers == &numbers
```

So:

```c
*numbers       // same as numbers
*(numbers + 1) // same as numbers
*(numbers + 2) // same as numbers
```

`arr[i]` is equivalent to `*(arr + i)`. [170][184]

## Access array using pointer

```c
#include <stdio.h>

int main() {
    int numbers = {10, 20, 30, 40, 50};
    int *p = numbers;

    for (int i = 0; i < 5; i++) {
        printf("%d ", *(p + i));
    }

    return 0;
}
```

Output:

```text
10 20 30 40 50
```

## Array indexing is pointer arithmetic

```c
numbers
```

is the same as:

```c
*(numbers + 2)
```

## Difference between array and pointer

| Array | Pointer |
|---|---|
| Stores multiple values | Stores one address |
| `int arr[5]` creates 5 integer boxes | `int *p` stores one address |
| Array name acts like address of first element | Pointer can be changed to point elsewhere |
| Cannot do `arr++` | Can do `p++` |

## Pointers as function parameters

Normally, C passes a copy of a value to a function.

```c
void change(int n) {
    n = 100;
}
```

Original value does not change.

Using a pointer, the function receives the address and can change the original value.

```c
void change(int *n) {
    *n = 100;
}
```

## Example: change value using pointer

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

## Example: swap two numbers

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

Output:

```text
x = 10, y = 5
```

## Passing arrays to functions

When you pass an array to a function, C passes the address of its first element.

```c
void printArray(int arr[], int size);
```

is treated like:

```c
void printArray(int *arr, int size);
```

The function receives a pointer, so it can access and modify the original array elements. [180]

## Example: print array using pointer

```c
#include <stdio.h>

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {
    int numbers = {1, 2, 3, 4, 5};

    printArray(numbers, 5);

    return 0;
}
```

Output:

```text
1 2 3 4 5
```

## Example: modify array using function

```c
#include <stdio.h>

void doubleArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * 2;
    }
}

int main() {
    int numbers = {1, 2, 3, 4, 5};

    doubleArray(numbers, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
```

Output:

```text
2 4 6 8 10
```

## Things to try

### 1. Move pointer through array

```c
#include <stdio.h>

int main() {
    int arr = {10, 20, 30, 40};
    int *p = arr;

    for (int i = 0; i < 4; i++) {
        printf("%d ", *p);
        p++;
    }

    return 0;
}
```

Expected output:

```text
10 20 30 40
```

### 2. Find sum using pointer

```c
#include <stdio.h>

int main() {
    int arr = {1, 2, 3, 4, 5};
    int *p = arr;
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        sum += *(p + i);
    }

    printf("Sum: %d\n", sum);

    return 0;
}
```

Expected output:

```text
Sum: 15
```

### 3. Change array values using function

```c
#include <stdio.h>

void addOne(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i]++;
    }
}

int main() {
    int arr = {1, 2, 3};

    addOne(arr, 3);

    for (int i = 0; i < 3; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
```

Expected output:

```text
2 3 4
```

## Compile and run

```bash
gcc pointer_arrays.c -o pointer_arrays
./pointer_arrays
```
