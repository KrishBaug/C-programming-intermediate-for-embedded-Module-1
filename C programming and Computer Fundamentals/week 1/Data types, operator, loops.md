
# Integer Ranges and Integer Overflow

## What is integer range?

Every integer type can store only a limited range of values.

If you try to store a value bigger or smaller than that limit, it is called **integer overflow**.

## Common ranges on a typical 32-bit int system

| Type | Usual size | Range |
|---|---:|---|
| `signed char` | 1 byte | -128 to 127 |
| `unsigned char` | 1 byte | 0 to 255 |
| `short` | 2 bytes | -32,768 to 32,767 |
| `unsigned short` | 2 bytes | 0 to 65,535 |
| `int` | 4 bytes | -2,147,483,648 to 2,147,483,647 |
| `unsigned int` | 4 bytes | 0 to 4,294,967,295 |
| `long long` | 8 bytes | About -9.22 quintillion to 9.22 quintillion |
| `unsigned long long` | 8 bytes | 0 to about 18.44 quintillion |

## Signed integer overflow

A signed integer can store negative and positive values.

```c
int x = 2147483647;  // maximum int value
x = x + 1;           // overflow
```

For signed integers, overflow is **undefined behavior** in C. The program may give a wrong result, crash, or behave unpredictably. [67][68]

## Unsigned integer overflow

Unsigned integers wrap around.

```c
unsigned int x = 4294967295;  // maximum unsigned int
x = x + 1;                    // becomes 0
```

For unsigned types, overflow wraps around: `UINT_MAX + 1` becomes `0`. [68]

## Example

```c
#include <stdio.h>
#include <limits.h>

int main() {
    int max_int = INT_MAX;
    unsigned int max_unsigned = UINT_MAX;

    printf("Max int: %d\n", max_int);
    printf("Max unsigned int: %u\n", max_unsigned);

    max_int = max_int + 1;
    max_unsigned = max_unsigned + 1;

    printf("After int overflow: %d\n", max_int);
    printf("After unsigned overflow: %u\n", max_unsigned);

    return 0;
}
```

## How to avoid overflow

- Use a bigger type such as `long long`
- Check values before calculation
- Avoid unnecessary large multiplications
- Use `unsigned` only when negative values are impossible

# Type Conversion and Type Casting

## What is type conversion?

Type conversion means changing one data type into another.

Example:

```c
int a = 10;
float b = a;  // int is converted to float
```

## Automatic conversion

C automatically converts smaller/simple types when needed.

```c
int a = 10;
float b = 3.5;
float result = a + b;  // a becomes 10.0 temporarily
```

Here, `a` is automatically converted to `float`.

## Manual conversion: type casting

Type casting means manually converting one type to another.

```c
(data_type) value
```

Example:

```c
int a = 10;
int b = 3;

float result = (float) a / b;
```

Without casting:

```c
float result = a / b;  // result = 3.000000
```

With casting:

```c
float result = (float) a / b;  // result = 3.333333
```

## Full example

```c
#include <stdio.h>

int main() {
    int a = 10;
    int b = 3;

    float wrong = a / b;
    float correct = (float) a / b;

    printf("Without casting: %.2f\n", wrong);
    printf("With casting: %.2f\n", correct);

    return 0;
}
```

Output:

```text
Without casting: 3.00
With casting: 3.33
```

## Casting float to int

```c
float price = 99.75;
int whole = (int) price;
```

Result:

```text
whole = 99
```

It removes the decimal part; it does **not** round the value.

## char to int

```c
char letter = 'A';
int value = letter;
```

`'A'` has ASCII value `65`, so:

```text
value = 65
```

# Operators and Operator Precedence

## What is an operator?

An operator performs an action on values.

Example:

```c
int sum = 10 + 5;
```

Here, `+` is an operator.

## Arithmetic operators

| Operator | Meaning | Example |
|---|---|---|
| `+` | Addition | `10 + 5` |
| `-` | Subtraction | `10 - 5` |
| `*` | Multiplication | `10 * 5` |
| `/` | Division | `10 / 5` |
| `%` | Remainder | `10 % 3` |

Example:

```c
#include <stdio.h>

int main() {
    int a = 10, b = 3;

    printf("Sum: %d\n", a + b);
    printf("Difference: %d\n", a - b);
    printf("Product: %d\n", a * b);
    printf("Quotient: %d\n", a / b);
    printf("Remainder: %d\n", a % b);

    return 0;
}
```

## Relational operators

Used to compare two values.

| Operator | Meaning |
|---|---|
| `==` | Equal to |
| `!=` | Not equal to |
| `>` | Greater than |
| `<` | Less than |
| `>=` | Greater than or equal to |
| `<=` | Less than or equal to |

Example:

```c
if (age >= 18) {
    printf("Adult\n");
}
```

## Logical operators

| Operator | Meaning |
|---|---|
| `&&` | AND — both conditions must be true |
| `||` | OR — at least one condition must be true |
| `!` | NOT — reverses true/false |

