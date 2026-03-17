*This project has been created as part of the 42 curriculum by ekarakas.*

# Libft

## Description
Libft is the first library project in the 42 curriculum. Its goal is to help you understand how fundamental C functions work by implementing them yourself. You will create a personal library (`libft.a`) containing a variety of general-purpose functions, including:

- Reimplementations of standard C library functions (e.g., `ft_strlen`, `ft_memcpy`, `ft_strncmp`).
- Additional useful functions for strings, memory management, and file output (e.g., `ft_split`, `ft_itoa`, `ft_strjoin`, `ft_putchar_fd`).
- A linked list data structure with associated operations (e.g., `ft_lstadd_back`, `ft_lstmap`).

By the end of the project, you will have a solid foundation in C programming, memory management, and data structures.

## Instructions
1. **Compilation**
   - Run `make` to compile the library into `libft.a`.
   - Makefile flags: `-Wall -Wextra -Werror`.
   - Available Makefile targets: `all`, `clean`, `fclean`, `re`.

2. **Usage**
   - Include `libft.h` in your C programs.
   - Link your program with `libft.a` using:
     ```bash
     cc -Wall -Wextra -Werror your_program.c libft.a -o your_program
     ```
   - Use any of the implemented functions as you would use standard C library functions.

3. **Testing**
   - Test programs can be created to check the correctness of your functions.
   - During peer evaluation or personal defense, these tests may be used to demonstrate functionality.

## Library Contents

### Part 1 – Libc functions
- Character checks: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- String & memory: `ft_strlen`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_strlcpy`, `ft_strlcat`
- Character conversion: `ft_toupper`, `ft_tolower`
- String search & comparison: `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_memchr`, `ft_memcmp`, `ft_strnstr`, `ft_atoi`
- Memory allocation: `ft_calloc`, `ft_strdup`

### Part 2 – Additional functions
- String manipulation: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`
- File output: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Part 3 – Linked list
- Structure:
  ```bash
  typedef struct s_list
  {
      void *content;
      struct s_list *next;
  } t_list;
  ```

- Functions: `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Resources

C Standard Library Documentation

42 Network Intranet

AI was used to summarize the project requirements and help organize the README structure. All coding was implemented independently.
## Usage Examples
```bash
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char *s1 = "Hello";
    char *s2 = "World";
    char *joined = ft_strjoin(s1, s2);

    printf("Joined string: %s\n", joined);
    free(joined);

    int numbers[] = {1, 2, 3, 4};
    t_list *list = ft_lstnew(&numbers[0]);
    ft_lstadd_back(&list, ft_lstnew(&numbers[1]));
    printf("List size: %d\n", ft_lstsize(list));

    ft_lstclear(&list, free); // clears the list
    return 0;
}
```
#### Compile with:
```bash
cc main.c libft.a
```
