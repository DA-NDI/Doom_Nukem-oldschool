/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:39:11 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/08 16:20:42 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*copy_s1;
	const unsigned char	*copy_s2;

	copy_s1 = (const unsigned char*)s1;
	copy_s2 = (const unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (copy_s1[i] != copy_s2[i])
			return (copy_s1[i] - copy_s2[i]);
		i++;
	}
	return (0);
}
