/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bakh <mel-bakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:16:02 by mel-bakh          #+#    #+#             */
/*   Updated: 2025/12/27 18:31:18 by mel-bakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	count;
	int	temp;

	count = 0;
	if (n > 9)
	{
		temp = ft_putunsigned(n / 10);
		count += temp;
	}
	temp = ft_putchar((n % 10) + '0');
	count += temp;
	return (count);
}
