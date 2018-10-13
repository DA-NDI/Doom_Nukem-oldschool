/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:40:21 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/11 17:00:38 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*copy_dest;
	char	*copy_src;

	copy_dest = (char*)dest;
	copy_src = (char*)src;
	if (copy_src < copy_dest)
	{
		while (len--)
			copy_dest[len] = copy_src[len];
	}
	else
		ft_memcpy(copy_dest, copy_src, len);
	return (copy_dest);
}
