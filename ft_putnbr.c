/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bakh <mel-bakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:51:07 by mel-bakh          #+#    #+#             */
/*   Updated: 2025/12/17 15:34:14 by mel-bakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long long	nb;
	int			count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count++;
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10);
	if (count == -1 || ft_putchar((nb % 10) + '0') == -1)
		return (-1);
	return (count + 1);
}
