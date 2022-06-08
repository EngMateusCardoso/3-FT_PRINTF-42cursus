/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 23:47:30 by matcardo          #+#    #+#             */
/*   Updated: 2022/06/08 04:45:11 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./Libft/libft.h"

int		ft_printf(const char *str, ...);
int		putstr(char *str);
int		putnbr(int n);
int		putnbru(unsigned int n);
int		puthex(unsigned int n, int flag);
int		putptr(unsigned long int n);

#endif