Example:

```c
if (age >= 18 && age <= 60) {
    printf("Eligible\n");
}
```

## Assignment operators

| Operator | Example | Meaning |
|---|---|---|
| `=` | `a = 5` | Assign 5 to a |
| `+=` | `a += 5` | Same as `a = a + 5` |
| `-=` | `a -= 5` | Same as `a = a - 5` |
| `*=` | `a *= 5` | Same as `a = a * 5` |
| `/=` | `a /= 5` | Same as `a = a / 5` |
| `%=` | `a %= 5` | Same as `a = a % 5` |

## Increment and decrement

```c
a++;  // increases a by 1
a--;  // decreases a by 1
```

Example:

```c
int a = 5;
a++;
printf("%d", a);  // 6
```

## Operator precedence

Precedence decides which operation happens first.

Example:

```c
int result = 10 + 5 * 2;
```

Multiplication happens first:

```text
10 + (5 * 2)
10 + 10
= 20
```

## Priority order

| Priority | Operators |
|---:|---|
| 1 | `()` |
| 2 | `!`, `++`, `--` |
| 3 | `*`, `/`, `%` |
| 4 | `+`, `-` |
| 5 | `<`, `>`, `<=`, `>=` |
| 6 | `==`, `!=` |
| 7 | `&&` |
| 8 | `||` |
| 9 | `=` |

## Use brackets for clarity

```c
int result = (10 + 5) * 2;  // 30
```

Without brackets:

```c
int result = 10 + 5 * 2;    // 20
```

# Conditional Statements

## if statement

Runs code only when a condition is true.

```c
if (condition) {
    // code
}
```

Example:

```c
#include <stdio.h>

int main() {
    int age = 20;

    if (age >= 18) {
        printf("You are an adult\n");
    }

    return 0;
}
```

## if-else statement

Runs one block if the condition is true, another block if false.

```c
if (condition) {
    // true block
} else {
    // false block
}
```

Example:

```c
#include <stdio.h>

int main() {
    int age = 15;

    if (age >= 18) {
        printf("You are an adult\n");
    } else {
        printf("You are a minor\n");
    }

    return 0;
}
```

## if-else if-else

Used when there are multiple conditions.

```c
if (marks >= 90) {
    printf("Grade A\n");
} else if (marks >= 75) {
    printf("Grade B\n");
} else if (marks >= 50) {
    printf("Grade C\n");
} else {
    printf("Fail\n");
}
```

## switch statement

Used when comparing one variable with many fixed values.

```c
switch (day) {
    case 1:
        printf("Monday\n");
        break;

    case 2:
        printf("Tuesday\n");
        break;

    default:
        printf("Invalid day\n");
}
```

`switch` is useful for checking a value against several constant integer or character cases. [63]

## Full switch example

```c
#include <stdio.h>

int main() {
    int day = 2;

    switch (day) {
        case 1:
            printf("Monday\n");
            break;

        case 2:
            printf("Tuesday\n");
            break;

        case 3:
            printf("Wednesday\n");
            break;

        default:
            printf("Invalid day\n");
    }

    return 0;
}
```

## break importance

Without `break`, the program continues to the next case.

```c
case 1:
    printf("Monday\n");

case 2:
    printf("Tuesday\n");
    break;
```

If `day = 1`, both `Monday` and `Tuesday` may print.

# Loops

Loops repeat code multiple times.

## for loop

Use when you know how many times to repeat.

```c
for (initialization; condition; update) {
    // code
}
```

Example:

```c
#include <stdio.h>

int main() {
    for (int i = 1; i <= 5; i++) {
        printf("%d\n", i);
    }

    return 0;
}
```

Output:

```text
1
2
3
4
5
```

## while loop

Use when you do not know exactly how many times to repeat.

```c
while (condition) {
    // code
}
```

Example:

```c
#include <stdio.h>

int main() {
    int i = 1;

    while (i <= 5) {
        printf("%d\n", i);
        i++;
    }

    return 0;
}
```

A `while` loop checks the condition first, then runs the body only if the condition is true. [64][70]

## do-while loop

Runs the code at least once, then checks the condition.

```c
do {
    // code
} while (condition);
```

Example:

```c
#include <stdio.h>

int main() {
    int i = 1;

    do {
        printf("%d\n", i);
        i++;
    } while (i <= 5);

    return 0;
}
```

A `do-while` loop executes its body first and checks the condition afterward, so it always runs at least once. [69][71]

## break and continue

```c
break;      // stops the loop
continue;   // skips current iteration
```

Example:

```c
for (int i = 1; i <= 5; i++) {
    if (i == 3) {
        continue;  // skip 3
    }

    printf("%d\n", i);
}
```

Output:

```text
1
2
4
5
```

## Loop comparison

| Loop | Best used when |
|---|---|
| `for` | Number of repetitions is known |
| `while` | Repetition depends on a condition |
| `do-while` | Code must run at least once |
