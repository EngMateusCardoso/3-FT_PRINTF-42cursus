/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 23:47:30 by matcardo          #+#    #+#             */
/*   Updated: 2022/07/07 16:24:42 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		putstr(char *str);
int		putnbr(int n);
int		putnbr_u(unsigned int n);
int		puthex(unsigned long int n, int flag);
int		putptr(unsigned long int n);
char	*ft_strchr(const char *s, int c);
void	ft_putchar_fd(char c, int fd);

#endif
