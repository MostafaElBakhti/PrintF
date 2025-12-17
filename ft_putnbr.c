/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bakh <mel-bakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:51:07 by mel-bakh          #+#    #+#             */
/*   Updated: 2025/12/15 16:20:43 by mel-bakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long long	nb;
	int			count;
	int			temp;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		temp = ft_putchar('-');
		if (temp == -1)
			return (-1);
		count += temp;
		nb = -nb;
	}
	if (nb >= 10)
	{
		temp = ft_putnbr(nb / 10);
		if (temp == -1)
			return (-1);
		count += temp;
	}
	temp = ft_putchar((nb % 10) + '0');
	if (temp == -1)
		return (-1);
	count += temp;
	return (count);
}
