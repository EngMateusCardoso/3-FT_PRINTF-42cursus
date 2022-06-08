/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 08:18:49 by matcardo          #+#    #+#             */
/*   Updated: 2022/06/08 02:55:25 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> // Lembre de apagar <-----------------------------------------------

int	ft_count_base(int n)
{
	if (n <= 9 && n >= -9)
		return (1);
	return (ft_count_base(n / 10) * 10);
}

unsigned int	ft_count_baseu(unsigned int n)
{
	if (n <= 9)
		return (1);
	return ((unsigned int)(ft_count_baseu(n / 10) * 10));
}

unsigned int	ft_count_basehex(unsigned int n)
{
	if (n <= 15)
		return (1);
	return ((unsigned int)(ft_count_basehex(n / 16) * 16));
}

unsigned long int	ft_count_basehexlong(unsigned long int n)
{
	//printf("--%lu\n",n);
	if (n <= 15)
		return (1);
	return ((unsigned long int)(ft_count_basehexlong(n / 16) * 16));
}

char	hex(unsigned int n, int isUpper)
{
	char	*hexstrlower = "0123456789abcdef";
	char	*hexstrupper = "0123456789ABCDEF";

	if (isUpper)
		return(hexstrupper[(unsigned int)n]);
	return(hexstrlower[(unsigned int)n]);
}

char	hexlong(unsigned long int n, int isUpper)
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
	base = ft_count_basehex(n);
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

int	putnbr(int n)
{
	long int	n_iter;
	int			base;
	int			count;

	count = 0;
	n_iter = n;
	base = ft_count_base(n);
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		count++;
		n_iter *= -1;
	}
	while (base >= 1)
	{
		n = n_iter / base;
		ft_putchar_fd(n + '0', 1);
		count++;
		n_iter -= base * n;
		base = base / 10;
	}
	return(count);
}

int	putnbru(unsigned int n)
{
	unsigned int	n_iter;
	unsigned int	base;
	int	count;

	count = 0;
	n_iter = n;
	base = ft_count_baseu(n);
	while (base >= 1)
	{
		n = n_iter / base;
		ft_putchar_fd(n + '0', 1);
		count++;
		n_iter -= base * n;
		base = base / 10;
	}
	return(count);
}

int		putstr(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		ft_putchar_fd(str[i++], 1);
	return(i);
}

int		puthexlong(unsigned long int n, int flag)
{
	unsigned long int	n_iter;
	unsigned long int	base;
	int	count;

	count = 0;
	n_iter = n;
	base = ft_count_basehexlong(n);
	//printf("--%lu\n",base);
	while (base >= 1)
	{
		n = n_iter / base;
		ft_putchar_fd(hexlong(n, flag), 1);
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
	count = puthexlong(n, 0) + 2;
	return(count);
}