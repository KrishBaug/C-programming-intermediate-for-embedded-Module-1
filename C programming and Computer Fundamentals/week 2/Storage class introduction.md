# Storage Classes in C

## What is a storage class?

A storage class controls:

- Where a variable can be used (scope)
- How long it stays in memory (lifetime)
- Whether its value is saved between function calls
- Where the variable is linked in the program

## Main storage classes

```c
auto
static
extern
register
```

## 1. auto

`auto` is used for normal local variables.

```c
auto int x = 10;
```

Usually, you do not need to write `auto` because local variables are automatic by default.

```c
int x = 10;  // same as auto int x = 10;
```

### Example

```c
#include <stdio.h>

void test() {
    auto int count = 0;

    count++;

    printf("Count: %d\n", count);
}

int main() {
    test();
    test();
    test();

    return 0;
}
```

### Output

```text
Count: 1
Count: 1
Count: 1
```

Every time `test()` runs, `count` starts again from `0`.

`auto` variables are created when their block starts and destroyed when the block ends. [120][124]

## 2. static

`static` keeps the value of a variable even after the function ends.

```c
static int count = 0;
```

### Example

```c
#include <stdio.h>

void increase() {
    static int count = 0;

    count++;

    printf("Count: %d\n", count);
}

int main() {
    increase();
    increase();
    increase();

    return 0;
}
```

### Output

```text
Count: 1
Count: 2
Count: 3
```

The value of `count` is remembered between function calls.

A `static` local variable is initialized only once and keeps its value across function calls. [122][124]

## static global variable

```c
static int count = 0;
```

A `static` global variable can be used only within the same file.

```c
static int total = 0;

void add() {
    total++;
}
```

## 3. extern

`extern` means a variable is defined somewhere else, often in another file.

```c
extern int total;
```

It tells the compiler: “This variable already exists; do not create a new one.”

### Example: two files

```c
// file1.c
int total = 100;
```

```c
// file2.c
#include <stdio.h>

extern int total;

int main() {
    printf("Total: %d\n", total);
    return 0;
}
```

Compile:

```bash
gcc file1.c file2.c -o program
./program
```

Output:

```text
Total: 100
```

`extern` is mainly used to share a global variable between multiple `.c` files. [124][129]

## 4. register

`register` suggests that a variable should be stored in a CPU register for faster access.

```c
register int i;
```

Example:

```c
#include <stdio.h>

int main() {
    register int i;

    for (i = 1; i <= 5; i++) {
        printf("%d\n", i);
    }

    return 0;
}
```

Important:

- `register` is only a request
- The compiler may ignore it
- You cannot take the address of a register variable using `&`

`register` variables have local lifetime, but the compiler decides whether to actually place them in a CPU register. [120][128]

## Storage class comparison

| Storage class | Scope | Lifetime | Value kept between calls? | Use |
|---|---|---|---|---|
| `auto` | Block/function | Until block ends | No | Normal local variables |
| `static` | Block or file | Entire program | Yes | Remember values |
| `extern` | Multiple files | Entire program | Yes | Share global variables |
| `register` | Block/function | Until block ends | No | Fast-access variables |

## Default storage class

```c
int x = 10;
```

- Inside a function → `auto`
- Outside all functions → `extern`

## Full example

```c
#include <stdio.h>

int global_count = 0;       // global variable

void increase() {
    static int static_count = 0;  // keeps value
    auto int local_count = 0;     // resets every call

    global_count++;
    static_count++;
    local_count++;

    printf("Global: %d, Static: %d, Local: %d\n",
           global_count, static_count, local_count);
}

int main() {
    increase();
    increase();
    increase();

    return 0;
}
```

### Output

```text
Global: 1, Static: 1, Local: 1
Global: 2, Static: 2, Local: 1
Global: 3, Static: 3, Local: 1
```

## Things to try

### 1. Use static to count function calls

```c
#include <stdio.h>

void call() {
    static int calls = 0;

    calls++;

    printf("Function called %d times\n", calls);
}

int main() {
    call();
    call();
    call();

    return 0;
}
```

Expected output:

```text
Function called 1 times
Function called 2 times
Function called 3 times
```

### 2. Compare auto and static

```c
#include <stdio.h>

void test() {
    auto int a = 0;
    static int b = 0;

    a++;
    b++;

    printf("auto: %d, static: %d\n", a, b);
}

int main() {
    test();
    test();
    test();

    return 0;
}
```

Expected output:

```text
auto: 1, static: 1
auto: 1, static: 2
auto: 1, static: 3
```

### 3. Use register in a loop

```c
#include <stdio.h>

int main() {
    register int i;

    for (i = 1; i <= 5; i++) {
        printf("%d ", i);
    }

    return 0;
}
```

Expected output:

```text
1 2 3 4 5
```

## Compile and run

```bash
gcc storage_classes.c -o storage_classes
./storage_classes
```
