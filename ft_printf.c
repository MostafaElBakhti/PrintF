/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bakh <mel-bakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:02:47 by mel-bakh          #+#    #+#             */
/*   Updated: 2025/11/29 15:02:47 by mel-bakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// ***************************************** \\

int ft_putchar(char c)
{
    return write(1, &c, 1);
}


// ***************************************** \\

int ft_putstr(char *s1)
{
    int i;
    i = 0;
    if (!s1)
    return write(1,"(null)",6);
    while (s1[i])
    {
        ft_putchar(s1[i]);
        i++;
        }
        return (i);
        }
        
        
// ***************************************** \\

int ft_putnbr(int n)
{
    long nb = n;
    int count = 0;

    if (nb < 0)
    {
        count += ft_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
        count += ft_putnbr(nb / 10);
    count += ft_putchar((nb % 10) + '0');

    return count;
}
             
// ***************************************** \\

//?   %u -->  0 To 4294967295 

int ft_putunbr(unsigned int n)
{
    int count;
    count = 0;

    if (n > 9)
        count+= ft_putunbr(n /10);
    count += ft_putchar((n % 10) + '0');
    return (count);
}

// ***************************************** \\
// %x hexadecimal lower case

// int ft_puthex(unsigned int n)
// {
//     char *hex;
//     int count;
//     hex = "0123456789abcdef";

//     count = 0;
//     if ( n >= 16)
//         count += ft_puthex(n / 16);
//     count += ft_putchar(hex[n % 16]);
//     return (count);
// }

int ft_puthex(unsigned int n, char format)
{
    char *hex;
    int count = 0;

    if (format == 'x')
        hex = "0123456789abcdef";
    else
        hex = "0123456789ABCDEF";

    if (n >= 16)
        count += ft_puthex(n / 16, format);

    count += ft_putchar(hex[n % 16]);

    return count;
}


// ***************************************** \\

int ft_printf(const char *format, ...)
{
    int i;
    int count;
    va_list args;
    va_start(args,format);

    i = 0 ;
    count = 0 ;
    while (format[i])
    {
        if (format[i] == '%' && format[i+1] == 's')
        {
            count += ft_putstr(va_arg(args,char *));
            i+= 2;
            continue ;
        }
        if (format[i] == '%' && format[i+1] == 'c')
        {
            count += ft_putchar(va_arg(args,int));
            i+= 2;
            continue ;
        }
        if (format[i] == '%' && (format[i+1] == 'd' || format[i+1] == 'i'))
        {
            count += ft_putnbr(va_arg(args,int));
            i+= 2;
            continue ;
        }
        if (format[i] == '%' && format[i+1] == 'u')
        {
            count += ft_putunbr(va_arg(args,unsigned int));
            i+= 2;
            continue ;
        }
        if (format[i] == '%' && (format[i+1] == 'x' || format[i+1] == 'X'))
        {
            count += ft_puthex(va_arg(args,unsigned int), format[i+1]);
            i+= 2;
            continue ;
        }
        count += ft_putchar(format[i]);
        i++;
        
        
    }
    return count ;
}

int main()
{
    unsigned int n = -2;
    char *str = "world";
    char c = 'A';
    int test = ft_printf("hello %s , char %c , int %u "  , str , c, n , n);
    
    ft_printf("-----------------\n");
    ft_printf("test = %d\n", test);

}



































// int		ft_printf(const char *format, ...)
// {
//     va_list args;
//     va_start(args,format);
//     int i = 0;
//     int count = 0 ;
//     while (format[i])
//     {
//         if(format[i] == '%')
//         {
//             i++;
//             if(format[i] == 'c'){
//                 count += ft_putchar(va_arg(args,int));
//             }else if(format[i] == 's'){
//                 ft_putstr(va_arg(args,char *));
//             }
//         }else
//         {
//             count += ft_putchar(format[i]);
//         }
        
//     i++;
//     }
//     va_end(args);
//     return count ;
// }


// // ----------------------------------------------- //


// int ft_putchar(char c)
// {
//     return write(1,&c,1);
// }

// // ----------------------------------------------- //

// int ft_putstr(char *s)
// {
//     if (!s)
//     {
//        return write(1,"(null)",6);
//     }
//     int i = 0;
//     while (s[i])
//     {
//         ft_putchar(s[i]);
//         i++;
//     }
//     return (i);
// }

// int main()
// {
//     ft_printf("hello %s c char %c \n" , "world" , 'A');
// }