# Header Files and Source Files

## Why use separate files?

If all code is in one file, it becomes messy for bigger projects.

So we split code:

- `.h` file → tells other files what functions exist
- `.c` file → contains the actual function code
- `main.c` → uses those functions

## Example project

```text
my_project/
├── main.c
├── calculator.c
└── calculator.h
```

## 1. Header file: calculator.h

```c
#ifndef CALCULATOR_H
#define CALCULATOR_H

int add(int a, int b);
int subtract(int a, int b);

#endif
```

### Meaning

- `calculator.h` says: “There is a function called `add()` and `subtract()`.”
- It does **not** contain the full code.
- It only tells other files these functions exist.

### Why `#ifndef`, `#define`, `#endif`?

They prevent the same header file from being included twice.

```c
#ifndef CALCULATOR_H
#define CALCULATOR_H

// your declarations

#endif
```

This is called an **include guard**.

## 2. Source file: calculator.c

```c
#include "calculator.h"

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}
```

### Meaning

- This file contains the real working code.
- `add()` actually adds two numbers.
- `subtract()` actually subtracts two numbers.

## 3. Main file: main.c

```c
#include <stdio.h>
#include "calculator.h"

int main() {
    int result = add(5, 3);

    printf("Result: %d\n", result);

    return 0;
}
```

### Meaning

- `main.c` includes `calculator.h`
- Now `main.c` can use `add()` and `subtract()`
- The actual code is in `calculator.c`

## Compile all files together

```bash
gcc main.c calculator.c -o calculator
./calculator
```

### Output

```text
Result: 8
```

## Include types

```c
#include <stdio.h>
```
- Used for system/library headers.
- Example: `stdio.h`, `stdlib.h`, `string.h`

```c
#include "calculator.h"
```
- Used for your own header files.
- Example: files you created in your project.

## Simple rule

| File type | Contains | Example |
|---|---|---|
| `.h` | Function names / declarations | `calculator.h` |
| `.c` | Actual function code | `calculator.c` |
| `main.c` | Program starting point | `main()` |

## Full flow

```text
main.c
  ↓ includes
calculator.h
  ↓ tells compiler
calculator.c
  ↓ contains actual code
Final program
```

## When to use this?

Use separate `.h` and `.c` files when:

- Your project has many functions
- Multiple files need the same functions
- You want cleaner and organized code
