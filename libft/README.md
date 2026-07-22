*This project has been created as part
of the 42 curriculum by jpaulo-p.*
## Libft

### Description

**Welcome to Libft!**

Libft is the first project of the 42 Common Core. The objective is to recreate a set of standard C library functions and implement additional utility functions that will be used throughout future projects.

This project introduces fundamental concepts such as memory management, string manipulation, character handling, linked lists, and code organization. The resulting library serves as a personal toolkit for future development in C.

### Instructions

#### Prerequisites to compile
You will need a Unix-like environment (Linux or macOS) equipped with the make command and a standard C compiler, such as gcc or cc.

- To use this library, clone the repository using the command below:

```
git clone git@github.com:jpbellizia/libft.git
```
Command to view all available documents in the created directory:
```
cd libft
``` 
Now use the following commands according to your needs:

`make`        - Compiles the source files and generates the static library libft.a

`make clean`  - Removes the generated object files (.o)

`make fclean` - Removes the object files (.o) and the static library libft.a

`make re`     - Performs fclean followed by make

Before using any library function, include the header file in your source code:

```
#include "libft.h"
```

After the library has been generated, you can use all the implemented functions in your C projects by linking the library during compilation:

`cc -Wall -Wextra -Werror main.c libft.a -o my_program`

### Implemented functions (all functions implemented in the created *.c files)
These functions precisely replicate the behavior of standard functions found within <ctype.h>, <string.h> and <stdlib.h>.

#### Memory and byte operations:
| Function   | Parameters                               | Description                            |
| ---------- | ---------------------------------------- | -------------------------------------- |
| ft_memset  | void *b, int c, size_t len               | Fills memory with byte value.          |
| ft_bzero   | void *s, size_t n                        | Sets memory to zero.                   |
| ft_memcpy  | void *dst, const void *src, size_t n     | Copies memory block.                   |
| ft_memmove | void *dst, const void *src, size_t len   | Copies memory safely with overlap.     |
| ft_memchr  | const void *s, int c, size_t n           | Searches byte in memory.               |
| ft_memcmp  | const void *s1, const void *s2, size_t n | Compares memory blocks.                |
| ft_calloc  | size_t nmemb, size_t size                | Allocates and zero-initializes memory. |

#### String manipulation and inspection:
| Function    | Parameters                                      | Description                                |
| ----------- | ----------------------------------------------- | ------------------------------------------ |
| ft_strlen   | const char *s                                   | Returns string length.                     |
| ft_strchr   | const char *s, int c                            | Finds first occurrence of character.       |
| ft_strrchr  | const char *s, int c                            | Finds last occurrence of character.        |
| ft_strncmp  | const char *s1, const char *s2, size_t n        | Compares strings up to n characters.       |
| ft_strnstr  | const char *big, const char *little, size_t len | Searches substring within length limit.    |
| ft_strdup   | const char *s                                   | Duplicates a string.                       |
| ft_substr   | const char *s, unsigned int start, size_t len   | Creates substring from string.             |
| ft_strjoin  | const char *s1, const char *s2                  | Concatenates two strings.                  |
| ft_strtrim  | const char *s1, const char *set                 | Removes characters from beginning and end. |
| ft_split    | const char *s, char c                           | Splits string into array of strings.       |
| ft_strmapi  | const char *s, char (*f)(unsigned int, char)    | Creates new string applying function.      |
| ft_striteri | char *s, void (*f)(unsigned int, char*)         | Applies function to each character.        |
| ft_strlcpy  | char *dst, const char *src, size_t dstsize      | Safely copies string.                      |
| ft_strlcat  | char *dst, const char *src, size_t dstsize      | Safely concatenates strings.               |
| ft_atoi     | const char *str                                 | Converts string to integer.                |
| ft_itoa     | int n                                           | Converts integer to string.                |

#### Character checks and conversion:
| Function   | Parameters | Description                                 |
| ---------- | ---------- | ------------------------------------------- |
| ft_isalpha | int c      | Checks if character is alphabetic.          |
| ft_isdigit | int c      | Checks if character is a digit.             |
| ft_isalnum | int c      | Checks if character is alphanumeric.        |
| ft_isascii | int c      | Checks if character belongs to ASCII table. |
| ft_isprint | int c      | Checks if character is printable.           |
| ft_toupper | int c      | Converts lowercase to uppercase.            |
| ft_tolower | int c      | Converts uppercase to lowercase.            |

#### File descriptor output helpers:
| Function      | Parameters      | Description                          |
| ------------- | --------------- | ------------------------------------ |
| ft_putchar_fd | char c, int fd  | Writes character to file descriptor. |
| ft_putstr_fd  | char *s, int fd | Writes string to file descriptor.    |
| ft_putendl_fd | char *s, int fd | Writes string followed by newline.   |
| ft_putnbr_fd  | int n, int fd   | Writes integer to file descriptor.   |

#### Linked List Functions

| Function | Parameters | Description |
|-----------|------------|-------------|
| ft_lstnew | void *content | Creates a new list node. |
| ft_lstadd_front | t_list **lst, t_list *new | Adds a node at the beginning of the list. |
| ft_lstadd_back | t_list **lst, t_list *new | Adds a node at the end of the list. |
| ft_lstsize | t_list *lst | Returns the number of nodes in the list. |
| ft_lstlast | t_list *lst | Returns the last node of the list. |
| ft_lstdelone | t_list *lst, void (*del)(void *) | Deletes a node and frees its content. |
| ft_lstclear | t_list **lst, void (*del)(void *) | Deletes and frees all nodes in the list. |
| ft_lstiter | t_list *lst, void (*f)(void *) | Applies a function to each node content. |
| ft_lstmap | t_list *lst, void *(*f)(void *), void (*del)(void *) | Creates a new list by applying a function to each node. |

### Resources
- Terminal pages - (man libc)
- 42 school subject and project guidelines
- [Geeksforgeeks](https://www.geeksforgeeks.org/) - Make easier to understand functions and provide examples

##### AI usage disclosure
- It helped me to better understand the use of each of the developed functions.
- It was able to explain the movements of memory to me in a minimalist way.
