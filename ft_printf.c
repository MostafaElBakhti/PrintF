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


int ft_format(va_list args, char c )
{
    
}


int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == 's')
		{
			count += ft_putstr(va_arg(args, char *));
			i += 2;
			continue ;
		}
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			count += ft_putchar(va_arg(args, int));
			i += 2;
			continue ;
		}
		if (format[i] == '%' && (format[i + 1] == 'd'
				|| format[i + 1] == 'i'))
		{
			count += ft_putnbr(va_arg(args, int));
			i += 2;
			continue ;
		}
		if (format[i] == '%' && format[i + 1] == 'u')
		{
			count += ft_putunsigned(va_arg(args, unsigned int));
			i += 2;
			continue ;
		}
		if (format[i] == '%' && (format[i + 1] == 'x'
				|| format[i + 1] == 'X'))
		{
		count += ft_puthex(va_arg(args, unsigned int), format[i + 1]);
		i += 2;
		continue ;
	}
	count += ft_putchar(format[i]);
	i++;
	}
	va_end(args);
	return (count);
}