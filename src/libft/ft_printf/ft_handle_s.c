/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:49:40 by avolgin           #+#    #+#             */
/*   Updated: 2018/02/06 17:14:20 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

static char	*ft_handle_wchar_exc(int length, wchar_t *a, int *len, t_field *pl)
{
	char	*d;
	char	*free_me;
	int		i;

	i = 0;
	d = ft_strnew(1);
	while (length--)
	{
		free_me = (char*)ft_handle_unicode_c(a[i++], len);
		d = ft_strjoin_del_dest(d, free_me);
		if (pl->precision && \
			(pl->value_precision - (int)ft_strlen(d)) < 0)
		{
			d[ft_strlen(d) - ft_strlen(free_me)] = '\0';
			ft_strdel(&free_me);
			return (d);
		}
		ft_strdel(&free_me);
	}
	return (d);
}

void		ft_put_precision_s(char **s, t_field *placeholder)
{
	if (placeholder->precision &&
		(size_t)(placeholder->value_precision) < ft_strlen(*s))
		*(*s + placeholder->value_precision) = '\0';
}

char		*ft_put_length_s(t_field *pl, va_list *ap, int *len, char c)
{
	char	*d;
	wchar_t	*a;
	int		length;
	int		i;

	d = (void*)0;
	i = 0;
	if (pl->length != l && c == 's')
		d = (char*)(va_arg(*ap, unsigned int*));
	else if (pl->length == l || c == 'S')
	{
		a = va_arg(*ap, wchar_t*);
		length = ft_strlen_w(a);
		if (a == NULL)
			return (d);
		d = ft_handle_wchar_exc(length, a, len, pl);
	}
	return (d);
}

void		ft_put_width_s(char **s, t_field *pars)
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
		while (len_s--)
		{
			if (pars->zero)
				s_pad[i++] = '0';
			else
				s_pad[i++] = ' ';
		}
		*s = (pars->minus) ? ft_strjoin(*s, s_pad) : ft_strjoin(s_pad, *s);
		ft_strdel(&free_me);
		free(s_pad);
	}
}

void		ft_handle_s(t_field *pars, va_list *ap, int *len, char c)
{
	char	*s;
	char	*d;

	d = ft_put_length_s(pars, ap, len, c);
	if (d == NULL)
	{
		s = (pars->value_precision < 6 && pars->precision) ? \
		ft_strsub("(null)", 0, pars->value_precision) : ft_strdup("(null)");
		ft_put_width_s(&s, pars);
		ft_putstr(s);
		*len = *len + ft_strlen(s);
		free(s);
		return ;
	}
	s = (d == NULL) ? ft_strnew(6) : ft_strnew(ft_strlen(d));
	s = (d == NULL) ? ft_strdup("(null)") : ft_memmove(s, d, ft_strlen(d));
	pars->plus = 0;
	pars->space = 0;
	ft_put_precision_s(&s, pars);
	ft_put_width_s(&s, pars);
	ft_putstr(s);
	*len = (d == '\0') ? *len + ft_strlen(s) : *len + ft_strlen(s);
	if (pars->length == l || c == 'S')
		free(d);
	free(s);
}
