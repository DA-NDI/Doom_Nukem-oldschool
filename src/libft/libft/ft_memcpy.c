/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:21:15 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/11 16:04:05 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
		i++;
	}
	return (dest);
}
