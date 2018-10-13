/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:28:30 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/11 16:35:52 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	size_t	n;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	n = ft_strlen(s);
	if (!(new = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (*s)
		new[i++] = f(*s++);
	new[i] = '\0';
	return (new);
}
