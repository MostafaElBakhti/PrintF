/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bakh <mel-bakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:16:02 by mel-bakh          #+#    #+#             */
/*   Updated: 2025/12/06 00:16:02 by mel-bakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putunsigned(unsigned int n)
{
    int count;
    count = 0;

    if (n > 9)
        count+= ft_putunbr(n /10);
    count += ft_putchar((n % 10) + '0');
    return (count);
}