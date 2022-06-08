/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 08:18:49 by matcardo          #+#    #+#             */
/*   Updated: 2022/06/08 05:07:14 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	count_base_hex(unsigned int n)
{
	if (n <= 15)
		return (1);
	return ((unsigned int)(count_base_hex(n / 16) * 16));
}

unsigned long int	count_base_long_hex(unsigned long int n)
{
	if (n <= 15)
		return (1);
	return ((unsigned long int)(count_base_long_hex(n / 16) * 16));
}

char	hex(unsigned int n, int isUpper)
{
	char	*hexstrlower = "0123456789abcdef";
	char	*hexstrupper = "0123456789ABCDEF";

	if (isUpper)
		return(hexstrupper[(unsigned int)n]);
	return(hexstrlower[(unsigned int)n]);
}

char	long_hex(unsigned long int n, int isUpper)
{
	char	*hexstrlower = "0123456789abcdef";
	char	*hexstrupper = "0123456789ABCDEF";

	if (isUpper)
		return(hexstrupper[(unsigned long int)n]);
	return(hexstrlower[(unsigned long int)n]);
}

int		puthex(unsigned int n, int flag)
{
	unsigned int	n_iter;
	unsigned int	base;
	int	count;

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
	return(count);
}

int		put_long_hex(unsigned long int n, int flag)
{
	unsigned long int	n_iter;
	unsigned long int	base;
	int	count;

	count = 0;
	n_iter = n;
	base = count_base_long_hex(n);
	while (base >= 1)
	{
		n = n_iter / base;
		ft_putchar_fd(long_hex(n, flag), 1);
		count++;
		n_iter -= base * n;
		base = base / 16;
	}
	return(count);
}

int		putptr(unsigned long int n)
{
	int	count;
	
	write(1, "0x", 2);
	count = put_long_hex(n, 0) + 2;
	return(count);
}