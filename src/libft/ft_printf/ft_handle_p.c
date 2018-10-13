/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:30:44 by avolgin           #+#    #+#             */
/*   Updated: 2018/01/31 19:59:21 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

void	ft_handle_p(t_field *placeholder, va_list *ap, int *len, char c)
{
	char			*s;
	unsigned long	d;
	char			*pointer_x;

	d = 0;
	s = (void*)0;
	d = va_arg(*ap, unsigned long);
	s = (d == 0) ? ft_strdup("0") : ft_itoa_base_10_16(d);
	placeholder->plus = 0;
	placeholder->space = 0;
	ft_put_precision_o(&s, placeholder);
	s = ft_strjoin_del("0x", s);
	if (ft_put_width_x(&s, placeholder))
	{
		if ((pointer_x = ft_strchr(s, c)))
		{
			*pointer_x = '0';
			s[1] = c;
		}
	}
	ft_putstr(s);
	*len = *len + ft_strlen(s);
	free(s);
}
