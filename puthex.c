/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 08:18:49 by matcardo          #+#    #+#             */
/*   Updated: 2022/07/07 16:25:54 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long int	count_base_hex(unsigned long int n)
{
	if (n <= 15)
		return (1);
	return ((unsigned long int)(count_base_hex(n / 16) * 16));
}

char	hex(unsigned long int n, int isUpper)
{
	char	*hexstrlower;
	char	*hexstrupper;

	hexstrlower = "0123456789abcdef";
	hexstrupper = "0123456789ABCDEF";
	if (isUpper)
		return (hexstrupper[(unsigned long int)n]);
	return (hexstrlower[(unsigned long int)n]);
}

int	puthex(unsigned long int n, int flag)
{
	unsigned long int	n_iter;
	unsigned long int	base;
	int					count;

	count = 0;
	n_iter = n;
	base = count_base_hex(n);
	while (base >= 1)
	{
		n = n_iter / base;
		ft_putchar_fd(hex(n, flag), 1);
		count++;
		n_iter -= base * n;
		base = base / 16;
	}
	return (count);
}

int	putptr(unsigned long int n)
{
	int	count;

	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count = puthex(n, 0) + 2;
	return (count);
}
