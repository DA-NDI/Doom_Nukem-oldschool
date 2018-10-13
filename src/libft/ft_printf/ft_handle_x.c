/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:30:44 by avolgin           #+#    #+#             */
/*   Updated: 2018/02/01 01:19:44 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#define CHECK_PADD (placeholder->zero && !placeholder->precision)

void	ft_print_and_free(char **s, int *len)
{
	ft_putstr(*s);
	*len = *len + ft_strlen(*s);
	free(*s);
}

int		ft_put_width_x(char **s, t_field *placeholder)
{
	char	*s_pad;
	int		len_s;
	int		i;
	int		is_zero;

	is_zero = 0;
	i = 0;
	if (placeholder->width && placeholder->value_width > 0 &&
		(size_t)(placeholder->value_width) > ft_strlen(*s) &&
		placeholder->value_width > placeholder->value_precision)
	{
		len_s = (size_t)(placeholder->value_width) - ft_strlen(*s);
		s_pad = (**s == '-') ? ft_strnew(len_s + 2) : ft_strnew(len_s + 1);
		if ((**s == '-' || **s == '+' || **s == ' ') && placeholder->zero \
			&& !placeholder->precision)
			s_pad[i++] = *(*s)++;
		while (len_s--)
		{
			is_zero = CHECK_PADD ? 1 : is_zero;
			s_pad[i++] = CHECK_PADD ? '0' : ' ';
		}
		*s = (placeholder->minus) ? ft_strjoin_del_all(*s, s_pad) : \
			ft_strjoin_del_all(s_pad, *s);
	}
	return (is_zero);
}

void	ft_put_hash_x(char **s, t_field *placeholder, char c)
{
	if (placeholder->hash && c == 'x')
		*s = ft_strjoin_del("0x", *s);
	else if (placeholder->hash && c == 'X')
		*s = ft_strjoin_del("0X", *s);
}

void	ft_handle_x(t_field *placeholder, va_list *ap, int *len, char c)
{
	char			*s;
	unsigned long	d;
	char			*pointer_x;

	d = ft_put_length_u(placeholder, ap);
	if (c == 'x')
		s = (d == 0) ? ft_strdup("0") : ft_itoa_base_10_16(d);
	else if (c == 'X')
		s = (d == 0) ? ft_strdup("0") : ft_itoa_base_10_16x(d);
	if (d == 0)
		placeholder->hash = 0;
	placeholder->plus = 0;
	placeholder->space = 0;
	ft_put_precision_o(&s, placeholder);
	ft_put_hash_x(&s, placeholder, c);
	if (ft_put_width_x(&s, placeholder))
	{
		if ((pointer_x = ft_strchr(s, c)))
		{
			*pointer_x = '0';
			s[1] = c;
		}
	}
	ft_print_and_free(&s, len);
}
