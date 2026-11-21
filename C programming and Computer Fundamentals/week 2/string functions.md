# Standard String Functions

## Include header

```c
#include <string.h>
```

## 1. strlen()

`strlen()` returns the length of a string. It does **not** count `'\0'`. [154][157]

```c
size_t strlen(const char *str);
```

### Example

```c
#include <stdio.h>
#include <string.h>

int main() {
    char name[] = "Hello";

    printf("Length: %zu\n", strlen(name));

    return 0;
}
```

### Output

```text
Length: 5
```

`"Hello"` has 5 letters, but 6 characters in memory because of `'\0'`.

## 2. strcpy()

`strcpy()` copies one string into another, including `'\0'`. [156][163]

```c
char *strcpy(char *destination, const char *source);
```

### Example

```c
#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hello";
    char destination;

    strcpy(destination, source);

    printf("Copied string: %s\n", destination);

    return 0;
}
```

### Output

```text
Copied string: Hello
```

### Important

The destination must be big enough:

```c
char destination;   // enough for "Hello" + '\0'
strcpy(destination, "Hello");
```

If destination is too small, it can cause memory problems.

## 3. strcmp()

`strcmp()` compares two strings. [159][163]

```c
int strcmp(const char *str1, const char *str2);
```

| Return value | Meaning |
|---:|---|
| `0` | Strings are equal |
| Negative value | First string is smaller |
| Positive value | First string is bigger |

### Example

```c
#include <stdio.h>
#include <string.h>

int main() {
    char a[] = "apple";
    char b[] = "apple";
    char c[] = "banana";

    printf("%d\n", strcmp(a, b));  // 0
    printf("%d\n", strcmp(a, c));  // negative
    printf("%d\n", strcmp(c, a));  // positive

    return 0;
}
```

### Check if two strings are equal

```c
if (strcmp(a, b) == 0) {
    printf("Strings are equal\n");
} else {
    printf("Strings are not equal\n");
}
```

Do **not** compare strings like this:

```c
if (a == b)  // wrong for string content
```

This compares addresses, not the text.

## 4. strncpy()

`strncpy()` copies only a limited number of characters. [155][156]

```c
char *strncpy(char *destination, const char *source, size_t n);
```

### Example

```c
#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hello World";
    char destination;

    strncpy(destination, source, 5);
    destination = '\0';  // add null terminator manually

    printf("Copied: %s\n", destination);

    return 0;
}
```

### Output

```text
Copied: Hello
```

### Important warning

`strncpy()` may not add `'\0'` if the source is longer than `n`.

So manually add it:

```c
destination[n] = '\0';
```

## Full example

```c
#include <stdio.h>
#include <string.h>

int main() {
    char name = "John";
    char copy;
    char word[] = "Hello";

    printf("Length: %zu\n", strlen(name));

    strcpy(copy, name);
    printf("Copy: %s\n", copy);

    if (strcmp(name, copy) == 0) {
        printf("Strings are equal\n");
    }

    strncpy(copy, word, 3);
    copy = '\0';

    printf("First 3 characters: %s\n", copy);

    return 0;
}
```

### Output

```text
Length: 4
Copy: John
Strings are equal
First 3 characters: Hel
```

## Function summary

| Function | Purpose | Example |
|---|---|---|
| `strlen()` | Find string length | `strlen(name)` |
| `strcpy()` | Copy full string | `strcpy(dest, src)` |
| `strcmp()` | Compare two strings | `strcmp(a, b)` |
| `strncpy()` | Copy limited characters | `strncpy(dest, src, 5)` |

## Things to try

### 1. Find length of user input

```c
#include <stdio.h>
#include <string.h>

int main() {
    char name;

    printf("Enter name: ");
    scanf("%19s", name);

    printf("Length: %zu\n", strlen(name));

    return 0;
}
```

### 2. Copy one string to another

```c
#include <stdio.h>
#include <string.h>

int main() {
    char original = "C Programming";
    char copy;

    strcpy(copy, original);

    printf("Original: %s\n", original);
    printf("Copy: %s\n", copy);

    return 0;
}
```

### 3. Compare passwords

```c
#include <stdio.h>
#include <string.h>

int main() {
    char password;
    char correct[] = "hello123";

    printf("Enter password: ");
    scanf("%19s", password);

    if (strcmp(password, correct) == 0) {
        printf("Correct password\n");
    } else {
        printf("Wrong password\n");
    }

    return 0;
}
```

### 4. Copy first 4 letters

```c
#include <stdio.h>
#include <string.h>

int main() {
    char word[] = "Programming";
    char first4;

    strncpy(first4, word, 4);
    first4 = '\0';

    printf("%s\n", first4);

    return 0;
}
```

Expected output:

```text
Prog
```

## Compile and run

```bash
gcc string_functions.c -o string_functions
./string_functions
```
