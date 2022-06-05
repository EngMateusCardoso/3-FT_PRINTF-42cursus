/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 08:18:49 by matcardo          #+#    #+#             */
/*   Updated: 2022/06/05 09:13:19 by matcardo         ###   ########.fr       */
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