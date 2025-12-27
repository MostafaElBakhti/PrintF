/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bakh <mel-bakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:50:34 by mel-bakh          #+#    #+#             */
/*   Updated: 2025/12/27 18:30:37 by mel-bakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long ptr)
{
	int	count;
	int	temp;

	count = 0;
	if (! ptr)
	{
		temp = ft_putstr("0x0");
		return (temp);
	}
	temp = ft_putstr("0x");
	if (temp == -1)
		return (-1);
	count += temp;
	temp = ft_puthex(ptr, 'x');
	count += temp;
	return (count);
}
