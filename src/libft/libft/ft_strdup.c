/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:19:47 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/13 12:52:59 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *srt)
{
	int		i;
	int		length;
	char	*dest;

	i = 0;
	length = 0;
	while (srt[length] != '\0')
		length++;
	if ((dest = (char*)malloc(sizeof(char) * (length + 1))))
	{
		while (i < length)
		{
			dest[i] = (char)srt[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	else
		return (NULL);
}
