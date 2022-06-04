/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:24:22 by matcardo          #+#    #+#             */
/*   Updated: 2022/04/28 18:26:25 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strlcat() function appends the NUL-terminated string src to the end of dst.
It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.
They are designed to be safer, more consistent, andless error prone replacements
for strncat(3).
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_count;
	size_t	dst_len;
	size_t	src_len;

	src_count = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len) // Neste caso não há espaço para concatenar;
		return (size + src_len);
	while (src[src_count] && dst_len + src_count < size - 1)
	{
		dst[dst_len + src_count] = src[src_count];
		src_count++;
	}
	dst[dst_len + src_count] = '\0';
	return (dst_len + src_len);
}
