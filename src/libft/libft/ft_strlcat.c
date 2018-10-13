/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:51:17 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/11 16:41:07 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	a;

	a = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (size + src_len);
	if (src_len < size - dst_len)
	{
		ft_memcpy(dst + dst_len, src, src_len);
		dst += dst_len + src_len;
	}
	else
	{
		ft_memcpy(dst + dst_len, src, size - dst_len - 1);
		dst += size - 1;
	}
	*dst = '\0';
	return (src_len + dst_len);
}
