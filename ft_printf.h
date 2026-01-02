/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bakh <mel-bakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 16:12:13 by mel-bakh          #+#    #+#             */
/*   Updated: 2025/12/30 21:49:15 by mel-bakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define UPPER_BASE "0123456789ABCDEF" 
# define LOWER_BASE "0123456789abcdef"

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s1);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int n);
int		ft_puthex(unsigned long long n, char format);
int		ft_putptr(void *add);

#endif