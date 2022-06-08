/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:29:03 by matcardo          #+#    #+#             */
/*   Updated: 2022/06/08 05:22:18 by matcardo         ###   ########.fr       */
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


#include <stdio.h>
int main(void)
{
	char c = 'c';
	int num = 42;
	int num2 = -42;
	unsigned int num3 = 42;
	unsigned int num4 = -42;
	int count, count2;

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
	count = ft_printf("unsigned: %u %u %u %u\n", num3, num4, num, num2);
	printf("unsigned: %u %u %u %u\n", num3, num4, num, num2);
	printf("39 = %d\n", count);
	count = ft_printf("hex: %x %X %x %X\n", num, num, num2, num2);
	//count = printf("hex: %x %X %x %X\n", num, num, num2, num2);
	printf("29 = %d\n", count);
	count2 = printf("%p %p %p %p %p\n", &num, &num2, &num3, &num4, &c);
	count = ft_printf("%p %p %p %p %p\n", &num, &num2, &num3, &num4, &c);
	printf("%d = %d\n", count, count2);
	count = ft_printf("Percent: %%\n");
	printf("11 = %d\n", count);
	return(0);
}
//*/