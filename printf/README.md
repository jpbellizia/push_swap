*This project has been created as part of the 42 curriculum by jpaulo-p.*

# ft_printf

## Description

**Welcome to ft_printf!**

The goal of this project is to recreate the behavior of the standard C `printf()` function by implementing a custom version called `ft_printf()`.

Unlike the original implementation from the C standard library, this project focuses on supporting the mandatory conversions while introducing one of the most important concepts in C programming: **variadic functions**.

Through this project, I learned how functions can receive a variable number of arguments using the `<stdarg.h>` library, how format strings are parsed, and how different data types can be converted into their textual representation.

The final result is a reusable static library that can be linked to future C projects developed during the 42 Common Core.

---

## Instructions

### Prerequisites

You will need:

- Linux or macOS
- `make`
- `cc` or `gcc`

Clone the repository:

```bash
git clone git@github.com:jpbellizia/ft_printf.git
```

Enter the project directory:

```bash
cd ft_printf
```

Compile the library:

| Command | Description |
|----------|-------------|
| `make` | Compiles the project and generates `libftprintf.a` |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and the library |
| `make re` | Rebuilds the project from scratch |

Include the header in your project:

```c
#include "ft_printf.h"
```

Compile your project together with the generated library:

```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o my_program
```

---

## Supported Conversions

| Conversion | Description |
|------------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal format |
| `%d` | Prints a signed decimal integer |
| `%i` | Prints a signed integer |
| `%u` | Prints an unsigned decimal integer |
| `%x` | Prints a hexadecimal number using lowercase letters |
| `%X` | Prints a hexadecimal number using uppercase letters |
| `%%` | Prints the '%' character |

---

# Algorithm and Data Structure

The implementation of `ft_printf()` is based on a **sequential parser** that scans the format string one character at a time.

Whenever a regular character is found, it is immediately written to the standard output using the `write()` system call.

When the parser encounters the `'%'` character, the following character determines which conversion function must be executed.

This architecture follows a **dispatcher pattern**, where each conversion specifier is delegated to its own specialized function.

For example:

```
"%s %d %x"
```

is interpreted as:

```
print_string()
print_decimal()
print_hexadecimal()
```

This approach keeps each conversion independent, making the project easier to understand, debug, maintain and extend.

### Variadic Arguments

The project relies on the facilities provided by `<stdarg.h>`.

The argument list is initialized with:

```c
va_start(args, format);
```

Each conversion retrieves its corresponding value using:

```c
va_arg(args, type);
```

The parser itself determines **which type** should be extracted based on the conversion specifier present in the format string.

For example:

```c
ft_printf("%c %s %d", 'A', "Hello", 42);
```

results in the following sequence:

1. `%c` → `va_arg(args, int)`
2. `%s` → `va_arg(args, char *)`
3. `%d` → `va_arg(args, int)`

The `va_list` automatically advances after each extraction until every conversion has been processed.

### Number Conversion

Decimal and unsigned integers are printed recursively by repeatedly dividing the number by its numerical base.

Hexadecimal numbers follow the same recursive algorithm using base 16 and the corresponding digit table:

```
0123456789abcdef
```

or

```
0123456789ABCDEF
```

This approach avoids allocating temporary strings and minimizes memory usage.

### Memory Management

The mandatory implementation does not require dynamic memory allocation.

All conversions are printed directly to the output stream using `write()`, avoiding unnecessary allocations and reducing memory overhead.

### Data Structures

The project intentionally uses very few data structures.

Its implementation mainly relies on:

- Constant format string (`const char *`)
- Variadic argument list (`va_list`)
- Primitive integer types
- Character arrays for hexadecimal digit lookup

Since the parser processes the format string sequentially, no additional containers such as linked lists, arrays of objects or dynamic buffers are required.

This design keeps both memory consumption and algorithmic complexity low while remaining highly maintainable.

---

## Project Structure

```
ft_printf/
│
├── ft_printf.c
├── ft_printf.h
├── Makefile
├── libft/
│
├── handlers/
│   ├── print_char.c
│   ├── print_string.c
│   ├── print_decimal.c
│   ├── print_unsigned.c
│   ├── print_hex.c
│   └── print_pointer.c
│
└── utils/
```

*(The exact organization may vary depending on the implementation.)*

---

## Resources

- 42 School subject and project guidelines
- Linux Manual Pages (`man 3 printf`)
- Linux Manual Pages (`man stdarg`)
- The C Programming Language — Brian W. Kernighan & Dennis M. Ritchie
- GeeksforGeeks — explanations and algorithm references
- cppreference.com — C language reference

---

## AI Usage Disclosure

Artificial Intelligence was used exclusively as a learning support tool.

Its contribution included:

- Explaining the internal behavior of variadic functions.
- Clarifying memory organization during function calls.
- Helping understand recursive number conversion algorithms.
- Reviewing technical documentation and improving conceptual understanding.

All implementation decisions, code architecture, debugging and testing were carried out by the project author.