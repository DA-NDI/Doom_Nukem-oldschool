/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:30:40 by avolgin           #+#    #+#             */
/*   Updated: 2018/02/08 21:31:06 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	ft_get_types(char **tp)
{
	if (**tp == 'd' || **tp == 'i' || **tp == 'D' || **tp == 's' || **tp == \
		'S' || **tp == 'u' || **tp == 'U' || **tp == '%' || **tp == 'o' || \
		**tp == 'O' || **tp == 'x' || **tp == 'X' || **tp == 'c' || **tp == \
		'C' || **tp == 'p')
	{
		*tp += 1;
		return (1);
	}
	else
		return (0);
}

static int	ft_check_type(char **f_copy, t_field *parser, va_list *ap, int *len)
{
	if (**f_copy == 'd' || **f_copy == 'i')
		ft_print_d_i(parser, ap, len);
	else if (**f_copy == 'D')
		ft_handle_big_d(parser, ap, len);
	else if (**f_copy == 's' || **f_copy == 'S')
		ft_handle_s(parser, ap, len, **f_copy);
	else if (**f_copy == 'u')
		ft_handle_u(parser, ap, len);
	else if (**f_copy == 'U')
		ft_handle_big_u(parser, ap, len);
	else if (**f_copy == '%')
		ft_handle_percent(parser, len);
	else if (**f_copy == 'o')
		ft_handle_o(parser, ap, len);
	else if (**f_copy == 'O')
		ft_handle_big_o(parser, ap, len);
	else if (**f_copy == 'x' || **f_copy == 'X')
		ft_handle_x(parser, ap, len, **f_copy);
	else if (**f_copy == 'c' || **f_copy == 'C')
		ft_handle_c(parser, ap, len, **f_copy);
	else if (**f_copy == 'p')
		ft_handle_p(parser, ap, len, 'x');
	return (ft_get_types(f_copy));
}

static void	ft_reset_tfield(t_field *field)
{
	field->minus = 0;
	field->plus = 0;
	field->space = 0;
	field->apostrophe = 0;
	field->hash = 0;
	field->asteriks = 0;
	field->parameter = 0;
	field->width = 0;
	field->zero = 0;
	field->precision = 0;
	field->value_width = 0;
	field->value_precision = 0;
	field->length = 0;
}

static int	ft_print_all(char *format, va_list *ap, int len)
{
	t_field	*placeholder;

	placeholder = (t_field*)malloc(sizeof(t_field));
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format++);
			len++;
			continue;
		}
		while (*++format)
		{
			ft_reset_tfield(placeholder);
			ft_parse_all(&format, placeholder, ap);
			if (ft_check_type(&format, placeholder, ap, &len))
				break ;
			ft_putchar(*format++);
			len++;
			break ;
		}
	}
	free(placeholder);
	return (len);
}

int			ft_printf(char *format, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, format);
	len = ft_print_all(format, &ap, len);
	va_end(ap);
	return (len);
}
