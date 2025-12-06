/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bakh <mel-bakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:23:47 by mel-bakh          #+#    #+#             */
/*   Updated: 2025/11/29 15:23:47 by mel-bakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>


// cspdiuxX%
int main()
{
    int ft_ret, printf_ret;
    
    printf("\n========== TESTING FT_PRINTF ==========\n\n");
    
    // Test %c - character
    printf("--- Testing %%c (character) ---\n");
    ft_ret = ft_printf("ft_printf: [%c]\n", 'A');
    printf_ret = printf("printf   : [%c]\n", 'A');
    printf("Return values: ft=%d, printf=%d\n\n", ft_ret, printf_ret);
    
    // Test %s - string
    printf("--- Testing %%s (string) ---\n");
    ft_ret = ft_printf("ft_printf: [%s]\n", "Hello, World!");
    printf_ret = printf("printf   : [%s]\n", "Hello, World!");
    printf("Return values: ft=%d, printf=%d\n", ft_ret, printf_ret);
    
    ft_ret = ft_printf("ft_printf: [%s]\n", "");
    printf_ret = printf("printf   : [%s]\n", "");
    printf("Return values: ft=%d, printf=%d\n\n", ft_ret, printf_ret);
    
    // Test %d and %i - integers
    printf("--- Testing %%d and %%i (integers) ---\n");
    ft_ret = ft_printf("ft_printf: [%d] [%i]\n", 42, -42);
    printf_ret = printf("printf   : [%d] [%i]\n", 42, -42);
    printf("Return values: ft=%d, printf=%d\n", ft_ret, printf_ret);
    
    ft_ret = ft_printf("ft_printf: [%d] [%d]\n", 0, 2147483647);
    printf_ret = printf("printf   : [%d] [%d]\n", 0, 2147483647);
    printf("Return values: ft=%d, printf=%d\n", ft_ret, printf_ret);
    
    ft_ret = ft_printf("ft_printf: [%d]\n", (int)-2147483648);
    printf_ret = printf("printf   : [%d]\n", (int)-2147483648);
    printf("Return values: ft=%d, printf=%d\n\n", ft_ret, printf_ret);
    
    // Test %u - unsigned int
    printf("--- Testing %%u (unsigned int) ---\n");
    ft_ret = ft_printf("ft_printf: [%u]\n", 42);
    printf_ret = printf("printf   : [%u]\n", 42);
    printf("Return values: ft=%d, printf=%d\n", ft_ret, printf_ret);
    
    ft_ret = ft_printf("ft_printf: [%u]\n", 0);
    printf_ret = printf("printf   : [%u]\n", 0);
    printf("Return values: ft=%d, printf=%d\n", ft_ret, printf_ret);
    
    ft_ret = ft_printf("ft_printf: [%u]\n", 4294967295u);
    printf_ret = printf("printf   : [%u]\n", 4294967295u);
    printf("Return values: ft=%d, printf=%d\n\n", ft_ret, printf_ret);
    
    // Test %x and %X - hexadecimal
    printf("--- Testing %%x and %%X (hexadecimal) ---\n");
    ft_ret = ft_printf("ft_printf: [%x] [%X]\n", 255, 255);
    printf_ret = printf("printf   : [%x] [%X]\n", 255, 255);
    printf("Return values: ft=%d, printf=%d\n", ft_ret, printf_ret);
    
    ft_ret = ft_printf("ft_printf: [%x] [%X]\n", 0, 0);
    printf_ret = printf("printf   : [%x] [%X]\n", 0, 0);
    printf("Return values: ft=%d, printf=%d\n", ft_ret, printf_ret);
    
    ft_ret = ft_printf("ft_printf: [%x]\n", 2147483647);
    printf_ret = printf("printf   : [%x]\n", 2147483647);
    printf("Return values: ft=%d, printf=%d\n\n", ft_ret, printf_ret);
    
    // Test %p - pointer
    printf("--- Testing %%p (pointer) ---\n");
    int var = 42;
    ft_ret = ft_printf("ft_printf: [%p]\n", &var);
    printf_ret = printf("printf   : [%p]\n", &var);
    printf("Return values: ft=%d, printf=%d\n", ft_ret, printf_ret);
    
    ft_ret = ft_printf("ft_printf: [%p]\n", NULL);
    printf_ret = printf("printf   : [%p]\n", NULL);
    printf("Return values: ft=%d, printf=%d\n\n", ft_ret, printf_ret);
    
    // Test %% - literal percent
    printf("--- Testing %%%% (literal percent) ---\n");
    ft_ret = ft_printf("ft_printf: [%%]\n");
    printf_ret = printf("printf   : [%%]\n");
    printf("Return values: ft=%d, printf=%d\n\n", ft_ret, printf_ret);
    
    // Test mixed formats
    printf("--- Testing mixed formats ---\n");
    ft_ret = ft_printf("ft_printf: %c %s %d %i %u %x %X %% %p\n", 'Z', "test", 42, -10, 100, 15, 15, &var);
    printf_ret = printf("printf   : %c %s %d %i %u %x %X %% %p\n", 'Z', "test", 42, -10, 100, 15, 15, &var);
    printf("Return values: ft=%d, printf=%d\n\n", ft_ret, printf_ret);
    
    printf("========== TESTS COMPLETE ==========\n");
    
    return 0;
}   