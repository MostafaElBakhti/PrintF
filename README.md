*This project has been created as part of the 42 curriculum by mel-bakh.*

# ft_printf

## Description
`ft_printf` is a custom implementation of the standard `printf` function in C. The goal of this project is to recreate the functionality of `printf`, handling various format specifiers and ensuring compatibility with the C standard library. This project is part of the 42 curriculum, designed to enhance understanding of variadic functions, string manipulation, and low-level programming concepts.

## Instructions

### Compilation
To compile the project, use the provided `Makefile`. Run the following command in the root directory:

```bash
make
```

This will generate the `libftprintf.a` library, which can be linked to your project.

### Usage
To use the `ft_printf` function in your project, include the `ft_printf.h` header file and link the compiled library. Example:

```c
#include "ft_printf.h"

int main() {
    ft_printf("Hello, %s!\n", "world");
    return 0;
}
```

Compile and link with:

```bash
gcc -o example main.c libftprintf.a
```

### Cleaning
To remove object files and the compiled library, use:

```bash
make clean
make fclean
```

## Resources
- [C Variadic Functions](https://en.cppreference.com/w/c/variadic)
- [Printf Specification](https://man7.org/linux/man-pages/man3/printf.3.html)
- [42 Norm](https://github.com/42School/norminette)

### AI Usage
AI was used to assist in generating the README structure, ensuring clarity and completeness, and providing examples for usage and compilation.

## Algorithm and Data Structure
The `ft_printf` function uses a combination of:
- **Variadic arguments**: To handle a variable number of arguments passed to the function.
- **State machine parsing**: To process format specifiers and modifiers efficiently.
- **Buffering**: To optimize output by minimizing the number of write system calls.

These choices ensure that the implementation is both efficient and adheres to the expected behavior of the standard `printf` function.