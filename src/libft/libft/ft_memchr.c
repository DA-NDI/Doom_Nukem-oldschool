/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:26:31 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/01 22:09:14 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*copy;

	copy = (char*)s;
	i = 0;
	while (n--)
	{
		if (copy[i] == (char)c)
			return (copy + i);
		i++;
	}
	return (NULL);
}
