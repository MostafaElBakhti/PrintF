/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bakh <mel-bakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:16:27 by mel-bakh          #+#    #+#             */
/*   Updated: 2025/12/27 18:55:13 by mel-bakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long long n, char format)
{
	char	*hex;
	int		count;
	int		temp;

	count = 0;
	if (format == 'x')
		hex = LOWER_BASE;
	else
		hex = UPPER_BASE;
	if (n >= 16)
	{
		temp = ft_puthex(n / 16, format);
		count += temp;
	}
	temp = ft_putchar(hex[n % 16]);
	count += temp;
	return (count);
}
