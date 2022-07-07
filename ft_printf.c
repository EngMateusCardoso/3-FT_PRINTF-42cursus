/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:29:03 by matcardo          #+#    #+#             */
/*   Updated: 2022/07/07 16:25:25 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion(const char *format_str, va_list args)
{
	if (*format_str == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*format_str == 's')
		return (putstr(va_arg(args, char *)));
	else if (*format_str == 'p')
		return (putptr(va_arg(args, unsigned long int)));
	else if (*format_str == 'd')
		return (putnbr(va_arg(args, int)));
	else if (*format_str == 'i')
		return (putnbr(va_arg(args, int)));
	else if (*format_str == 'u')
		return (putnbr_u(va_arg(args, unsigned int)));
	else if (*format_str == 'x')
		return (puthex(va_arg(args, unsigned int), 0));
	else if (*format_str == 'X')
		return (puthex(va_arg(args, unsigned int), 1));
	else if (*format_str == '%')
		ft_putchar_fd('%', 1);
	else
		ft_putchar_fd('%', 1);
	return (1);
}

size_t	count_flags(const char *str)
{
	if (ft_strchr("cspdiuxX%", *str))
		return (1);
	else
		return (0);
}

int	ft_printf(const char *format_str, ...)
{
	va_list	args;
	size_t	size_flags;
	int		count;

	count = 0;
	va_start(args, format_str);
	while (*format_str)
	{
		if (*format_str == '%')
		{
			format_str++;
			count += conversion(format_str, args);
			size_flags = count_flags(format_str);
			while (size_flags-- > 0)
				format_str++;
			continue ;
		}
		ft_putchar_fd(*format_str, 1);
		format_str++;
		count++;
	}
	va_end(args);
	return (count);
}
