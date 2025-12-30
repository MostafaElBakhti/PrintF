/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bakh <mel-bakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:50:34 by mel-bakh          #+#    #+#             */
/*   Updated: 2025/12/30 21:52:19 by mel-bakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptrhex(unsigned long long nb)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += ft_print_ptrhex(nb / 16);
	count += ft_putchar(LOWER_BASE[nb % 16]);
	return (count);
}

int	ft_putptr(void *add)
{
	unsigned long long	to_num;
	int					count;

	to_num = (unsigned long long)add;
	count = 0;
	if (!add)
		return (ft_putstr("0x0"));
	if (to_num)
	{
		count += ft_putchar('0');
		count += ft_putchar('x');
	}
	count += ft_print_ptrhex(to_num);
	return (count);
}
