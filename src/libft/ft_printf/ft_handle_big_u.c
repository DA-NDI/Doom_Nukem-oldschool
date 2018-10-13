/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_big_u_.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:49:40 by avolgin           #+#    #+#             */
/*   Updated: 2018/02/01 18:32:38 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

void	ft_handle_big_u(t_field *placeholder, va_list *ap, int *len)
{
	char			*s;
	unsigned long	d;

	s = (void*)0;
	d = va_arg(*ap, unsigned long);
	s = (d == 0) ? ft_strdup("0") : ft_itoa_long_long_u(d);
	placeholder->plus = 0;
	placeholder->space = 0;
	ft_put_precision_u(&s, placeholder);
	ft_put_width_d_i(&s, placeholder);
	ft_putstr(s);
	*len = *len + ft_strlen(s);
	free(s);
}
