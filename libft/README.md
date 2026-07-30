*This project has been created as part
of the 42 curriculum by jpaulo-p.*

## Libft

### Description

**Welcome to Libft\!**

Libft is the first project of the 42 Common Core. The objective is to recreate a set of standard C library functions and implement additional utility functions that will be used throughout future projects.

This project introduces fundamental concepts such as memory management, string manipulation, character handling, linked lists, and code organization. The resulting library serves as a personal toolkit for future development in C.

### Instructions

#### Prerequisites to compile

You will need a Unix-like environment (Linux or macOS) equipped with the make command and a standard C compiler, such as gcc or cc.

- To use this library, clone the repository using the command below:

<!-- end list -->

    git clone git@github.com:jpbellizia/libft.git

Command to view all available documents in the created directory:

    cd libft

Now use the following commands according to your needs:

`make`        - Compiles the source files and generates the static library libft.a

`make clean`  - Removes the generated object files (.o)

`make fclean` - Removes the object files (.o) and the static library libft.a

`make re`     - Performs fclean followed by make

Before using any library function, include the header file in your source code:

    #include "libft.h"

After the library has been generated, you can use all the implemented functions in your C projects by linking the library during compilation:

`cc -Wall -Wextra -Werror main.c libft.a -o my_program`

### Implemented functions (all functions implemented in the created \*.c files)

These functions precisely replicate the behavior of standard functions found within \<ctype.h\>, \<string.h\> and \<stdlib.h\>.

#### Memory and byte operations:

| Function   | Parameters                               | Description                            |
| ---------- | ---------------------------------------- | -------------------------------------- |
| ft\_memset  | void \*b, int c, size\_t len               | Fills memory with byte value.          |
| ft\_bzero   | void \*s, size\_t n                        | Sets memory to zero.                   |
| ft\_memcpy  | void \*dst, const void \*src, size\_t n     | Copies memory block.                   |
| ft\_memmove | void \*dst, const void \*src, size\_t len   | Copies memory safely with overlap.     |
| ft\_memchr  | const void \*s, int c, size\_t n           | Searches byte in memory.               |
| ft\_memcmp  | const void \*s1, const void \*s2, size\_t n | Compares memory blocks.                |
| ft\_calloc  | size\_t nmemb, size\_t size                | Allocates and zero-initializes memory. |

#### String manipulation and inspection:

| Function    | Parameters                                      | Description                                |
| ----------- | ----------------------------------------------- | ------------------------------------------ |
| ft\_strlen   | const char \*s                                   | Returns string length.                     |
| ft\_strchr   | const char \*s, int c                            | Finds first occurrence of character.       |
| ft\_strrchr  | const char \*s, int c                            | Finds last occurrence of character.        |
| ft\_strncmp  | const char \*s1, const char \*s2, size\_t n        | Compares strings up to n characters.       |
| ft\_strnstr  | const char \*big, const char \*little, size\_t len | Searches substring within length limit.    |
| ft\_strdup   | const char \*s                                   | Duplicates a string.                       |
| ft\_substr   | const char \*s, unsigned int start, size\_t len   | Creates substring from string.             |
| ft\_strjoin  | const char \*s1, const char \*s2                  | Concatenates two strings.                  |
| ft\_strtrim  | const char \*s1, const char \*set                 | Removes characters from beginning and end. |
| ft\_split    | const char \*s, char c                           | Splits string into array of strings.       |
| ft\_strmapi  | const char \*s, char (\*f)(unsigned int, char)    | Creates new string applying function.      |
| ft\_striteri | char \*s, void (*f)(unsigned int, char*)         | Applies function to each character.        |
| ft\_strlcpy  | char \*dst, const char \*src, size\_t dstsize      | Safely copies string.                      |
| ft\_strlcat  | char \*dst, const char \*src, size\_t dstsize      | Safely concatenates strings.               |
| ft\_atoi     | const char \*str                                 | Converts string to integer.                |
| ft\_itoa     | int n                                           | Converts integer to string.                |

#### Character checks and conversion:

| Function   | Parameters | Description                                 |
| ---------- | ---------- | ------------------------------------------- |
| ft\_isalpha | int c      | Checks if character is alphabetic.          |
| ft\_isdigit | int c      | Checks if character is a digit.             |
| ft\_isalnum | int c      | Checks if character is alphanumeric.        |
| ft\_isascii | int c      | Checks if character belongs to ASCII table. |
| ft\_isprint | int c      | Checks if character is printable.           |
| ft\_toupper | int c      | Converts lowercase to uppercase.            |
| ft\_tolower | int c      | Converts uppercase to lowercase.            |

#### File descriptor output helpers:

| Function      | Parameters      | Description                          |
| ------------- | --------------- | ------------------------------------ |
| ft\_putchar\_fd | char c, int fd  | Writes character to file descriptor. |
| ft\_putstr\_fd  | char \*s, int fd | Writes string to file descriptor.    |
| ft\_putendl\_fd | char \*s, int fd | Writes string followed by newline.   |
| ft\_putnbr\_fd  | int n, int fd   | Writes integer to file descriptor.   |

#### Linked List Functions

| Function | Parameters | Description |
|-----------|------------|-------------|
| ft\_lstnew | void \*content | Creates a new list node. |
| ft\_lstadd\_front | t\_list \*\*lst, t\_list \*new | Adds a node at the beginning of the list. |
| ft\_lstadd\_back | t\_list \*\*lst, t\_list \*new | Adds a node at the end of the list. |
| ft\_lstsize | t\_list \*lst | Returns the number of nodes in the list. |
| ft\_lstlast | t\_list \*lst | Returns the last node of the list. |
| ft\_lstdelone | t\_list \*lst, void (\*del)(void \*) | Deletes a node and frees its content. |
| ft\_lstclear | t\_list \*\*lst, void (\*del)(void \*) | Deletes and frees all nodes in the list. |
| ft\_lstiter | t\_list \*lst, void (\*f)(void \*) | Applies a function to each node content. |
| ft\_lstmap | t\_list \*lst, void \*(\*f)(void \*), void (\*del)(void \*) | Creates a new list by applying a function to each node. |

### Resources

- Terminal pages - (man libc)
- 42 school subject and project guidelines
- [Geeksforgeeks](https://www.geeksforgeeks.org/) - Make easier to understand functions and provide examples

##### AI usage disclosure

- It helped me to better understand the use of each of the developed functions.
- It was able to explain the movements of memory to me in a minimalist way.
