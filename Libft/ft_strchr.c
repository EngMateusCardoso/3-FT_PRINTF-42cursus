/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matcardo <matcardo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:05:06 by matcardo          #+#    #+#             */
/*   Updated: 2022/04/28 18:35:48 by matcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strchr() function returns a pointer to the first occurrence of the character
c in the string s.
The strchr() and strrchr() functions return a pointer to the matched character
or NULL if the character is not found. The terminatingnull byte is considered 
part of the string, so that if c is specified as '\0', these functions return a 
pointer to the terminator.
*/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		if (s[i++] == (char)c)
			return ((char *)s + i - 1); // -1 devido ao incremento anterior
	if (s[i] == (char)c) // para pegar quando c = '\0'
		return ((char *)s + i); // Aqui não preciso pq não tem incremento a mais
	return (0);
}
