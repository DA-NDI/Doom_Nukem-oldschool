/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:58:53 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/09 19:45:34 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	a;
	size_t			s_length;
	char			*result;

	a = (const char)c;
	result = NULL;
	s_length = -1;
	while (s[++s_length] != '\0')
	{
		if (s[s_length] == a)
			result = (char*)&s[s_length];
	}
	if (s[s_length] == a)
		result = (char*)&s[s_length];
	return (result);
}
