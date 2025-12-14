/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bakh <mel-bakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:13:42 by mel-bakh          #+#    #+#             */
/*   Updated: 2025/12/07 15:50:22 by mel-bakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s1)
{
	int	i;
	int	count;
	int	temp;

	i = 0;
	count = 0;
	if (!s1)
		return (write(1, "(null)", 6));
	while (s1[i])
	{
		temp = ft_putchar(s1[i]);
		if (temp == -1)
			return (-1);
		count += temp;
		i++;
	}
	return (count);
}
