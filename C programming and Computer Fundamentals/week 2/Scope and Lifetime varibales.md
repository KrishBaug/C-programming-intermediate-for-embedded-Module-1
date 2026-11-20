# Scope and Lifetime of Variables

## What is scope?

Scope means the part of the program where a variable can be accessed.

Example:

```c
int main() {
    int age = 20;  // scope: inside main()

    printf("%d", age);  // allowed
}
```

`age` can be used only inside `main()`.

## What is lifetime?

Lifetime means how long a variable exists in memory.

Example:

```c
int main() {
    int age = 20;  // created here

    // age exists while main() is running

    return 0;
}  // age is destroyed here
```

## Local variables

A local variable is declared inside a function or block `{ }`.

```c
#include <stdio.h>

int main() {
    int x = 10;  // local variable

    printf("%d\n", x);

    return 0;
}
```

### Scope

- `x` can be used only inside `main()`

### Lifetime

- `x` is created when `main()` starts
- `x` is destroyed when `main()` ends

Variables declared inside a function or block are visible only until the end of that function or block. [110][114]

## Local variable inside a block

```c
#include <stdio.h>

int main() {
    {
        int a = 5;
        printf("%d\n", a);
    }

    // printf("%d", a);  // ERROR: a is not available here

    return 0;
}
```

`a` exists only inside the `{ }` block.

## Global variables

A global variable is declared **outside all functions**, usually at the top of the file.

```c
#include <stdio.h>

int count = 0;  // global variable

int main() {
    count = 10;

    printf("%d\n", count);

    return 0;
}
```

### Scope

- `count` can be used anywhere in the file after it is declared.

### Lifetime

- `count` exists from program start to program end.

Variables declared at the top level of a file have file scope and retain their values for the entire execution of the program. [114][119]

## Global variable used in functions

```c
#include <stdio.h>

int total = 0;  // global variable

void add(int n) {
    total = total + n;
}

int main() {
    add(5);
    add(10);

    printf("Total: %d\n", total);

    return 0;
}
```

### Output

```text
Total: 15
```

The global variable `total` keeps its value between function calls.

## Local vs global variables

| Feature | Local variable | Global variable |
|---|---|---|
| Declared | Inside a function or block | Outside all functions |
| Scope | Only inside its function/block | Entire file after declaration |
| Lifetime | Until function/block ends | Entire program |
| Default value | Garbage value | Usually `0` |
| Memory | Created and destroyed repeatedly | Exists throughout program |

## Same name: local hides global

```c
#include <stdio.h>

int x = 100;  // global

int main() {
    int x = 5;  // local

    printf("%d\n", x);  // prints 5

    return 0;
}
```

Output:

```text
5
```

The local `x` hides the global `x` inside `main()`.

## Access global variable when local has same name

Use `::`? No — C does not use `::` like C++.

In C, avoid using the same name for local and global variables.

## Example: local variable does not persist

```c
#include <stdio.h>

void increase() {
    int count = 0;

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
Count: 1
Count: 1
```

Every time `increase()` runs, `count` starts again from `0`.

## Example: global variable persists

```c
#include <stdio.h>

int count = 0;  // global

void increase() {
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

## Things to try

### 1. Local variable scope

```c
#include <stdio.h>

int main() {
    int a = 10;

    {
        int b = 20;
        printf("%d\n", a + b);
    }

    // printf("%d", b);  // error

    return 0;
}
```

### 2. Global counter

```c
#include <stdio.h>

int counter = 0;

void increase() {
    counter++;
}

int main() {
    increase();
    increase();
    increase();

    printf("%d\n", counter);

    return 0;
}
```

Expected output:

```text
3
```

### 3. Local variable in loop

```c
#include <stdio.h>

int main() {
    for (int i = 1; i <= 3; i++) {
        int square = i * i;

        printf("%d\n", square);
    }

    // printf("%d", square);  // error

    return 0;
}
```

## Compile and run

```bash
gcc scope.c -o scope
./scope
```
