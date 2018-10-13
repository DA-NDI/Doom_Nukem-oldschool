/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 18:10:22 by avolgin           #+#    #+#             */
/*   Updated: 2018/02/06 13:57:55 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

#define PAD_CHECK placeholder->zero && !placeholder->precision

void		ft_put_width_d_i(char **s, t_field *placeholder)
{
	char	*s_pad;
	int		len_s;
	int		i;
	char	*free_me;

	free_me = (void*)0;
	i = 0;
	s_pad = (void*)0;
	if (placeholder->width && placeholder->value_width > 0 && \
		(size_t)(placeholder->value_width) > ft_strlen(*s) && \
		placeholder->value_width > placeholder->value_precision)
	{
		free_me = *s;
		len_s = (size_t)(placeholder->value_width) - ft_strlen(*s);
		s_pad = (**s == '-') ? ft_strnew(len_s + 2) : ft_strnew(len_s + 1);
		if ((**s == '-' || **s == '+' || **s == ' ') && PAD_CHECK)
			s_pad[i++] = *(*s)++;
		while (len_s--)
			s_pad[i++] = (PAD_CHECK) ? '0' : ' ';
		*s = (placeholder->minus) ? ft_strjoin_del(*s, s_pad) : \
			ft_strjoin_del_dest(s_pad, *s);
		ft_strdel(&free_me);
	}
}

void		ft_put_flag(char **s, t_field *placeholder)
{
	if (placeholder->plus && *s && *s[0] != '-')
		*s = ft_strjoin_del("+", *s);
	if (placeholder->space && *s && *s[0] != '-')
		*s = ft_strjoin_del(" ", *s);
}

static void	ft_put_precision_d_i(char **s, t_field *placeholder)
{
	char	*s_zero;
	int		len_s;
	int		i;
	char	*free_me;

	free_me = *s;
	i = 0;
	if (placeholder->precision && placeholder->value_precision > 0 &&
		(size_t)(placeholder->value_precision) >= ft_strlen(*s))
	{
		len_s = (size_t)(placeholder->value_precision) - ft_strlen(*s);
		len_s = (**s == '-') ? len_s + 2 : len_s;
		s_zero = ft_strnew(len_s + 1);
		if (len_s)
		{
			while (len_s--)
				s_zero[i++] = '0';
			s_zero[0] = (**s == '-') ? '-' : '0';
		}
		*s = (**s == '-') ? ft_strjoin_del_dest(s_zero, *s + 1) : \
			ft_strjoin_del_dest(s_zero, *s);
		ft_strdel(&free_me);
	}
}

static void	ft_put_length_d_i(char **s, t_field *placeholder, va_list *ap)
{
	intmax_t	d;

	d = 0;
	if (placeholder->length == hh)
		d = (char)(va_arg(*ap, int));
	else if (placeholder->length == h)
		d = (short)(va_arg(*ap, int));
	else if (placeholder->length == l || placeholder->length == z)
		d = va_arg(*ap, long);
	else if (placeholder->length == ll || placeholder->length == j \
	|| placeholder->length == t)
		d = va_arg(*ap, long long);
	else
		d = va_arg(*ap, int);
	*s = ft_itoa_long_long(d);
}

int			ft_print_d_i(t_field *placeholder, va_list *ap, int *len)
{
	char	*s;
	char	*free_me;

	s = (void*)0;
	ft_put_length_d_i(&s, placeholder, ap);
	free_me = s;
	if (placeholder->precision && !placeholder->value_precision && *s == '0')
	{
		s = ft_strnew(1);
		ft_strdel(&free_me);
	}
	ft_put_precision_d_i(&s, placeholder);
	ft_put_flag(&s, placeholder);
	ft_put_width_d_i(&s, placeholder);
	ft_putstr(s);
	*len = *len + ft_strlen(s);
	free(s);
	return (*len);
}
