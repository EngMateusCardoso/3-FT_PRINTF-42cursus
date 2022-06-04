/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 06:31:57 by matcardo          #+#    #+#             */
/*   Updated: 2022/04/28 19:42:56 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The  strdup()  function  returns a pointer to a new string which is a duplicate
of the string s.  Memory for the new string is obtained with malloc(3), and can
be freed with free(3).
*/
char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*target;

	len = ft_strlen(src) + 1;
	target = (char *)ft_calloc(len, sizeof(char));
	if (target)
		ft_strlcpy(target, src, len);
	return (target);
}
