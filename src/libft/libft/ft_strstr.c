/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:45:05 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/01 22:13:46 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strstr(const char *big, const char *little)
{
	char	*copy_big;
	char	*copy_little;
	size_t	l;

	l = ft_strlen(little);
	copy_big = (char*)big;
	copy_little = (char*)little;
	if (l == 0 && little[0] == '\0')
		return (copy_big);
	while (*copy_big)
		if (ft_memcmp(copy_big++, copy_little, l) == 0)
			return (copy_big - 1);
	return (NULL);
}
