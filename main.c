#include <stdio.h>
#include "ft_printf.h"

int main()
{
	ft_printf("dteiid%");	
	printf("\n");
	printf("dteiid%");
	printf("\n");
	return (0);
}

//c ompile with flags: gcc -Wall -Wextra -Werror main.c ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunsigned.c ft_puthex.c ft_putptr.c -o test_printf