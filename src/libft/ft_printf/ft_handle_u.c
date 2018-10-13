/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:49:40 by avolgin           #+#    #+#             */
/*   Updated: 2018/02/01 05:12:38 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

void	ft_put_precision_u(char **s, t_field *placeholder)
{
	char	*s_zero;
	int		len_s;
	int		i;
	char	*free_me;

	free_me = *s;
	i = 0;
	s_zero = (void*)0;
	if (placeholder->precision && !placeholder->value_precision && **s == '0')
	{
		*s = ft_strnew(1);
		ft_strdel(&free_me);
	}
	if (placeholder->precision && placeholder->value_precision > 0 &&
		(size_t)(placeholder->value_precision) >= ft_strlen(*s))
	{
		len_s = (size_t)(placeholder->value_precision) - ft_strlen(*s);
		len_s = (**s == '-') ? len_s + 2 : len_s;
		s_zero = ft_strnew(len_s + 1);
		while (len_s--)
			s_zero[i++] = '0';
		*s = (**s == '-') ? ft_strjoin_del_dest(s_zero, *s + 1) : \
			ft_strjoin_del_dest(s_zero, *s);
		ft_strdel(&free_me);
	}
}

void	ft_handle_u(t_field *placeholder, va_list *ap, int *len)
{
	char			*s;
	unsigned long	d;

	s = (void*)0;
	d = ft_put_length_u(placeholder, ap);
	s = (d == 0) ? ft_strdup("0") : ft_itoa_long_long_u(d);
	placeholder->plus = 0;
	placeholder->space = 0;
	ft_put_precision_u(&s, placeholder);
	ft_put_width_d_i(&s, placeholder);
	ft_putstr(s);
	*len = *len + ft_strlen(s);
	free(s);
}
