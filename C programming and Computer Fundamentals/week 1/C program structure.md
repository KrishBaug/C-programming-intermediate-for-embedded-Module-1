# C Program Structure

## Smallest C program

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

### What each line means

```c
#include <stdio.h>
```
- This brings in ready-made code for input/output.
- `stdio.h` gives you `printf()` and `scanf()`.

```c
int main() {
```
- `main()` is where your program starts.
- Every C program must have one `main()` function.

```c
printf("Hello, World!\n");
```
- Prints text on the screen.
- `\n` means “move to the next line”.

```c
return 0;
```
- Tells the operating system: “Program finished successfully.”
- `0` means success; other numbers usually mean an error.

```c
}
```
- Closes the `main()` function.

## Compile and run

```bash
gcc program.c -o program
./program
```

- `gcc program.c` — compile the C file
- `-o program` — save the output as `program`
- `./program` — run the program

## Basic program structure

```c
#include <stdio.h>       // 1. Header files

int main() {             // 2. Main function
    int age = 20;        // 3. Variables

    printf("Age: %d\n", age);  // 4. Output

    return 0;            // 5. End program
}
```

## Common parts

| Part | Purpose |
|---|---|
| `#include` | Adds useful ready-made functions |
| `main()` | Starting point of the program |
| Variables | Store data, like `int age = 20;` |
| `printf()` | Print output |
| `scanf()` | Take input from user |
| `return 0;` | End the program successfully |

## Example: Take input and print it

```c
#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("You entered: %d\n", age);

    return 0;
}
```

### Run it

```bash
gcc age.c -o age
./age
```

### Output

```text
Enter your age: 20
You entered: 20
```

## Important rule

- Every C statement ends with a semicolon: `;`
- Code inside a function goes inside `{ }`
- C is case-sensitive: `Age` and `age` are different
