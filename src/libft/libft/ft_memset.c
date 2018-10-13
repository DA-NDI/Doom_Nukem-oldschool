/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:07:16 by avolgin           #+#    #+#             */
/*   Updated: 2017/11/01 22:10:56 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char			*copy_b;
	int				i;
	unsigned char	a;

	a = (char)c;
	i = 0;
	copy_b = b;
	while (len--)
	{
		copy_b[i] = a;
		i++;
	}
	return (b);
}
