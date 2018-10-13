/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 16:02:03 by avolgin           #+#    #+#             */
/*   Updated: 2018/07/20 08:48:46 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa(int n)
{
	char			*result;
	int				sign;
	unsigned int	i;
	long int		a;

	a = (long int)n;
	if (!(result = ft_strnew(ft_intlen(n))))
		return (NULL);
	i = 0;
	if (a == 0)
		return (ft_strzero(result));
	if ((sign = a) < 0)
		a = -a;
	while (a > 0)
	{
		result[i] = a % 10 + '0';
		i++;
		a = a / 10;
	}
	if (sign < 0)
		result[i++] = '-';
	result[i] = '\0';
	return (ft_reverse(result));
}
