/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 04:58:46 by matcardo          #+#    #+#             */
/*   Updated: 2022/07/07 16:26:19 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_base(int n)
{
	if (n <= 9 && n >= -9)
		return (1);
	return (ft_count_base(n / 10) * 10);
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
	return (count);
}

unsigned int	ft_count_base_u(unsigned int n)
{
	if (n <= 9)
		return (1);
	return ((unsigned int)(ft_count_base_u(n / 10) * 10));
}

int	putnbr_u(unsigned int n)
{
	unsigned int	n_iter;
	unsigned int	base;
	int				count;

	count = 0;
	n_iter = n;
	base = ft_count_base_u(n);
	while (base >= 1)
	{
		n = n_iter / base;
		ft_putchar_fd(n + '0', 1);
		count++;
		n_iter -= base * n;
		base = base / 10;
	}
	return (count);
}
