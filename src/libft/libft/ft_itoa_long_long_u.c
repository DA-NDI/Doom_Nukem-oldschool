/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long_long_u.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 16:02:03 by avolgin           #+#    #+#             */
/*   Updated: 2018/02/06 12:11:04 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_itoa_long_long_u(unsigned long long int nbr)
{
	unsigned long long int	temp;
	unsigned long long int	len;
	char					*str;

	temp = nbr;
	len = 2;
	while (temp /= 10)
		len++;
	if ((str = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);
}
