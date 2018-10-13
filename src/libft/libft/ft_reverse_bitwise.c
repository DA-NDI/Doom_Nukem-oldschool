/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bitwise.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:58:03 by avolgin           #+#    #+#             */
/*   Updated: 2018/01/30 17:23:37 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_reverse_bitwise(char *str)
{
	int		last;
	int		i;

	i = 0;
	last = ft_strlen(str) - 1;
	if (!str || !*str || last == -1)
		return (str);
	while (i < last)
	{
		str[i] ^= str[last];
		str[last] ^= str[i];
		str[i] ^= str[last];
		i++;
		last--;
	}
	return (str);
}
