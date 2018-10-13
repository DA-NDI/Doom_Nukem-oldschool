/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:04:31 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/13 12:57:52 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	little_len;
	char	*copy_big;
	size_t	i;

	i = 0;
	if (*small == '\0')
		return ((char*)big);
	copy_big = (char*)big;
	little_len = ft_strlen(small);
	if (little_len > len)
		return (NULL);
	while (*copy_big && i <= (len - little_len))
	{
		if (ft_memcmp(copy_big, small, little_len) == 0)
		{
			return (copy_big);
		}
		i++;
		copy_big++;
	}
	return (NULL);
}
