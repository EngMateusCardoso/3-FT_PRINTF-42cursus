/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:29:03 by matcardo          #+#    #+#             */
/*   Updated: 2022/06/05 09:16:48 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int	conversion(const char *format_str, va_list args)
{
	if (*format_str == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (*format_str == 's')
		return (putstr(va_arg(args, char *)));
	else if (*format_str == 'p')
		ft_putchar_fd('P', 1);
	else if (*format_str == 'd')
		return (putnbr(va_arg(args, int)));
	else if (*format_str == 'i')
		return (putnbr(va_arg(args, int)));
	else if (*format_str == 'u')
		ft_putchar_fd('U', 1);
	else if (*format_str == 'x')
		ft_putchar_fd('X', 1);
	else if (*format_str == 'X')
		ft_putchar_fd('Y', 1);
	else if (*format_str == '%')
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
			continue;
		}
		ft_putchar_fd(*format_str, 1);
		format_str++;
		count++;
	}
	va_end(args);
	return(count);//22
}

int main(void)
{
	char c = 'c';
	int num = 42;
	int num2 = -42;
	int count;

	count = ft_printf("Angularjs.\n");
	printf("11 = %d\n", count);
	count = ft_printf("charactere: %c\n", c);
	printf("14 = %d\n", count);
	count = ft_printf("charactere: %c outro c %c\n", c);
	printf("24 = %d\n", count);
	count = ft_printf("string: %s\n", "hello");
	printf("14 = %d\n", count);
	count = ft_printf("string: %s %s\n", "hello", "world!");
	printf("21 = %d\n", count);
	count = ft_printf("string: %s %c\n", "hello", 'A');
	printf("16 = %d\n", count);
	count = ft_printf("Decimal: %d %i\n", num, num2);
	printf("16 = %d\n", count);
	count = ft_printf("Percent: %%\n");
	printf("11 = %d\n", count);
	return(0);
}
