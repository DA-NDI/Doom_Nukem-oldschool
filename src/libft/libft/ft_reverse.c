/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:35:42 by avolgin           #+#    #+#             */
/*   Updated: 2018/01/23 19:15:51 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_reverse(char *s)
{
	size_t	length;
	size_t	i;
	int		c;

	i = 0;
	if (s[0] == '\0')
		return (s);
	length = ft_strlen(s) - 1;
	while (i < length)
	{
		c = s[i];
		s[i] = s[length];
		s[length] = c;
		i++;
		length--;
	}
	return (s);
}
