/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 08:18:49 by matcardo          #+#    #+#             */
/*   Updated: 2022/06/05 08:36:28 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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