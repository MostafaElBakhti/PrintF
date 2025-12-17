/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bakh <mel-bakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:02:47 by mel-bakh          #+#    #+#             */
/*   Updated: 2025/12/17 16:11:35 by mel-bakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list *args, char c)
{
	if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(*args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), c));
	else if (c == 'p')
		return (ft_putptr(va_arg(*args, unsigned long long)));
	else if (c == '%')
		return (ft_putchar('%'));
	else 
	{
		if (ft_putchar(c) == -1)
			return (-1);
		return (1);
	}
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	int		tmp;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		tmp = 0;
		if (format[i] == '%' && format[i +1])
			tmp = ft_format(&args, format[++i]);
		else
			tmp = ft_putchar(format[i]);
		if (tmp == -1)
			return (-1);
		count += tmp;
		i++;
	}
	va_end(args);
	return (count);
}

// please ask the reviewe to modify the ft_printf function to support a new custom conversion specifier ,
// such as %a (or any other unused specifier) , wich insert predefined string like "42School" into the output.