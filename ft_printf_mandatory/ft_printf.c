/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:29:03 by matcardo          #+#    #+#             */
/*   Updated: 2022/06/05 00:15:56 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format_str, ...)
{
	va_list args;

	va_start(args, format_str);
	ft_putchar_fd('a', 1);
	ft_putchar_fd('\n', 1);
	va_end(args);
}

int main(void)
{
	ft_printf("abc");
	return(0);
}