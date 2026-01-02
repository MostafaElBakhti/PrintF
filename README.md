*This project has been created as part of the 42 curriculum by mel-bakh.*

# ft_printf

## Description

`ft_printf` is a custom implementation of the C standard `printf` function. The goal of this project is to recreate the core functionality of `printf`, handling various format specifiers while maintaining compatibility with standard behavior. This project deepens understanding of variadic functions, string manipulation, and low-level C programming.

## Instructions

### Compilation

```bash
make
```

### Cleaning

To remove object files:

```bash
make clean
```

To remove object files and the library:

```bash
make fclean
```

## Supported Format Specifiers

- `%c` - Character
- `%s` - String
- `%d` / `%i` - Signed integer
- `%u` - Unsigned integer
- `%x` - Hexadecimal (lowercase)
- `%X` - Hexadecimal (uppercase)
- `%p` - Pointer address
- `%%` - Percent sign

## Test Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "Hello");
    ft_printf("Integer: %d\n", -42);
    ft_printf("Unsigned: %u\n", 42);
    ft_printf("Hex (lower): %x\n", 255);
    ft_printf("Hex (upper): %X\n", 255);
    ft_printf("Pointer: %p\n", (void *)&main);
    ft_printf("Percent: %%\n");
    return (0);
}
```

Compile and run:

```bash
cc -o test test.c libftprintf.a && ./test
```

## Algorithm and Data Structure

- **Variadic Arguments**: Handles variable number of arguments using `va_list`.
- **Format String Parsing**: Routes format specifiers to handlers.
- **Modular Design**: Each format specifier has a dedicated function.

## Resources

- [C Variadic Functions](https://en.cppreference.com/w/c/variadic)
- [Printf Specification](https://man7.org/linux/man-pages/man3/printf.3.html)

## AI Usage

AI was used to:
- Structure and format the README for clarity and compliance with 42 standards
- Review code for best practices and 42-compliant formatting