# Variables and Data Types

## What is a variable?

A variable stores a value that can change while the program runs.

```c
int age = 20;
```

Here:

- `int` → data type
- `age` → variable name
- `=` → assignment operator
- `20` → value stored in the variable

## Basic syntax

```c
data_type variable_name = value;
```

Examples:

```c
int marks = 90;
float price = 99.5;
char grade = 'A';
```

## Common data types

| Data type | Used for | Example |
|---|---|---|
| `char` | One character | `'A'` |
| `int` | Whole numbers | `25`, `-10` |
| `float` | Decimal numbers | `3.14` |
| `double` | Larger/more precise decimal numbers | `3.141592653589` |

## char

`char` stores one character.

```c
char grade = 'A';
char symbol = '#';
```

Important:

- Use single quotes: `'A'`
- Do **not** use double quotes for one character: `"A"` is a string, not a char

Example:

```c
#include <stdio.h>

int main() {
    char grade = 'A';

    printf("Grade: %c\n", grade);

    return 0;
}
```

Output:

```text
Grade: A
```

## int

`int` stores whole numbers.

```c
int age = 20;
int temperature = -5;
int students = 45;
```

Example:

```c
#include <stdio.h>

int main() {
    int age = 20;

    printf("Age: %d\n", age);

    return 0;
}
```

Output:

```text
Age: 20
```

## float

`float` stores decimal numbers.

```c
float price = 99.50;
float pi = 3.14;
```

Use `%f` to print a float.

```c
#include <stdio.h>

int main() {
    float price = 99.50;

    printf("Price: %f\n", price);

    return 0;
}
```

Output:

```text
Price: 99.500000
```

To control decimal places:

```c
printf("Price: %.2f\n", price);
```

Output:

```text
Price: 99.50
```

## double

`double` also stores decimal numbers, but with more precision than `float`.

```c
double pi = 3.141592653589793;
double salary = 55000.75;
```

Use `%lf` in `scanf()` and `%f` in `printf()`.

```c
#include <stdio.h>

int main() {
    double pi = 3.141592653589793;

    printf("Pi: %.10f\n", pi);

    return 0;
}
```

Output:

```text
Pi: 3.1415926536
```

## float vs double

| Type | Size | Precision | Use |
|---|---:|---:|---|
| `float` | Usually 4 bytes | Less precise | Normal decimal values |
| `double` | Usually 8 bytes | More precise | Scientific calculations, precise values |

## Format specifiers

| Data type | printf format |
|---|---|
| `char` | `%c` |
| `int` | `%d` |
| `float` | `%f` |
| `double` | `%f` in printf, `%lf` in scanf |

Example:

```c
printf("%c %d %f\n", grade, age, price);
```

# Signed and Unsigned Types

## Signed types

A signed type can store **positive, negative, and zero** values.

```c
int temperature = -10;
```

By default, `int`, `char`, `float`, and `double` are treated as signed where applicable.

## Unsigned types

An unsigned type can store only **zero and positive** values. It cannot store negative numbers.

```c
unsigned int age = 20;
```

## signed vs unsigned

| Type | Can store negative values? | Example |
|---|---|---|
| `signed int` | Yes | `-10`, `0`, `25` |
| `unsigned int` | No | `0`, `25` |

## Examples

```c
#include <stdio.h>

int main() {
    int a = -10;
    unsigned int b = 10;

    printf("Signed: %d\n", a);
    printf("Unsigned: %u\n", b);

    return 0;
}
```

Output:

```text
Signed: -10
Unsigned: 10
```

## Important warning

Never store a negative value in an unsigned variable:

```c
unsigned int x = -5;  // wrong idea
```

It will not behave like a normal negative number.

## Common integer types

```c
signed int a = -10;
unsigned int b = 10;

signed char c = -100;
unsigned char d = 200;
```

## When to use unsigned?

Use `unsigned` when a value can never be negative, such as:

- Age
- Number of students
- File size
- Array size

# sizeof Operator

`sizeof` tells you how many **bytes** a data type or variable takes in memory.

```c
sizeof(int)
sizeof(float)
sizeof(variable_name)
```

`sizeof` returns the storage size in bytes; its result type is `size_t`. [51]

## Example

```c
#include <stdio.h>

int main() {
    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));

    return 0;
}
```

Typical output on many systems:

```text
Size of char: 1 bytes
Size of int: 4 bytes
Size of float: 4 bytes
Size of double: 8 bytes
```

## sizeof with variables

```c
#include <stdio.h>

int main() {
    int age = 20;
    float price = 99.5;

    printf("Size of age: %zu bytes\n", sizeof(age));
    printf("Size of price: %zu bytes\n", sizeof(price));

    return 0;
}
```

## Important

- `sizeof(char)` is always `1` byte.
- `sizeof(int)` is commonly `4` bytes, but exact sizes can depend on the system and compiler.
- `sizeof` is useful to check memory usage.

## Full practical example

```c
#include <stdio.h>

int main() {
    char grade = 'A';
    int age = 20;
    float marks = 88.5;
    double pi = 3.141592653589;
    unsigned int students = 50;

    printf("Grade: %c\n", grade);
    printf("Age: %d\n", age);
    printf("Marks: %.2f\n", marks);
    printf("Pi: %.12f\n", pi);
    printf("Students: %u\n", students);

    printf("\nSizes:\n");
    printf("char: %zu byte\n", sizeof(grade));
    printf("int: %zu bytes\n", sizeof(age));
    printf("float: %zu bytes\n", sizeof(marks));
    printf("double: %zu bytes\n", sizeof(pi));
    printf("unsigned int: %zu bytes\n", sizeof(students));

    return 0;
}
```

## Compile and run

```bash
gcc variables.c -o variables
./variables
```
