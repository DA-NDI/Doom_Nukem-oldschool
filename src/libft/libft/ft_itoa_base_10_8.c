/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_10_8.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:37:37 by avolgin           #+#    #+#             */
/*   Updated: 2018/01/30 17:43:36 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_itoa_base_10_8(unsigned long long nbr)
{
	char	*result;
	int		bits;
	int		result_len;
	int		i;

	i = 0;
	bits = count_bits(nbr);
	result_len = (bits % 3 == 0) ? (bits / 3) : ((bits / 3) + 1);
	result = ft_strnew(result_len);
	while (i < result_len)
	{
		result[i] = (nbr & 7) + '0';
		nbr >>= 3;
		i++;
	}
	ft_reverse_bitwise(result);
	return (result);
}
