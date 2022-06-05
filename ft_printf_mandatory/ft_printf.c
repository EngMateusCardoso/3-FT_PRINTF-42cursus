/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:29:03 by matcardo          #+#    #+#             */
/*   Updated: 2022/06/05 05:53:43 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//size_t conversion(const char *format_str, va_list args)
//{
	//if()
//}

int	ft_printf(const char *format_str, ...)
{
	va_list args;
	size_t	size_flags;

	va_start(args, format_str);
	while (*format_str)
	{
		if (*format_str == '%')
		{
			//size_flags = conversion('X', 1);
			ft_putchar_fd('X', 1);
			size_flags = 2;
			while (size_flags-- > 0)
				format_str++;
			continue;
		}
		ft_putchar_fd(*format_str, 1);
		format_str++;
	}
	ft_putchar_fd('\n', 1);//Acho que tem que tirar isso no fim
	va_end(args);
}

int main(void)
{
	int num1 = 1;
	ft_printf("Angular%js", num1);
	return(0);
}