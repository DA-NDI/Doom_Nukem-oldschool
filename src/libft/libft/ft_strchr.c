/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:46:02 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/08 16:50:59 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	a;
	char	*copy_s;

	copy_s = (char*)s;
	a = (char)c;
	while (*copy_s != '\0')
	{
		if (*copy_s == a)
			return (copy_s);
		copy_s++;
	}
	if (*copy_s == '\0' && a == 0)
		return (copy_s);
	return (NULL);
}
