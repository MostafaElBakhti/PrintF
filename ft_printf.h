/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bakh <mel-bakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:03:10 by mel-bakh          #+#    #+#             */
/*   Updated: 2025/11/29 15:03:10 by mel-bakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s1);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int n);
int		ft_puthex(unsigned long long n, char format);
int		ft_putptr(unsigned long long ptr);

#endif