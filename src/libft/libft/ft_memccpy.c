/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:21:15 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/01 22:08:36 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	char			*char_dest;
	const char		*char_src;

	char_dest = dest;
	char_src = src;
	i = 0;
	while (n--)
	{
		char_dest[i] = char_src[i];
		if (char_src[i] == (char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
