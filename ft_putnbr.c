/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bakh <mel-bakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 15:51:07 by mel-bakh          #+#    #+#             */
/*   Updated: 2025/12/07 15:51:51 by mel-bakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putnbr(int n)
{
    long long nb = n;
    int count = 0;

    if (nb < 0)
    {
        count += ft_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
        count += ft_putnbr(nb / 10);
    count += ft_putchar((nb % 10) + '0');

    return count;
}