/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bakh <mel-bakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:02:47 by mel-bakh          #+#    #+#             */
/*   Updated: 2025/12/14 16:07:46 by mel-bakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list *args, char c)
{
	int	count;

	count = 0;
	if (c == 's')
		count = ft_putstr(va_arg(*args, char *));
	else if (c == 'c')
		count = ft_putchar(va_arg(*args, int));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(*args, int));
	else if (c == 'u')
		count = ft_putunsigned(va_arg(*args, unsigned int));
	else if (c == 'x' || c == 'X')
		count = ft_puthex(va_arg(*args, unsigned int), c);
	else if (c == 'p')
		count = ft_putptr(va_arg(*args, unsigned long long));
	else if (c == '%')
		count = ft_putchar('%');
	else
		count = ft_putchar(c);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	int		temp;
	va_list	args;

	if (! format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			temp = ft_format(&args, format[i + 1]);
			if (temp == -1)
				return (-1);
			count += temp;
			i += 2;
			continue ;
		}
		temp = ft_putchar(format[i]);
		if (temp == -1)
			return (-1);
		count += temp;
		i++;
	}
	va_end(args);
	return (count);
}