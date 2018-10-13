/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:42:44 by avolgin           #+#    #+#             */
/*   Updated: 2018/05/10 11:40:51 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

static int		ft_count_bits(int z)
{
	int		i;

	i = 0;
	while (z)
	{
		z = z >> 1;
		i++;
	}
	return (i);
}

static void		ft_print_8_to_11(unsigned int c, unsigned char **res)
{
	unsigned int	byte_mask_11;
	unsigned char	recover_first_6_bits;
	unsigned char	recover_last_5_bits;
	unsigned char	a;

	byte_mask_11 = 0xC080;
	recover_first_6_bits = (c << 26) >> 26;
	recover_last_5_bits = ((c >> 6) << 27) >> 27;
	a = (byte_mask_11 >> 8) | recover_last_5_bits;
	(*res)[0] = a;
	a = ((byte_mask_11 << 24) >> 24) | recover_first_6_bits;
	(*res)[1] = a;
	(*res)[2] = '\0';
}

static void		ft_print_12_to_16(unsigned int c, unsigned char **res)
{
	unsigned int	byte_mask_16;
	unsigned char	a;

	byte_mask_16 = 0xE08080;
	a = (byte_mask_16 >> 16) | ((c >> 12) << 28) >> 28;
	(*res)[0] = a;
	a = ((byte_mask_16 << 16) >> 24) | ((c >> 6) << 26) >> 26;
	(*res)[1] = a;
	a = (c << 26) >> 26 | ((byte_mask_16 << 24) >> 24);
	(*res)[2] = a;
}

static void		ft_print_17(unsigned int c, unsigned char **res)
{
	unsigned int	byte_mask_32;
	unsigned char	recover_s_6_bits;
	unsigned char	recover_t_6_bits;
	unsigned char	recover_l_3_bits;
	unsigned char	a;

	byte_mask_32 = 0xF0808080;
	recover_s_6_bits = ((c >> 6) << 26) >> 26;
	recover_t_6_bits = ((c >> 12) << 26) >> 26;
	recover_l_3_bits = ((c >> 18) << 29) >> 29;
	a = (byte_mask_32 >> 24) | recover_l_3_bits;
	(*res)[0] = a;
	a = ((byte_mask_32 << 8) >> 24) | recover_t_6_bits;
	(*res)[1] = a;
	a = (byte_mask_32 << 16) >> 24 | recover_s_6_bits;
	(*res)[2] = a;
	a = (byte_mask_32 << 24) >> 24 | (c << 26) >> 26;
	(*res)[3] = a;
	(*res)[4] = '\0';
}

unsigned char	*ft_handle_unicode_c(wchar_t d, int *len)
{
	unsigned char	a;
	unsigned int	c;
	int				size;
	unsigned char	*result;

	len = 0;
	result = (unsigned char*)ft_strnew(4);
	c = d;
	size = 0;
	size = ft_count_bits(c);
	if (size <= 7 || MB_CUR_MAX < 2)
	{
		a = c;
		result[0] = a;
		result[1] = '\0';
		return (result);
	}
	else if (size <= 11 && size > 7)
		ft_print_8_to_11(c, &result);
	else if (size <= 16 && size > 11)
		ft_print_12_to_16(c, &result);
	else
		ft_print_17(c, &result);
	return (result);
}
