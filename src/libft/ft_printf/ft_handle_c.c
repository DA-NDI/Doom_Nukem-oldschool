/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:49:40 by avolgin           #+#    #+#             */
/*   Updated: 2018/02/01 03:18:18 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

unsigned char	*ft_put_length_c(t_field *pars, va_list *ap, int *len, char c)
{
	wchar_t			d;
	unsigned char	*ret;

	ret = (void*)0;
	d = 0;
	if (pars->length != l && c == 'c')
	{
		ret = (unsigned char*)ft_strnew(1);
		*ret = (unsigned char)(va_arg(*ap, unsigned int));
	}
	else if (pars->length == l || c == 'C' || c == 'S')
	{
		d = (unsigned int)(va_arg(*ap, unsigned int));
		ret = ft_handle_unicode_c(d, len);
	}
	return (ret);
}

static void		ft_put_width_c(char **s, t_field *pars, int *start)
{
	char	*s_pad;
	int		len_s;
	int		i;
	char	*free_me;

	free_me = *s;
	i = 0;
	if (pars->width && pars->value_width > 0 &&
		(size_t)(pars->value_width) > ft_strlen(*s))
	{
		len_s = (size_t)(pars->value_width) - ft_strlen(*s);
		s_pad = (**s == '-') ? ft_strnew(len_s + 2) : ft_strnew(len_s + 1);
		if ((**s == '-' || **s == '+' || **s == ' ') && pars->zero)
			s_pad[i++] = *(*s)++;
		len_s = (**s == '\0') ? len_s - 1 : len_s;
		while (len_s--)
		{
			*start = (*start == 1) ? 2 : *start;
			s_pad[i++] = (pars->zero) ? '0' : ' ';
		}
		*s = (pars->minus) ? ft_strjoin(*s, s_pad) : ft_strjoin(s_pad, *s);
		ft_strdel(&free_me);
		free(s_pad);
	}
}

void			ft_handle_c(t_field *placeholder, va_list *ap, int *len, char c)
{
	unsigned char	*s;
	int				null_pos;

	null_pos = 0;
	s = (void*)0;
	s = ft_put_length_c(placeholder, ap, len, c);
	if (*s == '\0')
		null_pos = 1;
	placeholder->plus = 0;
	placeholder->space = 0;
	ft_put_width_c((char **)&s, placeholder, &null_pos);
	if (null_pos == 1)
		ft_putchar('\0');
	ft_putstr((char *)s);
	if (null_pos == 2)
		ft_putchar('\0');
	*len = (null_pos == 2 || null_pos == 1) ? *len + ft_strlen((char *)s) + 1 \
		: *len + ft_strlen((char *)s);
	free(s);
}
