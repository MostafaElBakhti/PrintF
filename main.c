#include <stdio.h>
#include <limits.h>
#include <string.h>

int main(){

	ft_printf("test \n: %p , %p" , NULL , (void *)555) ;
	printf("\n------------------------------\n");
	ft_printf("test \n: %p , %p" ,NULL , (void *)1) ;
	printf("\n------------------------------\n");
	return (0);
}

