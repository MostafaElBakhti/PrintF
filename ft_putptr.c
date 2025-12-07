/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bakh <mel-bakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:50:34 by mel-bakh          #+#    #+#             */
/*   Updated: 2025/12/07 21:30:34 by mel-bakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		write(1, "0x0", 3);
		return (3);
	}
	count += ft_putstr("0x");
	count += ft_puthex(ptr, 'x');
	return (count);
}
