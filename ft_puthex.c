/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bakh <mel-bakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 00:16:27 by mel-bakh          #+#    #+#             */
/*   Updated: 2025/12/06 00:16:27 by mel-bakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_puthex(unsigned long long n, char format)
{
    char *hex;
    int count = 0;

    if (format == 'x')
        hex = "0123456789abcdef";
    else
        hex = "0123456789ABCDEF";

    if (n >= 16)
        count += ft_puthex(n / 16, format);

    count += ft_putchar(hex[n % 16]);

    return count;
}