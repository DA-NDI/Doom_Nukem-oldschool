/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolgin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 20:21:03 by avolgin           #+#    #+#             */
/*   Updated: 2018/02/08 21:30:52 by avolgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MAX(x, y) (((x) > (y)) ? (x) : (y))
# define PL placeholder

# include <stdarg.h>
# include <unistd.h>
# include <libft.h>

/*
** MB_CUR_MAX - maximum length of multibyte char in current locale
** union - same as structure. but you can access and work with only one
** union element at a time. another elements will contain garbage. and you will
** rewrite every other time value of all other elements
*/
typedef struct		s_struct
{
	unsigned int	minus :1;
	unsigned int	plus :1;
	unsigned int	space :1;
	unsigned int	zero :1;
	unsigned int	apostrophe :1;
	unsigned int	hash :1;
	unsigned int	asteriks :1;
	unsigned int	parameter: 1;
	unsigned int	width: 1;
	unsigned int	precision: 1;
	int				value_width;
	int				value_precision;
	enum			e_length
	{
		no = 0,
		hh = 1,
		h = 2,
		l = 3,
		ll = 4,
		j = 5,
		z = 6,
		t = 7,
		L = 8
	}				length;
}					t_field;

/*
** if flags in enum are power of 2. like 1 2 4 8 16 32 etc.
** you can use | for multiple flags
**  if flag1 = 1 and flag2 = 2, then int res = flag1 | flag2 == 3
**	(0000 0001 | 0000 0010) -> 0000 0011 (3)
**
** enum			some_field
** {
**		flag1 = 1,
**		flag2 = 2,
**		flag3 = 4,
**		flag5 = 8,
**		flag6 = 16
** };
*/
void				ft_handle_o(t_field *pl, va_list *ap, int *len);
void				ft_put_precision_u(char **s, t_field *pl);
void				ft_put_precision_o(char **s, t_field *pl);
void				ft_put_hash_o(char **s, t_field *pl);
void				ft_handle_big_o(t_field *pl, va_list *ap, int *len);
void				ft_handle_big_u(t_field *pl, va_list *ap, int *len);
void				ft_handle_big_d(t_field *pl, va_list *ap, int *len);
void				ft_handle_x(t_field *pl, va_list *ap, int *len, char c);
void				ft_print_and_free(char **s, int *len);
void				ft_handle_c(t_field *pl, va_list *ap, int *len, char c);
void				ft_handle_p(t_field *pl, va_list *ap, int *len, char c);
void				ft_handle_s(t_field *pl, va_list *ap, int *len, char c);
void				ft_handle_u(t_field *pl, va_list *ap, int *len);
void				ft_handle_percent(t_field *pl, int *len);
unsigned char		*ft_handle_unicode_c(wchar_t d, int *len);
unsigned long		ft_put_length_u(t_field *pl, va_list *ap);
void				ft_put_flag(char **s, t_field *pl);
void				ft_put_width_d_i(char **s, t_field *pl);
int					ft_put_width_x(char **s, t_field *pl);
int					ft_print_d_i(t_field *pl, va_list *ap, int *len);
int					ft_printf(char *format, ...);
void				ft_unicode(int c);
void				ft_parse_all(char **format, t_field *parser, va_list *ap);

#endif
