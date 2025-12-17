#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
	printf("original \n : %v" , 
	42);
	printf("\n---------------------------------------\n");
	ft_printf("my function \n :%v" , 
	42);
	printf("\n---------------------------------------\n");
	return (0);
}