/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:16:01 by matcardo          #+#    #+#             */
/*   Updated: 2022/04/28 18:14:26 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The  memmove() function copies n bytes from memory area src to memory area dest.
The memory areas may overlap: copying takes place as though the bytes in src are
first copied into a temporary array that does not overlap src or dest, and the 
bytes are then copied  from the temporary array to dest.
The memmove() function returns a pointer to dest.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	cont;

	if (!dest && !src)
		return (NULL);
	cont = -1;
	if (dest > src)
		ft_memcpy(dest, src, n);
	else
		while (cont++ + 1 < n)
			*(char *)(dest + cont) = *(char *)(src + cont);
	return (dest);
}
