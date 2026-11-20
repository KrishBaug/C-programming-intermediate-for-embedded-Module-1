# One-Dimensional Arrays

## What is an array?

An array stores many values of the same type using one name.

Instead of writing:

```c
int a = 10;
int b = 20;
int c = 30;
```

Use an array:

```c
int numbers = {10, 20, 30};
```

## Declare a 1D array

```c
data_type array_name[size];
```

Example:

```c
int marks;
```

This creates 5 integer boxes:

```text
marks  marks  marks  marks  marks
```

Array indexing starts from `0`, so the last index is `size - 1`. [137][141]

## Initialize an array

```c
int marks = {90, 85, 70, 60, 95};
```

| Index | Value |
|---:|---:|
| 0 | 90 |
| 1 | 85 |
| 2 | 70 |
| 3 | 60 |
| 4 | 95 |

## Access array elements

```c
printf("%d", marks);  // 90
printf("%d", marks);  // 70
```

## Change an array element

```c
marks = 100;
```

Now:

```text
marks = 100
```

## Print all elements using loop

```c
#include <stdio.h>

int main() {
    int marks = {90, 85, 70, 60, 95};

    for (int i = 0; i < 5; i++) {
        printf("marks[%d] = %d\n", i, marks[i]);
    }

    return 0;
}
```

### Output

```text
marks = 90
marks = 85
marks = 70
marks = 60
marks = 95
```

## Take input into an array

```c
#include <stdio.h>

int main() {
    int numbers;

    for (int i = 0; i < 5; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    printf("\nYou entered:\n");

    for (int i = 0; i < 5; i++) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}
```

## Find sum of array elements

```c
#include <stdio.h>

int main() {
    int numbers = {10, 20, 30, 40, 50};
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        sum = sum + numbers[i];
    }

    printf("Sum: %d\n", sum);

    return 0;
}
```

### Output

```text
Sum: 150
```

## Find largest element

```c
#include <stdio.h>

int main() {
    int numbers = {12, 45, 7, 89, 23};
    int largest = numbers;

    for (int i = 1; i < 5; i++) {
        if (numbers[i] > largest) {
            largest = numbers[i];
        }
    }

    printf("Largest: %d\n", largest);

    return 0;
}
```

### Output

```text
Largest: 89
```

## Array size

```c
int numbers;
```

- Total elements: 5
- First index: `0`
- Last index: `4`

## Common mistake

```c
int numbers;

numbers = 10;  // WRONG
```

Valid indexes are `0` to `4`, not `5`.

# Multidimensional Arrays

A **multidimensional array** is an array of arrays. The most common type is a 2D array, which looks like a table with rows and columns. [132][138]

## Declare a 2D array

```c
data_type array_name[rows][columns];
```

Example:

```c
int matrix;
```

This creates:

```text
2 rows and 3 columns
```

## Initialize a 2D array

```c
int matrix = {
    {1, 2, 3},
    {4, 5, 6}
};
```

|  | Column 0 | Column 1 | Column 2 |
|---|---:|---:|---:|
| Row 0 | 1 | 2 | 3 |
| Row 1 | 4 | 5 | 6 |

## Access a 2D array element

```c
matrix  // 1
matrix  // 3
matrix  // 5
```

Syntax:

```c
array_name[row][column]
```

Both row and column indexes start from `0`. [131][133]

## Change a 2D array element

```c
matrix = 100;
```

Now:

```text
matrix = 100
```

## Print a 2D array

```c
#include <stdio.h>

int main() {
    int matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }

    return 0;
}
```

### Output

```text
1 2 3
4 5 6
```

## Take input into a 2D array

```c
#include <stdio.h>

int main() {
    int matrix;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nMatrix:\n");

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }

    return 0;
}
```

## Add two matrices

```c
#include <stdio.h>

int main() {
    int a = {
        {1, 2},
        {3, 4}
    };

    int b = {
        {5, 6},
        {7, 8}
    };

    int sum;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("Sum matrix:\n");

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", sum[i][j]);
        }

        printf("\n");
    }

    return 0;
}
```

### Output

```text
Sum matrix:
6 8
10 12
```

## 3D array

A 3D array has three indexes.

```c
int cube;
```

Example:

```c
int cube = {
    {
        {1, 2},
        {3, 4}
    },
    {
        {5, 6},
        {7, 8}
    }
};
```

Access:

```c
cube  // 4
cube  // 6
```

## Things to try

### 1. Store 5 student marks

```c
int marks = {80, 75, 90, 65, 85};
```

Print all marks using a loop.

### 2. Find average of array elements

```c
#include <stdio.h>

int main() {
    int marks = {80, 75, 90, 65, 85};
    int sum = 0;
    float average;

    for (int i = 0; i < 5; i++) {
        sum += marks[i];
    }

    average = sum / 5.0;

    printf("Average: %.2f\n", average);

    return 0;
}
```

Expected output:

```text
Average: 79.00
```

### 3. Print a 3x3 matrix

```c
int matrix = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
```

Use two nested loops to print it.

### 4. Find sum of all 2D array elements

```c
#include <stdio.h>

int main() {
    int matrix = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int sum = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
    }

    printf("Sum: %d\n", sum);

    return 0;
}
```

Expected output:

```text
Sum: 21
```

## Compile and run

```bash
gcc arrays.c -o arrays
./arrays
```
