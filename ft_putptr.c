/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bakh <mel-bakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 22:30:26 by mel-bakh          #+#    #+#             */
/*   Updated: 2025/12/06 22:30:26 by mel-bakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putptr(unsigned long long ptr)
{
    int count;
    count = 0;

    if (!ptr)
        return write(1, "(null)", 6);
    
    count += ft_putstr("0x");
    count += ft_puthex(ptr, 'x');

    return (count);
}