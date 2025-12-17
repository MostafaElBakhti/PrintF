#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
	printf("original : \nhello %a World");
	printf("\n---------------------------------------\n");
	ft_printf("myFunction : \nhello %a World");
	printf("\n---------------------------------------\n");
	return (0);
}

